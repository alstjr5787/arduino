#include "DHT.h"
const uint8_t relayPin = {13U};
const uint8_t FIRE_SENSOR = {3U};
const uint8_t TEMP_HUMID_PIN = {A0};
volatile uint16_t Button_counting = {0U};
class DHT dht (TEMP_HUMID_PIN, 11); // 객체생성
void setup() {
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  dht.begin();
  Serial1.println("블루투스 레디");
  attachInterrupt(digitalPinToInterrupt(FIRE_SENSOR), call911, RISING);
  pinMode(relayPin, OUTPUT);
}

void call911() {
  ++Button_counting;
  digitalWrite(relayPin, LOW);
  analogWrite(TEMP_HUMID_PIN, LOW);
  for(int i = 0; i < 3; i++){
  Serial.println(F("Fire!! Calling 119"));
  Serial1.println(F("Fire!! Calling 119"));
  }
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

    if (temperature >= 24.0) {
      digitalWrite(relayPin, HIGH); 
    } else if (temperature <= 24.0) {
      digitalWrite(relayPin, LOW); 
    }
  }
  delay(1000UL);
}
