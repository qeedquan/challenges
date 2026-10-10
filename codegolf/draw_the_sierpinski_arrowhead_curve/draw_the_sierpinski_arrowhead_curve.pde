/*

Introduction
The Sierpinski Arrowhead Curve is a curve that's limit is Sierpinski's Triangle.

It first starts like this:

 _
/ \
Then, each line is replaced with a rotated version of the first one:

  _
 / \
 \ /
_/ \_
Next:

     _
    / \
    \ /
   _/ \_
  /     \
  \_   _/
 _  \ /  _
/ \_/ \_/ \

https://i.stack.imgur.com/9zbLN.png

Your task
Given a number n, output the n-th iteration of the Sierpinski Arrowhead Curve.

You may choose 0 or 1-indexed input, but please specify that in your answer.

You may generate an image, or use Ascii Art in the format I have given above.

You may not use built-ins to generate this curve.

Remember, this is code-golf, so the code with the fewest bytes wins.

*/

Arrowhead arrowhead;
int order;

void setup() {
  size(1024, 768);
  
  arrowhead = new Arrowhead();
  order = 6;
  render(order);
}

void draw() {
}

void render(int order) {
  println("Order: " + order);
  background(200);
  push();
  translate(width/2-width/8, height/2);
  if ((order&1) != 0)
    scale(1, -1);
  arrowhead.reset();
  arrowhead.draw(order, width/3);
  pop();
}

void keyPressed() {
  int neworder = order;
  if (keyCode == RIGHT)
    neworder += 1;
  else if (keyCode == LEFT) {
    if (neworder > 0)
      neworder--;
  }
  
  if (order != neworder) {
    order = neworder;
    render(order);
  }
}

// https://en.wikipedia.org/wiki/Sierpi%C5%84ski_curve#Arrowhead_curve
class Arrowhead {
  PVector position;
  float orientation;
  
  Arrowhead() {
    reset();
  }
  
  void reset() {
    position = new PVector();
    orientation = 0;
  }
  
  void draw(int order, float length) {
    if ((order&1) == 0)
      curve(order, length, 60);
    else {
      turn(60);
      curve(order, length, -60);
    }
  }
  
  void curve(int order, float length, int angle) {
    if (order <= 0) {
      float x = position.x + cos(radians(orientation))*length;
      float y = position.y + sin(radians(orientation))*length;
      line(position.x, position.y, x, y);
      position.x = x;
      position.y = y;
    } else {
      curve(order - 1, length / 2, -angle);
      turn(angle);
      curve(order - 1, length / 2, angle);
      turn(angle);
      curve(order - 1, length / 2, -angle);
    }
  }
  
  void turn(float angle) {
    orientation += angle;
    orientation %= 360;
  }
}
