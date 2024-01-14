#include <SoftwareSerial.h>

SoftwareSerial ser(10,11);

void setup() {
  pinMode(9,OUTPUT);
  digitalWrite(9, HIGH);
  
 Serial.begin(38400);
 Serial.println("coman2:");
 ser.begin(38400);
}

void loop() {
  if(ser.available()){
    Serial.write(ser.read());
  }
  if(Serial.available()){
    ser.write(Serial.read());
  }
}