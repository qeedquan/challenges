/*

https://en.wikipedia.org/wiki/Recam%C3%A1n%27s_sequence

*/

ArrayList<Boolean> numbers;
ArrayList<Integer> sequence;
ArrayList<Arc>     arcs;
float scl;
int count;
int index;
int biggest;

class Arc {
  float start;
  float end;
  float dir;
  
  Arc(float start, float end, float dir) {
    this.start = start;
    this.end = end;
    this.dir = dir;
  }

  void show() {
    float diameter = abs(this.end - this.start);
    float x = (this.end + this.start) / 2;
    stroke(255);
    strokeWeight(0.5);
    noFill();
    if (this.dir == 0) {
      arc(x, 0, diameter, diameter, 2*PI, 0);
    } else {
      arc(x, 0, diameter, diameter, 0, 2*PI);
    }
  }
}

void setup() {
  size(800, 800);
  frameRate(30);
  reset();
}

void reset() {
  background(0);
  count = 1;
  index = 0;
  biggest = 0;
  scl = 0;
  
  numbers = new ArrayList<>();
  addNumber(index, true);

  sequence = new ArrayList<>();
  sequence.add(index);
  
  arcs = new ArrayList<>();
}

void step() {
  int next = index - count;
  if (next < 0 || numbers.get(next)) {
    next = index + count;
  }
  addNumber(next, true);
  sequence.add(next);

  var a = new Arc(index, next, count % 2);
  arcs.add(a);

  index = next;
  if (index > biggest) {
    biggest = index;
  }

  count++;
}

void draw() {
  step();
  translate(0, height / 2.0);
  scl = lerp(scl, (width * 1.0)/ biggest, 0.1);
  scale(scl);
  background(0);

  for (var a : arcs) {
    a.show();
  }
}

void addNumber(int index, boolean value) {
  while (numbers.size() <= index)
    numbers.add(false);
  numbers.set(index, value);
}
