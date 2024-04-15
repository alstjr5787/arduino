const uint8_t relayPin = {13U};

void setup() {
  Serial.begin(115200UL); 
  pinMode(relayPin, OUTPUT);

}

void loop() {
  if(Serial.available()) { // 블루투스를 통해서값이 들어왔으면
    char input_value = static_cast<char>(Serial.read()); // 1byte 읽어서 아스키 보드
    if(input_value == "1") {
      digitalWrite(relayPin, HIGH);
      Serial.println(F("Switch On")); // 블루투스 창으로 Switch On
    }
    else if(input_value == "0") {
      digitalWrite(relayPin, LOW);
      Serial.println(F("Switch OFF")); // 블루투스 창으로 Switch OFF
    }
    else {}
  }

}
