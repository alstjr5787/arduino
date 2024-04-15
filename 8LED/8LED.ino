
const uint8_t LEDS[] = {3U ,4U ,5U ,6U ,7U ,8U ,9U, 10U};

void setup() 
{
  // pinMode(LED1, OUTPUT);
  // pinMode(LED2, OUTPUT);
  // pinMode(LED3, OUTPUT);
  // pinMode(LED4, OUTPUT);
  // pinMode(LED5, OUTPUT);
  // pinMode(LED6, OUTPUT);
  // pinMode(LED7, OUTPUT);
  // pinMode(LED8, OUTPUT);
  for(int i = 0; i < 8; i++){
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() 
{
  // digitalWrite(LED1, HIGH);
  // delay(100UL);
  // digitalWrite(LED2, HIGH);
  // delay(500UL);
  // digitalWrite(LED3, HIGH);
  // delay(500UL);
  // digitalWrite(LED4, HIGH);
  // delay(500UL);
  // digitalWrite(LED5, HIGH);
  // delay(500UL);
  // digitalWrite(LED6, HIGH);
  // delay(500UL);
  // digitalWrite(LED7, HIGH);
  // delay(500UL);
  // digitalWrite(LED8, HIGH);
  // delay(500UL);
  for(int i = 0; i < 8; i++){
    digitalWrite(LEDS[i], HIGH);
    delay(500UL);
  }

  for(int i = 7; i >= 0; i--){
    digitalWrite(LEDS[i], LOW);
    delay(500UL);
}

  // digitalWrite(LED8, LOW);
  // delay(500UL);
  // digitalWrite(LED7, LOW);
  // delay(500UL);
  // digitalWrite(LED6, LOW);
  // delay(500UL);
  // digitalWrite(LED5, LOW);
  // delay(500UL);
  // digitalWrite(LED4, LOW);
  // delay(500UL);
  // digitalWrite(LED3, LOW);
  // delay(500UL);
  // digitalWrite(LED2, LOW);
  // delay(100UL);
  // digitalWrite(LED1, LOW);
  // delay(100UL);
  }
