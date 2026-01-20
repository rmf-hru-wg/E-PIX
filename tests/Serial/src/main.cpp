#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, World!");
}

int n = 0;
void loop() {
    Serial.println(n++);
    delay(1000);
}
