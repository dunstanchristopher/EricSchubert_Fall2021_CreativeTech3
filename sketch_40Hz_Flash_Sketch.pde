color c1 = color(0,0,0), c2 = color(255,255,255), current;
void setup() { 
  frameRate(40);
  size(1280, 960);
  current = c1;
}
void draw() { background(current);
if(current==c1) { current = c2; } else { current = c1; }
}
