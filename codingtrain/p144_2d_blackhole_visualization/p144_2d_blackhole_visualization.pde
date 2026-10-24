/*

https://en.wikipedia.org/wiki/Black_hole
https://youtu.be/zUyH3XhpLTo
https://www.asc.ohio-state.edu/orban.14/stemcoding/blackhole.html

*/

class Units {
  char mode;
  float c;
  float G;
  float dt;
  
  Units(char mode, float c, float G, float dt) {
    this.mode = mode;
    this.c = c;
    this.G = G;
    this.dt = dt;
  }
}

class Photon {
  PVector position;
  PVector velocity;
  float theta;

  ArrayList<PVector> history;
  
  boolean stopped;
  
  Photon(float x, float y) {
    position = new PVector(x, y);
    velocity = new PVector(-UNITS.c, 0);
    history = new ArrayList<PVector>();
    stopped = false;
    theta = PI;
  }
  
  void stop() {
    stopped = true;
  }
  
  void update() {
    if (!stopped) {
        history.add(position.copy());

      PVector deltaV = velocity.copy();
      deltaV.mult(UNITS.dt);
      position.add(deltaV);
    }

    if (history.size() > 500) {
      history.remove(0);
    }
    
    if (position.x < 0 || position.x > width || position.y < 0 || position.y > height) {
      stop(); 
    }
  }
  
  void show() {
    strokeWeight(4);
    stroke(255, 0, 0);
    point(position.x, position.y);

    strokeWeight(2);
    noFill();
    beginShape();
    for (var v : history) {
      vertex(v.x, v.y);
    }
    endShape();
  }
}

class Blackhole {
  PVector position;
  float mass;
  float radius;
  
  Blackhole(float x, float y, float m) {
    position = new PVector(x, y);
    mass = m;
    radius = (2 * UNITS.G * m) / (UNITS.c * UNITS.c);
  }
  
  void pull(Photon photon) {
    switch (UNITS.mode) {
    case 'N':
      pullNewton(photon);
      break;
    case 'E':
      pullEinstein(photon);
      break;
    }
  }
  
  void pullNewton(Photon photon) {
    PVector force = PVector.sub(position, photon.position);
    float r = force.mag();
    float fg = UNITS.G * mass / (r * r);
    force.setMag(fg);
    photon.velocity.add(force);
    photon.velocity.setMag(UNITS.c);
    if (r < radius) {
      photon.stop();
    }
  }
  
  void pullEinstein(Photon photon) {
    PVector force = PVector.sub(position, photon.position);
    float theta = force.heading();
    float r = force.mag();
    float fg = UNITS.G * mass / (r * r);
    float deltaTheta = -fg * (UNITS.dt / UNITS.c) * sin(photon.theta - theta);
    deltaTheta /= abs(1.0 - 2.0 * UNITS.G * mass / (r * UNITS.c * UNITS.c));
    photon.theta += deltaTheta;
    photon.velocity = PVector.fromAngle(photon.theta);
    photon.velocity.setMag(UNITS.c);

    if (r <= radius + 0.5) {
      photon.stop();
    }
  }

  void show() {
    ellipseMode(RADIUS);
    fill(0);
    noStroke();    
    float r = radius;
    ellipse(position.x, position.y, r, r);

    noFill();
    stroke(100, 100);
    strokeWeight(64);
    r = radius*3 + 32;
    ellipse(position.x, position.y, r, r);

    stroke(255, 150, 0, 100);
    strokeWeight(32);

    r = radius*1.5 + 16;
    ellipse(position.x, position.y, r, r);
  }
}

Units NEWTON = new Units('N', 30, 1.5, 0.1);
Units EINSTEIN = new Units('E', 30, 3.54, 0.1);
Units UNITS;

Blackhole         m87;
ArrayList<Photon> photons;

float start;
float end;

void setup() {
  size(800, 600);
  reset(EINSTEIN);
}

void reset(Units units) {
  UNITS = units;
  m87 = new Blackhole(width/2, height/2, 10000);
  start = height/2;
  end = height/2 - m87.radius*2.6;
  
  photons = new ArrayList<Photon>();
  for (var y = 0; y < start; y += 10) {
    photons.add(new Photon(width - 20, y));
  }
}

void draw() {
  background(255);

  stroke(0);
  strokeWeight(1);
  line(0, start, width, start);
  line(0, end, width, end);

  for (var p : photons) {
    m87.pull(p);
    p.update();
    p.show();
  }
  m87.show();
}

void keyPressed() {
  if (key == 'n') {
    reset(NEWTON);
  } else if (key == 'e') {
    reset(EINSTEIN);
  }
}
