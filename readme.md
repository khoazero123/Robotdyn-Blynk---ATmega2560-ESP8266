Hi!

It took me four months of struggling, but finally I know how to connect my combo board.

I would like to share my tiny knowledge with you and leave it here for further generations.

In order to connect Robotdyn mega to Blynk you need to do few steps.

1.  Flash ESP
2.  Upload code
3.  Setting switches

This was a quick overview. Now let's go to do it.

1.  Flash ESP\
    For flashing ESP follow this instruction list: [Robotdyn uno+wifi 66](https://community.blynk.cc/t/robotdyn-uno-wifi/14607/3?u)\
    (in this part, there is no difference between uno and mega) Stop following this list abeam *"After flashing the ESP it finally started to reply to AT commands."* and go to my next step.

2.  Upload code\
    Be very careful with dip-switch!\
    2.1. For this task, dip setting should be 3.ON 4.ON others are OFF.\
    2.2.I have downloaded an [example 26](https://examples.blynk.cc/?board=Arduino%20Mega%202560&shield=ESP8266%20WiFi%20Shield&example=GettingStarted%2FBlynkBlink) and made some changes.\
    2.3. You need to change Serial from 1 to 3 like this: #define EspSerial Serial3.\
    (exactly this i was solving four months)\
    Code should look like this:

```
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "...";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "...";
char pass[] = "...";

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial3

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(9600);
  delay(10);

  // Set ESP8266 baud rate;
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

```

This is **ABSOLUTE minimum** code to connect combo board.\
When is the board successfully connected, you can see ONLINE status in Blynk app.\
For more fun, you can add Terminal or Button for ledpin (it is described in docs). After uploading go to the next step.

1.  Setting switches\
    3.1. 8dip-switch: 1.ON 2.ON 3.ON 4.ON others are OFF.\
    This setting let you see serial print and at the same time it will communicate with ESP.\
    3.2. switch near ICSP set to RXD3 x TXD3\
    After moving all necessary switches go to the next step.

2.  Power it up, open app and take a beer.

That's all folks...

**Troubleshooting**

1.  Wrong Dip-setting
2.  Weak WIFI signal
3.  Wrong SSID, PASS, AUTH
4.  Use external power supply
5.  Possibly it could be high baud of ESP (never happen to me). You can reduce it to 9600 (to the same level as Serial.print)\
    For reducing baud use this

```
AT+UART_DEF=9600,8,1,0,0

```

or

```
AT+CIOBAUD=9600

```

it should reply

```
OK
```