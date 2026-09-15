void setup() {
  size(650, 360);
  frameRate(5);
}

void draw() {
  background(255);
  noStroke();

  float r = 40;
  for (int y = 0; y <= height; y += 50) {
    for (int x = 0; x <= width; x += 50) {
      float col = map(x, 0, width, 0, 255);
      float col1 = map(y, 0, height, 0, 255);
      fill(col + col1 - 250, col + col1 - 250, col + col1);
      ellipse(x, y, r, r);
    }
    r = random(35, 45);
  }
}
