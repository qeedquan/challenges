void setup() {
  size(800, 800);
}

void draw() {
  background(255);
  drawFlower(width/2, height/2, 100, 150);
  drawFlower(200,250,50,50);
  drawFlower(700,750,30,30);
  drawFlower(300,700,50,100);
  drawFlower(600,600,20,80);
  drawFlower(700,300,50,100);
}

void drawFlower(int circleX, int circleY, int circleWidth, int stemHeight) {
  noStroke();
  fill(50,255,50);

  // flower stem
  rect(circleX, circleY, 5, 1.5*stemHeight);
  fill(255,255,0);
  
  // left petals
  circle(circleX-circleWidth/2, circleY-circleWidth/2, 3*circleWidth/4);
  circle(circleX-circleWidth/2, circleY+circleWidth/2, 3*circleWidth/4);
  // right petals
  circle(circleX + circleWidth/2, circleY-circleWidth/2, 3*circleWidth/4);
  circle(circleX + circleWidth/2, circleY+circleWidth/2, 3*circleWidth/4);
  
  // flower middle circle
  fill(255,175,0);
  circle(circleX, circleY, 1.4*circleWidth);
}
