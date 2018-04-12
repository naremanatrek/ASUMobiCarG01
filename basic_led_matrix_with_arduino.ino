int colpin1=8;
int colpin2=9;
int rowpin1=1;
int rowpin2=2;
int rowpin3=3;
int rowpin4=4;
int rowpin5=5;


void setup() {
 pinMode(colpin1,OUTPUT);
 pinMode(colpin2,OUTPUT);
 pinMode(rowpin1,OUTPUT);
 pinMode(rowpin2,OUTPUT);
 pinMode(rowpin3,OUTPUT);
 pinMode(rowpin4,OUTPUT);
 pinMode(rowpin5,OUTPUT);

 

}

void loop() {
  digitalWrite(colpin1,HIGH);
  digitalWrite(colpin2,LOW);
 digitalWrite(rowpin1,LOW);
 digitalWrite(rowpin2,LOW);
digitalWrite(rowpin3,HIGH);
digitalWrite(rowpin4,LOW);
digitalWrite(rowpin5,LOW);

}
