int buzzerPin =  9;
int buttonPin =  11;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  int buttonPress;
  buttonPress = digitalWrite(buzzerPin, HIGH);
  
  if (buttonPress ==1 )
  {
    digitalWrite(buzzerPin, HIGH);
   
  }
  else
  digitalWrite(buzzerPin, LOW);
}
