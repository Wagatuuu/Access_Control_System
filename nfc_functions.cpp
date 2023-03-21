#include "nfc_functions.h"

void initNFC() {
  // Initialize NFC communication
  nfcReader.PCD_Init();
}

String readTagID() {
  // Wait for a tag to be present
  if (!nfcReader.PICC_IsNewCardPresent() || !nfcReader.PICC_ReadCardSerial()) {
    return "";
  }

  // Read the tag ID
  String tagID = "";
  for (byte i = 0; i < nfcReader.uid.size; i++) {
    tagID += String(nfcReader.uid.uidByte[i] < 0x10 ? "0" : "");
    tagID += String(nfcReader.uid.uidByte[i], HEX);
  }

  // Halt the tag and return the tag ID
  nfcReader.PICC_HaltA();
  return tagID;
}
