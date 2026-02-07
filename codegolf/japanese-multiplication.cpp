/*

There's a visual method for multiplication that is taught to Japanese schoolchildren [citation needed] that uses lines and crossings to get the answer.

https://i.sstatic.net/ZTcST.jpg

Your task is to implement this in ASCII art. You will be given two numbers to multiply. The output should be the corresponding ASCII art made up of \, /, and X, padded with ASCII spaces.

The first number of the multiplication will use backslashes, starting from left to right. The second number will use forward slashes, once again from leftmost digit to rightmost. The output is made up of distinct diagonal line groupings. The number of lines within a grouping should be equal to the value of the digit. There should be at least one diagonal space between each grouping and there should be no spaces within the grouping.

Suppose 43 is the first number. Before extending lines and creating crossings, it will start like this:

       \
      \
     \

   \
  \
 \
\
If the second number is 61, it will look like this before extending and crossing:

/
 /
  /
   /
    /
     /

       /
Conceptually "extend" the lines, using X's for intersection points, to get the result:

       \ /
      \ X /
     \ X X /
      X X X /
   \ / X X X /
  \ X / X X X /
 \ X X / X X X
\ X X X / X X \ /
 X X X X / X \ X
/ X X X X / \ X \
 / X X X X   X \
  / X X X \ / \
   / X X \ X
    / X \ X \
     / \ X \
        X \
       / \
Example Test Cases
5 * 9

    \ /
   \ X /
  \ X X /
 \ X X X /
\ X X X X /
 X X X X X /
/ X X X X X /
 / X X X X X /
  / X X X X X /
   / X X X X X
    / X X X X \
     / X X X \
      / X X \
       / X \
        / \
16 * 27

       \ /
      \ X /
     \ X X
    \ X X \ /
   \ X X \ X /
  \ X X \ X X /
   X X \ X X X /
\ / X \ X X X X /
 X / \ X X X X X /
/ X   X X X X X X /
 / \ / X X X X X X
    X / X X X X X \
   / X / X X X X \
    / X / X X X \
     / X / X X \
      / X / X \
       / X / \
        / X
         / \
7 * 24

      \ /
     \ X /
    \ X X
   \ X X \ /
  \ X X \ X /
 \ X X \ X X /
\ X X \ X X X /
 X X \ X X X X
/ X \ X X X X \
 / \ X X X X \
    X X X X \
   / X X X \
    / X X \
     / X \
      / \
123 * 543

       \ /
      \ X /
     \ X X /
      X X X /
   \ / X X X /
  \ X / X X X
   X X / X X \ /
\ / X X / X \ X /
 X / X X / \ X X /
/ X / X X   X X X /
 / X / X \ / X X X
  / X / \ X / X X \ /
   / X   X X / X \ X /
    / \ / X X / \ X X /
       X / X X   X X X
      / X / X \ / X X \
       / X / \ X / X \
        / X   X X / \
         / \ / X X
            X / X \
           / X / \
            / X
             / \
735 * 21

                \ /
               \ X /
              \ X X
             \ X X \ /
            \ X X \ X
             X X \ X \
          \ / X \ X \
         \ X / \ X \
        \ X X   X \
         X X \ / \
      \ / X \ X
     \ X / \ X \
    \ X X   X \
   \ X X \ / \
  \ X X \ X
 \ X X \ X \
\ X X \ X \
 X X \ X \
/ X \ X \
 / \ X \
    X \
   / \

Rules
There should be at least one (diagonal) space between each set of lines. For the purposes of this challenge, it doesn't have to line up in any sort of pretty visual way.
Border crossings should jut out by exactly one slash.
Any amount of padding to the left or the right is allowed as long as all the crossings line up correctly.
Single-width ASCII spaces must be used as padding.
You do not need to calculate the actual result of the multiplication.
You may assume the number is in base 10 and and is at most three digits long with no zeros.
Order matters for the purposes of the output. The first number is always in the \ direction and the second number is always in the / direction.
Input and output may be in any convenient format.
Standard loopholes are banned.
Happy Golfing!

*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int uint;

vector<int> lens(uint n)
{
	vector<int> r = { 0 };
	do
	{
		for (auto i = 0u; i < n % 10; i++)
			r.push_back(1);
		r.push_back(0);
		n /= 10;
	} while (n);

	return r;
}

void vismul(uint x, uint y)
{
	static const char sym[] = " \\/x";

	auto a = lens(x);
	auto b = lens(y);
	reverse(b.begin(), b.end());

	auto m = a.size();
	auto n = b.size();
	auto s = m + n;

	vector<vector<char> > l(s, vector<char>(s, ' '));
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
			l[i + j][j - i + m] = sym[a[i] + (2 * b[j])];
	}

	printf("%u*%u\n", x, y);
	for (size_t i = 0; i < s; i++)
	{
		for (size_t j = 0; j < s; j++)
			printf("%c", l[i][j]);
		printf("\n");
	}
}

int main()
{
	vismul(1, 1);
	vismul(2, 61);
	vismul(45, 1);
	vismul(21001, 209);
	vismul(21, 32);
	vismul(5, 9);
	vismul(16, 27);
	vismul(7, 24);
	vismul(123, 543);
	vismul(735, 21);

	return 0;
}
