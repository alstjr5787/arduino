#include <IRremote.hpp>
const uint8_t IR_PIN {8U};
class IRrecv irrecv(IR_PIN);
class decode_results result;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  irrecv.begin(IR_PIN, LED_BUILTIN);
  Serial.begin(115200UL);

}

void loop() {
  if(irrecv.decode()) {
    uint8_t data_value = irrecv.decodedIRData.command;
    Serial.println(data_value, HEX);
    switch(data_value){
      case 0x16:
      digitalWrite(LED_BUILTIN, HIGH);
      break;
      case 0x0c:
      digitalWrite(LED_BUILTIN, LOW);
      break;
    }
    irrecv.resume();
    irrecv.start(10);
  }

}
