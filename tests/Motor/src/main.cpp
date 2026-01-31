#include <Arduino.h>
#include <IcsBaseClass.h>
#include <IcsHardSerialClass.h>

#define ICS_BAUDRATE 115200
#define ICS_TIMEOUT 10

#define myEN1 8
#define myTX1 17
#define myRX1 18

#define myEN2 16
#define myTX2 15
#define myRX2 7

IcsHardSerialClass krs1(&Serial1, myEN1, ICS_BAUDRATE, ICS_TIMEOUT, myRX1, myTX1);
IcsHardSerialClass krs2(&Serial2, myEN2, ICS_BAUDRATE, ICS_TIMEOUT, myRX2, myTX2);

void setup() {
    krs1.begin();
    krs2.begin();
}

void loop() {
    krs2.setPos(1,7500);
    delay(1000);
    krs2.setPos(1,5500);
    delay(1000);
    krs2.setPos(1,7500);
    delay(1000);
    krs2.setPos(1,9500);
    delay(1000);
}
