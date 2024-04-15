const uint8_t PIR_SENSOR {2U};  
const uint8_t BUZZ {30U};  
const uint8_t RED {10U};  
const uint8_t GREEN {9U};
const uint8_t BLUE {10U};  

bool pir_state {false};
void setup() {
  Serial.begin(115200UL);
  pinMode(PIR_SENSOR, INPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  bool detect = digitalRead(PIR_SENSOR);
  delay(10UL);
  if(detect) {
    if(!pir_state) {
      pir_state = true;
      Serial.println(F("Mother is comming"));
      tone(BUZZ, 10);
      delay(100UL);
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, HIGH);
    }
  } else {
    pir_state = false;
    noTone(BUZZ);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
  delay(100UL);
}
