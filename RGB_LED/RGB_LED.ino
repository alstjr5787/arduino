const uint8_t VR_PIN {A0};  
enum RGBLED {
  RED = 8U,
  GREEN, // 9
  BLUE // 10
};
void setup() {
  Serial.begin(115200UL);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(VR_PIN, INPUT);
}

void loop() {
  uint8_t RGB = analogRead(VR_PIN) / 4;
  analogWrite(RED, RGB);
  analogWrite(GREEN, RGB);
  analogWrite(BLUE, RGB);

}
