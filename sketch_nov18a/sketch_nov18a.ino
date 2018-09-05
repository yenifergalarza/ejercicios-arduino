const int motIzq1=5;
const int motDer1=6;
const int motIzq2=10;
const int motDer2=9;
int vel=100;

void setup() {
pinMode(motIzq1,OUTPUT);
pinMode(motDer1,OUTPUT);
pinMode(motIzq2,OUTPUT);
pinMode(motDer2,OUTPUT);
 Serial.begin(9600);

}

void loop() {
 
  analogWrite(motIzq1,vel);
  analogWrite(motDer1,0);
  delay(1000);
  
  analogWrite(motIzq1,0);
  analogWrite(motDer1,vel);
  delay(1000);
  
  analogWrite(motIzq2,vel);
  analogWrite(motDer2,0);
  delay(1000);
  
  analogWrite(motIzq2,0);
  analogWrite(motDer2,vel);
  delay(1000);
 
}
