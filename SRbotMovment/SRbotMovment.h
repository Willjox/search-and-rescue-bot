#ifndef SRbotMovment_h
#define SRbotMovment_h

#include "Arduino.h"
#include "Servo.h"
#include "SRbotSensors.h"

class SRbotMovment
{
  public:
  SRbotMovment();
  int followLine();
  void turn(int direction);
  void rotate();
  void stop();
  void start();
  void freeTurn();
  void straight();
  void forceTurn();
  int followLineToEndOfLine();

  private:
    const int servoPins[2] = {9,10};
    const float kp = 0.008;
    const float kd = 0.001;
    const float ki = 0.0003;

    SRbotSensors *sensors;
    Servo leftServo;
    Servo rightServo;

    boolean stopped;
    boolean forcedTurn;

    float integrator;
    int lastError;
    int leftBaseSpeed;
    int rightBaseSpeed;

    void adjustSpeed(int left, int right);
    void servoOutput(int left , int right);
    void control(int position);
    void endOfLine();
};

#endif
