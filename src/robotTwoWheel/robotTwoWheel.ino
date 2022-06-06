#include "constants.h"
#include "Distance.h"
#include "Motors.h"

DistanceDetector detector = DistanceDetector(DS_TRIGGER_PIN, DS_ECHO_PIN);

Motors motors;
const int INITIAL_SPEED = 45;
const int ROTATE_SPEED = 30;
const int MIN_DISTANCE = 20;
int movementSpeed = INITIAL_SPEED;
unsigned long lastLoopTime;

void setup() {
  
  Serial.begin(SERIAL_SPEED);
  while (!Serial);
  
  // distance
  pinMode(DS_TRIGGER_PIN, OUTPUT);
  pinMode(DS_ECHO_PIN, INPUT);

  motors.attach(L_PWM, L_DIR, R_PWM, R_DIR);
  motors.move(movementSpeed);
}

void loop() {

  unsigned long now = millis();
  if (now - lastLoopTime < INTERVAL) {
    return;
  }
  lastLoopTime = now;

  keepGoing();
}

void keepGoing() {
  while (true) {
    long distance = detector.distance();
    if (distance > MIN_DISTANCE) {
      motors.move(movementSpeed);
      break;
    }
    motors.stop();
    motors.randomTurn(1);
    motors.stop();
  }
}
