#include <LiquidCrystal_I2C.h>
#include "HCSR04.h"
const uint8_t SURVO{13U};

enum PINS {
  TRIGGER = 30U,
  ECHO
};

class UltraSonicDistanceSensor ultra_soic(TRIGGER, ECHO);
class LiquidCrystal_I2C lcd(0x27, 16, 2);
float temperature = {22.05};

void setup() {
  Serial.begin(115200UL);
  lcd.init();
  lcd.home(); 
  lcd.backlight();
  pinMode(SURVO, OUTPUT);
}

void loop() {
  float distance = ultra_soic.measureDistanceCm();
    if (distance > 400.0F or distance < 0.0F) {
      lcd.println(F("Out of ranges"));
    } else {
      lcd.print(F("distance: "));
      lcd.print(String(distance) + String(" cm"));
      lcd.setCursor(0,0);
      delay(500UL);
      lcd.clear();

      if (distance >= 10 || distance <= 1){ 
        for(int i = 255; i >= 0; i -= 5) {
        analogWrite(SURVO, i);
        delay(25UL);
        lcd.setCursor(0,1);
        lcd.print("WELCOME");
        delay(500UL);
        lcd.clear();
      }
    }
    delay(500UL);
  }
}
