  // Main Branch
  // Pre-Build


      //Declaration
  //TimeRelatedVariabels
  unsigned long previousMillis;
  unsigned long currentMillis;


  // Declared IO
  int pumpOutput = 13;


  //Declared varibels
  bool digitalMoist = false; // Value of moisture
  int analogMoist;
  bool digitalMoist;
  int irrigationTime = 10000; //MilliS


      //Functions Section

  // Functrions


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



