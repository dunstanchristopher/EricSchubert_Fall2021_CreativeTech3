
#define FORCESENSORPIN A2 // the FSR and 10K pulldown are connected to A0

void setup() {
  Serial.begin(115200);
}

void loop() {
  int analogReading = analogRead(FORCESENSORPIN);

  Serial.print("Force sensor reading = ");
  Serial.print(analogReading); 

  if (analogReading < 10)       
    Serial.println(" -> no pressure");
  else if (analogReading < 200) 
    Serial.println(" -> light touch");
  else if (analogReading < 500) 
    Serial.println(" -> light squeeze");
  else if (analogReading < 800) 
    Serial.println(" -> medium squeeze");
  else 
    Serial.println(" -> big squeeze");

  delay(1000);
}
