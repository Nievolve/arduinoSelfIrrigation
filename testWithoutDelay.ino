
const int ledPin = 2;  // the number of the LED pin


int ledState = LOW; 

unsigned long previousMillis = 0;  // will store last time LED was updated


const long interval = 1000;  // interval at which to blink (milliseconds)

void setup() {
// Declare IO
  pinMode(ledPin, OUTPUT);
}

void loop() {


  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and if it's on when checked it turns off
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
