/*

First of all ... I would like to wish everyone a Merry Christmas (sorry if I am a day late for your timezone).

To celebrate the occasion, we are going to draw a snowflake. Because the year is 2015 and Christmas is on the 25th (for a large portion of persons), we will draw a Pentaflake.
The Pentaflake is a simple fractal composed of pentagons. Here are a few examples (taken from here):
https://i.sstatic.net/kt6zm.gif
https://mathworld.wolfram.com/Pentaflake.html

Each Pentaflake has an order n. The Pentaflake of order 0 is simply a pentagon. For all other orders n, a Pentaflake is composed of 5 Pentaflakes of the previous order arranged around a 6th Pentaflake of the previous order. For example, a Pentaflake of order 1 is composed of 5 pentagons arranged around a central pentagon.

Input
The order n. This may be given in any way except that of a predefined variable.

Output
An image of the order n Pentaflake. Must be at least 100px wide and 100px long. It may be saved to a file, displayed to the user, or outputted to STDOUT. Any other form of output is not allowed. All image formats existing before this challenge are allowed.

Winning
As codegolf, the person with the least number of bytes wins.

*/

float PHI = (1 + sqrt(5))/2;

int iterations = 5;

void setup() {
  size(1024, 768);
  render();
}

void draw() {
}

void render() {
  background(200);
  pentaflake(iterations);
}

void keyPressed() {
  int newiterations = iterations;
  if (key == CODED) {
    if (keyCode == LEFT) {
      newiterations -= 1;
    } else if (keyCode == RIGHT) {
      newiterations += 1;
    }
  }
  if (newiterations < 0)
    newiterations = 0;
    
  if (newiterations != iterations) {
    iterations = newiterations;
    println("ITERATIONS: " + iterations);
    render();
  }
}

// ported from @flawr solution
void pentaflake(int maxdepth) {
  recurse(maxdepth, 0, 0, 0, 0);
}

void recurse(int maxdepth, int depth, float x, float y, int layer) {
  var N = 5;
  var L = 2;
  var C = pow(PHI, 2*depth);

  if (depth < maxdepth) {
    recurse(maxdepth, depth+1, x, y, layer^1);
    for (var i = 1; i <= N; i++) {
      var a = 2*PI*i/N;
      var b = PI/N;
      var nx = x + cos(a + layer*b)/C;
      var ny = y + sin(a + layer*b)/C;
      recurse(maxdepth, depth+1, nx, ny, layer);
    }
    return;
  }

  fill(0);
  beginShape();
  for (var i = 1; i <= N; i++) {
    var a = 2*PI*i/N;
    var b = PI/N;
    var px = x + PHI*cos(a + layer*b)/C;
    var py = y + PHI*sin(a + layer*b)/C;
    px = map(px, -L, L, 0, width);
    py = map(py, -L, L, 0, height);
    vertex(px, py); 
  }
  endShape();
}
