/*

https://en.wikipedia.org/wiki/Heightmap
https://www.redblobgames.com/maps/terrain-from-noise/

*/

int cols;
int rows;
int scl;
int w, h;

float flying;
float terrain[][]; 

void setup() {
  size(600, 600, P3D);

  w = 1400;
  h = 1000;
  scl = 20;
  cols = w / scl;
  rows = h / scl;
  terrain = new float[cols][rows];

  flying = 0;
}

void draw() {
  flying -= 0.1;
  float yoff = flying;
  for (int y = 0; y < rows; y++) {
    float xoff = 0;
    for (int x = 0; x < cols; x++) {
      terrain[x][y] = map(noise(xoff, yoff), 0, 1, -100, 100);
      xoff += 0.2;
    }
    yoff += 0.2;
  }

  background(50, 60, 70);
  translate(0, 50);
  rotateX(PI / 3);
  fill(200, 200, 200, 200);
  translate(-w/3, -h/2, -200);
  for (int y = 0; y < rows - 1; y++) {
    beginShape(TRIANGLE_STRIP);
    for (int x = 0; x < cols; x++) {
      vertex(x * scl, y * scl, terrain[x][y]);
      vertex(x * scl, (y + 1) * scl, terrain[x][y + 1]);
    }
    endShape();
  }
}
