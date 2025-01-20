// C++ code
//

int driverClock = 0; // Allround clock that sets the process

const int motorOutput = 9;
const int ledGreen1 = 2;
const int ledRed1 =3;
const int ledYellow1 =4;
const int  moistSensor1 = A1;

int cooldownTimer = 0;
int moistStatus = 870;

//Functions

// Functrions to blink LED lights
void blinkLED(int ledPin) {
  	for (int i = 1; i <= 50; i++) {
    digitalWrite(ledPin, HIGH); // LED ON
    delay(100);           // wait
    digitalWrite(ledPin, LOW);  // LED OFF
    delay(100);           // wait
    }

// SETUP
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

    // Timebased automation
  if (driverClock>=600 && cooldownTimer <=1){
  digitalWrite(motorOutput, HIGH);
  blinkLED(ledGreen1);
  pumpFuncLOW(motorOutput);
  driverClock = 0;
    
  }
    // Sensorbased automation
  if (moistStatus<600 %% moistStatus>101 %% cooldownTimer <=1){
    digitalWrite(motorOutput, HIGH);
    blinkLED(ledYellow1);
    digitalWrite(motorOutput, LOW);
    cooldownTimer=60000;
  }
  else if(moistStatus<100){
    digitalWrite(motorOutput, HIGH);
    blinkLED(ledYellow1);
    digitalWrite(motorOutput, LOW);
    cooldownTimer=60000;
  }
  

 
  
  // loop


  

  // SENSORS

  moistStatus = analogRead(A1);
  delay(10);


    // READ OUT
  Serial.println(moistStatus);
  Serial.println(cooldownTimer);
  
  // adjustments
  driverClock++;
  if (cooldownTimer>=1){
  cooldownTimer=cooldownTimer-1;
  }
  delay(1000);
}


