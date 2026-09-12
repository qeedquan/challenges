/*

https://en.wikipedia.org/wiki/Rubik%27s_Cube

*/

import peasy.*;

int UPP = 0;
int DWN = 1;
int RGT = 2;
int LFT = 3;
int FRT = 4;
int BCK = 5;

color colors[] = {
  color(255, 255, 255),
  color(255, 255, 0),
  color(255, 165, 0),
  color(255, 0, 0),
  color(0, 255, 0),
  color(0, 0, 255)
};

class Cube {
  PVector pos;
  float len;
  
  Cube(float x, float y, float z, float len) {
    this.pos = new PVector(x, y, z);
    this.len = len;
  }
  
  void show() {
    fill(255);
    stroke(0);
    strokeWeight(8);
    push();
    translate(this.pos.x, this.pos.y, this.pos.z);
    
    float r = this.len / 2;
    
    // z-fixed
    beginShape();
    fill(colors[BCK]);
    vertex(-r, -r, -r);
    vertex(r, -r, -r);
    vertex(r, r, -r);
    vertex(-r, r, -r);
    endShape(CLOSE);

    beginShape();
    fill(colors[FRT]);
    vertex(-r, -r, r);
    vertex(r, -r, r);
    vertex(r, r, r);
    vertex(-r, r, r);
    endShape(CLOSE);

    // y-fixed
    beginShape();
    fill(colors[DWN]);
    vertex(-r, -r, -r);
    vertex(r, -r, -r);
    vertex(r, -r, r);
    vertex(-r, -r, r);
    endShape(CLOSE);

    beginShape();
    fill(colors[UPP]);
    vertex(-r, r, -r);
    vertex(r, r, -r);
    vertex(r, r, r);
    vertex(-r, r, r);
    endShape(CLOSE);

    // x-fixed
    beginShape();
    fill(colors[LFT]);
    vertex(-r, -r, -r);
    vertex(-r, r, -r);
    vertex(-r, r, r);
    vertex(-r, -r, r);
    endShape(CLOSE);

    beginShape();
    fill(colors[RGT]);
    vertex(r, -r, -r);
    vertex(r, r, -r);
    vertex(r, r, r);
    vertex(r, -r, r);
    endShape(CLOSE);

    pop();
  }
}

PeasyCam cam;
Cube     cube[][][];

void setup() {
  size(800, 800, P3D);
  hint(ENABLE_DEPTH_TEST);
  cam = new PeasyCam(this, 400);
  cube = makeCube();
}

Cube[][][] makeCube() {
  int   dim = 3;
  Cube  cube[][][] = new Cube[dim][dim][dim];
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      for (int k = 0; k < dim; k++) {
        float len = 50;
        float offset = (dim - 1) * len * 0.5;
        float x = len * i - offset;
        float y = len * j - offset;
        float z = len * k - offset;
        cube[i][j][k] = new Cube(x, y, z, len);
      }
    }
  }
  return cube;
}

void draw() {
  background(51);
  for (int i = 0; i < cube.length; i++) {
    for (int j = 0; j < cube[i].length; j++) {
      for (int k = 0; k < cube[i][j].length; k++) {
        cube[i][j][k].show();
      }
    }
  }
}
