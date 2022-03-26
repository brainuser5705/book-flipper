#include "Servo.h"

#define BUTTON_PIN 2
#define SERVO_PIN 12

int buttonState;
Servo wheelServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(BUTTON_PIN);
  wheelServo.attach(SERVO_PIN);
  
  if (buttonState == HIGH){
    wheelServo.write(70);
    delay(100);
  }else{
    wheelServo.write(90);
    wheelServo.detach();
  }
}
