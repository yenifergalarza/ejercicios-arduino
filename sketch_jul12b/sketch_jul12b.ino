#include <SoftwareSerial.h>
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int estado='G';
long duracion1,duracion2,duracion3;
long cm1,cm2,cm3;
int valor1;
//configuración de pines de los ultrasonidos
int trig1 = 25;
int eco1 = 24;

int trig2 = 53;
int eco2 = 52;

int trig3 = 23;
int eco3 = 22;

int infraPin1 = 27;
int infraPin2= 26;
SoftwareSerial ALEX(15,14);//RX,TX

//FUNCION PRINCIPAL 1
void setup() {
 
  delay(5000);
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  
 
pinMode(infraPin1, INPUT);
  
  pinMode(eco1,INPUT);
  pinMode(eco2,INPUT);
  pinMode(eco3,INPUT);
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(trig3,OUTPUT);
 
  pinMode(infraPin2, INPUT);
}

//OTRAS FUNCIONES


int calcularDistancia1(){ // se insertan los valores del pin de ultrasonidos a utilizar
  pinMode(trig1, OUTPUT);
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1,LOW);
  pinMode(eco1,INPUT);
  duracion1 = pulseIn(eco1,HIGH);
  cm1 = duracion1/29/2;
}
 
 int calcularDistancia2(){ // se insertan los valores del pin de ultrasonidos a utilizar
  pinMode(trig2, OUTPUT);
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2,LOW);
  pinMode(eco2,INPUT);
  duracion2 = pulseIn(eco2,HIGH);
  cm2 = duracion2/29/2;
  }

 int calcularDistancia3(){ // se insertan los valores del pin de ultrasonidos a utilizar
  pinMode(trig3, OUTPUT);
  digitalWrite(trig3,LOW);
  delayMicroseconds(2);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig3,LOW);
  pinMode(eco3,INPUT);
  duracion3 = pulseIn(eco3,HIGH);
  cm3 = duracion3/29/2;
  
  }
void loop() {
  if(ALEX.available()>0){
}
  estado=ALEX.read();
}
  

  if(estado=='E')// ATRAS()
  {
 motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
  }
if(estado=='A')// ADELANTE()
{ 
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
}
 

if(estado=='B')//IZQUIERDA()
{
motor1.run(BACKWARD);
motor1.setSpeed(250);
motor2.run(RELEASE);
motor3.run(FORWARD);
motor3.setSpeed(250);
motor4.run(RELEASE);
 }


if(estado=='D'){//DERECHA

motor1.run(RELEASE);
motor2.run(BACKWARD);
motor2.setSpeed(250);
motor3.run(RELEASE);
motor4.run(FORWARD);
motor4.setSpeed(250);
}

if(estado=='C'){
// DETENERSE()
 motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);

}


//FUNCION PRINCIPAL 2
int valor1=digitalRead(infraPin1);

if(valor1==0){
  ADELANTE();
  delay(500);
}
int valor2=digitalRead(infraPin2);
if (valor2==0){
  ADELANTE();
}
  
  calcularDistancia1();
  calcularDistancia2();
  calcularDistancia3();


if(cm1<40){
  ADELANTE();
}else{
  IZQUIERDA();
  }

if(cm2<10){
  DERECHA();
}
if(cm3<10){
  IZQUIERDA();
 }
 
}
