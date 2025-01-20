// C++ code
//

int driverClock = 0; // Allround clock that sets the process

const int motorOutput = 9;
const int ledGreen1 = 2;
const int ledRed1 =3;
const int ledYellow1 =4;
const int  moistSensor1 = A1;

int cooldownTimer = 0;
int moistStatus = 0;

//Functions

// Functrions to blink LED lights
void blinkLED(int ledPin) {
  	for (int i = 1; i <= 50; i++) {
    digitalWrite(ledPin, HIGH); // LED ON
    delay(100);           // wait
    digitalWrite(ledPin, LOW);  // LED OFF
    delay(100);           // wait
    }
}
void pumpFuncHIGH(int motorOutput){
  digitalWrite(motorOutput, HIGH);
}
void pumpFuncLOW(int motorOutput){
  digitalWrite(motorOutput, LOW);
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
  if (driverClock>=600 && cooldownTimer <=1){
    pumpFuncHIGH(motorOutput);
     blinkLED(ledGreen1);
  


  pumpFuncLOW(motorOutput);
    driverClock = 0;
    
  }
  
  if (moistStatus>600){
    pumpFuncHIGH(motorOutput);
    blinkLED(ledYellow1);
    pumpFuncLOW(motorOutput);
    cooldownTimer=1000;
  }
  

 
  
  // loop


  

  
  moistStatus = analogRead(A1);
  delay(200);

  Serial.println(moistStatus);
  Serial.println(cooldownTimer);
  
  
  driverClock++;
  if (cooldownTimer>=1){
  cooldownTimer=cooldownTimer-100;
  }
  delay(1000);
}


