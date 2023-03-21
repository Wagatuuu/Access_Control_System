#include "nfc_functions.h"
#include "ultrasonic_functions.h"
#include "access_control_functions.h"

void setup() {
  // Initialize NFC reader
  initNFC();

  // Initialize ultrasonic sensor
  initUltrasonicSensor();
  
  // Initialize LED pins
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
}

void loop() {
  // Check for nearby users
  checkForNearbyUsers();

  // Read tag ID
  String tagID = readTagID();

  // Check if tag is authorized
  if (checkAccess(tagID)) {
    // Grant access
    grantAccess();
  }
  else {
    // Deny access
    denyAccess();
  }
}
