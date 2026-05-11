#include <Arduino.h>

class Button {

private:

static int _Btnpin;

public:
    Button(int pin) {
        _Btnpin = pin;
        pinMode(_Btnpin, OUTPUT);
    }

    static bool Pressed() {
        if (digitalRead(_Btnpin) == LOW) return true;
        return false;
    }

    static bool Read() {
        bool state = digitalRead(_Btnpin) == LOW;
        if (state) {
            delay(20);
            return (digitalRead(_Btnpin) == LOW);
        }
        return false;
    }

    static bool Held(unsigned long duration) {
        unsigned long startTime = millis();
        while (digitalRead(_Btnpin) == LOW) {
            if (millis() - startTime >= duration) {
                return true;
            }
        }
        return false;
    }

};
