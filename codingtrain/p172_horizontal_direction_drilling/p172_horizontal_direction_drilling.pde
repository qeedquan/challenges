/*

https://www.youtube.com/watch?v=JAhdb7dKQpU

*/

PVector pos;
PVector dir;
float   bias;
ArrayList<PVector> path;

void setup() {
  size(600, 400);
  reset();
}

void reset() {
  bias = 1;
  pos = new PVector(10, 100);
  dir = new PVector(1, 0);
  path = new ArrayList<PVector>();
}

void draw() {
  drill();

  background(45, 197, 244);
  noStroke();
  rectMode(CORNER);
  fill(11, 106, 136);
  rect(0, 100, width, height - 100);
  fill(248, 158, 79);
  arc(width / 2, 100, 400, 200, 0, PI);

  beginShape();
  noFill();
  stroke(255);
  strokeWeight(4);
  for (var v : path) {
    vertex(v.x, v.y);
  }
  endShape();

  stroke(252, 238, 33);
  strokeWeight(8);
  push();
  translate(pos.x, pos.y);
  rotate(dir.heading() + (PI / 6) * bias);
  line(0, 0, 10, 0);
  pop();
}

void drill() {
  float angle = 0.01;
  dir.rotate(angle * bias);
  path.add(pos.copy());
  pos.add(dir);
}

void keyPressed() {
  if (keyCode == ' ')
    reset();
}

void mousePressed() {
  bias *= -1;
}
