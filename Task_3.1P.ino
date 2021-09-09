#include "thingProperties.h"
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE 22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here

  float temperature = dht.readTemperature();
  temp = temperature;
  Serial.print("%    temperature");
  Serial.print(temperature);
  Serial.println("celcius");
  delay(1000);


}

void onLedChange() {
  // Do something
  digitalWrite(LED_BUILTIN, led);

}
