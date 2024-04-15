const uint8_t BUTTON_SW_1 = {31U};
int count = 0;
bool button_ps = false;

enum RGB {
  RED = 8U, 
  GREEN, // 9
  BLUE // 10
};


void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_SW_1, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_SW_1)) {
    delay(10UL);

    if (!button_ps) { 
      button_ps = true; 
      count++; 
      Serial.print(F("BUTTON Counting: "));
      Serial.println(count);
    }
  } else {
    button_ps = false; 
  }

  if (count % 2 == 0) {
    digitalWrite(RED, LOW); 
    digitalWrite(GREEN, LOW); 
    digitalWrite(BLUE, LOW); 
  } else {
    digitalWrite(RED, HIGH); 
    digitalWrite(GREEN, HIGH); 
    digitalWrite(BLUE, HIGH); 
  }

  delay(10UL);
}
