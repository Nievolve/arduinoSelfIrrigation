// Test Developtment
  // For hardware testing

    //Declaration
//General
int driverClock = 0; // Cycle counter to manage the program
unsigned long cooldownTimer = 0; // Cooldown counter to prevent functions to execute

// Declared IO
const int motorOutput = 9; // Digital output for pump/motor
const int ledGreen1 = 2; // Digital output for LED(Green)
const int ledRed1 =3; // Digital output for LED(Red)
const int ledYellow1 =4; // Digital output for LED(Yellow)
const int  moistSensor1 = A1; // Analog input for sensor (moist)


//Declared varibels
int moistStatus = 0; // Value of moisture

    //Functions Section


  // Functions

void blinkLED(int ledPin) {
  	for (int i = 1; i <= 50; i++) {
    digitalWrite(ledPin, HIGH); // LED ON
    delay(100);           // wait
    digitalWrite(ledPin, LOW);  // LED OFF
    delay(100);           // wait
    }
}






void setup()
{
  pinMode(motorOutput, OUTPUT);
  pinMode(ledGreen1, OUTPUT);
  pinMode(ledRed1, OUTPUT);
  pinMode(moistSensor1, INPUT);
  pinMode(A0, OUTPUT);
  pinMode(ledYellow1,OUTPUT);

  Serial.begin(9600);
}
void loop()
{


moistStatus = analogRead(moistSensor1);

if (moistStatus>= 867/2){
  digitalWrite(motorOutput, HIGH);
  blinkLED(ledYellow1);
  digitalWrite(motorOutput, LOW);
}

Serial.println(moistStatus);
 
}



