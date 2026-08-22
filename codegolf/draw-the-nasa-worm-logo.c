/*

Introduction

On 30 May 2020, NASA and SpaceX launched a crewed rocket to the international space station on the SpaceX Demo 2 mission. This is the first time humans have been launched into orbit from American soil since the retiring of the Space Shuttle in 2011, and the first time ever that a private company has launched astronauts into orbit. The rocket bore the iconic NASA worm logo, the first time this logo has been used since 1992. Let's celebrate NASA and SpaceX's achievement by drawing the worm logo.

I looked on the internet for a specification of this logo. The best I could find was on Reddit. However there are a number of issues with this version. For example the thickness of vertical and curved lines is defined as 1 but for horizontal lines it is 0.95 and there is no specification of how to transition between the two thicknesses.

Challenge

Draw the simplified version of the NASA worm logo defined in the SVG below.

Some notes on the design:

All parts of the worm are 100 units wide.
All diagonal lines have a slope of 24/7. This takes advantage of the pythagorean triple 24^2 + 7^2 = 25^2 to ensure accurate and consistent positions of the thickness of the worm and the beginnings and endings of arcs while using only integer coordinates.
As the vertical height of the arms of the A's are not multiples of 24, the x coordinates of the bottoms of the A are not integers, but they are integer multiples of 1/6.
The S is 500 units high, from y=100 to y=600. The curved parts of the S have internal and external radii of 50 and 150.
The internal and internal radii of the curved parts of the N and A's are 25 and 125. The y coordinates of the centres of these arcs are y=215 and y=485. This means that the tops and bottoms of the arcs extend above and below the top and bottom of the S, specifically to y=90 and y=610. This is similar to the official logo.
The ends of the N terminate at y=100 and y=600. Similarly, the ends of the A's terminate at y=600.
There is an overlap region between the first A and the S. The length of the upper and lower arms of the S is chosen to be 231.67 units so that this overlap region is triangular. The top of the lower arm of the S meets the A at 1043.33,600
In addition to the SVG script, A PNG image (not perfectly to scale) is given with annotations of the coordinates of all parts of the logo: all four coordinates of each straight section and the centre and radius of each curved section. Note that because of the way SVG defines arcs, the coordinates of the centres of the curved sections do not appear in the SVG script. Curved sections are shown in black and straight sections are shown in red, with the exception of the lower arm of the S, which is shown in blue to distinguish it from the part of the A which it overlaps.

PNG

https://i.sstatic.net/Q8A46.png

SVG

<svg xmlns="http://www.w3.org/2000/svg" viewbox=0,0,2000,700>

<path fill="red" d="M110,600 L110,215 A125,125,0,0,1,355,180 L446,492 A25,25,0,0,0,495,485 L495,100 L595,100 L595,485 A125,125,0,0,1,350,520 L259,208 A25,25,0,0,0,210,215 L210,600"/>

<path fill="red" d="M587.5,600 L710,180 A125,125,0,0,1,950,180 L1072.5,600 L968.33,600 L854,208 A25,25,0,0,0,806,208 L691.67,600" />

<path fill="red" d="M1043.33,500 L1275,500 A50,50,0,0,0,1275,400 L1175,400 A150,150,0,0,1,1175,100 L1406.67,100 L1406.67,200 L1175,200 A50,50,0,0,0,1175,300 L1275,300 A150,150,0,0,1,1275,600 L1043.33,600"/>

<path fill="red" d="M1407.5,600 L1530,180 A125,125,0,0,1,1770,180 L1892.5,600 L1788.33,600 L1674,208 A25,25,0,0,0,1626,208 L1511.67,600" />

</svg>

Rules

The logo shall be in a single arbitrary colour on a distinctly coloured background.

The accuracy of the logo shall be within +/- 2 units of the specification given in this question.

It is not essential to use the coordinate system used in the specification given in this question. The logo may be rescaled, and different amounts of whitespace may be added above, below, left and right, so long as the logo can be visualized easily with free and easily available software. The logo may not be rotated.

The logo may be drawn filled, or as an outline. The first A and the S overlap slightly. If drawn as an outline, it is preferred that the lines at the overlap of these two letters are omitted, so that the A and S form a single continuous outline. It is however permitted to include the complete outline of the A and/or the complete outline of the S, with the shape specified in the PNG and SVG in the question. No other extraneous lines are permitted.

Any pre-existing graphics format is acceptable provided it can be viewed with free and easily available software. Any means of output accepted by standard rules on this site is acceptable, inlcuding viewing on the screen, output to a file, or (if applicable) as a returned value from a function call. Please Include instructions on how to view your output in your answer. Your program or function should take no input.

It is not acceptable to use a font with letters of the correct or similar shape to print "NASA", with or without modification. (In practice this is unlikely to be an issue, because although there are similar fonts, I think it's very unlikely that the letters match the proportions specified in this question.)

This is codegolf. Shortest code wins.

*/

#include <stdio.h>

void
worm()
{
	puts("<svg xmlns=\"http://www.w3.org/2000/svg\" viewbox=\"0,0,2000,700\">\"");
	puts("<path fill=\"red\" d=\"M110,600 L110,215 A125,125,0,0,1,355,180 L446,492 A25,25,0,0,0,495,485 L495,100 L595,100 L595,485 A125,125,0,0,1,350,520 L259,208 A25,25,0,0,0,210,215 L210,600\" />");
	puts("<path fill=\"red\" d=\"M587.5,600 L710,180 A125,125,0,0,1,950,180 L1072.5,600 L968.33,600 L854,208 A25,25,0,0,0,806,208 L691.67,600\" />");
	puts("<path fill=\"red\" d=\"M1043.33,500 L1275,500 A50,50,0,0,0,1275,400 L1175,400 A150,150,0,0,1,1175,100 L1406.67,100 L1406.67,200 L1175,200 A50,50,0,0,0,1175,300 L1275,300 A150,150,0,0,1,1275,600 L1043.33,600\" />");
	puts("<path fill=\"red\" d=\"M1407.5,600 L1530,180 A125,125,0,0,1,1770,180 L1892.5,600 L1788.33,600 L1674,208 A25,25,0,0,0,1626,208 L1511.67,600\" />");
	puts("</svg>");
}

int
main()
{
	worm();
	return 0;
}
