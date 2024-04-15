#include "HCSR04.h"
#include "DHT.h"

const uint8_t BUZZER = {29U};
const uint8_t TEMP_HUMID_PIN = {A0};

enum ULTRASONIC {
  TRIGGER = 30U,
  ECHO
};

class DHT dht (TEMP_HUMID_PIN, 11); // 객체생성
class UltraSonicDistanceSensor ultra_soic(TRIGGER, ECHO);

float temperature = {22.05};
void setup() {
  Serial.begin(115200UL);
  dht.begin();
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  bool dht11_state = dht.read();
  
  if (dht11_state) {
    float temperature = dht.readTemperature();
    Serial.print(F("온도: "));
    Serial.println(String(temperature) + String(" C"));
    Serial1.print(F("온도: "));
    Serial1.println(String(temperature) + String(" C"));
    
    float humidity = dht.readHumidity();
    Serial.print(F("습도: "));
    Serial.println(String(humidity) + String(" %"));
    Serial1.print(F("습도: "));
    Serial1.println(String(humidity) + String(" %"));
    
    float heat = dht.computeHeatIndex(temperature, humidity);
    Serial.print(F("열: "));
    Serial.println(String(heat) + String(" degree"));
    Serial1.print(F("열: "));
    Serial1.println(String(heat) + String(" degree"));

    float distance = ultra_soic.measureDistanceCm();
    if (distance > 400.0F or distance < 0.0F) {
      Serial.println(F("Out of ranges"));
      digitalWrite(BUZZER, HIGH);
    } else {
      Serial.print(F("거리: "));
      Serial.println(String(distance) + String(" cm"));
      digitalWrite(BUZZER, LOW);
  
      if (distance >= 100 || distance <= 0){ 
        tone(BUZZER, 3000, 10000);   
      }
      else if(distance <= 60 && distance >= 51){ 
        tone(BUZZER, 2600, 600);    
      }
      else if(distance <= 50 && distance >= 41){ 
        tone(BUZZER, 2000, 400);    
      }
      else if(distance <= 40 && distance >= 31){ 
        tone(BUZZER, 1500, 200);   
      }
      else if(distance <= 30 && distance >= 21){ 
        tone(BUZZER, 1000, 100);    
      }
      else if(distance <= 20 && distance >= 11){ 
        tone(BUZZER, 500, 50);   
      }
      else if (distance <= 10 && distance >= 1){ 
        tone(BUZZER, 100, 10);    
      }
    }
    delay(500UL);
  }
}




