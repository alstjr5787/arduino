const uint8_t WATER_SENSOR = A15;
const uint8_t SERVO_MOTOR = 13;

void setup() {
  Serial.begin(115200);
  pinMode(WATER_SENSOR, INPUT);
  pinMode(SERVO_MOTOR, OUTPUT);
}

void loop() {
  uint16_t water_value = analogRead(WATER_SENSOR);
  Serial.print(F("Water value: "));
  Serial.println(water_value);

  if (water_value < 200) { 
    analogWrite(SERVO_MOTOR, 0);
  } else if (water_value >= 200 && water_value < 400) { 
    for (int i = 0; i < 255; i += 5) {
      analogWrite(SERVO_MOTOR, i);
      delay(100);
    }

  } else if (water_value >= 400 && water_value < 600) { 
    for (int i = 0; i < 255; i += 5) {
      analogWrite(SERVO_MOTOR, i);
      delay(50);
    }

    for (int i = 255; i >= 0; i -= 5) {
      analogWrite(SERVO_MOTOR, i);
      delay(50);
    }

  } else { 
    for (int i = 0; i < 255; i += 5) {
      analogWrite(SERVO_MOTOR, i);
      delay(25);
    }
    for (int i = 255; i >= 0; i -= 5) {
      analogWrite(SERVO_MOTOR, i);
      delay(25);
    }
  }
}
