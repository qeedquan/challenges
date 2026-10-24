/*

Can you write a program that renders to screen a group of pixels exploding apart (as in a simple particle engine) and can you do this in any remarkably small number of characters (key strokes)?
(Recall the game lemmings, when those little guys would explode and their little pixel pieces fly apart.)

Someone programmed a simple particle system here as a Processing sketch and it is pretty hefty compared to what I think others should be able to accomplish if they tried.
But I'd be much more impressed if it someone could do the same in c++ and sdl, or even java or c#.

*/

class Particle {
  float x, y;
  float speed;
  float angle;
}

Particle[] particles;
int numParticles;

void setup() {
  size(1024, 768);
  numParticles = 512;
  createParticles(numParticles);
}

void createParticles(int size) {
  particles = new Particle[size];
  for (var i = 0; i < particles.length; i++) {
    particles[i] = new Particle();
    particles[i].x = width/2;
    particles[i].y = height/2;
    particles[i].speed = randomGaussian()*0.5;
    particles[i].angle = random(2*PI);
  }
}

void draw() {  
  background(150, 160, 170);
  for (var particle : particles) {
    particle.x = particle.x + particle.speed*cos(particle.angle);
    particle.y = particle.y + particle.speed*sin(particle.angle);
    circle(particle.x, particle.y, 4);
  }
}

void keyPressed() {
  if (key == ' ')
    createParticles(numParticles);
}
