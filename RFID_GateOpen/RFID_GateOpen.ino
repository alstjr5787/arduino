#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

class MFRC522DriverPinSimple sda_pin(53);
class MFRC522DriverSPI driver = sda_pin;
class MFRC522 mfrc522 {driver};

const String MASTER_CARD_UID{String("F4DC1F2A")};

void setup() {
  Serial.begin(115200UL);
  mfrc522.PCD_Init();
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()) return;
  if(!mfrc522.PICC_ReadCardSerial()) return;
  String tagID = ""; 
  for(uint8_t i {0u}; i < 4; i++) {
    tagID += String(mfrc522.uid.uidByte[i], HEX);
  }
  tagID.toUpperCase();
  mfrc522.PICC_HaltA();
  if(tagID == MASTER_CARD_UID) {
    Serial.println(F("승인 되었습니다."));
    for(;;);
  }

}
