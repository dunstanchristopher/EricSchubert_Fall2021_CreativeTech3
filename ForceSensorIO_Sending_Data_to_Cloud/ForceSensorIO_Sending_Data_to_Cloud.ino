#include "config.h"
#define FORCESENSORPIN A2

int current = 0;
int last = -1;

AdafruitIO_Feed *queen = io.feed("queen");

void setup() {
// start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  // put your main code here, to run repeatedly:
io.run();
current = analogRead(FORCESENSORPIN);
if(current == last)
  return;
  Serial.print("sending -> ");
  Serial.println(current);
  queen->save(current);

  last = current;

  delay(3000);
}
