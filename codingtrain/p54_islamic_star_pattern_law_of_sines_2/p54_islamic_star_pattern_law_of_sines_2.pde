/*

http://www.cgl.uwaterloo.ca/csk/projects/starpatterns/
https://en.wikipedia.org/wiki/Ernest_Hanbury_Hankin
https://en.wikipedia.org/wiki/Law_of_sines

*/

ArrayList<Polygon> polys;

float angle;
float delta;

float deltaSlider;
float angleSlider;

void setup() {
  size(400, 400);
  angle = 75;
  delta = 10;
  deltaSlider = delta;
  angleSlider = angle;
  
  polys = new ArrayList<Polygon>();
  
  var inc = 100;
  for (var x = 0; x < width; x += inc) {
    for (var y = 0; y < height; y += inc) {
      var poly = new Polygon(4);
      poly.addVertex(x, y);
      poly.addVertex(x + inc, y);
      poly.addVertex(x + inc, y + inc);
      poly.addVertex(x, y + inc);
      poly.close();
      polys.add(poly);
    }
  }
}

void draw() {
  background(51);
  angle = angleSlider;
  delta = deltaSlider;
  
  strokeWeight(2);
  for (var i = 0; i < polys.size(); i++) {
    var poly = polys.get(i);
    poly.hankin();
    poly.show();
  }
}

void keyPressed() {
  if (keyCode == UP) {
    deltaSlider += 1;
  } else if (keyCode == DOWN) {
    deltaSlider -= 1;
  } else if (keyCode == LEFT) {
    angleSlider -= 1;
  } else if (keyCode == RIGHT) {
    angleSlider += 1;
  }
  deltaSlider = constrain(deltaSlider, 0, 25);
  angleSlider = constrain(angleSlider, 0, 90);
  print("Angle: " + angle + " Delta: " + delta + "\n");
}

class Hankin {
  PVector a, b, v;
  
  Hankin(PVector a, PVector v) {
    this.a = a;
    this.v = v;
    this.b = PVector.add(a, v);
  }
  
  void show() {
    stroke(248, 158, 79);
    strokeWeight(2);
    line(a.x, a.y, b.x, b.y);
  }
}

class Edge {
  PVector a, b;
  Hankin h1, h2;
  
  Edge(PVector a, PVector b) {
    this.a = a;
    this.b = b;
    this.h1 = null;
    this.h2 = null;
  }

  void show() {
    stroke(248, 158, 79);
    //line(this.a.x, this.a.y, this.b.x, this.b.y);
    h1.show();
    h2.show();
  }

  void hankin(float sides) {
    var mid = PVector.add(a, b);
    mid.mult(0.5);

    var v1 = PVector.sub(a, mid);
    var v2 = PVector.sub(b, mid);
    
    // Edge length
    var elen = v1.mag() + delta;
    
    var offset1 = mid;
    var offset2 = mid;
    if (delta > 0) {
      v1.setMag(delta);
      v2.setMag(delta);
      offset1 = PVector.add(mid, v2);
      offset2 = PVector.add(mid, v1);
    }
    v1.normalize();
    v2.normalize();

    v1.rotate(radians(-angle));
    v2.rotate(radians(angle));
    
    // Calculate interior angle
    var interior = (sides - 2) * PI / sides;
    // Law of sines right here!
    var alpha = interior * 0.5;
    var beta = PI - radians(angle) - alpha;
    var hlen = (elen * sin(alpha)) / sin(beta);

    v1.setMag(hlen);
    v2.setMag(hlen);

    h1 = new Hankin(offset1, v1);
    h2 = new Hankin(offset2, v2);
  }
}

class Polygon {
  ArrayList<PVector> vertices;
  ArrayList<Edge> edges;
  float sides;
  
  Polygon(float n) {
    vertices = new ArrayList<PVector>();
    edges = new ArrayList<Edge>();
    sides = n;
  }

  void addVertex(float x, float y) {
    var a = new PVector(x, y);
    var total = vertices.size();
    if (total > 0) {
      var prev = this.vertices.get(total - 1);
      var edge = new Edge(prev, a);
      edges.add(edge);
    }
    vertices.add(a);
  }

  void close() {
    var total = vertices.size();
    var last = vertices.get(total - 1);
    var first = vertices.get(0);
    var edge = new Edge(last, first);
    edges.add(edge);
  }

  void hankin() {
    for (var i = 0; i < edges.size(); i++) {
      var edge = edges.get(i);
      edge.hankin(sides);
    }
  }

  void show() {
    for (var i = 0; i < edges.size(); i++) {
      var edge = edges.get(i);
      edge.show();
    }
  }
}
