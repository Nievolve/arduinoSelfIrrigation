  // Analog Branch
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
 
  int irrigationTime = 10000; //MilliS
  


      //Functions Section

  // Functrions
  void readAnalogValueMoist(){
    int analogValueMoist = analogRead(moistPinAnalog);
    int analogCurrentValueProcent = map(analogValueMoist,0,1023,0,100);
    Serial.print("Analog value: ");
  Serial.println(analogCurrentValueProcent);
    return analogCurrentValueProcent;
  }
  void readDigitalValueMoist(){
    int digitalValueMoist = digitalRead(moistPinDigital);
    Serial.print("Digital value: ");
    Serial.println(digitalValueMoist);
  }
void controlPump(bool state) {
    digitalWrite(pumpOutput, state ? HIGH : LOW);
}

      // SETUP Section
  void setup()
  {
    pinMode(pumpOutput, OUTPUT);
    pinMode(analogMoist, INPUT);
    pinMode(digitalMoist, INPUT);

    Serial.begin(9600);
  }
    // LOOP
  void loop()
  {
    currentMillis = millis();
  if(readDigitalValueMoist==1){
    controlPump(true);
    delay(irrigationTime);
    controlPump(false);
  }
  if(readAnalogValueMoist>=1){
    controlPump(true);
    delay(irrigationTime);
    controlPump(false);
  }

  readAnalogValueMoist();
  readDigitalValueMoist();

  delay(60000); //Wait an hour

  }