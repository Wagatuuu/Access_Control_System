#include "access_control_functions.h"

bool checkAccess(String tagID) {
  // Check if tag ID is in database
  for (int i = 0; i < NUM_AUTHORIZED_USERS; i++) {
    if (tagID.equals(authorizedUsers[i])) {
      return true;
    }
  }
  return false;
}

void grantAccess() {
  // Turn on green LED and buzzer
  digitalWrite(GREEN_LED_PIN, HIGH);
  tone(BUZZER_PIN, 1000, 1000);

  // Wait for 5 seconds
  delay(5000);

  // Turn off green LED and buzzer
  digitalWrite(GREEN_LED_PIN, LOW);
  noTone(BUZZER_PIN);

  // Unlock the solenoid lock
  digitalWrite(SOLENOID_PIN, HIGH);
  delay(500);
  digitalWrite(SOLENOID_PIN, LOW);
}

void denyAccess() {
  // Turn on red LED
  digitalWrite(RED_LED_PIN, HIGH);

  // Wait for 5 seconds
  delay(5000);

  // Turn off red LED
  digitalWrite(RED_LED_PIN, LOW);
}
void printAuthorizedUsers() {
  for (int i = 0; i < NUM_AUTHORIZED_USERS; i++) {
    Serial.println(authorizedUsers[i]);
  }
}
