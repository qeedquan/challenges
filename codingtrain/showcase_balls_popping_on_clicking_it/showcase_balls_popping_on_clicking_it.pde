ArrayList<Ball> balls;

void setup() {
  size(800, 800);
  reset();
}

void reset() {
  balls = new ArrayList<>();
  for (var i=0; i < 10; i++) {
    balls.add(new Ball(i, random(80, 100)));
  }
}

void keyPressed() {
  if (key == ' ') {
    reset();
  }
}

void mouseHover() {
  for (var ball : balls) {
    ball.hover(mouseX, mouseY);
  }
}

void mousePressed() {
  var newballs = new ArrayList<Ball>();
  for (var ball : balls) {
    if (!ball.clicked(mouseX, mouseY))
      newballs.add(ball);
  }
  balls = newballs;
}

void draw() {
  background(0);
  if (mouseX >= 0 && mouseX < width && mouseY >= 0 && mouseY < height ) {   
      mouseHover();
  } 
  
  for (var ball : balls) {
    ball.show();
    ball.bounce();
    ball.move();
  }
}

class Ball {
  int index;
  float x, y;
  float xspeed;
  float yspeed;
  float diameter;
  color strokeColor;

  Ball(int index, float diameter) {
    this.x = random(diameter/2, width - diameter/2);
    this.y = random(diameter/2, height - diameter/2);
    this.diameter = diameter;
    this.index = index;
    this.xspeed = random(-1, 1);
    this.yspeed = random(-1, 1);
    this.strokeColor = color(255, 255, 255);
  }
  
  void hover(float x, float y) {
    if (dist(this.x, this.y, x, y) <= diameter/2) {
      strokeColor = color(255, 0, 0);
    } else {
      strokeColor = color(255, 255, 255);
    }
  }
  
  void bounce() {
    if (x <= diameter/2 || x >= width - diameter/2)
       xspeed *= -1;
    
    if (y <= diameter/2 || y >= height - diameter/2)
      yspeed *= -1;
  }
  
  boolean clicked(float x, float y) {
    return dist(this.x, this.y, x, y) <= diameter/2;    
  }
  
  void move() {
    x += xspeed;
    y += yspeed;
  }
  
  void show() {
    stroke(255, 255, 255);
    textSize(32);
    textAlign(CENTER, CENTER);
    text(String.format("%d", index), x, y);
    stroke(strokeColor);
    strokeWeight(5);
    noFill();
    circle(x, y, diameter);
  }
}
