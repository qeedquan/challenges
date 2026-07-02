/*

The Penrose triangle, also known as the Penrose tribar, or the impossible tribar, is an impossible object.

The goal in this challenge is to display a Penrose triangle in the fewest bytes possible.

https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/Penrose-dreieck.svg/192px-Penrose-dreieck.svg.png

Rules:

You must display the Penrose Triangle digitally after generating it.
They must look the same as the above image of the wiki page (source above) without directly showing the image.
The same image with the same color scheme must be shown in at least 400x400 size.
Should be as accurate as possible.
Good luck and have fun!

*/

void setup() {
  size(402, 402);
}

void draw() {
  noStroke();

  fill(255);
  quad(171, 2, 237, 2, 401, 337, 335, 337);
  quad(335, 337, 125, 337, 156, 280, 308, 280);

  fill(125);
  quad(2, 335, 171, 2, 171, 121, 31, 401);
  quad(171, 2, 171, 121, 250, 280, 308, 280);
  
  fill(0);
  quad(171, 127, 34, 401, 127, 337, 201, 188);
  quad(34, 401, 127, 337, 401, 337, 374, 401);
}
