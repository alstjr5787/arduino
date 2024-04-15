const uint8_t SW_PIN{40U};
const uint8_t LED_PIN0{38U};
const uint8_t LED_PIN{42U};
const uint8_t BUZZ_PIN{44U};

void setup() {
  Serial.begin(115200UL);
  pinMode(SW_PIN, INPUT_PULLUP); 
  pinMode(LED_PIN0, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  bool sw_state = digitalRead(SW_PIN); 
  if (sw_state) {
    Serial.println(F("Fire"));
    digitalWrite(LED_PIN0, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZ_PIN, HIGH);
  } else {
    Serial.println(F("Quitet"));
    digitalWrite(LED_PIN0, LOW);
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZ_PIN);

  }
}
