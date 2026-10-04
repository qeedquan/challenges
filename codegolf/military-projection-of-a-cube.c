/*

A military projection is a projection where all lengths and the angles in the X-Z plane remain unattuned.

Your task is to print a cube in military projection using /, |, \, -, and any whitespaces you want, given any integer greater than zero as it's side length. You can leave sides out that are not visible to the human eye. Here are some examples:

  /-\
 /   \
|\   /| Side length:
| \ / | 2
 \ | /
  \|/

     /-\
    /   \
   /     \
  /       \
 /         \
|\         /|
| \       / | Side length:
|  \     /  |
|   \   /   | 5
|    \ /    |
 \    |    /
  \   |   /
   \  |  /
    \ | /
     \|/

 /-\  Side length:
|\ /|
 \|/  1
(Printing the side lengths is not required.)

For the uppermost corner you must use the dash. As you can see, all sides are equal in length (when measured in characters). You may use any kind of spacing you wish, and omit any characters that don't change the appearance of the cube.

This is code-golf, so the shortest answer in bytes wins!

*/

#include <stdio.h>
#include <stdarg.h>

void
outf(const char *fmt, ...)
{
	va_list ap;
	int i, n;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case ' ':
			n = va_arg(ap, int);
			for (i = 0; i < n; i++)
				putchar(' ');
			break;

		default:
			putchar(*fmt);
			break;
		}
	}
	va_end(ap);
	putchar('\n');
}

// Ported from @Koishore Roy solution
void
cube(int n)
{
	int i, s, w;

	printf("n=%d\n", n);
	outf(" /-\\", n);

	s = n;
	w = 1;
	for (i = 0; i < n - 1; i++) {
		w += 2;
		s -= 1;
		outf(" / \\", s, w);
	}

	s -= 2;
	for (i = 0; i < n; i++) {
		s += 1;
		outf("| \\ / |", s, w, s);
		w -= 2;
	}

	for (i = 0; i < n; i++) {
		outf(" \\ | /", n - s, s, s);
		s -= 1;
	}

	putchar('\n');
}

int
main()
{
	cube(1);
	cube(2);
	cube(5);

	return 0;
}
