Cloud[] clouds;

void setup() {
  size(800, 600);
  clouds = new Cloud[5];
  for (var i = 0; i < clouds.length; i++) {
    clouds[i] = new Cloud();
  }
}

void draw() {
  background(102, 178, 255);
  noStroke();
  fill(255);
  for (var cloud : clouds) {
    cloud.create();
    cloud.move();
  }
}

class Cloud {
  float x, y, m;
  float length;

  Cloud() {
    x = random(displayWidth/2);
    y = random(displayHeight/2);
    m = 0;
    length = random(40, 100);
  }

  void create() {
    rect(x + m, y, length + 100, length, 40);
    circle(x + m + 40, y, length);
    circle(x + m + 85, y, length + 30);
  }

  void move() {
    if (x + m < displayWidth/2) {
      m = m + 2;
    } else {
      m = m - displayWidth/1.5;
      y = random(displayHeight/2);
    }
  }
}
