#include <Wire.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 

char temp[10];
char humidity[10];
char merge[10];

void setup() {
 dht.begin();
 Serial.begin(9600); // begin serial for debug 
 Wire.begin(D1, D2); // join i2c bus with SDA=D1 and SCL=D2 of NodeMCU 
 delay(1000);
}

void loop() {
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 
 dtostrf(t, 3, 2, temp);
 dtostrf(h, 3, 2, humidity);
 
 for (byte i = 0; i < 4; i = i + 1) {
  merge[i]=humidity[i];
}

merge[4]=',';

for (byte i = 5; i < 9; i = i + 1) {
  merge[i]=temp[i-5];
}

 Serial.println(merge);
 
 Wire.beginTransmission(8); //begin with device address 8 
 Wire.write(merge);  // sends hello string 
 Wire.endTransmission();    // stop transmitting 

 
 delay(2000);
}
