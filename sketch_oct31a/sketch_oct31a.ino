#include<SoftwareSerial.h>
SoftwareSerial BT1(7,6);
long distancia, cm;

void setup() {
BT1.begin(9600);
}

void loop() {
 pinMode(10,OUTPUT); 
 digitalWrite(10,LOW);
 delayMicroseconds(2);
 digitalWrite(10,HIGH);
 delayMicroseconds(5);
 digitalWrite(10,LOW);

 pinMode(11,INPUT);
 distancia=pulseIn(11,HIGH);
 cm=distancia/29/2;
 BT1.print(cm);
 BT1.println(" cm");
 delay(1000);
 
}
