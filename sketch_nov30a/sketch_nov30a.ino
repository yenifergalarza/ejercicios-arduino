int sensor1;  
int sensor2;
int velocidad=120;
const int motIzq1=5;
const int motDer1=6;
const int motIzq2=10;
const int motDer2=9;
int disparo=12 ,eco=13 , frec;
long cm, distancia; 

void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
pinMode(8,OUTPUT);
for (int i=0;i<10;i++){
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(200);
  digitalWrite(8,LOW);
  digitalWrite(11,LOW);
  delay(200);
}

}
void avanzar () {
  analogWrite(5,0);
  analogWrite(6,velocidad);
  analogWrite(9,velocidad);
  analogWrite(10,0);
  return;
}
void derecha (){
  analogWrite(5,velocidad);
  analogWrite(6,0);
  analogWrite(9,velocidad);
  analogWrite(10,0);
  return;
}
void izquierda (){
  analogWrite(5,0);
  analogWrite(6,velocidad);
  analogWrite(10,velocidad);
  analogWrite(9,0);
  return;
 }
 void detener (){
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,0);
 }
void loop() {
  sensor1=analogRead(A0);
  sensor2=analogRead(A1);
  Serial.println(sensor1);
  Serial.println(sensor2);
  Serial.println("---------");
  pinMode(disparo,OUTPUT);
  digitalWrite(disparo,LOW);
  delayMicroseconds(2);
  digitalWrite(disparo,HIGH);
  delayMicroseconds(5);
  digitalWrite(disparo,LOW);
  pinMode(eco,INPUT);
  distancia=pulseIn(eco,HIGH);
  cm=distancia/29/2;
  if(sensor1<700 && sensor2<700){
    avanzar();
    if(cm<15){
      detener();
      delay(2000);
      derecha();
      delay(400);
      avanzar();
      delay(1500);
      detener();
      delay(1000);
      izquierda();
      delay(700);
      avanzar();  
  }
  digitalWrite(8,LOW);
  digitalWrite(11,LOW);
  if (sensor1>700 && sensor2<700){
    derecha();
    digitalWrite(8,HIGH);
    digitalWrite(11,LOW);
    
  }
  if(sensor1<700 && sensor2>700){
    izquierda();
    digitalWrite(8,LOW);
    digitalWrite(11,HIGH);}
  }
}
 





