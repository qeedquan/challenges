/*

The goal of this code golf is to draw a regular polygon (one with equal side lengths) given the number of sides and radius (distance from center to vertex).

The number of sides and the radius can be entered via a file, STDIN, or just a plain old variable. Use whatever is shorter in your language.
-25% of total characters/bytes if the image is actually drawn instead of ASCII art.

*/

int SIDES;
int RADIUS;

void setup() {
  size(1024, 768);
  SIDES = 3;
  RADIUS = height/2;
}

void draw() {
  background(150, 160, 170);
  translate(width/2, height/2);
  regularPolygon(SIDES, RADIUS);
}

void regularPolygon(int sides, int radius) {
  beginShape();
  for (var side = 0; side < sides; side++) {
    var t = 2 * PI * side/sides;
    var x = cos(t) * radius;
    var y = sin(t) * radius;
    vertex(x, y);
  }
  endShape(CLOSE);
}

void keyPressed() {
  if (keyCode == RIGHT) {
    SIDES += 1;
  } else if (keyCode == LEFT) {
    if (SIDES > 2)
      SIDES -= 1;
  }
}
