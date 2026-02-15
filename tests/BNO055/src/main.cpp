#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define SDA 5
#define SCL 4

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

imu::Quaternion q_ref;
bool ref_set = false;
unsigned long start_time;

void setup() {

    neopixelWrite(RGB_BUILTIN, 255, 0, 0);  // Red

    Serial.begin(115200);
    Wire.begin(SDA, SCL);

    if (!bno.begin()) {
        Serial.println("BNO055 not detected.");
        while (1);
    }

    delay(1000);
    bno.setExtCrystalUse(true);

    start_time = millis();

    Serial.println("Initialized");
    neopixelWrite(RGB_BUILTIN, 0, 255, 0);  // Green
}

void loop() {

    // --- 1秒後に基準姿勢取得 ---
    if (!ref_set && millis() - start_time > 1000) {
        q_ref = bno.getQuat();
        q_ref.normalize();
        ref_set = true;

        Serial.println("Reference captured");
        neopixelWrite(RGB_BUILTIN, 0, 0, 255);  // Blue
    }

    if (!ref_set) return;

    // --- 現在姿勢 ---
    imu::Quaternion q_now = bno.getQuat();
    q_now.normalize();

    // --- 相対姿勢（body → reference）---
    imu::Quaternion q_rel = q_ref.conjugate() * q_now;
    q_rel.normalize();

    // --- 相対Euler角（rad）---
    imu::Vector<3> euler = q_rel.toEuler();

    // --- 重力除去済み加速度（body座標系）---
    imu::Vector<3> accel_body =
        bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);

    // --- 基準座標系へ回転変換 ---
    // q_rel は body → reference
    imu::Vector<3> accel_ref =
        q_rel.rotateVector(accel_body);

    // --- 出力 ---
    Serial.print("Relative Angle [rad] ");
    Serial.print("Roll: ");  Serial.print(euler.x());
    Serial.print(" Pitch: "); Serial.print(euler.y());
    Serial.print(" Yaw: ");   Serial.print(euler.z());

    Serial.print(" | Linear Accel (reference frame) [m/s^2] ");
    Serial.print("X: "); Serial.print(accel_ref.x());
    Serial.print(" Y: "); Serial.print(accel_ref.y());
    Serial.print(" Z: "); Serial.print(accel_ref.z());

    Serial.println();

    delay(50);
}
