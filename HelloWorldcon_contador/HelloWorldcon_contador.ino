
#include <LiquidCrystal.h>//libreria//

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);// indico pines del arduino y lcd ees el objeto//
int brillo=9;
void setup() {
  pinMode(brillo,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() {
  
 analogWrite(brillo,80);
  lcd.setCursor(0, 1);
  
  lcd.print("soy angeles");
}

