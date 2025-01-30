---
tags:
  - project
  - Arduino
  - programming
---

# Automatiskt Bevattningssystem för Växter

Detta dokument beskriver hur du kan designa och programmera ett automatiskt bevattningssystem för växter i krukor. Systemet använder fuktighetssensorer och en pump för att hålla jorden på optimal fuktighetsnivå.

---

## 1. Projektets huvudmål och krav

- **Mål**: Automatiskt bevattningssystem som håller jorden i blomkrukor på optimal fuktighetsnivå.
- **Krav**:
  - Använda fuktighetssensorer för att mäta jordens fuktighet.
  - Aktivera pumpen när fuktigheten sjunker under en viss tröskel.
  - Stänga av pumpen när fuktigheten når en övre gräns.
  - Säkerställa att systemet är energisnålt och pålitligt.
  - Backup system som vattnar utefter tid

---

## 2. Systemets komponenter

### Hårdvara
- Fuktighetssensorer
- Vattenpump.
- Vattentank.
- Slang/rör för vattenförsörjning.
- Mikrokontroller (t.ex. Arduino, Raspberry Pi, ESP32).
- Strömförsörjning (batteri eller nätadapter).

### Mjukvara
- Program för att läsa av sensorer, styra pumpen och hantera logik.

---

## 3. Systemdesign och flöde

### 1. Initiering
- Starta upp systemet och kalibrera sensorer.
- Definiera tröskelvärden för fuktighet (t.ex. 30% för "för torrt" och 60% för "tillräckligt fuktigt").

### 2. Mätning
- Läs av fuktighetssensorerna med jämna mellanrum (t.ex. var 5:e minut).
- Beräkna genomsnittlig fuktighet om flera sensorer används.

### 3. Bevattningslogik
- Om fuktigheten < lägre tröskelvärde:
  - Aktivera pumpen för att vattna.
- Om fuktigheten > övre tröskelvärde:
  - Stäng av pumpen.

### 4. Säkerhetsfunktioner
- Stäng av pumpen om vattentanken är tom (om du har en sensor för detta).
- Undvik överhettning av pumpen genom att begränsa körtiden.

### 5. Energihantering
- Använd lågeffektlägen för mikrokontrollern mellan mätningar.
- Stäng av systemet vid nattetid om det inte behövs.

---

## 4. Programstruktur

Här är ett exempel på hur du kan strukturera koden:

```python
# Pseudokod för bevattningssystem

# Inställningar
LOWER_THRESHOLD = 30  # Lägre fuktighetströskel (%)
UPPER_THRESHOLD = 60  # Övre fuktighetströskel (%)
PUMP_DURATION = 10    # Tid i sekunder som pumpen ska köras

# Initiera komponenter
def init_system():
    sensor.init()
    pump.init()

# Läs fuktighet
def read_moisture():
    return sensor.read()

# Styra pumpen
def control_pump(state):
    if state == "ON":
        pump.on()
    else:
        pump.off()

# Huvudloop
def main():
    init_system()
    while True:
        moisture = read_moisture()
        if moisture < LOWER_THRESHOLD:
            control_pump("ON")
            sleep(PUMP_DURATION)
            control_pump("OFF")
        elif moisture > UPPER_THRESHOLD:
            control_pump("OFF")
        sleep(300)  # Vänta 5 minuter mellan mätningar

# Kör programmet
if __name__ == "__main__":
    main()
```


## 5. Testning och felsökning

- **Testa sensorer**: Kontrollera att fuktighetssensorerna ger korrekta värden.
    
- **Testa pumpen**: Se till att pumpen startar och stängs av som den ska.
    
- **Simulera scenarier**:
    
    - Testa systemet med olika fuktighetsnivåer.
        
    - Simulera tom vattentank eller felaktiga sensorvärden.
        
- **Optimera**:
    
    - Justera tröskelvärden och pumpkörtid för bästa resultat.
        
    - Implementera loggning för att spara data och analysera systemets prestanda.
        

---

## 6. Utökade funktioner (valfritt)

- **Fjärrstyrning**: Lägg till Wi-Fi eller Bluetooth för att kontrollera systemet via en app.
    
- **Datainsamling**: Logga fuktighetsdata för att analysera växternas behov över tid.
    
- **Fler zoner**: Utöka systemet till att hantera flera krukor med olika fuktighetsbehov.
    
- **Varningar**: Skicka notiser om fel (t.ex. tom vattentank eller trasig sensor).
    

---

## 7. Dokumentation och underhåll

- Dokumentera hur systemet är uppbyggt och hur det ska underhållas.
    
- Tänk på att rengöra sensorer och rör regelbundet för att undvika tillstoppingar.