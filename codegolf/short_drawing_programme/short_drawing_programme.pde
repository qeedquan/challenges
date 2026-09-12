/*

You just invited a liberal arts major to your house and you're telling him/her

"You know, I am a great programmer and I can do x and y and z..."

S/he quickly gets bored and asks you:

"If you really are a great programmer, can you make a programme to let me draw, I just need to draw lines on the screen by using the mouse, and selecting different colours in any manner".

Your code may import standard libraries. Your code may require the colours to be selected via the keyboard.

This is code-golf; shortest code wins.

Bullet points
The lines are drawn by moving the mouse around while pressing the left button.

Bresenham's Line Algorithm is not necessary any built-in algorithm will do the trick

If the user can change the line thickness in any way you get a * 0.8 bonus but it is not obligatory.

I guess it should be nicer to implement the line-drawing ourselves, but if you want you can import a library for that just say it in the code description.

The minimum is 5 different colours (red,green,blue,white,black). If you make them change randomly you get a penalty of *1.2. You may change them in any way you may want (both buttons and key presses are OK).

Drawing them pressing the mouse between to points or freehand would be best (i.e. as you do in paint) and gives you a bonus of *0.7 , but any other method is okay: (example) click two points and draw a line between those points?

The drawing canvas has to be 600x400

Changing the colour should change the colour only of the lines that will be drawn in the future.

Implementing a "Clear All " command is not obligatory but if you implement that you get *0.9 bonus.

*/

int     linewidth;
PVector position;

void setup(){
  size(600, 400);
  linewidth = 1;
  position = new PVector();
  background(255);
}

void draw() {
  stroke(7*linewidth % 256, 5*linewidth % 256, linewidth % 256);
  strokeWeight(linewidth % 9);
  if (keyPressed)
    linewidth++;

  if (!mousePressed) {
    position.x = mouseX;
    position.y = mouseY;
    if (position.x < 0)
      background(255);
  }
}

void mouseReleased() {
  line(position.x, position.y, mouseX, mouseY);
}
