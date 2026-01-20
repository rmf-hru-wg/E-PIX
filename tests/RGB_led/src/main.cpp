#include <Arduino.h>

void setup() {}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    neopixelWrite(RGB_BUILTIN, 0, 255, 0); // green
    delay(1000);
    neopixelWrite(RGB_BUILTIN, 255, 0, 0); // red
    delay(1000);
    neopixelWrite(RGB_BUILTIN, 0, 0, 255); // blue
    delay(1000);
    neopixelWrite(RGB_BUILTIN, 0, 0, 0);   // off
    delay(1000);
}
