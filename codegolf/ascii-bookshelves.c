/*

You know those stackable shelves that are basically just wooden boxes that can be stacked together? We're going to simulate building some bookshelves out of those with some ASCII art.

Our books are all conveniently uniform in size, and all look like the following:

|X|
|X|
|X|
The bookshelves are individual boxes, always three characters high on the inside (enough to fit a book standing upright), composed of | characters on the left and right, - characters for the top and bottom, and wide enough to fit X books (where X is an input integer). For example, here's a bookshelf of size 3:

|---------|
|         |
|         |
|         |
|---------|
because you can fit 3 books into it like so

|---------|
||X||X||X||
||X||X||X||
||X||X||X||
|---------|
The input is going to be two strictly positive integers, X and Y, where X is the width of the shelves we have (measured in books), and Y is how many books we have to stack. If we have more books than fit on a single shelf, we need to add more shelves to the top. For example, here is input 4 wide / 6 books:

|------------|
||X||X|      |
||X||X|      |
||X||X|      |
|------------|
|------------|
||X||X||X||X||
||X||X||X||X||
||X||X||X||X||
|------------|
If Y % X > 0, meaning the number of books is not an integer multiple of the shelf size, the remainder books should go on the top-most left-most position (as in the case with 4 6, above) and the remaining part of that shelf filled in with spaces.

Input
Two strictly positive integers in any convenient format, each >0.
You can take the input in either order (e.g., size of shelves first, then number of books, or vice versa). Please state in your submission the input order.
You can safely assume that neither input will be larger than your language's default [int] size (or equivalent).
Output
The resulting ASCII art representation of the books and bookshelves.

Rules
Leading or trailing newlines or whitespace are all optional, so long as the characters themselves line up correctly.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.
Further Examples
6 wide / 2 books
|------------------|
||X||X|            |
||X||X|            |
||X||X|            |
|------------------|

2 wide / 6 books
|------|
||X||X||
||X||X||
||X||X||
|------|
|------|
||X||X||
||X||X||
||X||X||
|------|
|------|
||X||X||
||X||X||
||X||X||
|------|

4 wide / 9 books
|------------|
||X|         |
||X|         |
||X|         |
|------------|
|------------|
||X||X||X||X||
||X||X||X||X||
||X||X||X||X||
|------------|
|------------|
||X||X||X||X||
||X||X||X||X||
||X||X||X||X||
|------------|

*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
bookshelves(int X, int Y)
{
	int R;
	int i;

	printf("%d wide / %d books\n", X, Y);
	if (X < 1)
		return;

	for (; Y > 0; Y -= R) {
		R = Y % X;
		if (R == 0)
			R = X;

		putchar('|');
		repeat("---", X);
		puts("|");

		for (i = 0; i < 3; i++) {
			putchar('|');
			repeat("|X|", R);
			repeat("   ", X - R);
			puts("|");
		}

		putchar('|');
		repeat("---", X);
		puts("|");
	}
	puts("");
}

int
main()
{
	bookshelves(6, 2);
	bookshelves(2, 6);
	bookshelves(4, 9);
	bookshelves(10, 10);

	return 0;
}
