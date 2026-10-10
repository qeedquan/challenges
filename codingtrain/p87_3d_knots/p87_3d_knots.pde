/*

https://en.wikipedia.org/wiki/Knot_theory
https://paulbourke.net/geometry/knots/

*/

float angle;
float beta;
ArrayList<PVector> vectors;

void setup() {
  size(1024, 768, P3D);
  reset();
}

void reset() {
  vectors = new ArrayList<PVector>();
  beta = 0;
  angle = 0;
}

void draw() {
  background(0);
  translate(width/2, height/2);
  rotateY(angle);
  angle += 0.03;

  float r = 100 * (0.8 + 1.6 * sin(6 * beta));
  float theta = 2 * beta;
  float phi = 0.6 * PI * sin(12 * beta);
  float x = r * cos(phi) * cos(theta);
  float y = r * cos(phi) * sin(theta);
  float z = r * sin(phi);
  stroke(255, r, 255);

  vectors.add(new PVector(x, y, z));
  beta += 0.01;

  noFill();
  stroke(255);
  strokeWeight(8);
  beginShape();
  for (var v : vectors) {
    vertex(v.x, v.y, v.z);
  }
  endShape();
}
