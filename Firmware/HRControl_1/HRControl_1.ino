// #include <WiFi.h>
#include "IcsHardSerialClass.h"
#include "pin.h"

#define BAUDRATE 115200
#define TIMEOUT 1000

IcsHardSerialClass krs1(&Serial0, EN1, BAUDRATE, TIMEOUT, RX1, TX1);
IcsHardSerialClass krs2(&Serial1, EN2, BAUDRATE, TIMEOUT, RX2, TX2);

void setup() {
  Serial.begin();
  krs1.begin();
  krs2.begin();
}
void loop() {
    //Serial.println("ok");
    //delay(100);
    for(int i=4000;i<11000;i+=100){
      int now1 = krs1.setPos(0, i);
      int now2 = krs2.setPos(0, i);
      Serial.printf("%d %d\r\n", now1, now2);
      delay(10);
    }
    krs1.setPos(0, 4000);
    krs2.setPos(0, 4000);
    delay(1000);
    /*
    //位置指令　ID:0サーボを7500へ 中央
    delay(500); //0.5秒待つ
    krs.setPos(0,9500); //位置指令　ID:0サーボを9500へ 右
    delay(500); //0.5秒待つ
    krs.setPos(0,7500); //位置指令　ID:0サーボを7500へ 中央
    delay(500); //0.5秒待つ
    krs.setPos(0,5500); //位置指令　ID:0サーボを5500へ 左
    delay(500);
    */
}