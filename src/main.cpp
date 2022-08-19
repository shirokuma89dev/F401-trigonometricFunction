#include <Arduino.h>

#define HALF_PI 1.570

unsigned long startTime;
unsigned long sinDuration;
unsigned long atanDuration;
double data;

void calcSin(void) {
    for (double i = 0; i <= HALF_PI; i += 0.05) {
        data = i + (i * i * i) * (i * i - 20) * 0.0083;
    }
}

void calcAtan(void) {
    for (double i = 0; i <= 60.0; i += 0.05) {
        data = atan(i);//諦め
    }
}

void setup() {
    Serial.begin(9600);

    printf("Press any key to start...\n");
    while (!Serial.available()) {
    }

    startTime = micros();
    for (int i = 0; i < 1; i++) {
        calcSin();
    }
    sinDuration = micros() - startTime;

    startTime = micros();
    for (int i = 0; i < 1000; i++) {
        calcAtan();
    }
    atanDuration = micros() - startTime;

    printf("sin(x): %lu*10^-6[s]\n", sinDuration);
    printf("arctan(x): %lu*10^-6[s]\n", atanDuration);
}

void loop() {}