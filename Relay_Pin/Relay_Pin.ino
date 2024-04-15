const uint8_t relayPin = {13U};

void setup()
{
  pinMode(relayPin, OUTPUT);
}

void loop()
{
  digitalWrite(relayPin, HIGH); 
  delay(1000); 
  digitalWrite(relayPin, LOW); 
  delay(1000); 
}
