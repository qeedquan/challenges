/*

In trigonometry, there are certain angles known as "special angles". This is because when you take sin, cos or tan of one of these angles, you get a result that is easy to remember because it is a square root of a rational number. These special angles are always multiples of either pi/6, or pi/4. Here is a visualization of all the special angles, and their corresponding trig values.

https://i.stack.imgur.com/aLeMP.gif

As you can see, for each angle their is a corresponding pair of numbers. The first number is cosine of that angle, and the second is sine of that angle. To find tangent of one of these angles, just divide sin by cos. For example, tan(pi/6) is equal to

sin(pi/6) / cos(pi/6) ==
(1/2) / (√3/2) ==
1/√3 ==
√3/3
The Challenge
You must write a full program that takes 3 inputs.

A single char representing the trig function you're supposed to calculate. This will be either 's' (sin), 'c' (cos), or 't' (tan).

The numerator of the input angle. This can be any positive integer. Note that an input of 5 means the numerator is 5 * pi.

The denominator of the input angle. This will always be one of the following: 1, 2, 3, 4, 6

Then print out the exact value the trig function of that angle. Here is a list of sin, cos, and tan of all angles up to 2 * pi:

sin(0pi):    0
sin(pi/6):   1/2
sin(pi/4):   root(2)/2
sin(pi/3):   root(3)/2
sin(pi/2):   1
sin(2pi/3):  root(3)/2
sin(3pi/4):  root(2)/2
sin(5pi/6):  1/2
sin(1pi):    0
sin(7pi/6):  -1/2
sin(5pi/4):  -root(2)/2
sin(4pi/3):  -root(3)/2
sin(3pi/2):  -1
sin(5pi/3):  -root(3)/2
sin(7pi/4):  -root(2)/2
sin(11pi/6): -1/2
sin(2pi):    0

cos(0pi):    1
cos(pi/6):   root(3)/2
cos(pi/4):   root(2)/2
cos(pi/3):   1/2
cos(pi/2):   0
cos(2pi/3):  -1/2
cos(3pi/4):  -root(2)/2
cos(5pi/6):  -root(3)/2
cos(1pi):    -1
cos(7pi/6):  -root(3)/2
cos(5pi/4):  -root(2)/2
cos(4pi/3):  -1/2
cos(3pi/2):  0
cos(5pi/3):  1/2
cos(7pi/4):  root(2)/2
cos(11pi/6): root(3)/2
cos(2pi):    1

tan(0pi):    0
tan(pi/6):   root(3)/3
tan(pi/4):   1
tan(pi/3):   root(3)
tan(pi/2):   nan
tan(2pi/3):  -root(3)
tan(3pi/4):  -1
tan(5pi/6):  -root(3)/3
tan(1pi):    0
tan(7pi/6):  root(3)/3
tan(5pi/4):  1
tan(4pi/3):  root(3)
tan(3pi/2):  nan
tan(5pi/3):  -root(3)
tan(7pi/4):  -1
tan(11pi/6): -root(3)/3
tan(2pi):    0
If you get a number larger than 2pi, subtract 2pi from it until you get a number that is in range. For example, sin(17pi/6) is the same as sin(5pi/6) == 1/2. Your program is expected to do basic simplification, for example, if your input is cos(2pi/4) this is the same as cos(pi/2) == 0. Builtin trigonometry functions are disallowed.

Shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

const char *
sct(const char *f, int n, int d)
{
	static const int fraction[][2] = {{0, 1}, {1, 6}, {1, 4}, {1, 3}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {1, 1}, {7, 6}, {5, 4}, {4, 3}, {3, 2}, {5, 3}, {7, 4}, {11, 6}, {2, 1}};
	static const char *sine[] = {"0", "1/2", "root(2)/2", "root(3)/2", "1", "root(3)/2", "root(2)/2", "1/2", "0", "-1/2", "-root(2)/2", "-root(3)/2", "-1", "-root(3)/2", "-root(2)/2", "-1/2", "0"};
	static const char *cosine[] = {"1", "root(3)/2", "root(2)/2", "1/2", "0", "-1/2", "-root(2)/2", "-root(3)/2", "-1", "-root(3)/2", "-root(2)/2", "-1/2", "0", "1/2", "root(2)/2", "root(3)/2", "1"};
	static const char *tangent[] = {"0", "root(3)/3", "1", "root(3)", "nan", "-root(3)", "-1", "-root(3)/3", "0", "root(3)/3", "1", "root(3)", "nan", "-root(3)", "-1", "-root(3)/3", "0"};

	const char **func;
	size_t i;
	int m;

	if (!strcmp(f, "sin"))
		func = sine;
	else if (!strcmp(f, "cos"))
		func = cosine;
	else if (!strcmp(f, "tan"))
		func = tangent;
	else
		return NULL;

	m = gcd(n, d);
	n /= m;
	d /= m;
	for (i = 0; i < nelem(fraction); i++) {
		if (n == fraction[i][0] && d == fraction[i][1])
			return func[i];
	}

	return NULL;
}

void
test(const char *f, int n, int d, const char *r)
{
	const char *s;

	s = sct(f, n, d);
	printf("%s\n", s);
	assert(!strcmp(s, r));
}

int
main(void)
{
	test("sin", 0, 23, "0");
	test("tan", 2, 1, "0");
	test("cos", 11, 6, "root(3)/2");
	test("sin", 5, 4, "-root(2)/2");

	return 0;
}
