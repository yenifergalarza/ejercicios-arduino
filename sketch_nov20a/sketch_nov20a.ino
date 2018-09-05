void setup() {
Serial.begin(9600);  // put your setup code here, to run once:

}

void loop() {
  int CNY1=analogRead(A0);// put your main code here, to run repeatedly:
Serial.print(CNY1);
if(CNY1<800) Serial.println("Blanco1");
else Serial.println("Negro1");
delay(200);
int CNY2=analogRead(A0);// put your main code here, to run repeatedly:
Serial.print(CNY2);
if(CNY2<800) Serial.println("Blanco2");
else Serial.println("Negro2");
delay(200);



}
