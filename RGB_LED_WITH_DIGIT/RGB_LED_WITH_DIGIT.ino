enum RGB {
  RED = 8U, 
  GREEN, // 9
  BLUE // 10
};

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(115200UL);
}

void loop() {
  while(Serial.available())
  {
    uint16_t red_value = {Serial.parseInt()};
    uint16_t green_value = {Serial.parseInt()};
    uint16_t blue_value = {Serial.parseInt()};
    if(Serial.read() == '\n'); {
    analogWrite(RED, red_value);
    analogWrite(GREEN, green_value);
    analogWrite(BLUE, blue_value);
    }
  }

}
