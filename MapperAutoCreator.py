import cv2 as cv
import numpy as np
from struct import pack, unpack
import socket
import time

UDP_PORT = 6454

def pack_artnet_packet(seqNumb,Net,SubUni,data):
    Opcode = 0x5000
    packet = b'Art-Net\x00'
    packet += pack('H', Opcode)
    packet += b'\x00\x0e'    #protocol revision number 14
    packet += pack('B', seqNumb)
    packet += b'\x00'      #physical input port from which DMX512
    packet += pack('B', SubUni)  #The lowbyte of the 15 bit Port-Address to which this packet is destined.
    packet += pack('B', Net)  #The lowbyte of the 15 bit Port-Address to which this packet is destined.
    packet += pack('!H', data.size)
    packet += np.ndarray.tobytes(data)
    #packet += pack('B'*len(data),*data)
    return packet

def setPixel(img,x0,y0):
   global number
   number += 1
   img[x0,y0] = (255,255,255)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

cap = cv.VideoCapture(0)

result = np.zeros((1080, 1920, 3), np.uint8)

def mapperDetect(LedNumber,FixtureIp,FixtureUniv):
    mapping = np.zeros((LedNumber,2),np.uint16)
    Luminosity = 20
    for x in range(0,LedNumber):
        pixelData = np.zeros((LedNumber, 3), np.uint8)
        pixelData[x] = (Luminosity,Luminosity,Luminosity)
        dataS = pack_artnet_packet(10,0,FixtureUniv,pixelData)
        sock.sendto(dataS, (FixtureIp, UDP_PORT))
        time.sleep(0.05)
        maxLoctotal = (0,0)
        for y in range(1,11):
            # Capture frame-by-frame
            ret, img = cap.read()
            gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
            #gray = cv.resize(gray,(480,270))
            gray = cv.GaussianBlur(gray, (5, 5), 0)
            (minVal, maxVal, minLoc, maxLoc) = cv.minMaxLoc(gray)
            maxLoctotal = np.add(maxLoctotal, maxLoc)
            maxLocAverage = np.divide(maxLoctotal,y)
            
        cv.circle(result, tuple(maxLocAverage.astype(int)), 1, (255, 255, 255), 1)
        cv.imshow("result", result)
            # display the results of the naive attempt
        mapping[x]= tuple(maxLocAverage.astype(int))

        if cv.waitKey(1) & 0xFF == ord('q'):
               break
    pixelData = np.zeros((120, 3), np.uint8)
    dataS = pack_artnet_packet(10,0,FixtureUniv,pixelData)
    sock.sendto(dataS, (FixtureIp, UDP_PORT))
    return mapping

Circle = mapperDetect(90,"192.168.0.100",0)
np.save(f"Circle.npy",Circle)

Square = mapperDetect(120,"192.168.0.101",1)
np.save(f"Square.npy",Square)

Triangle = mapperDetect(99,"192.168.0.102",2)
np.save(f"Triangle.npy",Triangle)

Penta = mapperDetect(90,"192.168.0.103",3)
np.save(f"Penta.npy",Penta)




cv.waitKey(0)
cap.release()
cv.destroyAllWindows()
