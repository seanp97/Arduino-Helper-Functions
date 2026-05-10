# Arduino Utility Functions Library

A lightweight helper library for Arduino projects that simplifies common tasks like controlling pins, reading sensors, serial communication, delays, random values, and button handling.

----------

## Features

-   Easy pin control (`On`, `Off`, `Toggle`)
-   Built-in delay helper (`Wait`)
-   Simplified input/output setup
-   LED blinking helper
-   Analog reading and smoothing
-   PWM dimming support
-   Button state helpers
-   Random integer and float generation
-   Voltage calculation helper
-   Serial printing shortcuts

----------

# Installation

1.  Create a new `Helper.h` or `.ino` file.
2.  Paste the code into the file.
3.  Include it in your Arduino project.

```
#include "Helper.h"
```

----------

# Functions

## Pin Control

### `On(int PIN)`

Turns a pin HIGH.

```
On(13);
```

----------

### `Off(int PIN)`

Turns a pin LOW.

```
Off(13);
```

----------

### `Toggle(int PIN)`

Toggles the current state of a pin.

```
Toggle(13);
```

----------

### `Write(int PIN, int STATE)`

Writes HIGH or LOW depending on state.

```
Write(13, true);
```

----------

# Timing

### `Wait(float seconds)`

Pauses execution for a number of seconds.

```
Wait(1.5);
```

----------

# Pin Modes

### `Pin(int PIN, int TYPE)`

Set pin mode manually.

```
Pin(13, OUTPUT);
```

----------

### `Output(int PIN)`

Set a pin as OUTPUT.

```
Output(13);
```

----------

### `Input(int PIN)`

Set a pin as INPUT.

```
Input(2);
```

----------

### `Pullup(int PIN)`

Enable internal pull-up resistor.

```
Pullup(2);
```

----------

# LED Helpers

### `Blinky(int PIN, float DELAY_FIRST = 1, float DELAY_SECOND = 1)`

Blink an LED with custom delays.

```
Blinky(13, 0.5, 0.5);
```

----------

### `Dim(int PIN, int brightness)`

Dim an LED using PWM.

Brightness range: `0 - 255`

```
Dim(9, 128);
```

----------

# Reading Pins

### `Read(int PIN)`

Reads a digital pin state.

```
int state = Read(2);
```

----------

### `Scan(int PIN)`

Reads an analog value.

```
int value = Scan(A0);
```

----------

### `ScanSmooth(int PIN)`

Reads analog input and averages 10 readings.

```
int smooth = ScanSmooth(A0);
```

----------

### `Voltage(int PIN)`

Converts analog reading to voltage.

```
float volts = Voltage(A0);
```

----------

# Button Helpers

### `Pressed(int PIN)`

Returns true if pin is HIGH.

```
if(Pressed(2)) {    Print("Pressed");}
```

----------

### `Released(int PIN)`

Returns true if pin is LOW.

```
if(Released(2)) {    Print("Released");}
```

----------

### `WasPressed(int PIN)`

Detects a button press with debounce support.

```
if(WasPressed(2)) {    Print("Button Clicked");}
```

----------

### `Changed(int PIN)`

Returns true if pin state changed.

```
if(Changed(2)) {    Print("State Changed");}
```

----------

### `IsHigh(int PIN)`

Checks if pin is HIGH.

```
if(IsHigh(2)) {    Print("HIGH");}
```

----------

### `IsLow(int PIN)`

Checks if pin is LOW.

```
if(IsLow(2)) {    Print("LOW");}
```

----------

# Serial Helpers

### `SerialBegin(int baud = 9600)`

Starts serial communication.

```
SerialBegin(115200);
```

----------

### `Print(const char* str)`

Print text to Serial Monitor.

```
Print("Hello World");
```

----------

### `PrintVal(const char* label, float val)`

Print labeled values.

```
PrintVal("Temperature", 23.5);
```

Output:

```
Temperature: 23.5
```

----------

# Utilities

### `Scale(int val, int inMin, int inMax, int outMin, int outMax)`

Maps a value from one range to another.

```
int scaled = Scale(sensor, 0, 1023, 0, 255);
```

----------

### `RandomInt(int min, int max)`

Generate random integer.

```
int num = RandomInt(1, 10);
```

----------

### `RandomFloat(float min, float max)`

Generate random float.

```
float num = RandomFloat(0.0, 1.0);
```

----------

# Example

```
#include <Arduino.h>void setup() {    SerialBegin();    Output(13);    Pullup(2);}void loop() {    Blinky(13, 0.2, 0.2);    if(WasPressed(2)) {        Print("Button Pressed");    }    int sensor = ScanSmooth(A0);    PrintVal("Sensor", sensor);    Wait(1);}
```

----------

# Notes

-   `Dim()` requires a PWM-capable pin.
-   `Voltage()` assumes a 5V Arduino board.
-   `Changed()` stores states in a static array sized for 20 pins.
-   `WasPressed()` currently tracks only one button reliably because of its static variable implementation.

----------

# License

MIT License

Use freely in personal and commercial projects.
