% I noticed that it seems nobody has posted a non-ASCII (related) USA flag challenge yet, so what better time than the 4th of July?
%
% The Challenge
% Draw the current (as of 2022) flag of the United States of America. Here is the flag:
% https://upload.wikimedia.org/wikipedia/en/a/a4/Flag_of_the_United_States.svg
% Specifications
% https://upload.wikimedia.org/wikipedia/commons/a/ab/Flag_of_the_United_States_specification.svg
% Hoist (height) of the flag: A = 1.0
% Fly (width) of the flag: B = 1.9
% Hoist (height) of the canton ("union"): C = 0.5385 (A × 7/13, spanning seven stripes)
% Fly (width) of the canton: D = 0.76 (B × 2/5, two-fifths of the flag width)
% E = F = 0.0538 (C/10, one-tenth of the height of the canton)
% G = H = 0.0633 (D/12, one twelfth of the width of the canton)
% Diameter of star: K = 0.0616 (L × 4/5, four-fifths of the stripe width, the calculation only gives 0.0616 if L is first rounded to 0.077)
% Width of stripe: L = 0.0769 (A/13, one thirteenth of the flag height)
% The colors used are (as RGB tuples and hex codes):
%
% White: 255,255,255 or #FFFFFF;
% Old Glory Red: 179,25,66 or #B31942;
% Old Glory Blue: 10,49,97 or #0A3161.
% Source: Wikipedia
%
% Rules
% The image must be sized at a 19:10 ratio, and at least 760 by 400 pixels (if it is a raster image).
% If your language does not allow to use arbitrary RGB colors you may use any colors reasonably recognizable as "white", "red", and "blue".
% The image can be saved to a file or piped raw to STDOUT in any common image file format, or it can be displayed in a window.
% Your program must create the image and not just load it from a website.
% Built-in flag images, flag-drawing libraries, horrendously upscaling a flag emoji or any other emoji are prohibited.
% Scoring
% This is code-golf, so shortest code wins!
%
% Since the flag can change at any time following the admission of one or more new states, let's make our programs futureproof! -10 bonus points if your program can draw other star dispositions by accepting as an optional argument a list of star coordinates (which may be a number different than 50) in any coordinate system of your choice (inspired by this challenge).
%
% If such optional argument is not provided, your program must draw the flag as previously described.
% If an empty list is passed as a parameter, you can either draw no stars, or treat it as if no argument has been given (and hence draw the standard flag).
% The other parts of the flag (the stripes and the blue background) must be the same in any case.


% ported from @bartyslartfast solution

/star { 
	gsave 
	8.23 mul exch 7 mul 60 add
	translate
	0 4 moveto 4
	{
		144 rotate 0 4 lineto
	} repeat
	fill
	grestore
} def

<0a3161b31942> { 255 div } forall 

setrgbcolor 0 20 120
{ 0 exch 247 10 rectfill } for
setrgbcolor 0 60 98.8 70
rectfill 1
setgray
count 0 eq

{
	1 1 2 {
		/i exch def i 2 11 {
			i 2 9 {
				1 index star
			} for
		} for
	} for
}

{
	{
		{ star } loop
	} stopped
} ifelse

