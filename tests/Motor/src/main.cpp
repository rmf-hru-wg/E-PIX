#include <Arduino.h>
#include <IcsBaseClass.h>
#include <IcsHardSerialClass.h>

#define ICS_BAUDRATE 115200
#define ICS_TIMEOUT 10

#define myEN1 16
#define myTX1 17
#define myRX1 18

IcsHardSerialClass krs1(&Serial1, myEN1, ICS_BAUDRATE, ICS_TIMEOUT, myRX1, myTX1);

void setup() {
    krs1.begin();
}

void loop() {
    krs1.setPos(1,7500);
    delay(1000);
    krs1.setPos(1,5500);
    delay(1000);
    krs1.setPos(1,7500);
    delay(1000);
    krs1.setPos(1,9500);
    delay(1000);
}
