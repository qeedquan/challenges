float r;
float factor;

void setup() {
  size(600, 600);

  r      = height/2.0 - 16.0;
  factor = 2.0;
}

void draw() {
  background(0);

  int total = 200;
  factor += 0.015;

  translate(width / 2, height / 2);
  stroke(255, 150);
  strokeWeight(2);
  noFill();
  ellipse(0, 0, r * 2, r * 2);

  strokeWeight(2);
  for (int i = 0; i < total - 1; i++) {
    PVector a = getVector(i, total);
    PVector b = getVector(i + 16, total);
    PVector c = getVector((i + 8) * factor, total);
    PVector d = getVector((i + 1) * factor, total);
    bezier(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);
  }
}

PVector getVector(float index, float total) {
  float   angle = map(index % total, 0, total, 0, TWO_PI);
  PVector v = PVector.fromAngle(angle + PI);
  v.mult(r);
  return v;
}
