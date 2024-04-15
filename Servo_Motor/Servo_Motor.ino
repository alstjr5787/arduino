const uint8_t SERVO_PIN{12U};
void setup() {
  Serial.begin(115200UL);
  pinMode(SERVO_PIN, OUTPUT);

}

void loop() {
  for(int i = 0; i < 255; i += 5) {
    analogWrite(SERVO_PIN, i);
    delay(100UL);
  }
  delay(1000UL);
  for(int i = 255; i >= 0; i -= 5) {
    analogWrite(SERVO_PIN, i);
    delay(100UL);
  }
  delay(1000UL);
}

