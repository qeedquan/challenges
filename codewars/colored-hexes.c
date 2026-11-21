/*

You're looking through different hex codes, and having trouble telling the difference between
http://www.colorhexa.com/000001 #000001
http://www.colorhexa.com/100000 #100000

We need a way to tell which is red, and which is blue!

That's where you create  __hex color__ !!!

It should read an RGB input, and return whichever value (red, blue, or green) is of greatest concentration!

But, if multiple colors are of equal concentration, you should return their mix!

red + blue = magenta

green + red = yellow

blue + green = cyan

red + blue + green = white


One last thing, if the string given is empty, or has all 0's, return black!

Examples:

codes = "087 255 054" -> "green"
codes = "181 181 170" -> "yellow"
codes = "000 000 000" -> "black"
codes = "001 001 001" -> "white"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

const char *
hexcolor(const char *s)
{
	int c, r, g, b;

	if (!s[0])
		return "black";
	if (sscanf(s, "%d %d %d", &r, &g, &b) != 3)
		return NULL;

	if (r == 0 && g == 0 && b == 0)
		return "black";
	if (r == g && g == b)
		return "white";

	c = max(r, max(g, b));
	if (r == c && b == c)
		return "magenta";
	if (r == c && r == g)
		return "yellow";
	if (b == c && g == c)
		return "cyan";

	if (r == c)
		return "red";
	if (g == c)
		return "green";
	return "blue";
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = hexcolor(s);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	test("", "black");
	test("000 000 000", "black");
	test("121 245 255", "blue");
	test("027 100 100", "cyan");
	test("021 021 021", "white");
	test("255 000 000", "red");
	test("000 147 000", "green");
	test("212 103 212", "magenta");
	test("101 101 092", "yellow");

	return 0;
}
