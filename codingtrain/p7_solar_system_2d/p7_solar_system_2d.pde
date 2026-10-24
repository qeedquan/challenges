/*

https://en.wikipedia.org/wiki/Solar_System

*/

Planet sun;

void setup() {
  size(600, 600);
  sun = new Planet(50, 0, 0, random(TWO_PI));
  sun.spawnMoons(5, 1);
}

void draw() {
  background(51);
  translate(width / 2, height / 2);
  sun.show();
  sun.orbit();
}

class Planet {
  float radius;
  float distance;
  float orbitspeed;
  float angle;
  ArrayList<Planet> planets;
  
  Planet(float radius, float distance, float orbitspeed, float angle) {
    this.radius = radius;
    this.distance = distance;
    this.orbitspeed = orbitspeed;
    this.angle = angle;
    this.planets = new ArrayList<Planet>();
  }

  void orbit() {
    angle += orbitspeed;
    for (var planet : planets) {
      planet.orbit();
    }
  }
  
  void spawnMoons(int total, int level) {
    for (int i = 0; i < total; i++) {
      float r = this.radius / (level * 2);
      float d = random(50, 150);
      float o = random(-0.1, 0.1);
      float a = random(TWO_PI);
      this.planets.add(new Planet(r, d / level, o, a));
      if (level < 3) {
        int num = (int) Math.floor(random(0, 4));
        var planet = planets.get(i);
        planet.spawnMoons(num, level + 1);
      }
    }
  }

  void show() {
    push();
    fill(255, 100);
    rotate(angle);
    translate(distance, 0);
    ellipse(0, 0, radius * 2, radius * 2);
    for (var planet : planets) {
      planet.show();
    }
    pop();
  }
}
