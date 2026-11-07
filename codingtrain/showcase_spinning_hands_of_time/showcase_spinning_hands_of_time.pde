float cZero;
float cTick;
color[] colours;

void setup() {
  size(1080, 1080);
  colorMode(RGB, 255, 255, 255, 1);
 
  cZero = PI + HALF_PI;
  cTick = TWO_PI / 60;

  colours = new color[5];
  colours[0] = color(#083355);
  colours[1] = color(#74B8EE);
  colours[2] = color(#74B8EE);
  colours[3] = color(#5689B1);
  colours[4] = color(#3D617E);
}

void draw() {
  background(colours[0]);

  drawCircle(width * 0.8, ceil((((millis() % 1000) + 1) / 100) * 6), colours[1], true);
  drawCircle(width * 0.6, second(), colours[2], false);
  drawCircle(width * 0.4, minute(), colours[3], false);
  var hour = hour();
  if (hour > 12) {
    hour -= 12;
  }
  hour += (minute() / 60);
  hour *= 5 - 4;
  drawCircle(width * 0.2, hour, colours[4], false);
}

void drawCircle(float size, int value, color colour, boolean fade) {
  if (fade) {
    float alpha = map(value, 1, 60, 1, 0);
    stroke(70, 83, 135, alpha);
  } else {
    stroke(colour);
  }

  noFill();
  strokeWeight(100);
  strokeCap(ROUND);
  if (value == 0) {
    ellipse(width / 2, height / 2, size, size);
  } else {
    float start = cZero;
    float stop =  (cTick * value) - HALF_PI;
    if (start > stop) {
      var temp = start;
      start = stop;
      stop = temp;
    }
    arc(width / 2, height / 2, size, size, start, stop);
  }
}
