class Path {
  float x, y;
  boolean active;
  boolean fixed;
  
  Path(float x, float y) {
    this.x = x;
    this.y = y;
    this.active = false;
    this.fixed = false;
  }
};

ArrayList<Path> cirPath = new ArrayList<Path>();
int             spacing = 2;

Path polarToCartesian(float r, float angle) {
  angle = radians(angle);
  return new Path(r * cos(angle), r * sin(angle));
}

void setup() {
  size(400, 400);
  float radius = 200;
  for (int a = 0; a < 360; a += spacing) {
    Path cv = polarToCartesian(radius, a);
    cv.active = true;
    if (a % 120 == 0) {
      cv.fixed = true;
    }
    cirPath.add(cv);
  }
}

void draw() {
  background(220);
  translate(width / 2, height / 2);
  rotate(30);
  stroke(0);
  strokeWeight(2);
  noFill();
  beginShape();
  for (var i = 0; i < cirPath.size(); i++) {
    var v = cirPath.get(i);
    if (v.active) {
      vertex(v.x, v.y);
    }
  }
  endShape(CLOSE);

  var activeList = new ArrayList<Path>();
  for (int i = 0; i < cirPath.size(); i++) {
    var v = cirPath.get(i);
    if (v.active && !v.fixed) {
      activeList.add(v);
    }
  }

  if (activeList.size() == 0)
    return;
  var index = 0;
  var v = activeList.get(index);
  if (v != null) {
    v.active = false;
  }
}
