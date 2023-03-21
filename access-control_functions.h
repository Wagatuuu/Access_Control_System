#include <Arduino.h>

#define NUM_AUTHORIZED_USERS 3
#define SOLENOID_PIN 3
#define RED_LED_PIN 4
#define GREEN_LED_PIN 5
#define BUZZER_PIN 6

extern String authorizedUsers[NUM_AUTHORIZED_USERS];

bool checkAccess(String tagID);
void grantAccess();
void denyAccess();
