#include <LiquidCrystal.h>//libreria//
LiquidCrystal lcd(12, 11, 8, 5, 4, 3, 2);// indico pines del arduino y lcd ees el objeto//

void setup() {
  lcd.begin(16,2);
}

void loop() {
  
 lcd.setCursor(0,0);
  lcd.print("ELECTRONICA");
  lcd.setCursor(0,1);
  lcd.print("Contador : ");

  for(int cont=10; cont<=100;cont=cont+10){
    lcd.setCursor(11,1);
    lcd.print(cont);
    tone(8,cont*20);
    delay(1000);
  }
  lcd.clear(); //
}

