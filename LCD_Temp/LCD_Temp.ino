#include <LiquidCrystal_I2C.h>
#include "DHT.h"

const uint8_t SERVO_PIN{13U};
enum PINS {
  TEMPER_HUMID = A0,
  TRIGGER = 30,
  ECHO
};

class DHT dht(TEMPER_HUMID, 11);
class LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  dht.begin();
  lcd.init();
  lcd.home(); // (0,0)은 커서 (0,0) 가라
  lcd.backlight();
  pinMode(SERVO_PIN, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(dht.read()) {
    float temperature = dht.readTemperature();
    lcd.print(temperature);
    float humidity = dht.readHumidity();
    lcd.setCursor(0,1);
    lcd.print(humidity);
    delay(500UL);
    lcd.clear();
    lcd.setCursor(0,0);
  }
}
