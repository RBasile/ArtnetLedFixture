import cv2 as cv
import numpy as np
import time
import d3dshot
from struct import pack, unpack
import socket

UDP_IP = "<broadcast>"
UDP_PORT = 6454
gamma = 1.5
fps = 30
displayIndex = 0


def adjust_gamma(image, gamma=1.0):
   table = np.array([((i / 255.0) ** gamma) * 255
                     for i in np.arange(0, 256)]).astype("uint8")
   # apply gamma correction using the lookup table
   return cv.LUT(image, table)

def apply_brightness_contrast(input_img, brightness = 0, contrast = 0):
    if brightness != 0:
        if brightness > 0:
            shadow = brightness
            highlight = 255
        else:
            shadow = 0
            highlight = 255 + brightness
        alpha_b = (highlight - shadow)/255
        gamma_b = shadow
        buf = cv.addWeighted(input_img, alpha_b, input_img, 0, gamma_b)
    else:
        buf = input_img.copy()
    if contrast != 0:
        f = float(131 * (contrast + 127)) / (127 * (131 - contrast))
        alpha_c = f
        gamma_c = 127*(1-f)
        buf = cv.addWeighted(buf, alpha_c, buf, 0, gamma_c)
#cv.putText(buf,'B:{},C:{}'.format(brightness,contrast),(10, 30), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    return buf

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

def initD3Dshot():
    global displayIndex
    # D3D init
    d = d3dshot.create(capture_output="numpy", frame_buffer_size=60)
    
    # Choose display
    for i, display in enumerate(d.displays):
        current_display = display
        print('[' + str(i) + '] ' + display.name + '\n')
    # Set display
    #if len(d.displays) == 1:
    displayIndex = 0
    #else:
        #displayIndex = int(input("Select display by nr.: "))
    
    d.display = d.displays[displayIndex]
    print('\nYou\'ve selected [' + str(displayIndex) + '] ' + d.display.name)

    # Start capturing
    d.capture(target_fps=fps)
    time.sleep(0.1)
    return d
def changeScreen(d):
   global displayIndex
   displayIndex += 1
   if displayIndex >= len(d.displays):
      displayIndex = 0
   d.display = d.displays[displayIndex]
   print('\nYou\'ve selected [' + str(displayIndex) + '] ' + d.display.name)
   return d


def mapperExtract(frame,MappingData):
    LedBuffer = np.zeros((MappingData.shape[0], 3), np.uint8)
    for indx,(posX,posY) in  enumerate(MappingData):
        LedBuffer[indx] = frame[posY][posX]
    return LedBuffer

def drawMapper(frame,MappingData):
    for posX,posY in  MappingData:
        frame[posY][posX] = (255, 255, 255)
        frame[posY+1][posX] = (255, 255, 255)
        frame[posY][posX+1] = (255, 255, 255)
        frame[posY+1][posX+1] = (255, 255, 255)
    return frame

def mapperTransform(mapper,Position,Scale):
    mapper = np.add(mapper,Position).astype(int)
    mapper = np.multiply(mapper,Scale).astype(int)
    return mapper

def updateMappingTransform(frame,Position,Scale):
    PentaMapping = mapperTransform(PentaMappingF,Position,Scale)
    CircleMapping = mapperTransform(CircleMappingF,Position,Scale)
    SquareMapping = mapperTransform(SquareMappingF,Position,Scale)
    TriangleMapping = mapperTransform(TriangleMappingF,Position,Scale)
    frame = apply_brightness_contrast(frame, -200 , 0 )
    frame = drawMapper(frame,PentaMapping)
    frame = drawMapper(frame,CircleMapping)
    frame = drawMapper(frame,SquareMapping)
    frame = drawMapper(frame,TriangleMapping)
    frame = cv.resize(frame,(480,270))
    cv.imshow('ScreenToArnet',cv.cvtColor(frame, cv.COLOR_BGR2RGB))
    return CircleMapping,SquareMapping,TriangleMapping,PentaMapping


d = initD3Dshot()
lastTime = 0
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Running")

PentaMappingF = np.load("Penta.npy")
CircleMappingF = np.load("Circle.npy")
SquareMappingF = np.load("Square.npy")
TriangleMappingF = np.load("Triangle.npy")

PentaMapping = mapperTransform(PentaMappingF,(0,0),.9)
CircleMapping = mapperTransform(CircleMappingF,(0,0),.9)
SquareMapping = mapperTransform(SquareMappingF,(0,0),.9)
TriangleMapping = mapperTransform(TriangleMappingF,(0,0),.9)

frame = d.get_latest_frame()

frame = apply_brightness_contrast(frame, -200 , 0 )
#frame = cv.resize(frame,(960,540))
#frame = cv.resize(frame,(480,270))
frame = drawMapper(frame,PentaMapping)
frame = drawMapper(frame,CircleMapping)
frame = drawMapper(frame,SquareMapping)
frame = drawMapper(frame,TriangleMapping)
frame = cv.resize(frame,(480,270))
cv.imshow('ScreenToArnet',cv.cvtColor(frame, cv.COLOR_BGR2RGB))

seq =0

