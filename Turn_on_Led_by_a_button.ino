
//pin1:iput for button
//pin2:output for lead
int buttonvalue=0;
int button=1;
int led=2;

void setup() {
  pinMode(button,INPUT);
  
  pinMode(led,OUTPUT);

}

void loop() {
  buttonvalue=digitalRead(button);
  if(buttonvalue != 0){
    // if button is pressed then led on
      digitalWrite(led,HIGH);
  }
  else
  {
      //if button is not pressed then lead off
      digitalWrite(led,LOW);
  }
    
}
