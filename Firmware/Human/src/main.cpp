//#include <WiFi.h>
#include <IcsHardSerialClass.h>
#include <pin.h>

#define BAUDRATE 115200
#define TIMEOUT 1000

//HardwareSerial Serial(0);

IcsHardSerialClass krs(&Serial, EN1, BAUDRATE, TIMEOUT, 20, 21);
//IcsHardSerialClass krs(&Serial, EN2, BAUDRATE, TIMEOUT, RX2, TX2);

void setup() {
    pinMode(EN2, OUTPUT);
    pinMode(EN2, HIGH);
    Serial1.begin(115200, SERIAL_8E1, RX2, BNO055RST);
    pinMode(BNO055RST, OUTPUT);
    //krs.begin();
}
void loop() {
    Serial1.println("ok");
    delay(1000);
    /*
    krs.setPos(0,7500); //位置指令　ID:0サーボを7500へ 中央
    delay(500); //0.5秒待つ
    krs.setPos(0,9500); //位置指令　ID:0サーボを9500へ 右
    delay(500); //0.5秒待つ
    krs.setPos(0,7500); //位置指令　ID:0サーボを7500へ 中央
    delay(500); //0.5秒待つ
    krs.setPos(0,5500); //位置指令　ID:0サーボを5500へ 左
    delay(500);
    */
}