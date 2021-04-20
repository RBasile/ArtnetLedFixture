import clipboard


filepath = "web/artnet.html"
file_variable = open(filepath,encoding='utf8')
textall = file_variable.read()
print(textall)
textall = textall.replace("\n", "").replace("    ", "")
textall = textall.replace('"#', '/*/') #open when inside a comma
textall = textall.replace('#"', '/°/') #close
textall = textall.replace('#£', '/*/') #open outside comma
textall = textall.replace('£#', '/°/')
textall = textall.replace("\\", "\\\\")
textall = textall.replace('"', '\\"')


textall = textall.replace('/*/', '"+')
textall = textall.replace('/°/', '+"')

print(textall)
clipboard.copy(textall)
