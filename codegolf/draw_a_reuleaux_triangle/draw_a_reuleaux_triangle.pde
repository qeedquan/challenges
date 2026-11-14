/*

The Reuleaux triangle is the shape formed by the intersection of three circles, with each circle passing through the others' centers. Regardless of rotation, a Reuleaux triangle's width will always equal the radius of the circles:

https://i.sstatic.net/I9rVr.gif
Image: Wolfram MathWorld

Write a program that takes a width r as input and displays a Reuleaux triangle of that width (in pixels).

You must display the shape in isolation, i.e. solid-filled, un-stroked, and over a solid-filled background.

code-golf - Shortest program in bytes wins.

*/

float RADIUS = 600;
float ZOOM = 1.01;

void setup() {
  size(1024, 768);
}

void draw() {
  background(200);
  reuleaux(RADIUS);
}

void reuleaux(float r) {
  push();

  translate(width/2, height/2);
  scale(1, -1);
  rotate(sin(millis()*0.005));
  translate(-r-150, -r);
  
  fill(161, 168, 181);
  noStroke();
  arc(r, r, r, r, 0, PI/3);
  arc(r + r/2, r, r, r, 2*PI/3, PI);
  arc(r + r/4, r + r/2.3, r, r, 4*PI/3, 5*PI/3);

  pop();
}

void keyPressed() {
  if (key != CODED)
    return;

  if (keyCode == LEFT) {
    RADIUS /= ZOOM;
  } else if (keyCode == RIGHT) {
    RADIUS *= ZOOM;
  }
  println("RADIUS: " + RADIUS);
}
