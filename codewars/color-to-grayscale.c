/*

Grayscale colors in RGB color model are colors that have the same values for Red, Green and Blue. For example, #606060 is a grayscale color, while #FF0055 is not.

In order to correctly convert a color to grayscale, one has to use luminance Y for Red, Green and Blue components. One can calculate luminance Y through the formula introduced in the NTSC standard:

Y = 0.299 * R + 0.587 * G + 0.114 * B
This formula closely represents the average person's relative perception of the brightness of red, green, and blue light.

Given a color in 6-digit hexidecimal notation #RRGGBB in upper case, convert it to grayscale #YYYYYY. The answer should be a string representing the color code in 6-digit hexidecimal notation in upper or lower case.

Round the value of luminance Y to the closest integer.

All inputs will be valid.

*/

#include <stdio.h>
#include <math.h>

int
grayscale(const char *s)
{
	unsigned r, g, b;

	if (sscanf(s, "#%02X%02X%02X", &r, &g, &b) != 3)
		return -1;
	return round((0.299 * r) + (0.587 * g) + (0.114 * b));
}

int
main()
{
	printf("%#x\n", grayscale("#606060"));
	printf("%#x\n", grayscale("#FF0055"));
	return 0;
}
