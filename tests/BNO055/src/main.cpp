#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define SDA 5
#define SCL 4

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);  // I2C address 0x28

void setup() {
    Serial.begin(115200);
    delay(1000);

    Wire.begin(SDA, SCL);  // SDA, SCL

    if (!bno.begin()) {
        Serial.println("BNO055 not detected. Check wiring.");
        while (1);
    }

    delay(1000);
    bno.setExtCrystalUse(true);

    Serial.println("BNO055 Initialized");
}

void loop() {
    // オイラー角取得
    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

    // 加速度取得
    imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

    Serial.print("Euler [deg] ");
    Serial.print("Heading: "); Serial.print(euler.x());
    Serial.print("  Roll: ");  Serial.print(euler.z());
    Serial.print("  Pitch: "); Serial.print(euler.y());

    Serial.print(" | Accel [m/s^2] ");
    Serial.print("X: "); Serial.print(accel.x());
    Serial.print("  Y: "); Serial.print(accel.y());
    Serial.print("  Z: "); Serial.print(accel.z());

    Serial.println();

    delay(100);
}
