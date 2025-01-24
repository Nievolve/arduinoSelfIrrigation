// TestDev Branch
// Pre-Build

unsigned long previousMillis = 0;
unsigned long currentMillis;
const long interval= 10000;
int pumpState = LOW;

int pumpPin = 5;

void setup()
{
  pinMode(pumpPin,OUTPUT);
}


void loop(){
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  if(pumpState==LOW){
    pumpState=HIGH;
                    }
  else{
    pumpState=LOW;
      }
digitalWrite(pumpPin, pumpState)
                                                  }
}