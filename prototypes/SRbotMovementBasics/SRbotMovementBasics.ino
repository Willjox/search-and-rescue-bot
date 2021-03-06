#include <Servo.h>
// Motorshield pins
#define LEFT 111
#define RIGHT 222
#define FORWARD 120
#define REVERSE 60
Servo leftServo;
Servo rightServo;
const int startButton = 13;


void setup() {
 Serial.begin(9600);
 Serial.println("starting setup");
 leftServo.attach(7);
 rightServo.attach(8);
 pinMode(startButton, INPUT);
 Serial.println("Finished setup, waiting for start");
 //while(digitalRead(startButton) == LOW) {
   //delay(10);
 //}
 Serial.println("start detected, continuing");
}

void servoOutput(int leftSpeed, int rightSpeed) {
  leftServo.write(180-leftSpeed);
  rightServo.write(rightSpeed);
}

void adjustSpeed(int left, int right) {
  left = constrain(left + leftServo.read() , 5 , 175);
  right = constrain(right + rightServo.read() , 5 , 175);
  servoOutput(left,right);
}

void rotate(int direction) {
  if (direction == LEFT) {
    Serial.println("Rotating to the LEFT");
    servoOutput(REVERSE,FORWARD );
  } else if (direction == RIGHT) {
    Serial.println("Rotating to the RIGHT");
    servoOutput(FORWARD,REVERSE);
  } else {
    Serial.println("ERROR Rotating");
  }
}

void straight(int direction) {
  if (direction == FORWARD) {
    Serial.println("Going forward");
    servoOutput(FORWARD,FORWARD);
  } else if (direction == REVERSE) {
    Serial.println("Reversing");
    servoOutput(REVERSE,REVERSE);
  }  else {
    Serial.println("ERROR going straight");
  }
}

void loop() {
  Serial.println("starting loop");
  Serial.println("starting BackAndForth");
  straight(FORWARD);
  delay(2000);
  straight(REVERSE);
  delay(2000);
  Serial.println("starting Rotate");
  rotate(LEFT);
  delay(3000);
  rotate(RIGHT);
  delay(3000);
}
