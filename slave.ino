#include <Wire.h>
char merge[10]={};

void setup() {
 Wire.begin(8);                // join i2c bus with address 8 
 Wire.onReceive(receiveEvent); // register receive event 
 Serial.begin(9600);           // start serial for debug 
}

void loop() {
 delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 
int i=0; //counter for each bite as it arrives
  while (Wire.available()) { 
    merge[i] = Wire.read(); // every character that arrives it put in order in the empty array "t"
    i=i+1;
  }
  Serial.println(merge);
}
