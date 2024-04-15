const uint8_t LEDS[] = {3U ,4U ,5U ,6U ,7U ,8U ,9U, 10U};
const uint8_t VR_PIN{A0};

void setup() {
  // put your setup code here, to run once:
  pinMode(VR_PIN, INPUT);
   for(int i = 0; i < 8; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  Serial.begin(115200UL); //시리얼 통신을 통해 화면에 출력
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t vr_value = analogRead(VR_PIN);
  Serial.println(vr_value); //화면에 출력
  uint16_t mapped_value {map(vr_value, 0, 1023, 0, 8)};
  Serial.print(F("Mapping value :"));
  Serial.println(mapped_value);

  for (int i = 0; i < 8; ++i) {
    if (i < mapped_value) {
      digitalWrite(LEDS[i], HIGH);
    } 
    else {
      digitalWrite(LEDS[i], LOW);
    }
  }
   delay(100UL);
}
