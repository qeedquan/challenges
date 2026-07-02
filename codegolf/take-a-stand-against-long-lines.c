/*

Recently, someone proposed more stringent limits for Python's default line length:

Clearly, no program should ever use more than 80 characters per line, for a whole host of reasons. First and foremost, for readability and maintainability, it is important to have a solid standard, so we can adjust the width of our text editors appropriately. As a secondary benefit, code can easily be transferred onto media that may have restrictions, and where adding line-breaks can be distracting, like print pages for review in a meeting, or punch cards.

But is 80 characters too high? Some suggest 79, or even as low as 75, to allow for an 80 character wide terminal to fit the code with a few columns devoted to line numbers. Clearly, ultimately, lower is better, as lower limits allow for the code to be used in more situations without reformatting.

Introducing the max6 standard

Your goal is to find and demonstrate the minimum line length required by Your Favorite Language by writing a FizzBuzz variant with the fewest number of characters in any line.

Input
An integer, n, via any desired method.

Output
Print the numbers from 1 to n, (n ≥ 1, n ∈ ℤ) separated by line breaks, except:

for multiples of 3 print "Apple"
for multiples of 5 print "Pie"
for multiples of both 3 and 5 print "ApplePie"
Scoring
The maximum line length in bytes, not including the line break (Cr, CrLf, Lf, or other system standard break, specify, as desired), and the total code length in bytes as a tiebreaker.

Rules
All line breaks must be meaningful. Line breaks that can be removed and adjacent lines directly concatenated without an impact on the output, must be removed.

*/

#include <stdio.h>

void
applepie(int n)
{
	int i;

	for (i = 1; i <= n; i++) {
		switch (i % 15) {
		case 3:
		case 6:
		case 9:
		case 12:
			puts("Apple");
			break;
		case 5:
		case 10:
			puts("Pie");
			break;
		case 0:
			puts("ApplePie");
			break;
		default:
			printf("%d\n", i);
			break;
		}
	}
}

int
main()
{
	applepie(100);
	return 0;
}
