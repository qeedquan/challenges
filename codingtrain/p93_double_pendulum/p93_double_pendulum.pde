// https://en.wikipedia.org/wiki/Double_pendulum

float r1 = 125;
float r2 = 125;
float m1 = 10;
float m2 = 10;
float a1 = 0;
float a2 = 0;
float a1_v = 0;
float a2_v = 0;
float g = 1;

float px2 = -1;
float py2 = -1;
float cx, cy;

PGraphics buffer;

void setup() {
  size(600, 350);

  pixelDensity(1);
  a1 = PI / 2;
  a2 = PI / 2;
  cx = width / 2;
  cy = 50;
  
  buffer = createGraphics(width, height);
  buffer.beginDraw();
  buffer.background(250);
  buffer.endDraw();
}

void draw() {
  background(250);
  imageMode(CORNER);
  image(buffer, 0, 0, width, height);

  float num1 = -g * (2 * m1 + m2) * sin(a1);
  float num2 = -m2 * g * sin(a1 - 2 * a2);
  float num3 = -2 * sin(a1 - a2) * m2;
  float num4 = a2_v * a2_v * r2 + a1_v * a1_v * r1 * cos(a1 - a2);
  float den = r1 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
  float a1_a = (num1 + num2 + num3 * num4) / den;

  num1 = 2 * sin(a1 - a2);
  num2 = (a1_v * a1_v * r1 * (m1 + m2));
  num3 = g * (m1 + m2) * cos(a1);
  num4 = a2_v * a2_v * r2 * m2 * cos(a1 - a2);
  den = r2 * (2 * m1 + m2 - m2 * cos(2 * a1 - 2 * a2));
  float a2_a = (num1 * (num2 + num3 + num4)) / den;

  translate(cx, cy); 

  float x1 = r1 * sin(a1);
  float y1 = r1 * cos(a1);

  float x2 = x1 + r2 * sin(a2);
  float y2 = y1 + r2 * cos(a2);
  strokeWeight(2);
  line(0, 0, x1, y1);
  fill(0);
  ellipse(x1, y1, m1*2, m1*2);

  line(x1, y1, x2, y2);
  fill(0);
  ellipse(x2, y2, m2*2, m2*2);

  a1_v += a1_a;
  a2_v += a2_a;
  a1 += a1_v;
  a2 += a2_v;

  // a1_v *= 0.99;
  // a2_v *= 0.99;
  buffer.beginDraw();
  buffer.translate(cx, cy);
  buffer.stroke(0);
  if (frameCount > 1) {
    stroke(0, 100);
    strokeWeight(0.5);
    buffer.line(px2, py2, x2, y2);
  }
  buffer.endDraw();

  px2 = x2;
  py2 = y2;
}
