void setup() {
  size(400, 400);
  background(20, 100, 200);
}

void draw() {
  rectMode(CORNER);

  fill(200, 0, 0);
  rect(100, 200, 200, 50);

  fill(0, 50, 100);
  rect(50, 50, 50, 50, 50);
  rect(300, 50, 50, 50, 50);

  line (80,30,130,48);
  line (320,30,270,48);
  line(100, 200, 300, 250);

  rectMode(CENTER);
  fill(0);
  rect(200,350,50,50,10);
}
