#include<SoftwareSerial.h>
SoftwareSerial PuertoBT1(6,7);
int disparo=9, eco=8;
long duracion, cm;

void setup() {
  PuertoBT1.begin(9600);
}

void loop() {
 pinMode(disparo,OUTPUT);
 digitalWrite(disparo,LOW
}
