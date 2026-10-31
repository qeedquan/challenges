/*

Given two positive integers, W and H, output an ASCII-art box whose border is made of slashes (/ and \) with W "spikes" on the top and bottom edges, and H "spikes" on the left and right edges. The box's interior is filled with spaces.

A "spike" is simply two slashes coming together to form an arrow shape:

/\    \/

/      \
\      /
So the output for W = 4, H = 3 would be

/\/\/\/\
\      /
/      \
\      /
/      \
\/\/\/\/
as there are 4 spikes on the top pointing up, 4 on the bottom pointing down, 3 on the left pointing left, and 3 on the right pointing right.

Here are some other input/output pairs:

W H
[spiky slash box]

1 1
/\
\/

1 2
/\
\/
/\
\/

2 1
/\/\
\/\/

2 2
/\/\
\  /
/  \
\/\/

1 3
/\
\/
/\
\/
/\
\/

3 1
/\/\/\
\/\/\/

2 3
/\/\
\  /
/  \
\  /
/  \
\/\/

3 2
/\/\/\
\    /
/    \
\/\/\/

10 1
/\/\/\/\/\/\/\/\/\/\
\/\/\/\/\/\/\/\/\/\/

10 2
/\/\/\/\/\/\/\/\/\/\
\                  /
/                  \
\/\/\/\/\/\/\/\/\/\/

4 5
/\/\/\/\
\      /
/      \
\      /
/      \
\      /
/      \
\      /
/      \
\/\/\/\/
No lines in the output should have leading or trailing spaces. There may optionally be one trailing newline.

The shortest code in bytes wins.

*/

#include <stdio.h>

int
at(int x, int y, int w, int h)
{
	if (!(x == 0 || y == 0 || x == w - 1 || y == h - 1))
		return ' ';
	if ((x & 1) == (y & 1))
		return '/';
	return '\\';
}

void
spikybox(int w, int h)
{
	int x, y;

	printf("w=%d h=%d\n", w, h);
	w *= 2;
	h *= 2;
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			putchar(at(x, y, w, h));
		putchar('\n');
	}
	putchar('\n');
}

int
main()
{
	spikybox(1, 1);
	spikybox(1, 2);
	spikybox(2, 1);
	spikybox(2, 2);
	spikybox(1, 3);
	spikybox(3, 1);
	spikybox(2, 3);
	spikybox(3, 2);
	spikybox(10, 1);
	spikybox(10, 2);
	spikybox(4, 5);
	spikybox(4, 3);

	return 0;
}
