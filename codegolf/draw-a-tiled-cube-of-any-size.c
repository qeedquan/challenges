/*

Draw a tiled cube of any size, in ASCII art.

You will be given three numbers a, b and c, and the program should output an a*b*c sized cube.

Examples

3 3 3 ->

    ____ ____ ____
  /____/____/____/|
 /____/____/____/||
/____/____/____/|||
|____|____|____|||/
|____|____|____||/
|____|____|____|/

5 2 3 ->

    ____ ____ ____ ____ ____
  /____/____/____/____/____/|
 /____/____/____/____/____/||
/____/____/____/____/____/||/
|____|____|____|____|____||/
|____|____|____|____|____|/

4 6 5 ->

      ____ ____ ____ ____
    /____/____/____/____/|
   /____/____/____/____/||
  /____/____/____/____/|||
 /____/____/____/____/||||
/____/____/____/____/|||||
|____|____|____|____||||||
|____|____|____|____|||||/
|____|____|____|____||||/
|____|____|____|____|||/
|____|____|____|____||/
|____|____|____|____|/

Shortest code wins.

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
line(int x, int y)
{
	static const char sym[] = " |/_\n";

	int i;

	for (i = 0; i < x; i++)
		putchar(sym[y]);
}

int
yjz(int j, int z)
{
	if (!j)
		return 0;
	if (j > z)
		return 1;
	return 2;
}

void
cube(int x, int y, int z)
{
	int i, j;

	printf("x=%d y=%d z=%d\n", x, y, z);
	for (i = j = 0; j <= y + z; j++) {
		line(z - j, 0);
		for (i = x;; i--) {
			line(1, yjz(j, z));
			if (!i)
				break;
			line(4, 3);
		}

		i = y + z - j;
		i = min(i, j);
		i = min(i, z);
		i = min(i, y);
		line(i, 1);
		if (j > y)
			line(1, 2);
		line(1, 4);
	}
	printf("\n");
}

int
main()
{
	cube(3, 3, 3);
	cube(5, 2, 3);
	cube(4, 6, 5);
	cube(1, 1, 1);
	cube(10, 10, 10);

	return 0;
}
