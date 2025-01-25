// TestDev Branch
// Pre-Build
// Timekeeping
unsigned long previousMillis = 0;
unsigned long currentMillis;

// Set points
const long oninterval = 5000;  // Pump ON duration in milliseconds
const long offinterval = 10000; // Pump OFF duration in milliseconds

// IO
int pumpState = LOW;
int buttonState1 = LOW;
int buttonState2 = LOW;
bool automaticMode = false;

int pinButton1 = 3;
int pinButton2 = 4;
int pinRed = 2;   // Red LED for Automatic Mode
int pinYellow = 5; // Yellow LED for Manual Mode
int pumpPin = 13;

// Debounce variables
unsigned long lastDebounceTime1 = 0;
unsigned long debounceDelay = 50; // 50ms debounce delay
bool lastButtonState1 = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  pinMode(pinButton1, INPUT_PULLUP); 
  pinMode(pinButton2, INPUT_PULLUP);
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);

  // Initial state
  digitalWrite(pumpPin, LOW);
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYellow, HIGH);
}

void loop() {
  currentMillis = millis();

  // Handle button inputs with debounce
  handleButtonInputs();

  // Automatic mode logic
  if (automaticMode) {
    handleAutomaticMode();
  } else {
    // Manual mode logic
    handleManualMode();
  }
}

// Function to handle button inputs with debounce
void handleButtonInputs() {
  int reading1 = digitalRead(pinButton1);

  // Debounce Button 1
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = currentMillis;
  }
  if ((currentMillis - lastDebounceTime1) > debounceDelay) {
    if (reading1 == LOW && !automaticMode) {
      automaticMode = true;
      digitalWrite(pinRed, HIGH);
      digitalWrite(pinYellow, LOW);
    }
  }
  lastButtonState1 = reading1;

  // Button 2 to exit automatic mode
  buttonState2 = digitalRead(pinButton2);
  if (buttonState2 == LOW && automaticMode) {
    automaticMode = false;
    digitalWrite(pinRed, LOW);
    digitalWrite(pinYellow, HIGH);
    digitalWrite(pumpPin, LOW); // Ensure pump is off in manual mode
  }
}

// Function to handle automatic mode
void handleAutomaticMode() {
  if (pumpState == LOW) {
    if (currentMillis - previousMillis >= offinterval) {
      pumpState = HIGH;
      digitalWrite(pumpPin, pumpState);
      previousMillis = currentMillis;
    }
  } else {
    if (currentMillis - previousMillis >= oninterval) {
      pumpState = LOW;
      digitalWrite(pumpPin, pumpState);
      previousMillis = currentMillis;
    }
  }
}

// Function to handle manual mode
void handleManualMode() {
  // Manual mode feedback or control can be added here
  // Currently, the pump remains off
  digitalWrite(pumpPin, LOW);
}
