//Right motor pins
#define MRSpeed 39    // for generating PWM signal
#define MRDir 15        // for changing direction, forward and backward
#define MRSleep 31     // 
//left motor pins
#define MLSpeed 40
#define MLDir 14
#define MLSleep 11
const int trigPin = 32  ;
const int echoPin = 37 ; 
int ledPin =  9;
int buzzerPin = 10;
void setup() {
  pinMode(MRSpeed, OUTPUT);
  pinMode(MRDir, OUTPUT);
  pinMode(MRSleep, OUTPUT);
  digitalWrite(MRSleep, 1);
  pinMode(MLSpeed, OUTPUT);
  pinMode(MLDir, OUTPUT);
  pinMode(MLSleep, OUTPUT);
  digitalWrite(MLSleep, 1);
  Serial.begin(9600);    
  // initialize serial communication:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT); 
       
}
void loop()
{
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
  digitalWrite(MRSleep, 1);
  digitalWrite(MLSleep, 1);
  digitalWrite(MRDir, 1); 
  digitalWrite(MLDir, 1);
  analogWrite(MRSpeed, 100);  //255 is full speed PWM signal
  analogWrite(MLSpeed, 100);
  digitalWrite(ledPin, LOW); 
  
}
 else if (dis<20)
  {
   digitalWrite(MRSleep, 0); 
   digitalWrite(MLSleep, 0); 
   digitalWrite(ledPin, HIGH); 
  analogWrite(buzzerPin, HIGH);
  }
   else
   {
    digitalWrite(MRDir, 1);
    digitalWrite(MLDir, 1);
    digitalWrite(MLSleep, 1);
    digitalWrite(MRSleep, 1);
    analogWrite(MRSpeed, 50);  //255 is full speed PWM signal
    analogWrite(MLSpeed, 50);
    digitalWrite(ledPin, LOW); 
    analogWrite(buzzerPin, LOW);
 }
 
  Serial.println("Distance:");
Serial.println(dis);
delay(500);
}

