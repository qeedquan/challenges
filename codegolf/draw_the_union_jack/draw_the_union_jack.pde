/*

Preface
There are many "draw x flag" challenges, and upon searching it turns out there are no challenges to draw the union Jack! I feel like this would be a harder flag to draw but it should still be possible.

Challenge
Draw the Union Jack. It can be outputted to a file in any freely available graphics file format or drawn onto the screen.

Code Golf rules apply, shortest code in bytes wins.
Standard loopholes apply.
No builtins for flag drawing allowed.
Dimensions shall be as below. Minimum size 600x300 pixels (or units if your language supports only scalable graphics.) Maximum error 1 pixel.

Colours shall be red, white and blue as defined by your language or its documentation, or #CC0000, #FFFFFF and #003399 per Wikipedia page.

https://i.sstatic.net/lHE1z.png

*/

void setup() {
  size(600, 300);
  unionjack();
}

// ported from @6infinity8 solution
void unionjack() {
  int a = 300;
  int b = 2 * a;
  int c = 255;
  int d = 100;
  
  // white diagonals
  background(0, 51, 153);
  stroke(c);
  strokeWeight(60);
  line(0, a, b, 0);
  line(0, 0, b, a);

  // red diagonals
  stroke(c, 0, 0);
  strokeWeight(20);
  line(0, 310, a, 160);
  line(-22, 0, a, 160);
  line(a, 139, b, -12);
  line(a, 139, 624, a);
  noStroke();
  fill(c);
  
  // white cross
  rect(250, 0, d, b);
  rect(0, d, b, d);
  fill(c, 0, 0);

  // red cross
  rect(270, 0, 60, b);
  rect(0, 120, b, 60);
}
