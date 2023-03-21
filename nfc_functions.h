#include <Arduino.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

extern MFRC522 nfcReader;

void initNFC();
String readTagID();
