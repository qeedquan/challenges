/*

https://en.wikipedia.org/wiki/Space_Invaders

*/

Ship              ship;
ArrayList<Flower> flowers;
ArrayList<Drop>   drops;

void setup() {
  size(600, 400);
  reset();
}

void reset() {
  ship = new Ship();
  drops = new ArrayList<Drop>();
  flowers = new ArrayList<Flower>();
  for (var i = 0; i < 6; i++) {
    flowers.add(new Flower(i*80+80, 60));
  }
}

void draw() {
  background(51);
  ship.show();
  ship.move();

  for (var drop : drops) {
    drop.show();
    drop.move();
    for (var flower : flowers) {
      if (drop.hit(flower)) {
        flower.grow();
        drop.evaporate();
      }
    }
  }

  var edge = false;
  for (var flower : flowers) {
    flower.show();
    flower.move();
    if (flower.x > width || flower.x < 0) {
      edge = true;
    }
  }

  if (edge) {
    for (var flower : flowers) {
      flower.shiftDown();
    }
  }

  for (var i = drops.size()-1; i >= 0; i--) {
    var drop = drops.get(i);
    if (drop.toDelete) {
      drops.remove(i);
    }
  }
}

void keyReleased() {
  if (key != ' ') {
    ship.setDir(0);
  }
}

void keyPressed() {
  if (key == ' ') {
    drops.add(new Drop(ship.x, height));
  }
  
  if (keyCode == ENTER) {
    reset();
  }

  if (keyCode == RIGHT) {
    ship.setDir(1);
  } else if (keyCode == LEFT) {
    ship.setDir(-1);
  }
}


class Flower {
  float x;
  float y;
  float r;
  float xdir;
  
  Flower(float x, float y) {
    this.x = x;
    this.y = y;
    this.r = 30;
    this.xdir = 1;
  }

  void grow() {
    r += 2;
  }

  void shiftDown() {
    xdir = -xdir;
    y += r;
  }

  void move() {
    x += xdir;
  }

  void show() {
    noStroke();
    fill(255, 0, 200, 150);
    ellipse(x, y, r*2, r*2);
  }
}

class Drop {
  float x;
  float y;
  float r;
  boolean toDelete;
  
  Drop(float x, float y) {
    this.x = x;
    this.y = y;
    this.r = 8;
    this.toDelete = false;
  }

  void show() {
    noStroke();
    fill(150, 0, 255);
    ellipse(this.x, this.y, this.r*2, this.r*2);
  }

  void evaporate() {
    this.toDelete = true;
  }

  boolean hit(Flower flower) {
    return dist(x, y, flower.x, flower.y) < r + flower.r;
  }

  void move() {
    y -= 5;
  }
}

class Ship {
  float x;
  float xdir;
  
  Ship() {
    this.x = width/2;
    this.xdir = 0;
  }

  void show() {
    fill(255);
    rectMode(CENTER);
    rect(this.x, height-20, 20, 60);
  }

  void setDir(float dir) {
    xdir = dir;
  }

  void move() {
    x += xdir*5;
  }
}
