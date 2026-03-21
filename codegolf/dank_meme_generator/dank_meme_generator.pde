/*

I like making dank memes out of my own images. But all those so called "quick meme" sites just have too much code. I realized that the only way to make the dankest meme generator is to ask you guys at PPCG to golf one for me. So let me give you the low down on what you have to do.

Specs
Take an image as input as a file name, image object, etc. to make a meme out of.
Then take two strings for top text and bottom text (with no line breaks).
Render the text on the image in size 22pt Impact white font with 5px black outline (You can assume Impact is installed.
The text should be centered horizontally.
You can assume the text fits horizontally.
The respective texts should be 10px from the top and 8px from the bottom.
Then output the image by saving in a file, displaying, etc.
This is code-golf, so shortest code in bytes wins!
Happy Memeing!

*/

PImage meme;
String[] lines;
int fontsize;

void setup() {
  meme = loadImage("image.png");
  lines = loadStrings("input.txt");
  if (lines == null || lines.length != 2) {
    lines = new String[]{"TOP TEXT", "BOTTOM TEXT"};
  }
  size(128, 128);
  surface.setResizable(true);
  surface.setTitle("Dank Memes");
  surface.setSize(meme.width, meme.height);
  surface.setResizable(false);
  
  fontsize = 32;
  textSize(fontsize);
}

void draw() {
  image(meme, 0, 0);
  
  fill(color(255));
  textAlign(CENTER);
  text(lines[0], width/2, fontsize);
  text(lines[1], width/2, height - fontsize);
}
