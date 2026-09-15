float circlex;

void setup() {
  size(600, 600);
  reset();
}

void reset() {
  background(205);
  circlex = 1;
}

void draw() {
  if (mousePressed) {
    stroke(circlex, circlex, circlex);
    fill(0, 0, 0, 0);
    circle(mouseX, 300, circlex);
    circlex *= 1.1;
  }
}

void keyPressed() {
  if (key == ' ')
    reset();
}
