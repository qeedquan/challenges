/*

Since 2009, Android's version code names have been confectionery-themed. Android 1.5 is Cupcake, Android 1.6 is Donut, Android 2.0 is Eclair, etc.. In fact, the version names are alphabetical!

C -> Cupcake
D -> Donut
E -> Eclair
F -> Froyo
G -> Gingerbread
H -> Honeycomb
I -> Ice Cream Sandwich
J -> Jellybean
K -> Kitkat
L -> Lollipop
M -> Marshmallow
N -> Nougat
O -> Oreo
In order:

Cupcake, Donut, Eclair, Froyo, Gingerbread, Honeycomb, Ice Cream Sandwich, Jellybean, Kitkat, Lollipop, Marshmallow, Nougat, Oreo
Challenge
Write a program/function that takes a letter from C to O and outputs its respective Android version code name.

Specifications
Standard I/O rules apply.
Standard loopholes are forbidden.
You can choose to either support lowercase input or uppercase input or even both.
The output may be in title case (Cupcake) or completely lower case (eclair). Ice cream sandwich may be capitalized however you like. (I didn't expect it to cause so much confusion...)
This challenge is not about finding the shortest approach in all languages, rather, it is about finding the shortest approach in each language.
Your code will be scored in bytes, usually in the encoding UTF-8, unless specified otherwise.
Built-in functions (Mathematica might have one :P) that compute this sequence are allowed but including a solution that doesn't rely on a built-in is encouraged.
Explanations, even for "practical" languages, are encouraged.
Test cases
These are uppercase and title case.

Input   Output

F       Froyo
I       Ice Cream Sandwich
J       Jellybean
N       Nougat
G       Gingerbread
L       Lollipop
In a few better formats:

F, I, J, N, G, L
f, i, j, n, g, l

F I J N G L
f i j n g l

*/

#include <stdio.h>
#include <ctype.h>

const char *
codename(int c)
{
	static const char *tab[] = {
	    "Cupcake",
	    "Donut",
	    "Eclair",
	    "Froyo",
	    "Gingerbread",
	    "Honeycomb",
	    "Ice Cream Sandwich",
	    "Jellybean",
	    "Kitkat",
	    "Lollipop",
	    "Marshmallow",
	    "Nougat",
	    "Oreo",
	};

	c = toupper(c);
	if ('C' <= c && c <= 'O')
		return tab[c - 'C'];
	return NULL;
}

int
main()
{
	int c;

	for (c = 'C'; c <= 'O'; c++)
		printf("%c: %s\n", c, codename(c));

	return 0;
}
