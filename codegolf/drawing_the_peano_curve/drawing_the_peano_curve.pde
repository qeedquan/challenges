/*

Introduction
In geometry, the Peano curve is the first example of a space-filling curve to be discovered, by Giuseppe Peano in 1890. Peano's curve is a surjective, continuous function from the unit interval onto the unit square, however it is not injective. Peano was motivated by an earlier result of Georg Cantor that these two sets have the same cardinality. Because of this example, some authors use the phrase "Peano curve" to refer more generally to any space-filling curve.

Challenge
The program takes an input which is an integer n, and outputs a drawing representing the nth iteration of the Peano curve, starting from the sideways 2 shown in the leftmost part of this image:
https://i.stack.imgur.com/XVLbi.png

Input
An integer n giving the iteration number of the Peano curve. Optional, additional input is described in the bonuses section.

Output
A drawing of the nth iteration of the Peano curve. The drawing can be both ASCII art or a "real" drawing, whichever is easiest or shortest.

Rules
The input and output can be given in any convenient format (choose the most appropriate format for your language/solution).
No need to handle negative values or invalid input
Either a full program or a function are acceptable.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.
Bonuses
Since this shouldn't be a walk in the park (at least in most languages I can think of), bonus points are awarded for the following:

-100 bytes if your code generates a gif of the construction of the Peano curves up to n.
-100 bytes if your code draws a space-filling curve for any rectangular shape (the Peano curve only works for squares, obviously). You can assume that the input then takes on the form n l w where n has the same meaning as before (the number of the iteration), but where l and w become the length and width of the rectangle in which to draw the curve. If l == w, this becomes the regular Peano curve.
Negative scores are allowed (but are they possible...).

Edit
Please include the output of your program in the solution for n == 3 (l == w == 1).

*/

Peano peano;

void setup() {
  size(1000, 1000);
  peano = new Peano();
  render();
}

void render() {
  background(150, 160, 170);
  peano.render();
}

// https://www.researchgate.net/publication/228982573_A_recursive_algorithm_for_the_generation_of_space-filling_curves/
// https://rosettacode.org/wiki/Peano_curve
class Peano {
  PVector position;
  
  Peano() {
    position = new PVector();
  }
  
  void render() {
    recurse(0, 0, width, 0, 0);
  }
  
  void recurse(int x, int y, int lg, int i1, int i2) {
    if (lg < 1)
      return;

    if (lg == 1) {
      int nx = 3*x;
      int ny = 3*y;
      line(position.x, position.y, nx, ny);
      position.x = nx;
      position.y = ny;
      return;
    }
    
    lg /= 3;
    recurse(x+(2*i1*lg), y+(2*i1*lg), lg, i1, i2);
    recurse(x+((i1-i2+1)*lg), y+((i1+i2)*lg), lg, i1, 1-i2);
    recurse(x+lg, y+lg, lg, i1, 1-i2);
    recurse(x+((i1+i2)*lg), y+((i1-i2+1)*lg), lg, 1-i1, 1-i2);
    recurse(x+(2*i2*lg), y+(2*(1-i2)*lg), lg, i1, i2);
    recurse(x+((1+i2-i1)*lg), y+((2-i1-i2)*lg), lg, i1, i2);
    recurse(x+(2*(1-i1)*lg), y+(2*(1-i1)*lg), lg, i1, i2);
    recurse(x+((2-i1-i2)*lg), y+((1+i2-i1)*lg), lg, 1-i1, i2);
    recurse(x+(2*(1-i2)*lg), y+(2*i2*lg), lg, 1-i1, i2);
  }
}
