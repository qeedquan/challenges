ArrayList<Cube> cubes;

void setup() {
  size(800, 600);
  cubes = new ArrayList<>();
}

void mouseDragged () {
  cubes.add(new Cube(mouseX, mouseY));
}

void draw() {
  background(0);
  for (var cube : cubes) {
    cube.move();
    cube.show();
  }
}

class Cube {
  float x;
  float y;
  float wi;
  float g;
  float angle;
  float speed;
  
  Cube(int x, int y) {
    this.x = x;
    this.y = y;
    this.wi = random(50, 100);
    this.g = random(25, 100);
    this.angle = 0;
    this.speed = random (-1, 1);
  }
  
  void move() {
    this.x += this.speed;
    this.y += this.speed;
  }
  
  void show () {
    rectMode(CENTER);
    noStroke();
    fill(255, this.g);
    push();
    translate(this.x, this.y);
    rotate(radians(this.angle));
    rect (0, 0, this.wi, this.wi);
    pop();

    this.angle += this.speed;
  }
}
