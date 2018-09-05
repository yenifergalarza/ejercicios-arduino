
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int marcha=12;
int paro=11;

void setup(){
  Serial.begin(9600);
  pinMode(marcha,OUTPUT);
  pinMode(paro,OUTPUT);
  digitalWrite(marcha,LOW);
  digitalWrite(paro,LOW);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
  switch(customKey)
  {
   
    case'2':
   digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(2000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case'3':
    digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(3000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case '4':
    digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(4000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case'5':
    digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(5000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case'6':
    digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(6000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case '7':
   digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(7000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case'8':
    digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(8000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    case'9':
   digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(9000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
    
    case'0':
    digitalWrite(marcha,HIGH);
    digitalWrite(paro,LOW);
    delay(2000);
    digitalWrite(paro,HIGH);
    digitalWrite(marcha,LOW);
    break;
    
  }
}
