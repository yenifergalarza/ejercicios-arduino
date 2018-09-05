#include <SoftwareSerial.h>
int velocidad=250;  // VELOCIDAD DE LOS MOTORES
int estado='G';    // Comienza en reposo
int mot1Izq=5;
int mot1Der=6;
int mot2Izq=10;
int mot2Der=9; 
int mot3Izq=3;
int mot3Der=4;
int mot4Izq=7;
int mot4Der=8; 
int echo = 12;            // define el pin 12 como (echo) para el Ultrasonido
int trig = 13;            // define el pin 13 como (trig) para el Ultrasonido
long duracion, distancia;  // para Calcular distacia

SoftwareSerial ALEX(0,1); // RX | TX
void setup() {
  ALEX.begin(9600);  // INICIA EL PUERTO SERIAL PARA LA COMUNICACION CON EL BLUETOOTH 
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
   pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  pinMode(echo, INPUT);   // define el pin 12 como entrada (echo) 
  pinMode(trig,OUTPUT);   // define el pin 13 como salida  (trig) 
  pinMode(11,OUTPUT);
}

void loop() {
 if(ALEX.available()>0){
  estado = ALEX.read();
 }
 if(estado=='A'){  //avanzar
  analogWrite(10,0);
  analogWrite(6,0);
  analogWrite(9,velocidad);
  analogWrite(5,velocidad);
   analogWrite(8,0);
  analogWrite(4,0);
  analogWrite(7,velocidad);
  analogWrite(3,velocidad);
 }
 if(estado=='B'){  // izquierda
  analogWrite(10,306);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(5,velocidad);
   analogWrite(8,0);
  analogWrite(4,0);
  analogWrite(3,0);
  analogWrite(7,velocidad);
 }
 if(estado=='C'){    // detener
  analogWrite(10,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(5,0);
   analogWrite(8,0);
  analogWrite(4,0);
  analogWrite(7,0);
  analogWrite(3,0);
 }
  if(estado=='D'){ // derecha
  analogWrite(10,0);
  analogWrite(6,306);
  analogWrite(9,velocidad);
  analogWrite(5,0);
   analogWrite(8,0);
  analogWrite(4,0);
  analogWrite(7,0);
  analogWrite(3,velocidad);
 }
  if(estado=='E'){ //reversa
  analogWrite(10,velocidad);
  analogWrite(6,velocidad);
  analogWrite(9,0);
  analogWrite(5,0);
   analogWrite(7,0);
  analogWrite(3,0);
  analogWrite(8,velocidad);
  analogWrite(4,velocidad);
 }
 if(estado=='F'){// Boton ON,  se mueve sensando distancia 
  
     digitalWrite(trig, HIGH);   // genera el pulso de trigger por 10us
     delay(0.01);
     digitalWrite(trig, LOW);
     
     duracion = pulseIn(echo, HIGH);              // Lee el tiempo del Echo
     distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
     delay(10); 
     
     if (distancia <= 15 && distancia >=2){    // si la distancia es menor de 15cm
        digitalWrite(11,HIGH);                 // Enciende LED
        
      analogWrite(10,0);
      analogWrite(6,0);
      analogWrite(9,0);
      analogWrite(5,0);
      analogWrite(8,0);
      analogWrite(4,0);
      analogWrite(7,0);
      analogWrite(3,0);                  // Parar los motores por 200 mili segundos
        
        delay (200);
        
        analogWrite(10,velocidad);  // Reversa durante 500 mili segundos
        analogWrite(6,velocidad);  
        analogWrite(8,velocidad);
        analogWrite(4,velocidad);
        delay(500);           
              
       analogWrite(10,306);// Girar a la izquierda
       analogWrite(6,0);
       analogWrite(9,0);
       analogWrite(5,velocidad);
       analogWrite(8,0);
       analogWrite(4,0);
       analogWrite(3,0);
       analogWrite(7,velocidad);
       delay(1100);
        
        digitalWrite(11,LOW);
     }
     else{                   // Si no hay obstaculos se desplaza al frente  
      analogWrite(6,0);
      analogWrite(9,velocidad);
      analogWrite(5,velocidad);
      analogWrite(8,0);
      analogWrite(4,0);
      analogWrite(7,velocidad);
      analogWrite(3,velocidad);
     }
 }
 if(estado=='G'){ // boton OFF no hace nada
  analogWrite(10,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(5,0);
  analogWrite(8,0);
  analogWrite(4,0);
  analogWrite(7,0);
  analogWrite(3,0);
 }

}
