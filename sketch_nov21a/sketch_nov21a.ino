int estado;
int sensores;
int preguntar;
const int mot1Izq=5;
const int mot1Der=6;
const int mot2Izq=10;
const int mot2Der=9;

void setup(){
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

void adelante(){
  delay(200); 
  analogWrite(5,0);
  analogWrite(6,150);
  analogWrite(9,150);
  analogWrite(10,0);
  delay(100);
  analogWrite(mot1Izq,0);
  analogWrite(mot1Der,0);
  analogWrite(mot2Izq,0);
  analogWrite(mot2Der,0);
  delay(200);
  }
  
void derecha(){

  delay(200);
  analogWrite(5,0);
  analogWrite(6,100);
  analogWrite(9,0);
  analogWrite(10,0);
  delay(100);
  analogWrite(mot1Izq,0);
  analogWrite(mot1Der,0);
  analogWrite(mot2Izq,0);
  analogWrite(mot2Der,0);
  delay(200);
  } 

 void izquierda(){
   delay(200);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,100);
  analogWrite(10,0);
  delay(100);
  analogWrite(mot1Izq,0);
  analogWrite(mot1Der,0);
  analogWrite(mot2Izq,0);
  analogWrite(mot2Der,0);
  delay(200); 
 }
 
 void detener(){
  
  analogWrite(mot1Izq,0);
  analogWrite(mot1Der,0);
  analogWrite(mot2Izq,0);
  analogWrite(mot2Der,0);
   
 }


void loop(){
 int CNY1=analogRead(A0);
  int CNY2=analogRead(A1);
  Serial.println(CNY1);                       
  Serial.println(CNY2);
  delay(200);                                       
  if(CNY1<=800 && CNY2<=800){
 delay(200);
 adelante();
 }
  else {detener();}
if(CNY1>800 && CNY2<=810){
  delay(200); izquierda(); }
else {detener();}

if(CNY2>800 && CNY1<=810) { 
  delay(200); derecha();}
else {detener();}
  
}
