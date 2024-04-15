const uint8_t TILT_SW = 22U;
const uint8_t BUZZ_PIN = 24U;
const uint8_t BUTTON_SW = 26U;
const uint8_t LED_PIN[] = {46U, 44U, 42U, 40U, 38U, 36U, 34U, 32U};

static uint8_t earth_quake_count = 0u;

void setup() {
  Serial.begin(115200UL);
  pinMode(BUTTON_SW, INPUT);
  pinMode(TILT_SW, INPUT_PULLUP);
  pinMode(BUZZ_PIN, OUTPUT);

  for (int i = 0; i < 8; ++i) {
    pinMode(LED_PIN[i], OUTPUT);
    digitalWrite(LED_PIN[i], LOW); 
  }
}

void loop() {
  bool button_sw_state = digitalRead(BUTTON_SW);
  bool tilt_sw_state = digitalRead(TILT_SW);

  if (tilt_sw_state == HIGH) {
    ++earth_quake_count;
    if (earth_quake_count > 8) earth_quake_count = 8;
  }

  if (button_sw_state) {
    earth_quake_count = 0;
    Serial.println(F("Initializing..."));
    Serial.println(F("All LEDs off"));
    for (int i = 0; i < 8; ++i) {
      digitalWrite(LED_PIN[i], LOW); 
    }
    return;
  }

  switch (earth_quake_count) {
    case 1:
      Serial.println(F("Richter scale 1"));
      digitalWrite(LED_PIN[0], HIGH); 
      digitalWrite(BUZZ_PIN, HIGH);
      break;
    case 2:
      Serial.println(F("Richter scale 2"));
      digitalWrite(LED_PIN[1], HIGH); 
      break;
    case 3:
      Serial.println(F("Richter scale 3"));
      digitalWrite(LED_PIN[2], HIGH); 
      break;
    case 4:
      Serial.println(F("Richter scale 4"));
      digitalWrite(LED_PIN[3], HIGH); 
      break;
    case 5:
      Serial.println(F("Richter scale 5"));
      digitalWrite(LED_PIN[4], HIGH); 
      break;
    case 6:
      Serial.println(F("Richter scale 6"));
      digitalWrite(LED_PIN[5], HIGH); 
      break;
    case 7:
      Serial.println(F("Richter scale 7"));
      digitalWrite(LED_PIN[6], HIGH); 
      break;
    case 8:
      Serial.println(F("Richter scale 8"));
      digitalWrite(LED_PIN[7], HIGH); 
      break;
    default:
      Serial.println(F("No Earthquake : Richter scale 0"));
      for (int i = 0; i < 8; ++i) {
        digitalWrite(LED_PIN[i], LOW);
        noTone(BUZZ_PIN); 
      }
  }
  
  delay(250UL);
}
