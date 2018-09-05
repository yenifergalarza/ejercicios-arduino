int velocidad=200;  // VELOCIDAD DE LOS MOTORES
int estado='G';    // INICIA DETENIDO
int mot1Izq=5;
int mot1Der=6;
int mot2Izq=10;
int mot2Der=9; 
int pecho = 12;            // define el pin 12 como (pecho) para el Ultrasonido
int ptrig = 13;            // define el pin 13 como (ptrig) para el Ultrasonido
int duracion, distancia;  // para Calcular distacia


void setup() {
  Serial.begin(9600);  // INICIA EL PUERTO SERIAL PARA LA COMUNICACION CON EL BLUETOOTH 
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(pecho, INPUT);   // define el pin 12 como entrada (pecho) 
  pinMode(ptrig,OUTPUT);   // define el pin 13 como salida  (ptrig) 
  pinMode(11,OUTPUT);
}

void loop() {
 if(Serial.available()>0){
  estado = Serial.read();
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
  analogWrite(10,0);
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
  analogWrite(6,0);
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
  
     digitalWrite(ptrig, HIGH);   // genera el pulso de trigger por 10us
     delay(0.01);
     digitalWrite(ptrig, LOW);
     
     duracion = pulseIn(pecho, HIGH);              // Lee el tiempo del Echo
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
              
       analogWrite(10,0);// Girar durante 1100 milisegundos   
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
