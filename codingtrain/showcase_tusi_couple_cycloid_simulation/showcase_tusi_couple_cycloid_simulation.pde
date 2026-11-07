ArrayList<PVector> trail;
float time;

void setup() {
  size(400, 400);
  reset();
}

void reset() {
  trail = new ArrayList<PVector>();
  time = 0;
}

void draw() {
  background(0);
  translate(width / 2, height / 2);
  noFill();
  strokeWeight(3);
  stroke(255);

  float t = time;
  float r1 = 100;
  circle(0, 0, r1 * 2);

  stroke(255, 0, 0);
  strokeWeight(3);
  float r2 = r1 / 3;
  float x1 = (r1 - r2) * cos(t);
  float y1 = (r1 - r2) * sin(t);
  stroke(0, 255, 0);
  strokeWeight(3);
  circle(x1, y1, r2 * 2);

  float px = (r1 - r2) * cos(t) + r2 * cos(((r1 - r2) / r2) * t);
  float py = (r1 - r2) * sin(t) - r2 * sin(((r1 - r2) / r2) * t);

  trail.add(new PVector(px, py));

  stroke(255, 0, 0);
  strokeWeight(4);
  noFill();
  beginShape();
  for (var v : trail) {
    vertex(v.x, v.y);
  }
  endShape();

  stroke(100, 0, 155);
  strokeWeight(15);
  point(px, py);
 
  time += 0.01;

  if (trail.size() > 10000)
    trail.remove(0);
}
