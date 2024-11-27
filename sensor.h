#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

// Struct for sensor pins
struct SensorPins {
    int trig;
    int echo;
};

// Function prototype
float readUltrasonicDistance(SensorPins *sensor);

// Function to read distance from the ultrasonic sensor
float readUltrasonicDistance(SensorPins *sensor) {
    float duration, distance;

    pinMode(sensor->trig, OUTPUT);
    digitalWrite(sensor->trig, LOW);
    delayMicroseconds(2);
    digitalWrite(sensor->trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor->trig, LOW);

    pinMode(sensor->echo, INPUT);
    duration = pulseIn(sensor->echo, HIGH);
    distance = duration / 2 * 0.0344;
    return distance;
}

#endif // SENSOR_H
