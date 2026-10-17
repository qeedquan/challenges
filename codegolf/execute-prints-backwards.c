/*

Your task is to reverse the order in which some prints get executed.

Specs:
Your code will be in this form:

//some lines of code
/code/ print "Line1" /code/
/code/ print "Line2" /code/
/code/ print "Line3" /code/
/code/ print "Line4" /code/
//some lines of code
You will have to print (or echo, or write, or equivalent) those strings from the fourth to the first.

You decide which lines of your program must print the strings, but they must be adjacent;

Every line can contain only one print, and cannot exceed 60 bytes in length;

Since this is popularity-contest, be creative and avoid to write just a goto or a simple for(i){if(i=4)print"Line1";if(i=3)...}

The most upvoted answer in 2 weeks wins this.

Your output MUST be Line4 Line3 Line2 Line1 OR Line4Line3Line2Line1 OR Line4\nLine3\nLine2\nLine1(where \n is a newline), and it must be generated only by executing those prints backwards.

Happy coding!

UPDATE: Contest is over! Thank you all :)

*/

#define _GNU_SOURCE
#include <stdio.h>

void
output()
{
	const void *lab[] = { &&line1, &&line2, &&line3, &&line4 };

	int i;

	for (i = 3; i >= 0; i--) {
		goto *lab[i];

	line1:
		puts("Line1");
		continue;

	line2:
		puts("Line2");
		continue;

	line3:
		puts("Line3");
		continue;

	line4:
		puts("Line4");
		continue;
	}
}

int
main()
{
	output();
	return 0;
}
