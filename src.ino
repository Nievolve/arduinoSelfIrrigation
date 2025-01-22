// Logic Dev Branch
// Pre-Build


    //Declaration
//General
unsigned long cooldownTimer = 0; // Cooldown counter to prevent functions to execute
unsigned long maxCycle = 4294967295;
int driverClock = 1;

//Interval of irrigation
int examplePlant1 = maxCycle/50; // Waterpump is activated once per day 
int examplePlant2 = maxCycle/(50/7); //Waterpump is activated once per week

// Declared IO
const int motorOutput = 9; // Digital output for pump/motor
const int ledGreen = 2; // Digital output for LED(Green)
const int ledRed =3; // Digital output for LED(Red)
const int ledYellow =4; // Digital output for LED(Yellow)
const int ledBlue = 6;
const int ledWhite = 7;
const int  moistSensor = A1; // Analog input for sensor (moist)

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
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow,OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledWhite, OUTPUT);

  pinMode(moistSensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  

    // Timebased automation
  if (millis()>=12000*driverClock){
  digitalWrite(motorOutput, HIGH);
  blinkLED(ledGreen);
  delay(5000);
  digitalWrite(motorOutput, LOW);
  blinkLED(ledGreen);
  driverClock++;
    
  }


 
  



    // READ OUT

  Serial.println(millis());
  
  // adjustments
  if (cooldownTimer>=1){
  cooldownTimer--;
  }

}



