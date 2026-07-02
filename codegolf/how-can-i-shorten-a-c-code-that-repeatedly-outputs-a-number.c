/*

I wrote a code that separates the numbers from 1 to 9999 by comma

void p(n){printf("%d,",n);if(n<9999){p(n+1);}}main(){p(1);}

Is there a way to make this short code without using a repeat statement?

Thank you for reading my question.

*/

#include <stdio.h>

void
p(int n)
{
	printf("%d,", n);
	if (n < 9999)
		p(n + 1);
	else
		printf("\n");
}

int
main(void)
{
	p(1);
	return 0;
}
