int tiempo=100;
void setup (){
  for (int i=8;i<=12;i++) pinMode(i,OUTPUT);
}

void loop (){
  for(int veces=1; veces<=6; veces++){
 for(int i=8;i<=12;i++){
 digitalWrite(i,HIGH);
 delay(tiempo);
 digitalWrite(i,LOW);
}
  }
for(int veces=1; veces<=6; veces++){
for(int i=12;i>=8;i--){
 digitalWrite(i,HIGH);
 delay(tiempo);
 digitalWrite(i,LOW);
}
}


for(int veces=1; veces<=6; veces++){
for(int i=12;i>=8;i--)
digitalWrite(i,HIGH);
 delay(tiempo);
 for(int i=12;i>=8;i--)
 digitalWrite(i,LOW);
 delay(tiempo);
}
}

