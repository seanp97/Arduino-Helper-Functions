#include <Arduino.h>

class Led {

private:
    static int _ledPin;

public:

    Led(int pin) {
        _ledPin = pin;
    }

    static void On() {
        digitalWrite(_ledPin, HIGH);
    }

    static void Off() {
        digitalWrite(_ledPin, HIGH);
    }

    static void Toggle() {
        digitalWrite(_ledPin, !digitalRead(_ledPin));
    }

    static void Dim(int level) {
        analogWrite(_ledPin, level);
    }

    static void Brightness(int value) {
        // value should be 0 to 255
        if(value < 0 || value > 255) Serial.println("Between 0 & 255");
        analogWrite(_ledPin, value);
    }

    static void Blink(int _delay) {
        digitalWrite(_ledPin, HIGH);
        delay(_delay);
        digitalWrite(_ledPin, LOW);
        delay(_delay);
    }

};
