const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;
int command = 0;
int trig = 11; 
int echo = 12; 
void setup() 
{
  Serial.begin(9600);
  pinMode (IN1, OUTPUT); 
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT); 
  pinMode (IN4, OUTPUT); 
  pinMode (ENA, OUTPUT); 
  pinMode (ENB, OUTPUT); 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

if (Serial.available() > 0) 
{
  command=Serial.read();
}

 if (command == '0')

{ 
long du = 0, ds = 0;
            digitalWrite(trig, LOW); 
            delayMicroseconds(10); 
            digitalWrite(trig, HIGH); 
            delayMicroseconds(10); 
            digitalWrite(trig, LOW);
            du = pulseIn(echo, HIGH);
            ds = du*0.034/2 ;
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENA, 150);
            analogWrite(ENB, 150);
            if (ds<=20) 
            {
              analogWrite(ENA, 50);
              analogWrite(ENB, 50);
              digitalWrite(IN1, HIGH);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
              delay(1000);
              analogWrite(ENA, 150);
              analogWrite(ENB, 150);
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, HIGH);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
              delay(1000);
              }
              command='0';
} 
  else if(command == '1')
  { 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    command=0; 
  }
  else if (command == '2') 
  {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 50);
      analogWrite(ENB, 50); 
      command=0; 
    } 
    else if (command == '3') 
    {
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 50); 
      analogWrite(ENB, 50);
      command=0; 
      }
      else if (command == '4') 
      { 
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        command=0; 
        } 
        else if (command == '5') 
        {
            long du = 0, ds = 0;
            digitalWrite(trig, LOW); 
            delayMicroseconds(10); 
            digitalWrite(trig, HIGH); 
            delayMicroseconds(10); 
            digitalWrite(trig, LOW);
            du = pulseIn(echo, HIGH);
            ds = du*0.034/2 ;
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENA, 50);
            analogWrite(ENB, 50);
            if (ds<=20) 
            {
              analogWrite(ENA, 50);
              analogWrite(ENB, 50);
              digitalWrite(IN1, HIGH);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
              delay(1000);
              analogWrite(ENA, 50);
              analogWrite(ENB, 50);
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, HIGH);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
              delay(1000);
              }
              command='0';
}
}
