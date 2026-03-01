/*

Your challenge is to draw/plot one of the hearts below. The size must be at least 50x50 pixels (vector graphics is OK).
You may choose which of the hearts you want to draw/plot. Axes, grid lines etc. are accepted.
There must be at least 100 distinct coordinates/points on the graph.
The heart can be filled with color if you want to.

https://i.stack.imgur.com/Vnin0.jpg

The equations are either:

(x^2 + y^2 - 1)^3 - x^2*y^3 = 0

or

x = sin(t)*cos(t)*ln(|t|)
y = cos(t)^0.5 * |t|^0.3
t is in the range [-1, 1].

or

(y - (2(|x| + x^2 - 6)/(3|x| + x^2 + 2))^2 + x^2 = 36

or

r = (sin(t)*sqrt(|cos(t)|) / (sin(t) + 7/5)) - 2*sin(t) + 2

This is code-golf so the shortest code (in each language) in bytes wins. Please provide the output (or link to an online interpreter).

/*

/*

https://blogs.lcps.org/academiesonline/2021/02/13/the-equation-of-the-heart/
https://mathworld.wolfram.com/HeartCurve.html

*/

class Heart {
  float x0, y0;
  float x1, y1;
  float r;
  float t;
  
  Heart() {
    r = 15;
    reset();
  }
  
  void update(float dt) {
    t += dt;
    x0 = x1;
    y0 = y1;
    x1 = 16*sin(t)*sin(t)*sin(t);
    y1 = 13*cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t);
    x1 *= r;
    y1 *= r;
  }

  void reset() {
    x0 = y0 = x1 = y1 = t = 0;
  }
}

color colbg;
Heart heart;

void setup() {
  colbg = color(230, 230, 230);
  heart = new Heart();
  
  size(1024, 768);
  background(colbg);
}

void draw() {
  translate(width/2, height/2);
  scale(1, -1);
  heart.update(0.05);
  stroke(255, 0, 0);
  line(heart.x0, heart.y0, heart.x1, heart.y1);
}

void keyPressed() {
  if (key == ' ') {
    background(colbg);
    heart.reset();
  }
}
