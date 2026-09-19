/*

We don't have a single challenge about drawing a real 3 dimensional cube, so here it goes:

Challenge
Your task is to draw a rotated, cube with perspective. It can be in a separate window or as an image.

Input
Your input is 3 separate numbers between 0 and 359.99... These represent the rotation around the x, y and z axis in degrees.

0 0 0
30 0 40
95 320 12
Output
You can either display it in a separate window or save an image. You can use any type of display (vector based, rasterized, etc.).

Edit: ASCII is allowed too, to allow golfing languages with only textual output.

The output for rasterized or ASCII graphics must be at least 50*50 (pixels for rasterization, characters for ASCII)

Additional information
The positive z axis points out from the window, the x axis is horizontal, and the y axis is vertical. Basically the OpenGL standard.

Rotations are counter-clockwise if you look at the cube in the negative direction of a specific axis, e.g looking down for the y axis.

The camera should be on the z axis at a reasonable distance from the cube in the negative z direction, the cube should be at (0;0;0). The. cube also needs to be fully visible, and take up at least 50% of the drawing frame. The camera should look in the positive z direction at the cube.

The rotations of the cube get applied in the x->y->z order.

The cube is rotated around it's center, it doesn't move.

To project a cube in 2d space, you need to divide the x and y coordinates of the cube with the distance parallel to the z-axis between the point and the camera.

Rules
Rendering libraries are allowed, but the vertices need to be defined in the code. No 3d cube model class.

Test cases
https://i.sstatic.net/bEOH3.png

*/

float ANGLES[][] = new float[][] {
  {0, 0, 0},
  {0, 30, 0},
  {30, 30, 0},
  {45, 0, 0},
  {45, 0, 45},
};

int selection;
int fontsize;

void setup() {
  size(1024, 768, P3D);
  fontsize = 24;
  textSize(fontsize);
}

void draw() {
  background(200);
  push();
  
  var angles = ANGLES[selection];
  text(String.format("Angles: %.1f %.1f %.1f", angles[0], angles[1], angles[2]), fontsize, fontsize);
  translate(width/2, height/2, 0); 

  rotateZ(radians(angles[2]));
  rotateY(radians(angles[1]));
  rotateX(radians(angles[0]));
  
  noFill();
  box(min(width, height)/4);
  pop();
}

void keyPressed() {
  if (keyCode == RIGHT) {
    selection = (selection + 1) % ANGLES.length;
  } else if (keyCode == LEFT) {
    selection -= 1;
    if (selection < 0)
      selection = ANGLES.length - 1;
  }
}
