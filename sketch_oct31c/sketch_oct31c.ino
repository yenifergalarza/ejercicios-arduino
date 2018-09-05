#include<SoftwareSerial.h>
SoftwareSerial BT1(7,6);

char dato;

void setup() {
BT1.begin(9600);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);


}

void loop() {
//if(BT1.available()>0){
  dato=BT1.read();
  if(dato=='a'){
    digitalWrite(9,HIGH);
    tone(3,300);
    delay(300);
    digitalWrite(9,LOW);
    noTone(3);
  }
  if(dato=='b'){
    digitalWrite(10,HIGH);
    tone(3,600);
    delay(300);
    digitalWrite(10,LOW);
    noTone(3);
  }
  if(dato=='c'){
    digitalWrite(11,HIGH);
    tone(3,900);
    delay(300);
    digitalWrite(11,LOW);
    noTone(3);
  }
  if(dato=='d'){
    digitalWrite(12,HIGH);
    tone(3,1200);
    delay(300);
    digitalWrite(12,LOW);
    noTone(3);
  }
  if(dato=='e'){
    digitalWrite(13,HIGH);
    tone(3,1500);
    delay(300);
    digitalWrite(13,LOW);
    noTone(3);
  }
  //}
}
 
