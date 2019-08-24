#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "UmHIvY1ZzRkdHy-m5Xx9nM6HF5kw2aK8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "FPT-Nguy Hiem Cam Vao";
char pass[] = "110912@@";

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

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass, "blynk.megavn.net", 8440);
}

void loop()
{
  Blynk.run();
}
