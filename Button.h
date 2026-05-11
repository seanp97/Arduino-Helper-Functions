#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
private:
    static int _pin;

public:
    // Constructor initializes the pin and sets mode
    Button(int pin) {
        _pin = pin;
        pinMode(_pin, INPUT); 
    }

    static bool Pressed() {
        return (digitalRead(_pin) == LOW);
    }

    static bool Read() {
        if (digitalRead(_pin) == LOW) {
            delay(20);
            return (digitalRead(_pin) == LOW);
        }
        return false;
    }

    static bool Held(unsigned long duration) {
        unsigned long startTime = millis();
        while (digitalRead(_pin) == LOW) {
            if (millis() - startTime >= duration) {
                return true;
            }
        }
        return false;
    }
};

int Button::_pin = 0;

#endif
