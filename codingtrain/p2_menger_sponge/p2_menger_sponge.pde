/*

https://en.wikipedia.org/wiki/Menger_sponge

*/

class Box {
  PVector pos;
  float r;
  
  Box(float x, float y, float z, float r) {
    this.pos = new PVector(x, y, z);
    this.r = r;
  }
  
  ArrayList<Box> generate() {
    var boxes = new ArrayList<Box>();
    for (int x = -1; x < 2; x++) {
      for (int y = -1; y < 2; y++) {
        for (int z = -1; z < 2; z++) {
          var sum = abs(x) + abs(y) + abs(z);
          var newR = r / 3;
          if (sum > 1) {
            boxes.add(new Box(pos.x + x*newR, pos.y + y*newR, pos.z + z*newR, newR));
          }
        }
      }
    }
    return boxes;
  }
  
  void show() {
    push();
    fill(max(pos.x, 0.3), max(pos.y, 0.3), max(pos.z, 0.3));
    translate(pos.x, pos.y, pos.z);
    box(r);
    pop();
  }
}

ArrayList<Box> sponge;
float          angle;

void setup() {
  size(800, 800, P3D);
  colorMode(RGB, 1.0);
  reset();
}

void reset() {
  angle = 0;
  sponge = new ArrayList<Box>();
  sponge.add(new Box(0, 0, 0, 200));
}

void draw() {
  background(0.8);
  
  translate(width/2, height/2, 0);
  rotateX(angle);
  rotateY(angle * 0.4);
  rotateZ(angle * 0.1);
  
  for (var box : sponge) {
    box.show();
  }
  angle += 0.01;
}

void keyPressed() {
  reset();
}

void mousePressed() {
  var next = new ArrayList<Box>();
  for (var box : sponge) {
    var newBoxes = box.generate();
    next.addAll(newBoxes);
  }
  sponge = next;
}
