void setup() {
  size(600, 600, P3D);
}

void draw() {
  background(0);
  lights();

  translate(width/2, height/2, 0);
  scale(100);
  rotateY(frameCount * 0.02);
  rotateX(frameCount * 0.032);
  
  for (var i = -1; i < 2; i++) {
    for (var j = -1; j < 2; j++) {
      for (var k = -1; k < 2; k++) {
        push();
        translate(i, j, k);
        noStroke();

        if (i == 0 && j == 0 && k == 0) {
          fill(45, 197, 244);
          box(0.75);
        } else {
          fill(240, 99, 164);
          box(0.6);
        }
        pop();
      }
    }
  }
}
