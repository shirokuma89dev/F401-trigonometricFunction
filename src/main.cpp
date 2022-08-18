#include <Arduino.h>

#define HALF_PI 1.570 / 2

unsigned long startTime;
unsigned long sinDuration;
unsigned long atanDuration;
double data;

void calcSin(void) {
    for (double i = 0; i <= HALF_PI; i += 0.001) {
        data = sin(i);
    }
}

void calcAtan(void) {
    for (double i = 0; i <= 60.0; i += 0.05) {
        data = atan(i);
    }
}

void setup() {
    Serial.begin(9600);

    printf("Press any key to start...\n");
    while (!Serial.available()) {
    }

    startTime = micros();
    for (int i = 0; i < 1000; i++) {
        calcSin();
    }
    sinDuration = micros() - startTime;

    startTime = micros();
    for (int i = 0; i < 1000; i++) {
        calcSin();
    }
    atanDuration = micros() - startTime;

    printf("sin(x): %luE-6[s]\n", sinDuration);
    printf("arcsin(x): %luE-6[s]\n", atanDuration);
}

void loop() {}