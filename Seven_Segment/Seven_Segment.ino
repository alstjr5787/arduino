// const uint8_t pins[] = {27, 26, 25, 24, 23, 22, 21, 20};
const uint8_t pins[] = {20, 21, 22, 23, 24, 25, 26, 27};
const uint8_t numbers[] = {
  ~0b11111100, // 0
  ~0b01100000, // 1
  ~0b11011010, // 2
  ~0b11110010, // 3
  ~0b01100110, // 4
  ~0b10110110, // 5
  ~0b10111110, // 6
  ~0b11100000, // 7
  ~0b11111110, // 8
  ~0b11100110  // 9
};
enum PINS{
  BUZZ = 30U,
  BUTTON_SW_1,
  BUTTON_SW_2
};
bool alarm_on_state{false};
bool alarm_off_state{false};
void setup() {

  Serial.begin(115200);
  for (auto pin : pins) {
    pinMode(BUTTON_SW_1, INPUT);
    pinMode(BUTTON_SW_2, INPUT);
    pinMode(BUZZ, OUTPUT);
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for(auto number : numbers)
  {
    alarm_on_state = digitalRead(BUTTON_SW_1);
    alarm_off_state = digitalRead(BUTTON_SW_2);

    Serial.print("Alarm On: ");
    Serial.println(alarm_on_state);
    Serial.print("Alarm Off: ");
    Serial.println(alarm_off_state);
    for(uint8_t digit{0u}; digit < 8; digit++) 
    {
      if(bitRead(number, digit)) {
        digitalWrite(pins[digit], HIGH);
      }
      else
      {
        digitalWrite(pins[digit], LOW);
      }
    }
    delay(1000UL);
  }
  if(alarm_on_state){
    digitalWrite(BUZZ, HIGH);
    delay(500UL);
    }
  if(alarm_off_state) {
    digitalWrite(BUZZ, LOW);
    delay(1000UL); 
  }
}
