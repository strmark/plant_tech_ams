//Analog pin (Moisture Sensor)
#define ANA A0
//Digital pin (Moisture Sensor)
#define DIGI D5

//Power pin (Pump via transistor)
#define POMPOUT D6

double analogValue = 0.0;
int digitalValue = 0;
unsigned long checkInterval=5000;
unsigned long nextCheckAt = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ANA, INPUT);
  pinMode(DIGI, INPUT);
  pinMode(POMPOUT, OUTPUT);
  Serial.begin(115200);
  Serial.println("Paolo Test");
}
void loop() {
  if(millis()>nextCheckAt)
  {
    analogValue = analogRead(ANA);
    digitalValue = digitalRead(DIGI);

    // Serial data
    Serial.print("Analog raw: ");
    Serial.println(analogValue);
    Serial.print("Digital raw: ");
    Serial.println(digitalValue);
    Serial.println(" ");
    if (digitalValue == 0) {
      digitalWrite(POMPOUT, LOW);
    } else {
          Serial.println("Pumping");
        digitalWrite(POMPOUT, HIGH);
    }

    //Set the next check time
    nextCheckAt = millis()+checkInterval;
  }
  yield();
}
