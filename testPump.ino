    int pumpOutput = 13;
    int pumpState = LOW;
    unsigned long currentMillis;
    unsigned long previousMillis;

    int interval = 5000;



    void setup()
    {
    pinMode(pumpOutput, OUTPUT);
    }


    void loop()
    {
        currentMillis = millis();

        if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;

        // if the LED is off turn it on and if it's on when checked it turns off
        if (pumpState == LOW) {
        pumpState = HIGH;
        } else {
        pumpState = LOW;
        }
        digitalWrite(pumpOutput, pumpState);
    }
    }