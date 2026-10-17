/*

https://en.wikipedia.org/wiki/Toothpick_sequence

*/

ArrayList<Toothpick> picks;

float minX;
float maxX;

void setup() {
  size(600, 600);
  reset();
}

void reset() {
  minX = -width / 2;
  maxX = width / 2;
  picks = new ArrayList<Toothpick>();
  picks.add(new Toothpick(0, 0, 1));
}

void draw() {
  background(255);
  translate(width / 2, height / 2);

  var factor = float(width) / (maxX - minX);
  scale(factor);
  for (var t : picks) {
    t.show(factor);
    minX = min(t.ax, minX);
    maxX = max(t.ax, maxX);
  }

  var next = new ArrayList<Toothpick>();
  for (var t : picks) {
    if (t.newPick) {
      var nextA = t.createA(picks);
      var nextB = t.createB(picks);
      if (nextA != null) {
        next.add(nextA);
      }
      if (nextB != null) {
        next.add(nextB);
      }
      t.newPick = false;
    }
  }
  picks.addAll(next);

  if (frameCount > 200) {
    noLoop(); 
  }
}

class Toothpick {
  final int len = 63;

  float ax, ay;
  float bx, by;
  int dir;
  boolean newPick;
  
  Toothpick(float x, float y, int d) {
    newPick = true;
    dir = d;
    if (dir == 1) {
      ax = x - len / 2;
      bx = x + len / 2;
      ay = y;
      by = y;
    } else {
      ax = x;
      bx = x;
      ay = y - len / 2;
      by = y + len / 2;
    }
  }
  
  boolean intersects(float x, float y) {
    return ((ax == x && ay == y) || (bx == x && by == y));
  }

  Toothpick createA(ArrayList<Toothpick> others) {
    for (var other : others) {
      if (other != this && other.intersects(ax, ay)) {
        return null;
      }
    }
    return new Toothpick(ax, ay, -dir);
  }

  Toothpick createB(ArrayList<Toothpick> others) {
    for (var other : others) {
      if (other != this && other.intersects(bx, by)) {
        return null;
      }
    }
    return new Toothpick(bx, by, -dir);
  }

  void show(float factor) {
    stroke(0);
    if (newPick) {
      stroke(0, 0, 255);
    }
    strokeWeight(1 / factor);
    line(ax, ay, bx, by);
  }
}
