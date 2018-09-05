int ledrojo=13,ledblanco=12, ledazul=11, ledamarillo=10;

char dato;


void setup() {
  
  Serial.begin(9600);
  pinMode(ledrojo,OUTPUT);
  pinMode(ledblanco,OUTPUT);
  pinMode(ledazul,OUTPUT);
  pinMode(ledamarillo,OUTPUT);

}

void loop() {
  if(Serial.available()>0){
    dato=Serial.read();
    switch (dato){
      case'A':
      digitalWrite(ledrojo,HIGH);
   break;
    case 'B':
      digitalWrite(ledrojo,LOW);
      break;
      case'C':
      digitalWrite(ledblanco,HIGH);
   break;
    case 'D':
      digitalWrite(ledblanco,LOW);
      break;
    case 'E':
      digitalWrite(ledazul,HIGH);
      break;
      case'F':
      digitalWrite(ledazul,LOW);
   break;
    case 'G':
      digitalWrite(ledamarillo,HIGH);
      break;
      case 'H':
      digitalWrite(ledamarillo,LOW);
      break;
    }
  }

}
