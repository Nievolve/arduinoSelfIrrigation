// DEV BRANCH
// Build


    //Declaration
//General
unsigned long currentMillis = 0; // Cycle counter to manage the program
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

// Functrions to blink LED lights
void blinkLED(int ledPin) {
  	if(digitalRead(ledPin)==LOW) {

    digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, HIGH);
    }
}

    // SETUP Section
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
    // LOOP Section
void loop()
{
  currentMillis = millis();

    // Timebased automation
  if (currentMillis>=10000 && cooldownTimer <=1){
  digitalWrite(motorOutput, HIGH);
  blinkLED(ledGreen1);
  digitalWrite(motorOutput, LOW);
  currentMillis = currentMillis - millis();
    
  }
    // Sensorbased automation
  if (moistStatus<600 && cooldownTimer <=1){
    digitalWrite(motorOutput, HIGH);
    blinkLED(ledYellow1);
    digitalWrite(motorOutput, LOW);
    cooldownTimer=60000;
  }


 
  
  // loop


  

  // SENSORS

  moistStatus = analogRead(moistSensor1);
  delay(10);


    // READ OUT
  Serial.println("Moiststatus: ");
  Serial.println(moistStatus);
  Serial.println("CooldownTimer: ");
  Serial.println(cooldownTimer);
  Serial.println("Cycle nr: ");
  Serial.println(currentMillis);
  
  // adjustments
  if (cooldownTimer>=1){
  cooldownTimer--;
  }
  delay(200);
}



