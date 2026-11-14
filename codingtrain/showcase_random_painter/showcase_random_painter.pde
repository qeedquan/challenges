void setup() {
  size(400, 400);
  background(100);
}

void draw() {
  float r = random(255);
  float g = random(255);
  float b = random(255);
  fill(r, g, b, 70);
  circle(mouseX, mouseY, random(5, 45));
}

void keyPressed() {
  if (key == ' ') {
    println("Saving image");
    save("painting.png");
  }
}
