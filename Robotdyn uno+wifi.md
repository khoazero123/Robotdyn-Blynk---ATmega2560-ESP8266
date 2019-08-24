[![](https://community.blynk.cc/letter_avatar_proxy/v4/letter/b/d07c76/45.png "bjorgvinben")](https://community.blynk.cc/u/bjorgvinben)

[bjorgvinben](https://community.blynk.cc/u/bjorgvinben)

[Jun '17](https://community.blynk.cc/t/robotdyn-uno-wifi/14607/3?u=khoazero123)

Hi,\
I did spend quite some time to get the Robotdyn UNO with ESP8266 to communicate correctly.

The ESP8266 on these boards from Robotdyn (I have the UNO version but there is also available MEGA version) seem to have sketch similar to autoconnect Example from WiFiManager, which creates webserver on ip-number 192.168.4.1 which brings forward web-page which can be used to connect/configure the access-points.

This sketch seems to hinder the ESP8266 to receive and reply to AT commands.\
At least it did not respond to any AT commands through serial monitor.

See also discussion [here](http://community.blynk.cc/t/arduino-uno-esp8266-blynk-working-with-wifimanager-by-tzapu/12984/3) where it is stated that WifiManager does not work when ESP8266 is used in Shield mode.

I flashed new official firmware from here: [https://espressif.com/en/support/download/sdks-demos 199](https://espressif.com/en/support/download/sdks-demos)\
I used version v1.5.4 and patch V1.5.4.1 Patch_20160704

I used Flash Download Tools v3.4.4 tool from here: [https://espressif.com/en/support/download/other-tools 108](https://espressif.com/en/support/download/other-tools)

I used instructions from here: [http://remotexy.com/en/help/esp8266-firmware-update/ 168](http://remotexy.com/en/help/esp8266-firmware-update/)

In the bin folder coming from the .zip file are the files needed to flash the ESP8266.

Please note that in the folder from the patch is a newer esp_init_data_default.bin file to be used.\
In the AT folder under the bin file are folders and files.

In the README.txt file are instruction on what file to store where in the ESP8266 memory location.\
As the Robotdyn UNO + WiFi has ESP8266 which is stated to be 8Mb I used:

Which means files from the 512+512 were used.

After flashing the ESP it finally started to reply to AT commands.

I then used the ESP8266_Shield from the Blynk examples as a base for Sketch for the Arduino.\
My board being Uno, with only one hardware serial means that it has only one communication mode at any given time:

1.  USB -> UNO
2.  USB -> ESP8266
3.  UNO -> ESP8266\
    Which means that I am not able to use Serial monitoring when the Uno and ESP8266 are connected.

I therefore needed to change EspSerial definition in the sketch from Serial1 to Serial:\
(#define EspSerial Serial1 - > #define EspSerial Serial)

And comment out the console serial communication:\
// Set console baud rate\
// Serial.begin(9600);\
// delay(10);

And set serial speed to 11520.

Please note that changes to the dip-switches needs to be done depending on with which part you are communicating (Uno og ESP part) and them again to let the Uno communicate with ESP.

After this work, these boards have worked flawlessly for me.

I hope this helps

Regards\
BB