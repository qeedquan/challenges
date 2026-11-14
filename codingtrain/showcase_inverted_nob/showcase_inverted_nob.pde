void setup() {
  size(600, 600);
}

void draw() {
  float col = map(mouseX, 0, 600, 0, 255);
  float col2 = map(mouseX, 0, 600, 255, 0);
  background(col);

  noStroke();
  circle(mouseX, 300, 50);
  fill(col2);
}
