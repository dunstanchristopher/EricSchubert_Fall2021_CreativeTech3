int time = millis();

void setup() {
  size(1280, 720);
  background(0);
  noStroke();
}

void draw() {
  background(0);

  fill(255); // sets fill color to white

  int passedMillis = millis() - time; // calculates passed milliseconds
  if(passedMillis >= 25){
      time = millis();
      fill(0,0,0);  // if more than 215 milliseconds passed set fill color to red
  }
  rect(0,0,1280,720); // draw first circle


  fill(255); // fill white
}
