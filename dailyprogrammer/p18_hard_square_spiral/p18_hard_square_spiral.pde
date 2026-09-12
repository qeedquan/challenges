/*

Write a program that draws a square spiral. You can print out this spiral in ASCII text, but using a graphics library would produce a more pleasant output.
https://www.deviantart.com/10binary/art/square-spiral-203786602

Bonus: Now draw a normal spiral. Some samples of spirals can be found here.
https://www.google.com/search?hl=en&source=hp&biw=1920&bih=987&q=spiral&gbv=2&oq=spiral&udm=2

*/

int SIZE = 16;

void setup() {
  size(800, 800);
}

void draw() {
  background(255);
  push();
  translate(-width/2, -height/2);
  fill(0);
  spiral(width/8);
  pop();
}

void spiral(int max) {
  int x = 0;
  int y = 0;
  for (int i = max; i > 0; i -= 2) {
    horizontal(x, y, i);
    vertical(i-1, y+1, i);
    horizontal(x+1, i-1, i-1);
    vertical(x+1, y+2, i-1);
    x += 2;
    y += 2;
  }
}

void horizontal(int x0, int y, int x1) {
  for (int x = x0; x < x1; x++) {
    rect(x*SIZE, y*SIZE, SIZE, SIZE);
  }
}

void vertical(int x, int y0, int y1) {
  for (int y = y0; y < y1; y++) {
    rect(x*SIZE, y*SIZE, SIZE, SIZE);
  }
}
