int led=13;
int dato;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
if(Serial.available()>0){// SI DATO ES MAYOR A CERO
 dato=Serial.read();// 0-255
 analogWrite(led,dato);
}

}
