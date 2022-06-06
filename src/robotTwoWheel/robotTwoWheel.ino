#include "constants.h"
#include "Distance.h"
#include "Motors.h"

DistanceDetector detector = DistanceDetector(DS_TRIGGER_PIN, DS_ECHO_PIN);

Motors motors;
const int INITIAL_SPEED = 55;
const int ROTATE_SPEED = 30;
const int MIN_DISTANCE = 20;
int movementSpeed = INITIAL_SPEED;
unsigned long lastLoopTime;
int lastTurn = -1;

void setup() {

  Serial.begin(SERIAL_SPEED);
  while (!Serial);

  // distance
  pinMode(DS_TRIGGER_PIN, OUTPUT);
  pinMode(DS_ECHO_PIN, INPUT);

  motors.attach(L_PWM, L_DIR, R_PWM, R_DIR);

  delay(3000);
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
  unsigned int turns = 0;
  while (true) {

    long distance = detector.distance();

    if (distance > MIN_DISTANCE) {
      motors.move(movementSpeed);
      break;
    } else if (distance < 3) {
      motors.stepBack();
      motors.stop();
    } else {
      lastTurn *= -1;
      turns += 1;

      motors.stop();
      if (turns % 10 == 0) {
        motors.stepBack();
        motors.stop();
      }
      motors.randomTurn(lastTurn);
      motors.stop();
    }
  }
}
