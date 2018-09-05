
int disparo=7, eco=6,frec;
long duracion, cm;
int led=8;

void setup() {
  Serial.begin(9600);
}

void loop() {
  pinMode(disparo,OUTPUT);// he genrado el punto de disparo como salida
  digitalWrite(disparo,LOW);
  delayMicroseconds(2);
  digitalWrite(disparo,HIGH);
  delayMicroseconds(5);
  digitalWrite(disparo, LOW);

  pinMode(eco,INPUT);
  duracion=pulseIn(eco,HIGH);// comienza a medir la onda desde que sale y entra 
  
  cm=duracion/29/2;

if(cm<=70 && cm>=5){
  frec=-60*cm+4300;
  tone(8,frec);
}
  else noTone(8);
  Serial.println(cm);
  delay(50);
  }
