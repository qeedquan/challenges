/*

This happy individual is known in folklore as the Easter Bunny.

https://i.sstatic.net/U75Ab.png

Colours
It is created using 4 colours:

Light pink
Dark pink
White
Black
(I'm happy for these colours to be approximated in your answer. It does not need to be this precise shade)

Shapes
It is constructed of these shapes:

Two tall ellipses in light pink (outer ears). They have the same height and width.
Two tall ellipses in dark pink (inner ears). They are smaller than the outer ears and one is drawn on top of each of the outer ears. They are the same height and width.
One large circle in light pink (head). It intersects with the bottom third of both outer ears (but no higher).
Two circles in white (outer eyes). They are drawn on the head. Their diameter is less than the width of the outer ears. They have the same horizontal position as the outer ears.
Two circles in black (inner eyes). They have a smaller diameter than the outer eyes. One is drawn on each of the outer eyes.
One vertical line in black (upper mouth). It is drawn on the head and is lower than the bottom of the outer eyes. It is roughly equidistant from each eye.
Two arcs in black (lower mouth). They are drawn on the head and arc downwards from a horizontal line. Both intersect with the bottom of the upper mouth, but one goes right and the other goes left.
The Rules
Use any language and tools you like.
Output can be an image, html, svg, or other markup.
It's code golf, so aim to do it in the smallest number of bytes.
Please include a screenshot of the result.
Please feel free to approximate the colours defined.
Happy Easter!

*/

void draw() {
  background(150);
  bunny();
}

// ported from @Robert S. solution
void bunny() {
  int b = 50, c = 60, g = 70;
  noStroke();
  
  // Face
  fill(#FFCCCC);
  ellipse(b, g, c, c);
  
  // Outer ears
  ellipse(40, 25, 15, b);
  ellipse(c, 25, 15, b);
  
  // Inner ears
  fill(#FF9999);
  ellipse(40, 25, 7, 30);
  ellipse(c, 25, 7, 30);
  
  // Outer eyes
  fill(-1);
  ellipse(40, g, 10, 10);
  ellipse(c, g, 10, 10);
  
  // Inner eyes
  fill(0);
  ellipse(40, g, 5, 5);
  ellipse(c, g, 5, 5);
  
  // Mouth
  stroke(0);
  line(b, 80, b, 85);
  noFill();
  arc(53, 85, 5, 5, 0, PI);
  arc(48, 85, 5, 5, 0, PI);
}
