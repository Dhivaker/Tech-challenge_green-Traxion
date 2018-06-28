int ledPin =  9;
int buttonPin =  11;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int buttonPress;
  buttonPress = digitalWrite(buttonPin, HIGH);
  
  if (buttonPress ==1 )
  {
    digitalWrite(ledPin, HIGH);
   
  }
  else
  digitalWrite(ledPin, LOW);
}
