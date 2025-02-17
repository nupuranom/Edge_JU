#include <ESP32Servo.h> // Include the ESP32Servo library

Servo myServo;          // Create a Servo object
// const int servoPin = 18; // Connect your servo signal pin to GPIO 18 (changeable)

void setup() {
  Serial.begin(9600);
  myServo.attach(5); // Attach the servo to the specified pin
  myServo.write(0);         // Set initial position to 0 degrees
  delay(1000);              // Allow servo to reach the position
}

void loop() {
  // Move the servo to 90 degrees
  myServo.write(90);
  Serial.println("Move the motor at 90 degree: ");
  delay(1000); // Wait for 1 second

  // Move the servo back to 0 degrees
  myServo.write(0);
  Serial.println("Move the motor at 0 degree: ");
  delay(1000); // Wait for 1 second
}
