// Logic Dev Branch
// Pre-Build


const int DIGITAL_PIN = 3;
const int ANALOG_PIN = A0;
const int SENSOR_POWER = 2;
int moistVal;
bool isMoist = false;
String moisture;
void setup() {

Serial.begin(9600);
pinMode(DIGITAL_PIN, INPUT);
pinMode(SENSOR_POWER, OUTPUT);
pinMode(ANALOG_PIN, INPUT);
digitalWrite(SENSOR_POWER, LOW);
}
void loop() {
digitalWrite(SENSOR_POWER, HIGH);
delay(100);
 moistVal = analogRead(ANALOG_PIN);
 isMoist = digitalRead(DIGITAL_PIN);
digitalWrite(SENSOR_POWER, LOW);
if (isMoist==false) {
 moisture = "No";
 }
else {
 moisture = "Yes";
 }
 moistVal = map(moistVal, 0, 1023, 100, 0);
Serial.print("Raining: ");
Serial.println(moisture);
Serial.print("Moisture: ");
Serial.print(moistVal);
Serial.println("%\n");
delay(10000);
} 