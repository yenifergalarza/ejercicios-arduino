#include<Servo.h>
#include<LiquidCrystal.h>

Servo servoA;
LiquidCrystal lcd(12,11,5,4,3,2);
int angulo=5;
int disparo=7, eco=6;
long duracion, cm;


void imprimeLCD(){
  lcd.setCursor(0,0);
  lcd.print("Prueba del Servo");
  lcd.setCursor(0,1);
  lcd.print(angulo);
  lcd.print(" grados");
}
void setup() {
 servoA.attach(9);
 lcd.begin(16,2);

}

void loop() {
 
  pinMode(disparo,OUTPUT);
  digitalWrite(disparo,LOW);
  delayMicroseconds(2);
  digitalWrite(disparo,HIGH);
  delayMicroseconds(5);
  digitalWrite(disparo, LOW);

  pinMode(eco,INPUT);
  duracion=pulseIn(eco,HIGH);
  cm=duracion/29/2;

 lcd.setCursor(0,0);
  lcd.print("Distancia: ");

  if(cm<40);
  else servoA.write(angulo);
   lcd.print(cm);
  angulo=90;

  delay (2000);
  if(angulo>40) angulo=5;
  lcd.clear();

}
