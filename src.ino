// Logic Dev Branch
// Pre-Build
int motorOutput = 13;
int driveClock = 0;
int greenLED=5;
int yellowLED=4;
int redLED=3;
void setup()
{
pinMode(motorOutput, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(yellowLED, OUTPUT);
pinMode(redLED, OUTPUT);

digitalWrite(greenLED, LOW);
digitalWrite(yellowLED, LOW);
digitalWrite(redLED, LOW);
Serial.begin(9600);
}

void loop()
{
if (driveClock>=1){
  digitalWrite(motorOutput, HIGH);
  delay(15000);
  digitalWrite(motorOutput, LOW);
  driveClock = 0;
  }
    digitalWrite(greenLED, HIGH);
    
    delay(5000);
    digitalWrite(yellowLED,HIGH);
    delay(5000);
    digitalWrite(redLED, HIGH);
    delay(4950);
    digitalWrite(greenLED,LOW);
    digitalWrite(yellowLED,LOW);
    digitalWrite(redLED,LOW);
    delay(50);
    driveClock++;
}