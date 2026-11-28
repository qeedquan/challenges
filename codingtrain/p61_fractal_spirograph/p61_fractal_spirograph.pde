/*

https://softologyblog.wordpress.com/2017/02/27/fractal-spirographs/
https://en.wikipedia.org/wiki/Spirograph

*/

ArrayList<PVector> path;
Orbit              sun;
Orbit              end;
int                resolution;

class Orbit {
  float x, y, r;
  float speed;
  float angle;
  int n;
  int k;
  int resolution;
  Orbit parent;
  Orbit child;
  
  Orbit(float x, float y, float r, int n, int k, int resolution, Orbit parent) {
    this.x = x;
    this.y = y;
    this.r = r;
    this.n = n;
    this.k = k;
    this.resolution = resolution;
    this.parent = parent;
    this.speed = (radians(pow(k, n - 1))) / resolution;
    this.angle = -PI / 2;
  }

  Orbit addChild() {
    var newr = this.r / 3.0;
    var newx = this.x + this.r + newr;
    var newy = this.y;
    child = new Orbit(newx, newy, newr, n + 1, k, resolution, this);
    return child;
  }
  
  void update() {
    var parent = this.parent;
    if (parent != null) {
      this.angle += this.speed;
      var rsum = this.r + parent.r;
      this.x = parent.x + rsum * cos(this.angle);
      this.y = parent.y + rsum * sin(this.angle);
    }
  }

  void show() {
    stroke(255, 100);
    strokeWeight(1);
    noFill();
    ellipse(x, y, r * 2, r * 2);
  }
}

void setup() {
  size(600, 600);
  reset();
}

void reset() {
  resolution = 50;
  int k = -4;
  sun = new Orbit(width/2.0, height/2.0, width/4.0, 0, k, resolution, null);
  var next = sun;
  for (var i = 0; i < 10; i++) {
    next = next.addChild();
  }
  end = next;

  path = new ArrayList<PVector>();
}

void draw() {
  background(51);

  for (var i = 0; i < resolution; i++) {
    var next = sun;
    while (next != null) {
      next.update();
      next = next.child;
    }
    path.add(new PVector(end.x, end.y));
  }

  var next = sun;
  while (next != null) {
    next.show();
    next = next.child;
  }

  beginShape();
  stroke(255, 0, 255);
  noFill();
  for (var pos : path) {
    vertex(pos.x, pos.y);
  }
  endShape();
}
