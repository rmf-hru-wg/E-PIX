#include <Arduino.h>
#include <WiFi.h>

const char ssid[] = "E-PIX_WiFi";
const char pass[] = "E-PIX_WiFi";
const IPAddress ip(192, 168, 11, 3);
const IPAddress subnet(255, 255, 255, 0);
WiFiServer server(80);

void setup() {
    Serial.begin(115200);
    digitalWrite(LED_BUILTIN, LOW);

    WiFi.softAP(ssid, pass);
    delay(100);
    WiFi.softAPConfig(ip, ip, subnet);
    IPAddress myIP = WiFi.softAPIP();
    server.begin();
    Serial.print("SSID = ");
    Serial.println(ssid);
    Serial.print("IP address = ");
    Serial.println(myIP);
    Serial.println("server started");
    neopixelWrite(RGB_BUILTIN, 155, 0, 0);
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        Serial.println("new client");
        neopixelWrite(RGB_BUILTIN, 0, 155, 0);
        String inMsg = "";
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                Serial.write(c);
                if (c == '\n') {
                    if (inMsg.length() == 0) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();
                        client.println("<!DOCTYPE HTML>");
                        client.println("<html><body><h1>Hello from ESP32</h1></body></html>");
                        client.println();
                        break;
                    } else {
                        inMsg = "";
                    }

                }
            }
        }

        delay(5000);
        client.stop();
        Serial.println("client disconnected");
        neopixelWrite(RGB_BUILTIN, 155, 0, 0);
    }
}
