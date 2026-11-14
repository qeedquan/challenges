/*

Curve stitching is the process of "stitching" together multiple straight lines in order to create a curve, like so:

https://imgur.com/VtB49gB

For an explanation of curve stitching, visit this website.

We will be drawing our curve in the top left of the screen, as shown in the image above.

Given an integer n (via STDIN or a function parameter), being the number of lines to draw, and an integer p pixels, being the interval between the starting points, draw a straight line curve.

Horizontal/vertical lines are necessary, and should be part of the line count.

Example Outputs:
n = 25, p = 15

https://imgur.com/f5Grr8T

n = 20, p = 20

https://imgur.com/Mb2zjb9

This is a code-golf challenge, so shortest code wins.

*/

int N, P;

void setup() {
  size(1024, 768);
  N = 25;
  P = 15;
}

void draw() {
  background(230);
  stitch(N, P);
}

void stitch(int n, int p) {
  for (int i = 0; i < n; i++) {
    line(0, i*p, (n-i+1)*p, 0);
  }
}

void keyPressed() {
  if (keyCode == RIGHT) {
    N += 1;
  } else if (keyCode == LEFT) {
    N -= 1;
  } else if (keyCode == UP) {
    P += 1;
  } else if (keyCode == DOWN) {
    P -= 1;
  }
  println(String.format("N=%d, P=%d", N, P));
}
