#include "Servo.h"

#define BUTTON_PIN 2
#define WHEEL_SERVO_PIN 12
#define TURNER_SERVO_PIN 13


int buttonState;
Servo wheelServo;
Servo turnerServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);

  wheelServo.attach(WHEEL_SERVO_PIN);
  turnerServo.attach(TURNER_SERVO_PIN);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == HIGH){

    wheelServo.attach(WHEEL_SERVO_PIN);
    wheelServo.write(70);
    delay(500);
    wheelServo.write(90); // have to detach because it does not completely halt at 90
    wheelServo.detach();

    delay(1000);

    turnerServo.write(0);
    delay(1000);
    turnerServo.write(180);   
    
 
  }
}
