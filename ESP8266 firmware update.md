ESP8266 firmware update
=======================

To work with RemoteXY the ESP8266 module must have firmware that supports AT commands not less than v0.40. To check the version of firmware, as well as to update the firmware, need to connect the module to a computer via serial port. The module can be connected via the Arduino board, or through a USB-UART adapter.

### Connecting via the Arduino board

When using the Arduino as converter the ATmega is set into reset mode and only the internal USB-UART converter is active. For this the RESET pin connected to ground. Pins TX and RX are connected to ESP8266 one to one but not crosswise as if they were connected to the controller in run mode.

![](http://remotexy.com/img/help/help-esp8266-firmware-update-arduino.png)

### Connecting via the USB-UART adapter

The adapter must have an output 3.3V power supply for ESP8266. This output should provide the necessary current of at least 200mA.

![](http://remotexy.com/img/help/help-esp8266-firmware-update-usbuart.png)

Pin CPIO0 of ESP8266 determines the run mode of module. When this pin not connected the module is run in normal mode and it answers for AT commands. When this pin is connected to the ground, the module is run to the firmware update mode. The module will set in firmware update mode when CPIO0 pin was connected to the ground at the time of power on. If this pin connect to ground when module is works, module will not set into firmware update mode.

### Check the current firmware version

To send AT commands and view the responses need to use any software serial port monitor. Very suitable the serial port tool into Arduino IDE. The serial port monitor need be set that command line will be send with final NL and CR chars both. The baud rate of the default 115200 baud.

To use the module in normal mode the pin CPIO0 must be disconnected.

Check the current firmware version can be performed by AT-command: AT+GMR. Example module response:

`\
AT+GMR

AT version:0.40.0.0(Aug 8 2015 14:45:58)\
SDK version:1.3.0\
Ai-Thinker Technology Co.,Ltd.\
Build:1.3.0.2 Sep 11 2015 11:48:04\
OK\
`

Also it is necessary to know the flash memory size of ESP module, firmware upload address depend on it size. This manual describes updated firmware of module with flash memory size 8Mbit (512KB+512KB) or 16Mbit (1024KB+1024KB), as the most common. Flash memory size can be found if send the AT-command from reset: AT+RST.

`\
AT+RST

OK

 ets Jan  8 2013,rst cause:2, boot mode:(3,1)

load 0x40100000, len 1396, room 16\
tail 4\
chksum 0x89\
load 0x3ffe8000, len 776, room 4\
tail 4\
chksum 0xe8\
load 0x3ffe8308, len 540, room 4\
tail 8\
chksum 0xc0\
csum 0xc0

2nd boot version : 1.4(b1)\
  SPI Speed      : 40MHz\
  SPI Mode       : DIO\
  SPI Flash Size & Map: 8Mbit(512KB+512KB)\
jump to run user1 @ 1000

#т#n't use rtc mem data\
slЏ‚rlМя\
Ai-Thinker Technology Co.,Ltd.

ready\
`

### The tool for firmware update

To update the firmware you must download the special tool application and the firmware itself. Application for firmware update ESP8266 will use Flash Download Tools v2.4 from official site Espressif Systems. Link to the download page: <http://espressif.com/en/products/hardware/esp8266ex/resources>. You must go to "Tools" section.

Link to the program in our file storage: [FLASH_DOWNLOAD_TOOLS_v2.4_150924.rar](https://drive.google.com/file/d/0B25ZKkkYCPJbMnhCcC01SEcwUFE/view?usp=sharing)

### Firmware

The firmware can also be downloaded from the official site. A link to the download page on the official website: <http://espressif.com/en/products/hardware/esp8266ex/resources>. You must go to "SDKs & Demos" section and download firmware ESP8266 NONOS SDK version at least v1.3.0. This firmware version began to support AT commands v0.40.

Link to the program in our file storage: [esp8266_nonos_sdk_v1.4.0_15_09_18_0.rar](https://drive.google.com/file/d/0B25ZKkkYCPJbVGR1VHZOVmVvWjA/view?usp=sharing)

All downloaded files must be unpacked and placed in the directory where the full path to the file contains only Latin characters, ie characters without the language localization.

### Settings

Run the application Flash Download Tools v2.4 (the .exe file of the same name). In the opening window must correctly chose the downloaded files and setup the connection mode.

![](http://remotexy.com/img/help/help-esp8266-firmware-update-flash-tool.png)

Downloadable files are located in the "bin" directory with the firmware files. For each file you must specify a valid address download. Use the following table to select files and destination addresses:

| Файл в каталоге bin | Флеш 8Mbit (512KB+512KB) | Флеш 16Mbit (1024KB+1024KB) |
| esp_init_data_default.bin | 0xFC000 | 0x1FC000 |
| blank.bin | 0xFE000 | 0x1FE000 |
| boot_v1.4(b1).bin or later | 0x00000 | 0x00000 |
| user1.1024.new.2.bin (in subdirectory "at") | 0x01000 | 0x01000 |
| user2.1024.new.2.bin (in subdirectory "at") | 0x81000 | 0x81000 |

Set the following settings:

-   SPIAutoSet --- set;
-   CrystalFreq - 26M;
-   FLASH SIZE -- 8Mbit or 16Mbit depending on the size of the flash memory;
-   COM PORT -- select the port that is connected to ESP;
-   BAUDRATE -- 115200

To start the firmware update process must press the button "START".

### The sequence of steps for ESP8266 firmware update

**1.** Connect the ESP module to the computer according to the wiring diagram in this article.

**2.** Start the serial port monitor. Send the AT-command AT+RST and AT+GMR for determine the current firmware version and memory size of the module. This step also allows to check the correct connection of the module.

**3.** Run the application for update firmware Flash Download Tools, correctly configure the uploaded files and addresses, correctly set settings.

**4.** Turn off power the ESP8266 module.

**5.** Connect CPIO0 pin to the ground.

**6.** Turn on power the ESP8266 module.

**7.** Click button "START" in the application for update firmware.

**8.** Wait until the end of the update firmware. At the end of the process appears inscription FINISH green.

**9.** Turn off power the ESP8266 module and disconnect the ground from pin CPIO0.

**10.** Turn on the module and run the serial port monitor. Make sure the module and new firmware version is works by send the AT-command AT+GMR.