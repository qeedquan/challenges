/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version

Task:
Summer is coming, John has some watermelon to eat. When he eats a piece of watermelon into his mouth, if there are more than 5 watermelon seeds, John spit them out; if not, John will swallow them down.

Give you a parameter watermelon(2D number array, 8x8), 0 is the watermelon flesh, 1 is the watermelon seed.

1,0,0,1,1,1,0,1
1,0,1,0,1,1,0,0
1,1,1,1,0,0,0,0
0,1,0,1,1,1,1,0
0,0,0,1,0,1,0,0
1,1,1,0,0,0,1,1
1,0,1,1,0,0,0,0
0,0,0,0,0,0,0,0
```
John eats 1/4 every time(4x4 matrix)...

```
1,0,0,1,1,1,0,1      x,x,x,x,1,1,0,1      x,x,x,x,x,x,x,x
1,0,1,0,1,1,0,0      x,x,x,x,1,1,0,0      x,x,x,x,x,x,x,x
1,1,1,1,0,0,0,0      x,x,x,x,0,0,0,0      x,x,x,x,x,x,x,x
0,1,0,1,1,1,1,0      x,x,x,x,1,1,1,0      x,x,x,x,x,x,x,x
0,0,0,1,0,1,0,0  ==> 0,0,0,1,0,1,0,0  ==> 0,0,0,1,0,1,0,0
1,1,1,0,0,0,1,1      1,1,1,0,0,0,1,1      1,1,1,0,0,0,1,1
1,0,1,1,0,0,0,0      1,0,1,1,0,0,0,0      1,0,1,1,0,0,0,0
0,0,0,0,0,0,0,0      0,0,0,0,0,0,0,0      0,0,0,0,0,0,0,0

                     x,x,x,x,x,x,x,x      x,x,x,x,x,x,x,x
                     x,x,x,x,x,x,x,x      x,x,x,x,x,x,x,x
                     x,x,x,x,x,x,x,x      x,x,x,x,x,x,x,x
                     x,x,x,x,x,x,x,x      x,x,x,x,x,x,x,x
                 ==> x,x,x,x,0,1,0,0  ==> x,x,x,x,x,x,x,x
                     x,x,x,x,0,0,1,1      x,x,x,x,x,x,x,x
                     x,x,x,x,0,0,0,0      x,x,x,x,x,x,x,x
                     x,x,x,x,0,0,0,0      x,x,x,x,x,x,x,x

```
Return a number that John spit out how much the watermelon seeds.

Example:
```
In accordance with the above example, John spit out:
10(1st eat)+8(2nd eat)+7(3rd eat)+0(4th eat)=25
So, sc(watermelon) should return 25

Another example:
watermelon=[
[0,1,0,0,0,0,1,0],
[0,0,1,0,1,0,0,0],
[0,1,1,0,1,0,0,0],
[0,0,0,0,0,0,0,0],
[1,0,0,0,0,0,1,0],
[0,0,1,0,1,0,1,0],
[0,1,0,1,1,0,0,0],
[0,1,0,0,0,0,0,1]]
John spit out: 0(1st eat)+0(2nd eat)+0(3rd eat)+0(4th eat)=0
So, sc(watermelon) should return 0
(John swallowed all the watermelon seeds)

*/

#include <assert.h>
#include <string.h>

int
sc(int w[8][8])
{
	int c[4];
	int i, j;
	int r;

	memset(c, 0, sizeof(c));
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (!w[i][j])
				continue;

			if (i < 4 && j < 4)
				c[0] += 1;
			else if (i < 4 && j > 3)
				c[1] += 1;
			else if (i > 3 && j > 3)
				c[2] += 1;
			else
				c[3] += 1;
		}
	}

	for (r = i = 0; i < 4; i++) {
		if (c[i] > 5)
			r += c[i];
	}
	return r;
}

int
main()
{
	int w1[8][8] = {
		{ 1, 0, 0, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 1, 1 },
		{ 1, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },

	};

	int w2[8][8] = {
		{ 0, 1, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 1 }
	};

	assert(sc(w1) == 25);
	assert(sc(w2) == 0);

	return 0;
}
