int estado,velocidad=200;
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
   
  analogWrite(5,0);
  analogWrite(6,velocidad);
  analogWrite(9,velocidad);
  analogWrite(10,0);
    
  }
  
void derecha(){

  
  analogWrite(5,0);
  analogWrite(6,velocidad);
  analogWrite(9,0);
  analogWrite(10,0);
  
  } 

 void izquierda(){
   
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,velocidad);
  analogWrite(10,0);
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
  Serial.println("------------");
  delay(1000);  
                                       
  if(CNY1<400 && CNY2<400){ // blanco blanco     

 adelante();
 }

if(CNY1>800 && CNY2<400){

   derecha(); }


if(CNY1<400 && CNY2>810) { 
   izquierda();}


if(CNY1>800 && CNY2>810) { 
  detener();}

}

