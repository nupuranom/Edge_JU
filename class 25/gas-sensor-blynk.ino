#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;  
char ssid[] = "Rafiqul";  
char pass[] = "923800315";

#define GAS_SENSOR_PIN A0  // Analog pin for gas sensor

BlynkTimer timer;

// Function to read gas sensor data and send it to Blynk
void sendGasData() {
    int gasValue = analogRead(GAS_SENSOR_PIN); // Read gas sensor value (0-1023)
    int percentage = map(gasValue, 0, 1023, 0, 100); // Convert to percentage (0-100%)

    Serial.print("Gas Value: ");
    Serial.println(percentage);

    Blynk.virtualWrite(V1, percentage); // Send data to Blynk gauge (V1)
}

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);

    timer.setInterval(1000L, sendGasData); // Send data every 1 second
}

void loop() {
    Blynk.run();
    timer.run();
}
