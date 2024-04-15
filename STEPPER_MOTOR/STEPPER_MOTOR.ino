#include <Stepper.h>
const uint16_t STEP_PER_REVOLUTION = 2048U;
class Stepper stepping(STEP_PER_REVOLUTION, 8, 10, 9, 11);

void setup() {
  Serial.begin(115200UL);
  stepping.setSpeed(14);
}

void loop() {
  Serial.println(F("Clockwise"));
  stepping.step(STEP_PER_REVOLUTION); 
  delay(1000UL);
  Serial.println(F("Counter Clockwise"));
  stepping.step(-STEP_PER_REVOLUTION); 
  delay(1000UL);
}
