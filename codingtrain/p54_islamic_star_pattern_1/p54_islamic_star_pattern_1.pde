/*

http://www.cgl.uwaterloo.ca/csk/projects/starpatterns/
https://en.wikipedia.org/wiki/Ernest_Hanbury_Hankin

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
      var poly = new Polygon();
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
  PVector end;
  float prevD;
  
  Hankin(PVector a, PVector v) {
    this.a = a;
    this.v = v;
    this.b = PVector.add(a, v);
    this.end = null;
    this.prevD = 0;
  }
  
  void show() {
    stroke(255, 0, 255);
    line(this.a.x, this.a.y, this.end.x, this.end.y);
  }
  
  // http://paulbourke.net/geometry/pointlineplane/
  void findEnd(Hankin other) {
    var den = (other.v.y * this.v.x) - (other.v.x * this.v.y);
    if (den == 0) {
      return;
    }
    var numa = (other.v.x * (this.a.y - other.a.y)) - (other.v.y * (this.a.x - other.a.x));
    var numb = (this.v.x * (this.a.y - other.a.y)) - (this.v.y * (this.a.x - other.a.x));
    var ua = numa / den;
    var ub = numb / den;
    var x = this.a.x + (ua * this.v.x);
    var y = this.a.y + (ua * this.v.y);

    if (ua > 0 && ub > 0) {
      var candidate = new PVector(x, y);
      var d1 = PVector.dist(candidate, this.a);
      var d2 = PVector.dist(candidate, other.a);
      var d = d1 + d2;
      var diff = abs(d1 - d2);
      if (diff < 0.001) {
        if (this.end == null) {
          this.end = candidate;
          this.prevD = d;
        } else if (d < this.prevD) {
          this.prevD = d;
          this.end = candidate;
        }
      }
    }
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
    stroke(255, 50);
    //line(this.a.x, this.a.y, this.b.x, this.b.y);
    h1.show();
    h2.show();
  }

  void hankin() {
    var mid = PVector.add(a, b);
    mid.mult(0.5);

    var v1 = PVector.sub(a, mid);
    var v2 = PVector.sub(b, mid);
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

    h1 = new Hankin(offset1, v1);
    h2 = new Hankin(offset2, v2);
  }

  void findEnds(Edge edge) {
    h1.findEnd(edge.h1);
    h1.findEnd(edge.h2);
    h2.findEnd(edge.h1);
    h2.findEnd(edge.h2);
  }
}

class Polygon {
  ArrayList<PVector> vertices;
  ArrayList<Edge> edges;
  
  Polygon() {
    vertices = new ArrayList<PVector>();
    edges = new ArrayList<Edge>();
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
      edge.hankin();
    }

    for (var i = 0; i < edges.size(); i++) {
      for (var j = 0; j < edges.size(); j++) {
        if (i != j) {
          var edge = edges.get(i);
          var nextEdge = edges.get(j);
          edge.findEnds(nextEdge);
        }
      }
    }
  }

  void show() {
    for (var i = 0; i < edges.size(); i++) {
      var edge = edges.get(i);
      edge.show();
    }
  }
}
