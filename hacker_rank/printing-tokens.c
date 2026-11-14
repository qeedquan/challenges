/*

Given a sentence, s, print each word of the sentence in a new line.

Input Format

The first and only line contains a sentence, s.

Constraints
1 <= len(s) <= 1000

Output Format

Print each word of the sentence in a new line.

Sample Input 0

This is C
Sample Output 0

This
is
C
Explanation 0

In the given string, there are three words ["This", "is", "C"]. We have to print each of these words in a new line.

Sample Input 1

Learning C is fun
Sample Output 1

Learning
C
is
fun
Sample Input 2

How is that
Sample Output 2

How
is
that

*/

#include <stdio.h>
#include <ctype.h>

void
tokenize(const char *string)
{
	int spaces;
	size_t index;

	spaces = 0;
	for (index = 0; string[index]; index++) {
		if (isspace(string[index])) {
			if (!spaces) {
				puts("");
				spaces = 1;
			}
		} else {
			printf("%c", string[index]);
			spaces = 0;
		}
	}
	puts("");
}

int
main()
{
	tokenize("This is C");
	tokenize("Learning C is fun");
	tokenize("How is that");

	return 0;
}