while True:
   seq += 1
   if seq >255: seq = 0
   # Capture frame-by-frame
   frame = d.get_latest_frame()
   frame = adjust_gamma(frame, gamma)
   #frame = cv.resize(frame,(480,270))
   #frame = cv.blur(frame,(200,200))
   #frame = cv.GaussianBlur(frame, (50, 50), 0)

   LedBuffer = mapperExtract(frame,CircleMapping)
   artnetPacket = pack_artnet_packet(10,0,0,LedBuffer)
   sock.sendto(artnetPacket, ("192.168.0.100", UDP_PORT))

   LedBuffer = mapperExtract(frame,SquareMapping)
   artnetPacket = pack_artnet_packet(10,0,1,LedBuffer)
   sock.sendto(artnetPacket, ("192.168.0.101", UDP_PORT))

   LedBuffer = mapperExtract(frame,TriangleMapping)
   artnetPacket = pack_artnet_packet(10,0,2,LedBuffer)
   sock.sendto(artnetPacket, ("192.168.0.102", UDP_PORT))

   LedBuffer = mapperExtract(frame,PentaMapping)
   artnetPacket = pack_artnet_packet(10,0,3,LedBuffer)
   sock.sendto(artnetPacket, ("192.168.0.103", UDP_PORT))
   if cv.getWindowProperty("ScreenToArnet", cv.WND_PROP_VISIBLE) <1:
      break
   k = cv.waitKey(1);
   if(k == 27) or (k == ord("q")):
     break
   elif (k == ord("+")):
     gamma = gamma + 0.1
     print(gamma)
   elif (k == ord("-")):
     gamma = gamma - 0.1
     print(gamma)
   elif (k == ord("1")):
     CircleMapping,SquareMapping,TriangleMapping,PentaMapping = updateMappingTransform(frame,(100,300),0.6)
   elif (k == ord("2")):
     CircleMapping,SquareMapping,TriangleMapping,PentaMapping = updateMappingTransform(frame,(0,0),0.9)
   elif (k == ord("3")):
     CircleMapping,SquareMapping,TriangleMapping,PentaMapping = updateMappingTransform(frame,(0,0),1)
   elif (k == ord("f")):
      frame = cv.resize(frame,(480,270))
      frameText = frame.copy()
      frameText = apply_brightness_contrast(frameText, -150 , 0 )
      cv.putText(frameText, "Pause", (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1.0, (255,255,255), 4)
      cv.imshow('ScreenToArnet',cv.cvtColor(frameText, cv.COLOR_BGR2RGB))
      time.sleep(.2)
      cv.waitKey(0);
      cv.imshow('ScreenToArnet',cv.cvtColor(frame, cv.COLOR_BGR2RGB))
   elif (k == ord("b")):
      frameBlack = apply_brightness_contrast(frame, -255 , 0 )
      LedBuffer = mapperExtract(frameBlack,CircleMapping)
      artnetPacket = pack_artnet_packet(10,0,0,LedBuffer)
      sock.sendto(artnetPacket, ("192.168.0.100", UDP_PORT))

      LedBuffer = mapperExtract(frameBlack,SquareMapping)
      artnetPacket = pack_artnet_packet(10,0,1,LedBuffer)
      sock.sendto(artnetPacket, ("192.168.0.101", UDP_PORT))

      LedBuffer = mapperExtract(frameBlack,TriangleMapping)
      artnetPacket = pack_artnet_packet(10,0,2,LedBuffer)
      sock.sendto(artnetPacket, ("192.168.0.102", UDP_PORT))

      LedBuffer = mapperExtract(frameBlack,PentaMapping)
      artnetPacket = pack_artnet_packet(10,0,3,LedBuffer)
      sock.sendto(artnetPacket, ("192.168.0.103", UDP_PORT))
      frame = cv.resize(frame,(480,270))
      frameText = frame.copy()
      frameText = apply_brightness_contrast(frameText, -150 , 0 )
      cv.putText(frameText, "Black Pause", (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1.0, (255,255,255), 4)
      cv.imshow('ScreenToArnet',cv.cvtColor(frameText, cv.COLOR_BGR2RGB))
      time.sleep(.2)
      cv.waitKey(0);
      cv.imshow('ScreenToArnet',cv.cvtColor(frame, cv.COLOR_BGR2RGB))
   elif (k == ord("*")):
      print("ScreenChange")
      changeScreen(d)
   elif (k == -1):
     pass
   else:
     print(k)

    
   timeFrame = time.perf_counter()
   sleepDur = 1/fps - (timeFrame - lastTime)
   #print(1/fps,timeFrame - lastTime,sleepDur)
   lastTime = timeFrame
   if sleepDur > 0:
      #print(sleepDur)
      time.sleep(sleepDur)
        
print("END")

frameBlack = apply_brightness_contrast(frame, -255 , 0 )
LedBuffer = mapperExtract(frameBlack,CircleMapping)
artnetPacket = pack_artnet_packet(10,0,0,LedBuffer)
sock.sendto(artnetPacket, ("192.168.0.100", UDP_PORT))

LedBuffer = mapperExtract(frameBlack,SquareMapping)
artnetPacket = pack_artnet_packet(10,0,1,LedBuffer)
sock.sendto(artnetPacket, ("192.168.0.101", UDP_PORT))

LedBuffer = mapperExtract(frameBlack,TriangleMapping)
artnetPacket = pack_artnet_packet(10,0,2,LedBuffer)
sock.sendto(artnetPacket, ("192.168.0.102", UDP_PORT))

LedBuffer = mapperExtract(frameBlack,PentaMapping)
artnetPacket = pack_artnet_packet(10,0,3,LedBuffer)
sock.sendto(artnetPacket, ("192.168.0.103", UDP_PORT))
cv.destroyAllWindows()
d.stop()

