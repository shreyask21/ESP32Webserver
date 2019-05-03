
# ESP32 Webserver
An Arduiono sketch for ESP32 to create a WiFi accesspoint and control GPIO pins via HTML GUI. 
HTML pages are stored on SPIFFS `(SPI Flash File System)` on the onboard flash memory of ESP32.

![Webpage](https://raw.githubusercontent.com/shreyask21/ESP32Webserve/master/screenshot1.png "Webpage")

## ESP32 Dependancies:
The following dependancies are needed. Please install them.

[ESPAsyncWebserver](https://github.com/me-no-dev/ESPAsyncWebServer)

[SPIFFS Plugin](https://github.com/me-no-dev/arduino-esp32fs-plugin)

## Installing:
Install Arduino IDE and the dependancies. Open the `.ino` and set the upload settings and hit upload.
After that, for ESP32, click on **ESP32 Sketch data upload** to upload the data to SPIFFS.

![Arduino](https://raw.githubusercontent.com/shreyask21/ESP32Webserve/master/screenshot2.png "SPIFFS Upload")

## Testing:
Connect to ESP32 WiFi access point (aka hotspot) and visit [192.168.4.1](http://192.168.4.1).
