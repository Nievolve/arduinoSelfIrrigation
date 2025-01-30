  // Main Branch
  // Pre-Build


      //Declaration
  //TimeRelatedVariabels
  unsigned long previousMillis;
  unsigned long currentMillis;


  // Declared IO
  const int pumpOutput = 13;
  const int moistPinAnalog = A0;
  const int moistPinDigital = 5;


  //Declared varibels
  bool digitalMoist = false; // Value of moisture
  int analogMoist;
  bool digitalMoist;
  int irrigationTime = 10000; //MilliS
  


      //Functions Section

  // Functrions
  void readAnalogValueMoist(pinMoist){
    analogValueMoist = analogRead(pinMoist);
    int analogCurrentValue = map(analogValueMoist,0,1023,0,100);
    return analogCurrentValue;
  }
void controlPump(bool state) {
    digitalWrite(PUMP_PIN, state ? HIGH : LOW);
}

      // SETUP Section
  void setup()
  {
    pinMode(pumpOutput, OUTPUT);
    pinMode(analogMoist, INPUT);
    pinMode(digitalMoist, INPUT);
  }
    // LOOP
  void loop()
  {
    currentMillis = millis();
    




  }



