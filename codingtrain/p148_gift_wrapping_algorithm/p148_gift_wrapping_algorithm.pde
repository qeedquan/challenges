/*

https://en.wikipedia.org/wiki/Gift_wrapping_algorithm
https://en.wikipedia.org/wiki/Convex_hull

*/

ArrayList<PVector> points;
ArrayList<PVector> hull;

PVector leftMost;
PVector currentVertex;
PVector nextVertex;
int index;
int nextIndex;

void setup() {
  size(500, 500);
  reset();
}

void reset() {
  int buffer = 20;
  points = new ArrayList<PVector>();
  for (int i = 0; i < 50; i++) {
    points.add(new PVector(random(buffer, width - buffer), random(buffer, height - buffer)));
  }
  points.sort((a, b) -> (a.x-b.x) > 0 ? 1 : -1);
  leftMost = points.get(0);
  currentVertex = leftMost;
  hull = new ArrayList<PVector>();
  hull.add(currentVertex);
  nextVertex = points.get(1);
  index = 2;
  nextIndex = -1;

  loop();
}

void draw() {
  background(0);

  stroke(255);
  strokeWeight(8);
  for (var p : points) {
    point(p.x, p.y);
  }

  stroke(0, 0, 255);
  fill(0, 0, 255, 50);
  beginShape();
  for (var p : hull) {
    vertex(p.x, p.y);
  }
  endShape(CLOSE);

  stroke(0, 255, 0);
  strokeWeight(32);
  point(leftMost.x, leftMost.y);

  stroke(200, 0, 255);
  strokeWeight(32);
  point(currentVertex.x, currentVertex.y);

  stroke(0, 255, 0);
  strokeWeight(2);
  line(currentVertex.x, currentVertex.y, nextVertex.x, nextVertex.y);

  PVector checking = points.get(index);
  stroke(255);
  line(currentVertex.x, currentVertex.y, checking.x, checking.y);

  PVector a = PVector.sub(nextVertex, currentVertex);
  PVector b = PVector.sub(checking, currentVertex);
  PVector c = a.cross(b);
  if (c.z < 0) {
    nextVertex = checking;
    nextIndex = index;
  }

  index = index + 1;
  if (index >= points.size()) {
    if (nextVertex == leftMost) {
      println("done");
      noLoop();
    } else {
      hull.add(nextVertex);
      currentVertex = nextVertex;
      index = 0;
      nextVertex = leftMost;
    }
  }
}

void keyPressed() {
  if (key == ' ') {
    reset();
  }
}
