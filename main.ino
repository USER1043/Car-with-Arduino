#include <Arduino.h>
#include "motor_control.h"
#include "sensor.h"

// Global instances of structs
MotorPins motorPins;
SensorPins sensorPins;

// Initialize command and variables
char cmd = 'S';
float distance;

void setup()
{
    // Initialize motor pins
    motorPins.leftForward = 12;
    motorPins.leftReverse = 13;
    motorPins.rightForward = 10;
    motorPins.rightReverse = 11;

    // Initialize sensor pins
    sensorPins.trig = 2;
    sensorPins.echo = 3;

    // Set pin modes for motor control
    pinMode(motorPins.leftForward, OUTPUT);
    pinMode(motorPins.leftReverse, OUTPUT);
    pinMode(motorPins.rightForward, OUTPUT);
    pinMode(motorPins.rightReverse, OUTPUT);

    // Initialize sensor pins
    pinMode(sensorPins.trig, OUTPUT);
    pinMode(sensorPins.echo, INPUT);

    Serial.begin(9600); // Initialize serial communication
}

void loop()
{
    if (Serial.available() > 0)
    {
        cmd = Serial.read();
        Serial.println(cmd);

        if (cmd == '1')
        {
            char path1[] = {'F', 'R', 'F', 'R', 'F', 'R', 'F', 'S'};
            for (int i = 0; i < sizeof(path1); i++)
            {
                move(path1[i], &motorPins);
                delay(1000);
            }
        }
        else if (cmd == '2')
        {
            char path2[] = {'F', 'R', 'R', 'F', 'L', 'L', 'F', 'R', 'R', 'S'};
            for (int i = 0; i < sizeof(path2); i++)
            {
                move(path2[i], &motorPins);
                delay(1000);
            }
        }
        else if (cmd == '3')
        {
            char path3[] = {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'S'};
            for (int i = 0; i < sizeof(path3); i++)
            {
                move(path3[i], &motorPins);
                delay(1000);
            }
        }
        else if (cmd == '4')
        {
            char path4[] = {'R', 'R', 'R', 'R', 'L', 'L', 'L', 'L', 'S'};
            for (int i = 0; i < sizeof(path4); i++)
            {
                move(path4[i], &motorPins);
                delay(1000);
            }
        }
        else
        {
            move(cmd, &motorPins);
        }
    }

    distance = readUltrasonicDistance(&sensorPins);

    if (distance <= 25.00)
    {
        move('S', &motorPins);
        delay(500);
    }
    else if (distance > 25.00 && distance <= 50.00)
    {
        move('B', &motorPins);
        delay(500);
    }
    else
    {
        move(cmd, &motorPins);
    }

    delay(100);
}