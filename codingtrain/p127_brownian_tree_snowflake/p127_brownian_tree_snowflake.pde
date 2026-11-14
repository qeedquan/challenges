/*

https://e4494s.neocities.org/snowflake

*/

Particle            current;
ArrayList<Particle> snowflake;

void setup() {
  size(800, 800);
  reset();
}

void reset() {
  current = new Particle(height/2, 0);
  snowflake = new ArrayList<Particle>();
}

void draw() {
  translate(width/2, height/2);
  rotate(PI/6);
  background(0);

  var count = 0;
  while (!current.finished() && !current.intersects(snowflake)) {
    current.update();
    count++;
  }

  if (count == 0) {
    noLoop();
    println("snowflake completed");
  }

  snowflake.add(current);
  current = new Particle(height/2, 0);

  for (var i = 0; i < 6; i++) {
    rotate(PI/3);
    current.show();
    for (var p : snowflake) {
      p.show();
    }

    push();
    scale(1, -1);
    current.show();
    for (var p : snowflake) {
      p.show();
    }
    pop();
  }
}

class Particle {
  PVector pos;
  float r;
  
  Particle(float radius, float angle) {
    this.pos = PVector.fromAngle(angle);
    this.pos.mult(radius);
    this.r = 2;
  }

  void update() {
    this.pos.x -= 1;
    this.pos.y += random(-3, 3);

    var angle = this.pos.heading();
    angle = constrain(angle, 0, PI/6);
    var magnitude = this.pos.mag();
    this.pos = PVector.fromAngle(angle);
    this.pos.setMag(magnitude);
  }

  void show() {
    fill(100, 200, 255, 150);
    stroke(255, 150);
    ellipse(this.pos.x, this.pos.y, this.r * 2, this.r * 2);
  }

  boolean intersects(ArrayList<Particle> snowflake) {
    for (var s : snowflake) {
      var d = dist(s.pos.x, s.pos.y, this.pos.x, this.pos.y); 
      if (d < this.r * 2) {
        return true;
      }
    }
    return false;
  }

  boolean finished() {
    return (this.pos.x < 1);
  }
}
