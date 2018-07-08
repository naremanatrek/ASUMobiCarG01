#include <TimerOne.h>
// constants to interrupt pins:
const int motor1 = 2;
const int motor2 = 3;
volatile int counter1 = 0; //no of counts per second
volatile int counter2 = 0;
float slots = 20.00;
const float wheel = 66.10;
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 8;
char command;
char mode;
int value;
void forward()
{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA,70);
      analogWrite(ENB,70);
}
void backward()
{
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA,70);
      analogWrite(ENB,70);
}
void right()
{
             digitalWrite(IN1, HIGH); 
             digitalWrite(IN2, LOW);
             digitalWrite(IN3, LOW);
             digitalWrite(IN4, HIGH);
             analogWrite(ENA,70);
             analogWrite(ENB,70);
}
void left()
{
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, HIGH);
              digitalWrite(IN3, HIGH);
              digitalWrite(IN4, LOW);
              analogWrite(ENA,70);
              analogWrite(ENB,70);
}
void stopp()
{
              digitalWrite(IN1, LOW);
              digitalWrite(IN2, LOW);
              digitalWrite(IN3, LOW);
              digitalWrite(IN4, LOW);  
}
// ISR
void ISR_counter1()
{
  counter1++;
}
void ISR_counter2()
{
  counter2++;
}
int CMtoSteps(float cm) 
{
  int result;
  float circumference = (wheel * 3.14) / 10; 
  float cm_step = circumference / slots;  
  float f_result = cm / cm_step;  
  result = (int) f_result; 
  return result;  
}
//void ISR_timerone()
//{
//  Timer1.detachInterrupt();
//  Serial.print("motor1 speed is:")
//  float rpm1 = (counter1 / slots) * 60.00;
//  Serial.print(rpm1);
//  Serial.print(" RPM, ");
//  counter1 = 0;
//  Serial.print("motor2 speed is:")
//  float rpm2 = (counter2 / slots) * 60.00;
//  Serial.print(rpm2);
//  Serial.print(" RPM.");
//  counter2 = 0;
//  Timer1.attachInterrupt(ISR_timerone);
//}
void acc_forward(int distance)
{
      counter1 = 0;
      counter2 = 0;
      int dist_to_slots = CMtoSteps(distance);
      while(dist_to_slots >counter1 && dist_to_slots > counter2)
      {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA,60);
      analogWrite(ENB,60);
      }
      else
      {
        stopp();
      }
      counter1 = 0;
      counter2 = 0;
}
void acc_reverse(int distance)
{
      counter1 = 0;
      counter2 = 0;
      int dist_to_slots = CMtoSteps(distance);
      while(dist_to_slots >counter1 && dist_to_slots > counter2)
      {
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA,60);
      analogWrite(ENB,60);
      }
      else
      {
        stopp();
      }
      counter1 = 0;
      counter2 = 0;
}
void acc_rotate(int angle)
{
  counter1 = 0;
  counter2 = 0;
  int no_of_slots = (angle / 18);
  while(counter1 < no_of_slots && counter2 < no_of_slots)
  {
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA,70);
    analogWrite(ENB,70);
  }
  else
  {
    stopp();
  }
  counter1 = 0;
  counter2 = 0;
}
void setup() 
{
  Serial.print(9600);
  pinMode (IN1, OUTPUT); 
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT); 
  pinMode (IN4, OUTPUT); 
  pinMode (ENA, OUTPUT); 
  pinMode (ENB, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(motor1) , ISR_counter1 ,RISING);
  attachInterrupt(digitalPinToInterrupt(motor2) , ISR_counter2 ,RISING);
  //Timer1.attachInterrupt(ISR_timerone);
}

void loop()
{
  if(Serial.available() > 0)
  command = Serial.read();
  if(command == 'Accurate')
  {
    Serial.print("Accurate mode is on");
    mode = Serial.read();
    if(mode == 'F')
    {
      value = Serial.read();
      Serial.print("We are in forward accurate mode our car will move a distance = ");
      Serial.print(value);
      acc_forward(value);
    }
    if(mode == 'B')
    {
      value = Serial.read();
      Serial.print("We are in backward accurate mode our car will move a distance = ");
      Serial.print(value);
      acc_reverse(value);
    }
    if(mode == 'Rotate')
    {
      value = Serial.read();
      Serial.print("We are in rotation accurate mode our car will move a distance = ");
      Serial.print(value);
      acc_rotate(value);
    }
    if(mode == 'Demo')
    {
      Serial.print("let our love and friendships stay beautiful to infinity ");
      acc_forward(200);
      acc_rotater(45);
      acc_forward(283);
      acc_rotatel(45);
      acc_forward(200);
      acc_rotatel(45);
      acc_forward(283);
      stopp();
      delay(25000);
      Serial.print("hi there i am drawig a rectangle, i am smart ;)!");
      acc_forward(200);
      acc_rotater(90);
      acc_forward(200);
      acc_rotater(90);
      acc_forward(200);
      acc_rotatel(90);
      acc_forward(200);
      stopp();
      delay(25000);
    }
  }
}
