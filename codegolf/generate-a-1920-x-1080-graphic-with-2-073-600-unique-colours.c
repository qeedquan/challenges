/*

Challenge:

Write a program that outputs a graphic file 1920 pixels wide by 1080 pixels high. Every one of the 2,073,600 pixels within the graphic must be a unique colour and no colour values should be repeated. The colours should be specified in RGB and start at 0,0,0 and count upwards in sequence towards 255,255,255. You'll find a 1920 x 1080 pixel image will contain lots of blacks, blues and greens only.

For example, (a smaller cut down version). If the height was set to 5 and the width was set to 5 a 25 pixel square graphic would be output and each pixel would be a unique colour. The RGB colour array would look like this:

Array (
[0] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 0
    )

[1] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 1
    )

[2] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 2
    )

[3] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 3
    )

[4] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 4
    )

[5] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 5
    )

[6] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 6
    )

[7] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 7
    )

[8] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 8
    )

[9] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 9
    )

[10] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 10
    )

[11] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 11
    )

[12] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 12
    )

[13] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 13
    )

[14] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 14
    )

[15] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 15
    )

[16] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 16
    )

[17] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 17
    )

[18] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 18
    )

[19] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 19
    )

[20] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 20
    )

[21] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 21
    )

[22] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 22
    )

[23] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 23
    )

[24] => Array
    (
        [0] => 0
        [1] => 0
        [2] => 24
    )

)
Rules:

Any programming language can be used to generate the image.

The answer with the most upvotes wins.

Colours must only be used once.

Pixel in position 0,0 must start with colour 0,0,0

Colours must fall within the true color 24 bit range.

Image must be 1920 x 1080 pixels in size.

Colours must be in RGB format.

Using a library to output the image is ok.

Output must be in the format of a graphic file e.g. output.png

Output as text which represents the colour values doesn't count, the code must output a graphic file.

File size of the output image doesn't matter.

You must be able to view the output by opening it as a graphic in the chrome web browser.

I would be impressed if you mange to do this with really short code, your program also outputs the time in elapsed seconds taken to generate the image embedded within the image itself overlaid on the sequential pixels, your program outputs the image within 10 seconds. I would be really impressed if your program outputs the image within 1 second.

*/

#include <stdio.h>

void
gen(void)
{
	unsigned x, y, w, h, c;

	w = 1920;
	h = 1080;

	printf("P3\n");
	printf("%d %d\n", w, h);
	printf("255\n");
	for (c = y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			printf("%3d %3d %3d\t", (c >> 16) & 0xff, (c >> 8) & 0xff, (c & 0xff));
			c++;
		}
		printf("\n");
	}
}

int
main(void)
{
	gen();
	return 0;
}
