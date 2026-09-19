/*

ISO Paper Sizes Defined:

The A series paper sizes are defined by the following requirements:

The length divided by the width is the square root of 2.
The A0 size has an area of 1 unit.
Each subsequent size A(n) is defined as A(n-1) cut in half parallel to its shorter sides.
https://i.stack.imgur.com/tDQjn.gif

Task:

given an input f[n] output A0 divided into n subdivisions.

Test cases:

f[1] to f[12]:

https://i.stack.imgur.com/Ji01L.gif

Here, A0 is given by f[1], but this indexing isn't essential.

Winning criteria:

The shortest code in bytes wins.

*/

class Rect {
  int x, y, w, h;
  
  Rect(int x, int y, int w, int h) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
  }
  
  String toString() {
    return String.format("Rect(%d, %d, %d, %d)", x, y, w, h);
  }
}

class Divider {
  ArrayList<Rect>    rects;
  ArrayList<Integer> colors;
  
  Divider(int x, int y, int w, int h) {
    rects = new ArrayList<Rect>();
    rects.add(new Rect(x, y, w, h));
    
    colors = new ArrayList<Integer>();
    colors.add(randrgb());
  }
  
  void draw() {
    strokeWeight(5);
    stroke(0);
    for (int i = 0; i < rects.size(); i++) {
      Rect r = rects.get(i);
      int c = colors.get(i);
      
      fill(c);
      rect(r.x, r.y, r.w, r.h);
    }
  }
  
  void next() {
    int n = rects.size();
    Rect r = rects.get(n - 1);
    if (n%2 != 0)
      rects.add(new Rect(r.x, r.y + r.h/2, r.w, r.h/2));
    else
      rects.add(new Rect(r.x + r.w/2, r.y, r.w/2, r.h));   
    colors.add(randrgb());
  }
}

Divider divider;

void setup() {
  size(310*2, 432*2);
  reset();
}

void reset() {
  divider = new Divider(0, 0, width, height);
}

void draw() {
  divider.draw();
}

void keyPressed() {
  if (key == ' ') {
    reset();
  } else if (key == ENTER) {
    divider.next();
  }
}

color randrgb() {
  float r = random(256);
  float g = random(256);
  float b = random(256);
  return color(r, g, b);
}
