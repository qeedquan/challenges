float r1, g1, b1, r2, g2, b2, r3, b3, g3, v1, v2, v3;

void setup() {
  size(400, 400);
  r1 = 255;
  g1 = 252;
  b1 = 196;
  r2 = 255;
  g2 = 255;
  b2 = 205;
  r3 = 199;
  g3 = 230;
  b3 = 255;
  v1 = random(0.2,1.8);
  v2 = random(300);
  v3 = random(150,450);
  randomSeed(80);
}

void draw() {
  background(r3, g3, b3);
  r3 = map(mouseY, 0, 300, 199, 67);
  g3 = map(mouseY, 0, 300, 230, 72);
  b3 = map(mouseY, 0, 300, 255, 79);

  // Sun
  g1 = map(mouseY, 0, 300, 255, 190);
  b1 = map(mouseY, 0, 300, 255, 110);
  g2 = map(mouseY, 0, 300, 255, 159);
  b2 = map(mouseY, 0, 300, 205, 120);
  fill(r1, g1, b1);
  strokeWeight(4);
  stroke(r2, g2, b2);
  circle(mouseX, mouseY, 50);
  
  // Moon
  fill(237, 237, 245);
  stroke(210, 205, 190);
  strokeWeight(2);
  circle(mouseX, mouseY-300, 50);
  
  // Stars
  circle(mouseX+v2, mouseY-v3, 1);
  circle(mouseX+v2-150, mouseY-v3-30, 1);
  circle(mouseX+v2-350, mouseY-v3+50, 1);
  circle(mouseX+v2-450, mouseY-v3-200, 1);
  circle(mouseX+v2-250, mouseY-v3-300, 1);

  // Field
  fill(#94C761);
  stroke(#559255);
  strokeWeight(1);
  circle(50, 400, 450);
  circle(300, 650, 950);

  // Main house
  fill(#CCCBCA);
  stroke(#45352A);
  rect(150, 150, 100, 100);

  // Roof
  fill(#A07355);
  stroke(#646971);
  triangle(150, 150, 250, 150, 200, 100);

  // Windows
  fill(#C2B674);
  square(165, 180, 20);
  square(215, 180, 20);

  line(175, 180, 175, 200);
  line(165, 190, 185, 190);

  line(225, 180, 225, 200);
  line(215, 190, 235, 190);

  // Door
  fill(#A07355);
  stroke(#4B3B31);
  rect(190, 210, 20, 40);
  circle(205, 230, 3);
}
