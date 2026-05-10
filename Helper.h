#ifndef HELPER_H
#define HELPER_H

#include <Arduino.h>

// Basic Digital I/O
void On(int PIN);
void Off(int PIN);
void Output(int PIN);
void Input(int PIN);
void Pullup(int PIN);
void Write(int PIN, int STATE);
void Toggle(int PIN);
int Read(int PIN);
void Pin(int PIN, int TYPE);

// Analog & PWM
void Dim(int PIN, int brightness);
int Scan(int PIN);
int ScanSmooth(int PIN);
float Voltage(int PIN);
int Scale(int val, int inMin, int inMax, int outMin, int outMax);

// Timing & Sequencing
void Wait(float seconds);
void Blinky(int PIN, float DELAY_FIRST = 1, float DELAY_SECOND = 1);

// Logic & State
bool Pressed(int PIN);
bool Released(int PIN);
bool Changed(int PIN);
bool IsHigh(int PIN);
bool IsLow(int PIN);
bool WasPressed(int PIN);

// Communication
void SerialBegin(int baud = 9600);
void Print(const char* str);
void PrintVal(const char* label, float val);

// Randomization
int RandomInt(int min, int max);
float RandomFloat(float min, float max);

#endif
