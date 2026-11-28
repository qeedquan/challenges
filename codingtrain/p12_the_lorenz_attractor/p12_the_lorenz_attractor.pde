/*

https://en.wikipedia.org/wiki/Lorenz_system

*/

ArrayList<PVector> points;
float a, b, c;
float x, y, z;

void setup() {
  size(1200, 900, P3D);
  colorMode(HSB);
  reset();
}

void reset() {
  x = 0.01;
  y = 0;
  z = 0;
  
  a = 10;
  b = 28;
  c = 8.0 / 3.0;
  
  points = new ArrayList<PVector>();
}

void draw() {
  background(0);

  float dt = 0.01;
  float dx = (a * (y - x)) * dt;
  float dy = (x * (b - z) - y) * dt;
  float dz = (x * y - c * z) * dt;
  x = x + dx;
  y = y + dy;
  z = z + dz;

  points.add(new PVector(x, y, z));

  translate(0, 0, -80);
  float camX = map(mouseX, 0, width, -200, 200);
  float camY = map(mouseY, 0, height, -200, 200);
  camera(camX, camY, (height / 2.0) / tan(PI * 30.0 / 180.0), 0, 0, 0, 0, 1, 0);
  scale(5);
  stroke(255);
  noFill();

  float hu = 0;
  beginShape();
  for (var v : points) {
    stroke(hu, 255, 255);
    vertex(v.x, v.y, v.z);
    hu += 1;
    if (hu > 255) {
      hu = 0;
    }
  }
  endShape();
}
