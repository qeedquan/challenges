/*

You may have heard of the "Hacker Logo", also called the "Hacker Emblem". It looks like this:

http://3.bp.blogspot.com/_-4G7w0aTpbg/Ss6YxNNOJ6I/AAAAAAAAAXA/rSmdVWvSZqM/s400/Symbol+Hacker.jpg

This is a pattern from a mathematical simulation called the Game of Life. The glider is the simplest Life pattern that moves, and the most instantly recognizable of all Life patterns.

The challenge
The challenge is pretty simple: Display the hacker logo. This is defined as:

A 3x3 grid with a border, a white background and gray gridlines.
Five black dots arranged in the GoL glider pattern.
Nothing else.
The rules
The black dots must fill 40%-80% of their individual grid-boxes.
You will display the emblem with graphical output but no ASCII art.
The output must be at least 30x30 pixels.
The output must only have the colors gray, black and white.
Each grid-box in the grid will be the same size. The grid will be a regular 3x3 square.
You may not pull the logo from the internet or your filesystem.
Your program will display the logo on an empty screen/window. If it terminates it must do so normally.
Note that "dots" does not necessarily mean "circles". A "dot" is a single geometric shape centered in the middle of the grid-box with one surface. For example, while a circle or square will qualify as a dot, two triangles or a checkerboard will not.
The winner
As this is code-golf, the shortest answer in each language wins!

Please include a screenshot of the output of your program in your answer.

*/

void setup() {
  size(420, 420);
}

void draw() {
  background(255);
  logo();
}

void logo() {
  final int SEPERATOR = 140;
  final int RADIUS    = 120;
  final int CENTER    = SEPERATOR/2;
  
  strokeWeight(2);
  for (int i = 1; i <= 2; i++) {
    line(SEPERATOR*i, 0, SEPERATOR*i, height);
    line(0, SEPERATOR*i, width, SEPERATOR*i);
  }
  
  fill(0);
  circle(CENTER*3, CENTER, RADIUS);
  circle(CENTER*5, CENTER*3, RADIUS);
  circle(CENTER, CENTER*5, RADIUS);
  circle(CENTER*3, CENTER*5, RADIUS);
  circle(CENTER*5, CENTER*5, RADIUS);
}
