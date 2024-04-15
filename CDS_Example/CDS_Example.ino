const uint8_t LIGHT_PIN{A1};

void setup() {
  // setup code here, to run once:
  Serial.begin(115200);
  pinMode(LIGHT_PIN, INPUT_PULLUP); // or INPUT_PULLDOWN
}

void loop() {
  // main code here, to run repeatedly:
  uint16_t light_value(analogRead(LIGHT_PIN));
  Serial.print("Light value: ");
  Serial.println(light_value);
  delay(100UL);
}
