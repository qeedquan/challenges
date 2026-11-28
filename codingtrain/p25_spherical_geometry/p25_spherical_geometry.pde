/*

https://en.wikipedia.org/wiki/Sphere

*/

int total = 25;
PVector globe[][] = new PVector[total + 1][total + 1];

float r = 200;
float angleX = 0;
float angleY = 0;

void setup() {
  size(800, 800, P3D);
  noFill();
  strokeWeight(2);
  stroke(200);

  for (int i = 0; i < total + 1; i++) {
    float lat = map(i, 0, total, 0, PI);
    for (int j = 0; j < total + 1; j++) {
      float lon = map(j, 0, total, 0, TWO_PI);
      float x = r * sin(lat) * cos(lon);
      float y = r * sin(lat) * sin(lon);
      float z = r * cos(lat);
      globe[i][j] = new PVector(x, y, z);
    }
  }
}

void draw() {
  background(51);
  translate(width/2, height/2, 0);
  rotateX(angleX);
  rotateY(angleY);

  for (int i = 0; i < total; i++) {
    beginShape(TRIANGLE_STRIP);
    for (int j = 0; j < total + 1; j++) {
      PVector v1 = globe[i][j];
      vertex(v1.x, v1.y, v1.z);
      PVector v2 = globe[i + 1][j];
      vertex(v2.x, v2.y, v2.z);
    }
    endShape();
  }

  angleX += 0.005;
  angleY += 0.006;
}
