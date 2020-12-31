#include <Arduino.h>

#define RIGHT_PIN 14
#define LEFT_PIN 12
int outputs[] = { 16, 5, 4, 0 };

void
setup()
{
    // Serial port for debugging purposes
    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(OPEN_PIN, INPUT);
    pinMode(CLOSED_PIN, INPUT);
    for (int i = 0; i < 4; i++) {
        pinMode(outputs[i], OUTPUT);
    }
}

unsigned int counter = 0;

void loop()
{
    unsigned int right = digitalRead(OPEN_PIN);
    unsigned int left = digitalRead(CLOSED_PIN);
    counter = counter + right - left;
    unsigned int state = counter % 4;
    // Serial.printf("%d <-> %d | %d (%d)\n", right, left, counter, state);
    digitalWrite(LED_BUILTIN, right + left > 0 ? 0 : 1);
    for (unsigned int i = 0; i < 4; i++) {
        digitalWrite(outputs[i], i == state ? 1 : 0);
    }
    delay(2);
}
