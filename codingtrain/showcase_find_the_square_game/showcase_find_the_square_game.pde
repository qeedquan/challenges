float posX, posY;
float rectSize;
int points;
boolean godsEye;

void setup() {
  size(800, 600);
  textSize(32);
  reset();
}

void reset() {
  posX = width / 2;
  posY = height / 2;
  rectSize = 50;
  points = 0;
  godsEye = false;
}

void draw() {
  background(0);

  fill(255);
  strokeWeight(0);
  text("points: " + points, 10, 32);
  noFill();

  if (inside()) {
    strokeWeight(1);
    stroke(255);
  } else {
    noFill();
    noStroke();
  }

  rectMode(CENTER);
  if (godsEye)
    fill(255);
  square(posX, posY, rectSize);
}

void keyPressed() {
  if (key == ' ') {
    godsEye = !godsEye;
  }
}

void mousePressed() {
  if (inside()) {
    posX = random(0, width);
    posY = random(0, height);
    points++;
  }
}

boolean inside() {
  return mouseX > posX - rectSize / 2 &&
         mouseX < posX + rectSize / 2 &&
         mouseY > posY - rectSize / 2 &&
         mouseY < posY + rectSize / 2;
}
