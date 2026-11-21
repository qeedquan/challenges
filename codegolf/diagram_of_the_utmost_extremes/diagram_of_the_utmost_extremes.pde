/*

The Mathematica SE question Creating the Yin Yang symbol with minimal code seems to be an out-of-the-box ready-to-go Code Golf SE question!

The following code creates the Yin Yang symbol

Graphics[{Black, Circle[{0, 0}, 1], White, 
   DiskSegment[{0, 0}, 1, {1/2 \[Pi], 3/2 \[Pi]}],
   Black, DiskSegment[{0, 0}, 1, {3/2 \[Pi], 5/2 \[Pi]}], White, 
   Disk[{0, 0.5}, 0.5],
   Black, Disk[{0, -0.5}, 0.5], Black, Disk[{0, 0.5}, 0.125],
   White, Disk[{0, -0.5}, 0.125]
   }] // Show
Knowing that 'there is always someone who can do things with less code', I wondered what the optimal way is, in Mathematica, to create the Yin Yang symbol.

Not really an urgent question to a real problem, but a challenge, a puzzle, if you like. I hope these kind of questions can still be asked here.

From my current understanding what's actually sought in this question is not the symbol for Yin and Yang which is just the complementary black and white halves of a circle, but the Taijitu or "Diagram of the Utmost Extremes" which is rotated by 90 degrees so that the circles halves are roughly left and right, and with two small circular spots are added along the vertical axis at half radius.

Answers to the meta question Default acceptable image I/O methods for image related challenges already show a high level of community acceptance; I wouldn't want to specify further.

Regular code golf; fewest bytes to generate Code Golf SE-acceptable graphics output per the meta link above.

In response to (and including recommendations from) helpful comments:

border thickness must be between 1 pixel and 4% of the overall diameter
spot diameter must be between 1/10 and 1/7 of the overall diameter
overall diameter at least 200 pixels
error 2 pixels / 1%.
Should resemble black ink on white paper as the original symbol is defined. However since some anti-aliasing uses color, use of color is not excluded as long as the image looks monochrome.
same orientation as the image specimen left side white, small dots along central vertical axis.

https://i.sstatic.net/FYtID.png

Source:

This is the Taijitu (太極圖), with black representing yin and white representing yang. It is a symbol that reflects the inescapably intertwined duality of all things in nature, a common theme in Taoism. No quality is independent of its opposite, nor so pure that it does not contain its opposite in a diminished form: these concepts are depicted by the vague division between black and white, the flowing boundary between the two, and the smaller circles within the large regions.

*/

void setup() {
  size(480, 480);
}

void yinyang() {
  // half of circle is white, other half is black
  fill(255);
  arc(width/2, height/2, width, height, PI/2, 3*PI/2);
  
  fill(0);
  arc(width/2, height/2, width, height, -PI/2, PI/2);
  
  float big_radius = 250;
  float small_radius = 50;
  
  // one white and black circle that overlaps each other to create a swirl
  noStroke();
  fill(255);
  float centerx = width/2;
  float centery = big_radius/2;  
  circle(centerx, centery, big_radius);

  fill(0);
  centery = height - big_radius/2;
  circle(centerx, centery, big_radius);

  // smaller white and black circle inside the two circles above
  fill(255);

  centery = height - big_radius/2;
  circle(centerx, centery, small_radius);
  
  fill(0);
  centery = big_radius/2 - small_radius/2;
  circle(centerx, centery, small_radius);
}

void draw() {
  background(40, 50, 60);
  push();
  yinyang();
  pop();
}
