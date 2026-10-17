/*

33 is a simple esolang I created. You may have seen me use it in a few questions. You're not going to be writing a full interpreter. The interpreter you will be writing is for a simplified version of 33.

This simplified 33 has two numeric registers: the accumulator and the counter. The accumulator holds all the post-arithmetic values, the counter is where numbers in the program come from. Both registers are initialized to 0.

0-9 | Appends the digit to the counter
a   | Adds the counter to the accumulator
m   | Subtracts the counter from the accumulator
x   | Multiplies the accumulator by the counter
d   | Divides the accumulator by the counter
r   | Divides the accumulator by the counter, but stores the remainder in the accumulator
z   | Sets the counter to 0
c   | Swaps the accumulator and counter
-----
p   | Outputs the current value of the accumulator as an ASCII character
o   | Outputs the current value of the accumulator as a formatted decimal number
i   | Outputs a newline character (0x0a)
-----
P   | Stores the ASCII value of the next character read in the accumulator
O   | Stores the next integer read into the accumulator
-----
n   | Skips the next instruction if the accumulator is not 0
N   | Skips the next instruction if the accumulator is 0
g   | Skips the next instruction if the accumulator is less than or equal to 0
G   | Skips the next instruction if the accumulator is greater than 0
h   | Skips the next instruction if the accumulator is greater than or equal to 0
H   | Skips the next instruction if the accumulator is less than 0

Test cases
Program / Input -> Output
2o          -> 0
25co        -> 25
1a0aoi      -> 11 (trailing newline)
Oo / 42     -> 42
Op / 42     -> *
1cNoo       -> 11
no          -> 0
Ogo / 2     -> 2
Ogoi / -4   -> (newline)
50a         -> (no output)
On12co / 12 -> 2
Clarifications
The input to your interpreter will be a valid simplified 33 program.
The input may be given in any acceptable format.
The output may be given in any acceptable format.
When dividing, truncate any decimal places.
A trailing newline is acceptable, but it must be consistent; as in, if there's an i at the end of the program, it should have two trailing newlines.
The accumulator and counter must be able to hold at least a signed byte (-128 to 127)
You may assume that the p instruction will never be given when the accumulator has an invalid ASCII character in it.
You may assume the O instruction will never be given unless there is a valid integer string (such as 3, -54, +23) left in the input.

*/

#include <stdio.h>

void
swap(int *a, int *b)
{
	int t;

	t = *b;
	*b = *a;
	*a = t;
}

void
interpret(const char *s)
{
	size_t i;
	int a, c;
	char v;

	a = c = 0;
	for (i = 0; s[i]; i++) {
		switch (s[i]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			c = (c * 10) + (s[i] - '0');
			break;

		case 'a':
			a += c;
			break;
		case 'm':
			a -= c;
			break;
		case 'x':
			a *= c;
			break;
		case 'd':
			if (c)
				a /= c;
			break;
		case 'r':
			if (c)
				a %= c;
			break;
		case 'z':
			c = 0;
			break;
		case 'c':
			swap(&a, &c);
			break;

		case 'p':
			printf("%c", a);
			break;
		case 'o':
			printf("%d", a);
			break;
		case 'i':
			printf("\n");
			break;

		case 'P':
			scanf("%c", &v);
			a = v;
			break;
		case 'O':
			scanf("%d", &a);
			break;

		case 'n':
			i += (a != 0);
			break;
		case 'N':
			i += (a == 0);
			break;
		case 'g':
			i += (a <= 0);
			break;
		case 'G':
			i += (a > 0);
			break;
		case 'h':
			i += (a >= 0);
			break;
		case 'H':
			i += (a < 0);
			break;
		}
		if (!s[i])
			break;
	}
	printf("\n");
}

int
main()
{
	interpret("2o");
	interpret("25co");
	interpret("1a0aoi");
	interpret("Oo");
	interpret("Op");
	interpret("1cNoo");
	interpret("no");
	interpret("Ogo");
	interpret("Ogoi");
	interpret("50a");
	interpret("On12co");

	return 0;
}
