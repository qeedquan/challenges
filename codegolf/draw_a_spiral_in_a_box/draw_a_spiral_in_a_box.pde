/*

https://i.stack.imgur.com/QDFZn.png

This geometric spiral looks complicated, but it's fairly simple to draw; take the following box:
https://i.stack.imgur.com/Xfuu0.png

Draw a straight line between the corner of the box and some set distance above the next corner counter-clockwise.
https://i.stack.imgur.com/0lOvI.png

Continue this pattern inward, always staying that set distance away from the corner of the next line. Here's a few more lines in.
https://i.stack.imgur.com/I396r.png

As you can see, as the pattern continues, the spiral approaches the center and the boxes you draw begin to rotate. Note that the distance remains constant, regardless of angle.

The Challenge
The Inspiration (and also thanks to the wonderful person who introduced me to this concept <3)
https://www.youtube.com/watch?v=S7DxlebZcrk

Given a numerical (possibly fractional) input from 1 to 25, write an image to disk that uses this pattern or display the output on the screen, where the distance from each corner is the distance of one initial side of the box divided by the input. Continue the pattern inward until the distance from the corner specified is longer than the length of the next side.

Rules
You may not use built-ins for this spiral creation, but you may use image processing builtins.
If you write to disk, you must output an image in any of .jpg, .gif, .tiff, .pbm, .ppm, and .png.
The initial side length must be at least 500 pixels.
The initial corner may be whichever you choose.
As always, the Standard Loopholes are disallowed.

*/

float R, S;
int   N;

void setup() {
  size(1024, 768);
  textSize(24);
  S = 512;
  R = S*10;
  N = 50;
}

void draw() {
  background(100);

  fill(35, 40, 76);
  text(String.format("N: %d R: %.3f S: %.3f", N, R, S), 32, 32);

  translate((width - S)/2, (height-S)/2);
  
  float M = N * abs(sin(0.001*millis()));
  ArrayList<PVector> p = gen((int)M, R, S);
  for (int i = 1; i < p.size()-1; i++) {
    PVector a = p.get(i);
    PVector b = p.get(i - 1);
    line(a.x, a.y, b.x, b.y);
  }
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == LEFT)
      N -= 5;
    else if (keyCode == RIGHT)
      N += 5;
  }
}

/*

@Level River St

The algorithm is parameterized by (N, R, S)
N - Rough number of slices to make, more means more resolution.
R - Initial scale factor
S - Size of the screen

The algorithm works by creating an initial square of S size in a list of points P.
Then it generates new points by the following update:

l = Length of the P points array (grows as points are added)
Q = P[l-3] - P[l-4]
R = (Q*S)/N
Z = P[l-4] + Q/R

Add Z to the point list

*/

ArrayList<PVector> gen(int n, float r, float s) {
  ArrayList<PVector> p = new ArrayList<PVector>() {{
    add(new PVector(0, 0));
    add(new PVector(0, s));
    add(new PVector(s, s));
    add(new PVector(s, 0));
    add(new PVector(0, 0));
  }};
  
  while (r > 1) {
    int l = p.size();
    PVector u = p.get(l - 3);
    PVector v = p.get(l - 4);

    PVector q = PVector.sub(u, v);
    r = q.mag()/s * n;

    q.div(r);
    q.add(v);
    p.add(q);
  }
  return p;
}
