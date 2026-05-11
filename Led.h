#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {

private:
    static int _ledPin;

public:
    // Constructor: Sets the pin and initializes it as an OUTPUT
    Led(int pin) {
        _ledPin = pin;
        pinMode(_ledPin, OUTPUT);
    }

    static void On() {
        digitalWrite(_ledPin, HIGH);
    }

    static void Off() {
        digitalWrite(_ledPin, LOW);
    }

    // Flips the current state of the LED
    static void Toggle() {
        digitalWrite(_ledPin, !digitalRead(_ledPin));
    }

    // Sets brightness (0-255) using PWM
    static void Dim(int level) {
        analogWrite(_ledPin, level);
    }

    // Sets brightness with a safety check for range
    static void Brightness(int value) {
        if (value < 0 || value > 255) {
            Serial.println("Error: Value must be between 0 & 255");
            return;
        }
        analogWrite(_ledPin, value);
    }

    static void Blink(int _delay) {
        digitalWrite(_ledPin, HIGH);
        delay(_delay);
        digitalWrite(_ledPin, LOW);
        delay(_delay);
    }

};

// Initialize the static variable (Required for C++ Linker)
int Led::_ledPin = 0;

#endif
