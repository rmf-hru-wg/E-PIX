# Control Board 1

## スペック

- ESP32C3@160MHz WiFi+BT5(BT Classicは非対応)
- ICS変換 × 2
- ADC × 2
- BTS6142D 保護回路+ロードスイッチ
- 9DoF IMU AE-BNO055を裏面に搭載可能

## 設計指針

- できるだけ安く　1000円以下
- できるだけ小さく　40mm×40mm
- ICS変換基板の小型化　10mm×8mm
- 無線を使った遠隔操作　WiFi 2.4GHz IEEE 802.11b/g/n

## 今後の方針

- CPUをラズパイなどにして計算性能やカメラの搭載
- ROS2と繋げる