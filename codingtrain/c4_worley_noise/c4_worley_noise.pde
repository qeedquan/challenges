/*

https://en.wikipedia.org/wiki/Worley_noise

*/

PVector[] points;
float[]   distances;

void setup() {
  size(128, 128);
  pixelDensity(1);
  reset();
}

void reset() {
  points = new PVector[20];
  distances = new float[points.length];
  for (int i = 0; i < points.length; i++) {
    points[i] = new PVector(random(width), random(height), random(width));
  }
}

void draw() {
  loadPixels();
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {    
      for (int i = 0; i < points.length; i++) {
        PVector v = points[i];
        int     z = frameCount % width;
        float   d = dist(x, y, z, v.x, v.y, v.z);
        distances[i] = d;
      }
      var sorted = sort(distances);
      float r = map(sorted[0], 0, 150, 0, 255);
      float g = map(sorted[1], 0, 50, 255, 0);
      float b = map(sorted[2], 0, 200, 255, 0);
      int index = x + y*width;
      pixels[index] = color(r, g, b, 255);
    }
  }
  updatePixels();
}
