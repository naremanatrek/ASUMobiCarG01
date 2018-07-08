const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 10;
int command = 0;
int number = 0;
int trig = 11; 
int echo = 12;
int x = 0;
int l =2;
int c =13;
int r =8;
int z = 0;
char value ;
void forward()
{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA,80);
      analogWrite(ENB,80);
}
void backward()
{
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA,80);
      analogWrite(ENB,80);
}
void right()
{
             digitalWrite(IN1, HIGH); 
             digitalWrite(IN2, LOW);
             digitalWrite(IN3, LOW);
             digitalWrite(IN4, HIGH);
             analogWrite(ENA,80);
             analogWrite(ENB,80);
}
void left()
{
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, HIGH);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
              analogWrite(ENA,80);
              analogWrite(ENB,80);
}
void stopp()
{
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, LOW);
              digitalWrite(IN4, LOW);  
} 
void acc_right()
{
  digitalWrite(IN1, LOW); 
             digitalWrite(IN2, HIGH);
             digitalWrite(IN3, LOW);
             digitalWrite(IN4, LOW);
             analogWrite(ENA,80);
             analogWrite(ENB,0);
}
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
  pinMode(l , INPUT);
  pinMode(c , INPUT);
  pinMode(r , INPUT);
}

void loop() {

if (Serial.available() > 0) 
{
  command=Serial.read();
}
if(command == '1')
{
  forward();
}
 if (command == 'F')

{ 
long du = 0, ds = 0;
            digitalWrite(trig, LOW); 
            delayMicroseconds(10); 
            digitalWrite(trig, HIGH); 
            delayMicroseconds(10); 
            digitalWrite(trig, LOW);
            du = pulseIn(echo, HIGH);
            ds = du*0.034/2 ;
            forward();
            if (ds<=10) 
            {
              backward();
              delay(1000);
              right();
              delay(1000);
              }
              command='F';
} 
  else if(command == 'B')
  { 
    backward();
  }
  else if (command == 'R') 
  {
      right();
      } 
    else if (command == 'L') 
    {
      left();
      }
      else if (command == 'S') 
      { 
        stopp();
        } 
        if(command == 'T')
        {
          if(digitalRead(r) == HIGH && digitalRead(l) == HIGH && digitalRead(c) == LOW)
          {
            Serial.print("WhiteBlackWhite");
            Serial.print("\t");
            forward();
            x=1;
          }
          if(digitalRead(r) == LOW && digitalRead(l) == HIGH && digitalRead(c) == HIGH )
          {
             Serial.print("WhiteWhiteBkack");
             Serial.print("\t");
             right();
             x=2;
          }
          if(digitalRead(r) == HIGH && digitalRead(l) == LOW && digitalRead(c) == HIGH)
          {
              Serial.print("BlackWhiteWhite");
              Serial.print("\t");
              left();
              x=3;
          }
          if(digitalRead(r) == LOW && digitalRead(l) == LOW && digitalRead(c) == LOW)
          {
            Serial.print("BlackBlackBlack");
            Serial.print("\t");
            forward();
          }
          if(digitalRead(r) == HIGH && digitalRead(l) == LOW && digitalRead(c) == LOW)
          {
            Serial.print("BlackBlackWhite");
            Serial.print("\t");
            left();
          }
          if(digitalRead(r) == LOW && digitalRead(l) == HIGH && digitalRead(c) == LOW)
          {
            Serial.print("WhiteBlackBlack");
            Serial.print("\t");
            right();
          }
          if(digitalRead(r) == HIGH && digitalRead(l) == HIGH && digitalRead(c) == HIGH)
          {
            Serial.print("Hi hana i love you <3");
            if(z == 0)
            {
              left();
              z=1;
            }
            if(z % 2 == 0)
            {
              left();
              z++;
            }
            if(z % 2 == 1)
            {
              right();
              z++;
            }
          }
        }
        if(command == '3')
        {
            forward();
            delay(2800);
            stopp();
            acc_right();
            delay(1300);
            stopp();
            forward();
            delay(2800);
            stopp();
            acc_right();
            delay(1300);
            stopp();
            forward();
            delay(2800);
            acc_right();
            delay(1300);
            stopp();
            forward();
            delay(2800);
            stopp();
            //delay(25000);
            //forward();
           // delay(2800);
            //acc_right();
           // delay(450);
            
          //while(1)
          //{
            //if(Serial.available() > 0)
            //{
             // value = Serial.read();
           // }
            //if (isDigit(value))
             //  {
                   //data = data + value;
                 //  com2=data.toInt();
               //}
              // else if(value == ';')
            //     break;
          //}
        }
}
