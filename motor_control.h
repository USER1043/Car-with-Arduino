#ifndef MOTOR_CONTROL_H // Check if MOTOR_CONTROL_H is not defined
#define MOTOR_CONTROL_H // Define MOTOR_CONTROL_H

#include <Arduino.h> // Include Arduino library for pinMode, digitalWrite, etc.

// Struct for motor pins
struct MotorPins {
    int leftForward : 10;
    int leftReverse : 10;
    int rightForward : 10;
    int rightReverse : 10;
};

// Function prototype
void move(char direction, MotorPins *motor);

// Function to control motor based on direction
void move(char direction, MotorPins *motor) {
    if (direction == 'F') {
        digitalWrite(motor->leftReverse, LOW);
        digitalWrite(motor->leftForward, HIGH);
        digitalWrite(motor->rightReverse, LOW);
        digitalWrite(motor->rightForward, HIGH);
    } else if (direction == 'B') {
        digitalWrite(motor->leftReverse, HIGH);
        digitalWrite(motor->leftForward, LOW);
        digitalWrite(motor->rightReverse, HIGH);
        digitalWrite(motor->rightForward, LOW);
    } else if (direction == 'R') {
        digitalWrite(motor->leftReverse, LOW);
        digitalWrite(motor->leftForward, LOW);
        digitalWrite(motor->rightReverse, LOW);
        digitalWrite(motor->rightForward, HIGH);
    } else if (direction == 'L') {
        digitalWrite(motor->leftReverse, LOW);
        digitalWrite(motor->leftForward, HIGH);
        digitalWrite(motor->rightReverse, LOW);
        digitalWrite(motor->rightForward, LOW);
    } else if (direction == 'S') {
        digitalWrite(motor->leftReverse, LOW);
        digitalWrite(motor->leftForward, LOW);
        digitalWrite(motor->rightReverse, LOW);
        digitalWrite(motor->rightForward, LOW);
    }
}

#endif // End of MOTOR_CONTROL_H
