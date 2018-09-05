#include<SoftwareSerial.h>
SoftwareSerial BT1(7,6);
int mIzq=9;
int mDer=10;
char dato;

void setup() {
BT1.begin(9600);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

}

void loop() {
if(BT1.available()>0){
  dato=BT1.read();
  if(dato=='a'){
    analogWrite(mIzq,50);
    analogWrite(mDer,0);
  }
  if(dato=='b'){
    analogWrite(mIzq,100);
    analogWrite(mDer,0);
  }
  if(dato=='c'){
    analogWrite(mIzq,150);
    analogWrite(mDer,0);
  }
  if(dato=='d'){
    analogWrite(mIzq,200);
    analogWrite(mDer,0);
  }
  if(dato=='e'){
    analogWrite(mIzq,255);
    analogWrite(mDer,0);
  }
  if(dato=='p'){
    analogWrite(mIzq,0);
    analogWrite(mDer,0);
  }
  }
}

