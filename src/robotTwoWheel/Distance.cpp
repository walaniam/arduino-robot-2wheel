#include "Distance.h"

DistanceDetector::DistanceDetector(int trigger, int echo) {
  triggerPin = trigger;
  echoPin = echo;
}

long DistanceDetector::distance() {

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long time = pulseIn(echoPin, HIGH);
  long distanceCm = time / 58; // sound distance in 1s

  return distanceCm;
}
