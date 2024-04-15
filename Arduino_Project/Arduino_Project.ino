#include "DHT.h"
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>
#include <LiquidCrystal_I2C.h>

class MFRC522DriverPinSimple sda_pin(53);
class MFRC522DriverSPI driver = sda_pin;
class MFRC522 mfrc522 {driver};
class LiquidCrystal_I2C lcd(0x27, 16, 2);

const uint8_t TEMP_HUMID_PIN = A0;
const uint8_t BUTTON_SW = 2;
const uint8_t BUTTON_SW_2 = 3;
const uint8_t BUZZ_PIN = 11;
const uint8_t SERVO_PIN = 12;
const uint8_t pins[] = {20, 21, 22, 23, 24, 25, 26, 27};
const uint8_t numbers[] = {
  ~0b11111100,
  ~0b01100000, 
  ~0b11011010, 
  ~0b11110010,
  ~0b01100110, 
  ~0b10110110, 
};
const String MASTER_CARD_UID{String("F4DC1F2A")};

enum RGBLED {
  RED = 8,
  GREEN, // 9
  BLUE // 10
};
DHT dht(TEMP_HUMID_PIN, DHT11);
volatile uint16_t Button_counting = {0U};
volatile bool cardcheck = true;
int failcount = 0;
float SetTemperature = 0.0; 

void inter_btn() {
  ++Button_counting;
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  Serial.println(F("Interrupt Btn Push"));
  delay(1000UL);
  cardcheck = true; // 카드인증 전 상태로
}

void segmentfail(int attempts) {
  for (int i = 0; i < 5; i++) {
    int digit = (attempts / int(pow(10, 4 - i))) % 10;
    byte segments = numbers[digit];
    for (int j = 0; j < 8; j++) {
      digitalWrite(pins[j], bitRead(segments, j));
    }
  }
}

void setup() {
  Serial.begin(115200UL);
  mfrc522.PCD_Init();
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello Arduino");
  lcd.setCursor(0,1);
  lcd.print("Hello Kim");

  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON_SW, INPUT);
  pinMode(BUTTON_SW_2, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);

  dht.begin();
  attachInterrupt(digitalPinToInterrupt(BUTTON_SW), inter_btn, RISING);
}

void loop() {
  if (cardcheck) {
    while (failcount < 5) {
      if (!mfrc522.PICC_IsNewCardPresent()) continue;
      if (!mfrc522.PICC_ReadCardSerial()) continue;
      String tagID = "";
      for (uint8_t i = 0; i < 4; i++) {
        tagID += String(mfrc522.uid.uidByte[i], HEX);
      }
      tagID.toUpperCase();
      mfrc522.PICC_HaltA();
      if (tagID == MASTER_CARD_UID) {
        Serial.println(F("Success Success"));
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH);
        for(int i = 0; i < 255; i += 5) {
          analogWrite(SERVO_PIN, i); 
          delay(100UL);
        }
        for(int i = 255; i >= 0; i -= 5) {
        analogWrite(SERVO_PIN, i);
        delay(100UL);
      }
        delay(2000);
        cardcheck = false;
        
        Serial.println("Input temp: ");
        while (!Serial.available());
        SetTemperature = Serial.parseFloat(); 

        return;
      } else {
        Serial.println(F("Fail Fail"));
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Fail");
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, LOW);
        digitalWrite(BUZZ_PIN, HIGH);
        delay(500);
        digitalWrite(BUZZ_PIN, LOW);
        delay(1500);
        failcount++;
        segmentfail(failcount);
      }
    }
    unsigned long startMillis = millis();
    while (millis() - startMillis < 5000) {
      digitalWrite(BUZZ_PIN, HIGH);
      digitalWrite(RED, HIGH);
      delay(300);
      digitalWrite(RED, LOW);
      delay(300);
      digitalWrite(BUZZ_PIN, LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Error");
    }
  } else {
    float temperature = dht.readTemperature();
    digitalWrite(GREEN, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temper: ");
    lcd.print(dht.readTemperature());
    lcd.print(" C");
    Serial.print(F("Temper: "));
    Serial.println(String(temperature) + String(" C"));
    float humidity = dht.readHumidity();
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(dht.readHumidity());
    lcd.print("%");
    Serial.print(F("Humidity: "));
    Serial.println(String(humidity) + String(" %"));
    delay(2000);

    if (temperature < SetTemperature) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low temp!");
      Serial.println("Low temp!");
    }

    if (temperature <= 23.0) {
      digitalWrite(BLUE, HIGH);
      delay(2000UL);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
    } else if (temperature > 23.0 && temperature <= 28.0) {
      digitalWrite(GREEN, HIGH);
      delay(2000UL);
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);
    } else {
      digitalWrite(RED, HIGH);
      delay(2000UL);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
    }
  }
}
