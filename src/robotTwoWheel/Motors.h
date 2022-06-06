#ifndef Motors_h
#define Motors_h

#include <Arduino.h>

// motor max voltage
// 6 batteries
// const int PWM_MAX = 165 // Max voltage for motor on 1,5V
//const int PWM_MAX = 172; // Max voltage for motor on chargeable 1,2V

// 5 batteries
const int PWM_MAX = 145;

const int L_PWM = 5;
const int L_DIR = 4;
const int R_PWM = 6;
const int R_DIR = 9;
const int STEP_BACK_SPEED = -40;

class Motors {
  public:
    Motors();
    void attach(int leftPwm, int leftDirection, int rightPwm, int rightDirection);
    void move(int speed);
    void stepBack();
    void randomTurn(int turnDirection);
    void rotateLeft(int speed);
    void rotateRight(int speed);
    void stop();
  private:
    int leftPwm;
    int leftDirection;
    int rightPwm;
    int rightDirection;
    void motorMove(int motorDir, int motorPwm, int speed);
    void motorRight(int speed);
    void motorLeft(int speed);
};

#endif
