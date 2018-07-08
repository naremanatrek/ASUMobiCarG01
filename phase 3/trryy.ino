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
             digitalWrite(IN2, LOW);
             digitalWrite(IN3, HIGH);
             digitalWrite(IN4, LOW);
             analogWrite(ENA,0);
             analogWrite(ENB,100);
}
void setup() {
  // put your setup code here, to run once:
pinMode (IN1, OUTPUT); 
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT); 
  pinMode (IN4, OUTPUT); 
  pinMode (ENA, OUTPUT); 
  pinMode (ENB, OUTPUT); 
}

void loop()
{
             forward();
            delay(2800);
            stopp();
            acc_right();
            delay(1700);
            stopp();
            forward();
            delay(2800);
            stopp();
            acc_right();
            delay(1700);
            stopp();
            forward();
            delay(2800);
            acc_right();
            delay(1700);
            stopp();
            forward();
            delay(2800);
            stopp();

}
