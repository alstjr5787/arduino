const uint8_t LED_LOW {12U};
const uint8_t LED_HIGH {13U};

void setup() 
{
  pinMode(LED_LOW, OUTPUT);
  pinMode(LED_HIGH, OUTPUT);
}

void loop() 
{
  digitalWrite(LED_LOW, HIGH); 
  digitalWrite(LED_HIGH, HIGH);
  delay(500UL);

  digitalWrite(LED_LOW, LOW); 
  digitalWrite(LED_HIGH, LOW);
  delay(500UL);
}
