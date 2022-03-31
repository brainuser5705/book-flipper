#include "Servo.h"

#define BUTTON_PIN                 5
#define WHEEL_SERVO_PIN           13
#define TURNER_SERVO_PIN          12

#define LEFT_TILT_SERVO_PIN        2
#define RIGHT_TILT_SERVO_PIN      11

#define POTENT_PIN                A0
#define MIN_POTENT                 0
#define MAX_POTENT              1023

int buttonState;
Servo wheelServo;
Servo turnerServo;

Servo leftTiltServo;
Servo rightTiltServo;

int potentValue;
int servoAngle;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);

  wheelServo.attach(WHEEL_SERVO_PIN);
  turnerServo.attach(TURNER_SERVO_PIN);
  
  leftTiltServo.attach(LEFT_TILT_SERVO_PIN);
  rightTiltServo.attach(RIGHT_TILT_SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  flipPage();
  tilt();
}

void tilt(){
  potentValue = analogRead(A0);
  servoAngle = map(potentValue, MIN_POTENT, MAX_POTENT, 0, 180);
  rightTiltServo.write(servoAngle);
  leftTiltServo.write(servoAngle);
  delay(50);
}

void flipPage(){
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
