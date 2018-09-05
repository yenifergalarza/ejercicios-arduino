int sensor1;
int sensor2;

void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(11,OUTPUT);
pinMode(8,OUTPUT);

}


void loop() {
  sensor1=analogRead(A0);
  sensor2=analogRead(A1);
  Serial.println(sensor1);
  Serial.println(sensor2);
  delay(2000);
  Serial.println("---------");
}

 

