#include "ultrasonic_functions.h"

void initUltrasonicSensor() {
  // Initialize ultrasonic sensor pins
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
}

void checkForNearbyUsers() {
  // Send a trigger signal
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);

  // Calculate the distance to the nearest object
  float distance = duration * 0.034 / 2;

  // If the distance is less than 20 cm, turn on the OLED screen
  if (distance < 20) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Please tap your");
    display.println("access card");
    display.display();
  }
}
