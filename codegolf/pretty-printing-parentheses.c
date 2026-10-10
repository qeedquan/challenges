/*

The worst part about long lines or code or math equations are the parentheses. Nobody wants to read through 2x(3y+4*abs(x^[2*e^x])-5{3(x+y)-5})!

So, the goal of this challenge is to make it at least slightly easier to read these parentheses-filled beasts! For the above math equation, the output should be:

2x (
  3y+4*abs (
    x^ [
      2*e^x
    ]
  )
  -5 {
    3 (
      x+y
    )
    -5
  }
)
A parenthesis is defined as either of these characters: ()[]{}. Indents should each be two spaces, and there should be one space of seperation between the expression and the parenthesis: 2x (, x^ [ as some examples.

I would like to debut the Atomic Code Golf metric in this question. Take out all separators in your code (()[]{}. ; to name some common ones), and then take the length of your program if every reserved word and operator were 1 character long. That is your program's score. if x**(3.2)==b[3]:print x is 11 points: if|x|**|3|.|2|==|b|3|print|x, or ix*3.2=b3px. Any quick questions about the metric can be posted here; larger questions should be discussed in meta using the link above.

Lowest score wins. Good luck, have fun!

*/

#include <stdio.h>
#include <string.h>

int
isopen(int c)
{
	return strchr("([{", c) != NULL;
}

int
isclose(int c)
{
	return strchr(")]}", c) != NULL;
}

int
isparen(int c)
{
	return isopen(c) || isclose(c);
}

void
spaces(int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("  ");
}

void
prettyprint(const char *s)
{
	size_t i, j;
	int d;

	d = 0;
	i = 0;
	for (;;) {
		for (j = i; s[i] && !isparen(s[i]); i++)
			printf("%c", s[i]);

		if (!s[i])
			break;

		if (isopen(s[i])) {
			if (i != j)
				printf(" ");
			printf("%c\n", s[i]);
			spaces(++d);
		} else if (isclose(s[i])) {
			printf("\n");
			spaces(--d);
			printf("%c", s[i]);
			if (!isclose(s[i + 1])) {
				printf("\n");
				spaces(d);
			}
		}
		i += 1;
	}
	printf("\n");
}

int
main(void)
{
	prettyprint("2x(3y+4*abs(x^[2*e^x])-5{3(x+y)-5})");
	prettyprint("(((2x)))");
	return 0;
}
