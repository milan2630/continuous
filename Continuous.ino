#include <Servo.h>

Servo myservo;
float flowRate;//variable to be changed for setting flow rate
float power;//stores power value resulting in set flow rate
#define PUMPPIN 9    //peristaltic pump control pin, connect to arduino digital pin 9

void setup() 
{
  myservo.attach(PUMPPIN);//initializes pump 9 as the pin controlling the pump
  flowRate = .5;//user sets flow rate
  power = (flowRate + .7999) / .008018;//power is set to the appropriate value that the pump flows at the desired flowrate
}

void loop() 
{
    myservo.write(int(power));   //set motor to speed
}
