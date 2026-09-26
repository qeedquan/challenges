float x, y, r, g, b, interval;
float velocityHorizontal;
float velocityVertical;

void setup() {
  size(600, 400);
  x = random(width - width, width);
  y = random(height - height, height);
  r = g = b = 0;
  interval = 10;
  velocityHorizontal = velocityVertical = 10;
}

void draw() {
  stroke(255);
  strokeWeight(4);
  fill(r, g, b);
  ellipse(x, y, 100, 100);

  if (x > width || x < 0) {
    if (x > width) {
      x = width;
    } else {
      x = 0;
    }
    y = random(y - interval, y + interval);
    velocityHorizontal *= -1;
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
  }

  if (y > height || y < 0) {
    if (y > height) {
      y = height;
    } else {
      y = 0;
    }

    x = random(x - interval, x + interval);
    velocityVertical *= -1;
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
  }

  x += velocityHorizontal;
  y += velocityVertical;
}
