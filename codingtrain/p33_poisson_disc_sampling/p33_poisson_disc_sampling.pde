/*

https://www.jasondavies.com/poisson-disc/
https://en.wikipedia.org/wiki/Poisson_sampling
https://en.wikipedia.org/wiki/Colors_of_noise

*/

int       r;
int       k;
float     w;
PVector[] grid;
int       cols;
int       rows;

ArrayList<PVector> active;
ArrayList<PVector> ordered;

void setup() {
  size(400, 400);
  reset();
}

void reset() {
  background(0);
  strokeWeight(4);
  colorMode(HSB, 360, 100, 100);

  // STEP 0
  r = 4;
  k = 30;
  w = r / sqrt(2);
  cols = floor(width / w);
  rows = floor(height / w);
  grid = new PVector[cols * rows];

  // STEP 1
  var x = width / 2;
  var y = height / 2;
  var i = floor(x / w);
  var j = floor(y / w);
  var pos = new PVector(x, y);
  grid[i + j*cols] = pos;

  ordered = new ArrayList<PVector>();
  active = new ArrayList<PVector>();
  active.add(pos);
}


void draw() {
  background(0);
  for (var total = 0; total < 25; total++) {
    if (active.size() > 0) {
      var randIndex = floor(random(active.size()));
      var pos = active.get(randIndex);
      var found = false;
      for (var n = 0; n < k; n++) {
        var sample = PVector.random2D();
        var m = random(r, 2 * r);
        sample.setMag(m);
        sample.add(pos);

        var col = floor(sample.x / w);
        var row = floor(sample.y / w);
        if (col > -1 && row > -1 && col < cols && row < rows && grid[col + row * cols] == null) {
          var ok = true;
          for (var i = -1; i <= 1; i++) {
            for (var j = -1; j <= 1; j++) {
              var index = (col + i) + (row + j) * cols;
              var neighbor = (index >= 0 && index < grid.length) ? grid[index] : null;
              if (neighbor != null) {
                var d = PVector.dist(sample, neighbor);
                if (d < r) {
                  ok = false;
                }
              }
            }
          }
          if (ok) {
            found = true;
            grid[col + row * cols] = sample;
            active.add(sample);
            ordered.add(sample);
            break;
          }
        }
      }

      if (!found) {
        active.remove(randIndex);
      }
    }
  }

  for (var i = 0; i < ordered.size(); i++) {
    var order = ordered.get(i);
    if (order != null) {
      stroke(i % 360, 100, 100);
      strokeWeight(r * 0.5);
      point(order.x, order.y);
    }
  }
}
