void setup() {
  size(600, 600);
}

void draw() {
  background(0);
  stroke(255);
  strokeWeight(4);
  fill(127);
  beginShape();
  vertex(0, 300);
  bezierVertex(mouseX, mouseY, 400, 400, 600, 300);
  bezierVertex(400, 600, 200, 100, 0, 300);
  endShape();
}
