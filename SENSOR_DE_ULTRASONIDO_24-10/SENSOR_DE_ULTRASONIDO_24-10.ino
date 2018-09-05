#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int disparo=7, eco=6;
long duracion, cm;
int led=8;
void setup() {
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
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

  if(cm>250) lcd.print(" error !");
  else  lcd.print(cm);
  delay(200);
  lcd.clear();

  if(cm<30) digitalWrite(led,HIGH);
  else digitalWrite(led,LOW);
}
