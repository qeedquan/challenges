/*

https://web.archive.org/web/20160418004150/http://freespace.virgin.net/hugo.elias/models/m_fire.htm

*/

PImage buffer1;
PImage buffer2;
PImage cooling;
int w = 300;
int h = 200;

float ystart = 0.0;

void setup() {
  pixelDensity(1);
  size(600, 200);
  buffer1 = createImage(w, h, ARGB);
  buffer2 = createImage(w, h, ARGB);
  cooling = createImage(w, h, ARGB);
}

void cool() {
  cooling.loadPixels();
  float xoff = 0.0; // Start xoff at 0
  float increment = 0.02;
  // For every x,y coordinate in a 2D space, calculate a noise value and produce a brightness value
  for (int x = 0; x < w; x++) {
    xoff += increment; // Increment xoff
    float yoff = ystart; // For every xoff, start yoff at 0
    for (int y = 0; y < h; y++) {
      yoff += increment; // Increment yoff

      // Calculate noise and scale by 255
      float n = noise(xoff, yoff);
      int bright = (int)(pow(n, 3) * 255);

      // Try using this line instead
      //float bright = random(0,255);

      // Set each pixel onscreen to a grayscale value
      int index = (x + y * w);
      cooling.pixels[index] = color(bright, bright, bright, 255);
    }
  }

  cooling.updatePixels();
  ystart += increment;
}

void fire(int rows) {
  buffer1.loadPixels();
  for (int x = 0; x < w; x++) {
    for (int j = 0; j < rows; j++) {
      int y = h - (j + 1);
      int index = (x + y * w);
      buffer1.pixels[index] = color(255, 255, 255, 255);
    }
  }
  buffer1.updatePixels();
}

void draw() {
  fire(2);
  cool();
  background(0);
  buffer1.loadPixels();
  buffer2.loadPixels();
  for (int x = 1; x < w - 1; x++) {
    for (int y = 1; y < h - 1; y++) {
      int index0 = (x + y * w); // x, y
      int index1 = (x + 1 + y * w); // (x + 1), y
      int index2 = (x - 1 + y * w); // (x - 1), y
      int index3 = (x + (y + 1) * w); // x, (y + 1)
      int index4 = (x + (y - 1) * w); // x, (y - 1)

      // Because we are using only gray colors, the value of the color
      // components are the same, and we can use that as brightness.
      int c1 = buffer1.pixels[index1] & 0xff;
      int c2 = buffer1.pixels[index2] & 0xff;
      int c3 = buffer1.pixels[index3] & 0xff;
      int c4 = buffer1.pixels[index4] & 0xff;
      int c5 = cooling.pixels[index0] & 0xff;

      int newC = c1 + c2 + c3 + c4;
      newC = (int)(newC * 0.25 - c5);

      buffer2.pixels[index4] = color(newC, newC, newC, 255);
    }
  }
  buffer2.updatePixels();

  // Swap
  var temp = buffer1;
  buffer1 = buffer2;
  buffer2 = temp;

  image(buffer2, 0, 0);
  image(cooling, w, 0);
}
