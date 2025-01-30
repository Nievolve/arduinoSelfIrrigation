  // Logic Dev Branch
  // Pre-Build


      //Declaration
  //General
  unsigned long cooldownTimer = 0; // Cooldown counter to prevent functions to execute
  unsigned int driverClock = 0;

  //Interval of irrigation
  int programCycleTime=1000;
  unsigned int irrigationTime = 50000;

  // Declared IO
  const int motorOutput = 9; // Digital output for pump/motor
  const int ledGreen = 2; // Digital output for LED(Green)
  const int ledRed =3; // Digital output for LED(Red)
  const int ledYellow =4; // Digital output for LED(Yellow)
  const int ledBlue = 6;
  const int ledWhite = 7;
  const int  moistSensor = A1; // Analog input for sensor (moist)

  //Declared varibels
  bool digitalMoist = false; // Value of moisture
  int analogMoist;

      //Functions Section

  // Functrions to blink LED lights
  void onLED(int ledPin) {
  if(digitalRead(ledPin)==LOW) {
    digitalWrite(ledPin, HIGH);
  }
  }
  void offLED(int ledPin){
  if(digitalRead(ledPin)==HIGH) {
    digitalWrite(ledPin, LOW);
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
      // adjustments
    if (cooldownTimer>=1){
    cooldownTimer--;
    }
    driverClock++;
  
      // Timebased automation
  if (driverClock>=10 && cooldownTimer<=1){
    digitalWrite(motorOutput, HIGH);
    onLED(ledGreen);
    delay(irrigationTime);
    digitalWrite(motorOutput, LOW);
    offLED(ledGreen);
    driverClock=0;
    cooldownTimer=0;
  }
      // READ OUT

Serial.println(driverClock);
    

    delay(programCycleTime);

  }



