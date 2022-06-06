#ifndef DISTANCE_H
#define DISTANCE_H

#include <Arduino.h>

class DistanceDetector {
  public:
    int triggerPin;
    int echoPin;
    DistanceDetector(int trigger, int echo);
    long distance();
};

#endif
