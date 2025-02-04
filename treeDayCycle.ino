// Pumpens utgång
const int pumpOutput = 12;  // Kopplad till pumpen

// Tidskonstanter (i millisekunder)
const unsigned long PUMP_INTERVAL = 72UL * 3600UL * 1000UL;  // 72 timmar = 259200000 ms
const unsigned long PUMP_DURATION = 20UL * 1000UL;            // 20 sekunder = 20000 ms

// Variabler för att hålla reda på tidpunkter
unsigned long lastPumpTime = 0;  // Tid då pumpen senast startade
bool pumpActive = false;         // Indikerar om pumpen är igång just nu
unsigned long pumpOnTime = 0;    // Tid då pumpen tändes i den aktuella cykeln

void setup() {
  // Konfigurera pumpens utgång som OUTPUT
  pinMode(pumpOutput, OUTPUT);
  digitalWrite(pumpOutput, LOW);  // Säkerställ att pumpen är avstängd vid start
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Om pumpen är igång, kontrollera om den ska stängas av efter 20 sekunder
  if (pumpActive) {
    if (currentMillis - pumpOnTime >= PUMP_DURATION) {
      digitalWrite(pumpOutput, LOW);  // Stäng pumpen av
      pumpActive = false;
      // Spara starttiden för denna pumpcykel (detta kan användas som referens för nästa cykel)
      lastPumpTime = pumpOnTime;
    }
  }
  // Om pumpen är avstängd, kontrollera om 72 timmar har gått sedan senaste pumpstart
  else {
    if (currentMillis - lastPumpTime >= PUMP_INTERVAL) {
      digitalWrite(pumpOutput, HIGH);  // Slå på pumpen
      pumpActive = true;
      pumpOnTime = currentMillis;        // Spara tiden då pumpen startades
    }
  }
}
