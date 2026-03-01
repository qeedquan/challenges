/*

Chisanbop is a simple method of counting from zero to ninety-nine on two hands invented by Sung Jin Pai and revised by his son Hang Young Pai.

To make numbers, zero, one, or more digits are raised, and their values are summed.

Fingers on the left hand each have a value of ten. The left thumb has a value of fifty. The right thumb has a value of five. Fingers on the right hand each have a value of one.

Palms face away, and fingers nearer their hand's thumb are raised before others on the same hand.

These values and their associated equal-value preference order are shown below, in the order the user would see their digits:

Digit	L pinky	L ring	L middle	L index	L thumb	R thumb	R index	R middle	R ring	R pinky
Value	10	10	10	10	50	5	1	1	1	1
Rank	4	3	2	1	(1)	(1)	1	2	3	4
For example, to show thirty-two, the left hand's index, middle, and ring fingers and the right hand's index and middle fingers are raised:

  Hand:     L           R
 Digit: p r m i t   t i m r p
   Up?: 0 1 1 1 0   0 1 1 0 0

=> 0 + 10 + 10 + 10 + 0 + 0 + 1 + 1 + 0 + 0 = 32
Similarly, for forty-five:

 Hand:    L           R
Digit: p r m i t   t i m r p
  Up?: 1 1 1 1 0   1 0 0 0 0

=> 10 + 10 + 10 + 10 + 0 + 5 + 0 + 0 + 0 + 0 = 45
...or for sixty-eight:

 Hand:    L           R
Digit: p r m i t   t i m r p
  Up?: 0 0 0 1 1   1 1 1 1 0

=> 0 + 0 + 0 + 10 + 50 + 5 + 1 + 1 + 1 + 0 = 68
Challenge
In as few bytes as possible, in the language of your choice, write a program or function that produces the exact string below - all one hundred Chisanbop finger-raising instructions, from zero to ninety-nine, with . for lowered and o for raised. Each instruction is ordered as above, from left pinky to right pinky. You may output a single, trailing newline character, and each line may have consistent leading or trailing whitespace.

. . . . .   . . . . .
. . . . .   . o . . .
. . . . .   . o o . .
. . . . .   . o o o .
. . . . .   . o o o o
. . . . .   o . . . .
. . . . .   o o . . .
. . . . .   o o o . .
. . . . .   o o o o .
. . . . .   o o o o o
. . . o .   . . . . .
. . . o .   . o . . .
. . . o .   . o o . .
. . . o .   . o o o .
. . . o .   . o o o o
. . . o .   o . . . .
. . . o .   o o . . .
. . . o .   o o o . .
. . . o .   o o o o .
. . . o .   o o o o o
. . o o .   . . . . .
. . o o .   . o . . .
. . o o .   . o o . .
. . o o .   . o o o .
. . o o .   . o o o o
. . o o .   o . . . .
. . o o .   o o . . .
. . o o .   o o o . .
. . o o .   o o o o .
. . o o .   o o o o o
. o o o .   . . . . .
. o o o .   . o . . .
. o o o .   . o o . .
. o o o .   . o o o .
. o o o .   . o o o o
. o o o .   o . . . .
. o o o .   o o . . .
. o o o .   o o o . .
. o o o .   o o o o .
. o o o .   o o o o o
o o o o .   . . . . .
o o o o .   . o . . .
o o o o .   . o o . .
o o o o .   . o o o .
o o o o .   . o o o o
o o o o .   o . . . .
o o o o .   o o . . .
o o o o .   o o o . .
o o o o .   o o o o .
o o o o .   o o o o o
. . . . o   . . . . .
. . . . o   . o . . .
. . . . o   . o o . .
. . . . o   . o o o .
. . . . o   . o o o o
. . . . o   o . . . .
. . . . o   o o . . .
. . . . o   o o o . .
. . . . o   o o o o .
. . . . o   o o o o o
. . . o o   . . . . .
. . . o o   . o . . .
. . . o o   . o o . .
. . . o o   . o o o .
. . . o o   . o o o o
. . . o o   o . . . .
. . . o o   o o . . .
. . . o o   o o o . .
. . . o o   o o o o .
. . . o o   o o o o o
. . o o o   . . . . .
. . o o o   . o . . .
. . o o o   . o o . .
. . o o o   . o o o .
. . o o o   . o o o o
. . o o o   o . . . .
. . o o o   o o . . .
. . o o o   o o o . .
. . o o o   o o o o .
. . o o o   o o o o o
. o o o o   . . . . .
. o o o o   . o . . .
. o o o o   . o o . .
. o o o o   . o o o .
. o o o o   . o o o o
. o o o o   o . . . .
. o o o o   o o . . .
. o o o o   o o o . .
. o o o o   o o o o .
. o o o o   o o o o o
o o o o o   . . . . .
o o o o o   . o . . .
o o o o o   . o o . .
o o o o o   . o o o .
o o o o o   . o o o o
o o o o o   o . . . .
o o o o o   o o . . .
o o o o o   o o o . .
o o o o o   o o o o .
o o o o o   o o o o o

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
chisanbop(unsigned number, char *buffer)
{
	static const unsigned values[] = { 50, 10, 10, 10, 10, 5, 1, 1, 1, 1 };
	static const unsigned dots[] = { 8, 6, 4, 2, 0, 12, 14, 16, 18, 20 };
	static const char string[] = ". . . . .   . . . . .";

	size_t index;

	strcpy(buffer, string);
	for (index = 0; number > 0 && index < nelem(values); index++) {
		if (number >= values[index]) {
			number -= values[index];
			buffer[dots[index]] = 'o';
		}
	}
	return buffer;
}

int
main()
{
	unsigned number;
	char buffer[32];

	for (number = 0; number <= 99; number++) {
		chisanbop(number, buffer);
		puts(buffer);
	}

	return 0;
}
