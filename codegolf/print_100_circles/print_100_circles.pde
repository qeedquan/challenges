/*

Goal: Create the smallest possible code to open a separate window, in which there are 100 circles of random sizes and colors.

Rules: All circles must be visible to the unassisted, naked eye, so in other words more than 2 pixels across, the background must be black, at least 5 different colors must be recognizable, and at all circles must fit within the window.

*/

color colbg;
int   numcircles;

void setup() {
  colbg = color(0);
  numcircles = 100;
  
  size(1024, 768);
  background(colbg);
  drawCircles(numcircles);
}

void draw() {
}

void drawCircles(int n) {
  for (int i = 0; i < n; i++) {
    color col = color(30 + random(225), 30 + random(225), 30 + random(225));
    float r = 100*randomGaussian() + 10;
    float x = randomGaussian()*width/2 + width/2;
    float y = randomGaussian()*height/2 + height/2;
    fill(col);
    circle(x, y, r);
  }
}

void keyPressed() {
  if (keyCode == LEFT) {
    numcircles -= 5;
  } else if (keyCode == RIGHT) {
    numcircles += 5;
  }
  
  if (key == ' ' || keyCode == LEFT || keyCode == RIGHT) {
    background(colbg);
    drawCircles(numcircles);
  }
}
