enum PINS {
  JOYSTICK = A1,
  SERVO_MOTOR = 13U
};
void setup() {

  Serial.begin(115200UL);
  pinMode(JOYSTICK, INPUT);
  pinMode(SERVO_MOTOR, OUTPUT);
}

void loop() {

  uint16_t x_value {analogRead(JOYSTICK)};
  Serial.print(F("X Value: "));
  Serial.println(x_value);
  uint16_t mapped_value {map(x_value, 0, 1023, 0, 255)};
  analogWrite(SERVO_MOTOR, mapped_value);
  delay(50UL);

}
