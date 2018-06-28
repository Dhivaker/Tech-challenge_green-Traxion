
const int trigPin = 32  ;
const int echoPin = 37 ; 
int ledPin =  9;
void setup()
{
  Serial.begin(9600);    
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); 

}

void loop() {
   
 // establish variables for duration of the ping, and the distance result in inches and centimeters:
long duration;
// The ultrasound sensor is triggered by a HIGH pulse of 2 or more microseconds. Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
int dis;
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH);
dis = (duration/2)*0.034;   // convert the time into a distance in cm
if (dis>80)
{
  
  digitalWrite(ledPin, LOW); 
  
}
 else if (dis<20)
  {
   
   digitalWrite(ledPin, HIGH); 
 
  }
   else
   {
   
    digitalWrite(ledPin, LOW); 
    
 }
 
  Serial.println("Distance:");
Serial.println(dis);
delay(500);
}

