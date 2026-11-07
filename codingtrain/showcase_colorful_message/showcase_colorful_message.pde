void setup() {
  size(800, 600);
  background(255);
}

void draw() {
  int r = (int)random(255);
  int g = (int)random(255);
  int b = (int)random(255);
  int z = 150;
  
  noStroke();
  fill(r, g, b, 150);
  circle(mouseX, mouseY, z);

  fill(255);
  textAlign(CENTER, CENTER);
  textSize(width / 20);
  text("My family...", width/2, height/2 - height*0.12 + height*0.47);

  text("In your words, I find my way.", width / 2, height / 2 - height * 0.12);
  text("You are the light in my ordinary days,", width / 2, height / 2);
  text("The warmth that never fades away.", width/2, height/2 + height*0.12);
  text("The land fill with the Tree of Kindness.", width/2, height/2 + height*0.25);
}

void mousePressed() {
  background(255);
}
