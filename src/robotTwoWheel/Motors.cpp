#include "Motors.h"

Motors::Motors() {
}

void Motors::attach(int leftPwm, int leftDirection, int rightPwm, int rightDirection) {
  this->leftPwm = leftPwm;
  this->leftDirection = leftDirection;
  this->rightPwm = rightPwm;
  this->rightDirection = rightDirection;
  pinMode(leftDirection, OUTPUT);
  pinMode(rightDirection, OUTPUT);
  pinMode(leftPwm, OUTPUT);
  pinMode(rightPwm, OUTPUT);
}

void Motors::move(int speed) {
  motorRight(speed);
  motorLeft(speed);
}

void Motors::stepBack() {
  this->move(STEP_BACK_SPEED);
  delay(500);
}

void Motors::randomTurn(int turnDirection) {
  motorRight(turnDirection * -30);
  motorLeft(turnDirection * 30);
  delay(random(500, 1000));
}

void Motors::rotateLeft(int speed) {
  motorRight(speed);
  motorLeft(-1 * speed);
}

void Motors::rotateRight(int speed) {
  motorRight(-1 * speed);
  motorLeft(speed);
}

void Motors::motorRight(int speed) {
  motorMove(this->rightDirection, this->rightPwm, 0.99 * speed);
}

void Motors::motorLeft(int speed) {
  motorMove(this->leftDirection, this->leftPwm, speed);
}

void Motors::stop() {
  analogWrite(this->rightPwm, 0);
  analogWrite(this->leftPwm, 0);
}

void Motors::motorMove(int motorDir, int motorPwm, int speed) {
  
  int direction;
  if (speed > 0) {
    direction = 0;
  } else {
    direction = 1;
    speed = abs(speed);
  }

  speed = min(speed, 100);
  
  int speedRemaped = map(speed, 0, 100, 0, PWM_MAX);
  
  digitalWrite(motorDir, direction);
  analogWrite(motorPwm, speedRemaped);
}
