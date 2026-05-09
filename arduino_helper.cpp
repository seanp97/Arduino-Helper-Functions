#include <Arduino.h>

const int LED_PIN = 8; 

void On(int PIN) {
    digitalWrite(PIN, HIGH);
}

void Off(int PIN) {
    digitalWrite(PIN, LOW);
}

void Wait(float seconds) {
    delay(seconds * 1000);
}

void Blinky(int PIN, float DELAY_FIRST = 1, float DELAY_SECOND = 1) {
    On(LED_PIN); 
    Wait(DELAY_FIRST);  
    Off(LED_PIN);
    Wait(DELAY_SECOND);  
}

void Out(int PIN) {
    pinMode(PIN, OUTPUT);
}

void In(int PIN) {
    pinMode(PIN, INPUT);
}

void Print(const char* str) {
    Serial.println(str);
}

int Scale(int val, int inMin, int inMax, int outMin, int outMax) {
    return map(val, inMin, inMax, outMin, outMax);
}

void Toggle(int PIN) {
    digitalWrite(PIN, !digitalRead(PIN));
}

void Dim(int PIN, int brightness) {
    if(brightness > 255 || brightness < 0) Print("Between 0 & 255"); 
    analogWrite(PIN, brightness);
}

int Scan(int PIN) {
    return analogRead(PIN);
}

bool Pressed(int PIN) {
    return digitalRead(PIN) == HIGH;
}

int Read(int PIN) {
    return digitalRead(PIN);
}

bool Released(int PIN) {
    return digitalRead(PIN) == LOW;
}

void Pullup(int PIN) {
    pinMode(PIN, INPUT_PULLUP);
}

int RandomInt(int min, int max) {
    return random(min, max);
}

float RandomFloat(float min, float max) {
    return min + ((float)random(0, 10000) / 10000.0) * (max - min);
}

bool Changed(int PIN) {
    static int lastState[20];

    int current = digitalRead(PIN);

    if(current != lastState[PIN]) {
        lastState[PIN] = current;
        return true;
    }

    return false;
}

void SerialBegin(int baud = 9600) {
    Serial.begin(baud);
}

int ScanSmooth(int PIN) {
    long total = 0;
    for(int i = 0; i < 10; i++) {
        total += analogRead(PIN);
        delay(1); 
    }
    return total / 10;
}

float Voltage(int PIN) {
    return analogRead(PIN) * (5.0 / 1023.0);
}

void PrintVal(const char* label, int val) {
    Serial.print(label);
    Serial.print(": ");
    Serial.println(val);
}

bool IsHigh(int PIN) {
    return digitalRead(PIN) == HIGH;
}

bool IsLow(int PIN) {
    return digitalRead(PIN) == LOW;
}

void setup() {
    SerialBegin();
    Out(LED_PIN);
    Off(8);
}

void loop() {
  Blinky(8);
  Print("LED Blinking...");
  Wait(1);
}
