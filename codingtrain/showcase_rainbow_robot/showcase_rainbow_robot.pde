void setup() {
  size(400, 400);
}

void draw() {
  // pink background
  background(220, 0, 200);

  rectMode(CENTER);
  strokeWeight(2);

  // purple rectangle
  fill(106, 50, 159);
  rect(200, 200, 375, 375);

  // blue rectangle
  fill(52, 50, 159);
  rect(200, 200, 350, 350);

  // green rectangle
  fill(56, 118, 29);
  rect(200, 200, 325, 325);

  // yellow rectangle
  fill(255, 215, 0);
  rect(200, 200, 300, 300);

  // orange rectangle
  fill(255, 105, 0);
  rect(200, 200, 275, 275);

  // red rectangle
  fill(204, 0, 0);
  rect(200, 200, 250, 250);

  // black rectangle;
  fill(0, 0, 0);
  rect(200, 200, 225, 225);

  // eyes
  fill(250, 250, 250);
  ellipse(150, 150, 80, 80);
  ellipse(250, 150, 80, 80);

  fill(0, 0, 0);
  ellipse(150, 160, 40, 40);
  ellipse(250, 160, 40, 40);

  fill(250, 250, 250);
  ellipse(150, 155, 20, 20);
  ellipse(250, 155, 20, 20);

  // nose
  rect(200, 210, 20, 20);

  // mouth
  rect(200, 260, 120, 40);

  // top teeth
  rect(150, 250, 20, 20);
  rect(170, 250, 20, 20);
  rect(190, 250, 20, 20);
  rect(210, 250, 20, 20);
  rect(230, 250, 20, 20);
  rect(250, 250, 20, 20);

  // bottom teeth
  rect(150, 270, 20, 20);
  rect(170, 270, 20, 20);
  rect(190, 270, 20, 20);
  rect(210, 270, 20, 20);
  rect(230, 270, 20, 20);
  rect(250, 270, 20, 20);
}
