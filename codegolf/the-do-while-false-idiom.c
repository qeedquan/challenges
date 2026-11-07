/*

Do While False
At work today one of my colleagues was describing the use-case for do while(false). The person he was talking to thought that this was silly and that simple if statements would be much better. We then proceeded to waste half of our day discussing the best manner to write something equivalent to:

do
{
   //some code that should always execute...

   if ( condition )
   {
      //do some stuff
      break;
   }

   //some code that should execute if condition is not true

   if ( condition2 )
   {
       //do some more stuff
       break;
   }

   //further code that should not execute if condition or condition2 are true

}
while(false);
This is an idiom which is found in c quite often. Your program should produce the same output as the below pseudo-code depending on the conditions.

do
{
   result += "A";

   if ( C1)
   {
      result += "B";
      break;
   }

   result += "C"

   if ( C2 )
   {
       result += "D";
       break;
   }

   result += "E";

}
while(false);

print(result);
Therefore the input could be:

1. C1 = true, C2 = true
2. C1 = true, C2 = false
3. C1 = false, C2 = true
4. C1 = false, C2 = false
and the output should be:

1. "AB"
2. "AB"
3. "ACD"
4. "ACE"
This is code-golf so answers will be judged on bytes. Standard loopholes are banned.

Yes this is a simple one, but hopefully we will see some creative answers, I'm hoping the simplicity will encourage people to use languages they are less confident with.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
Evaluate(bool C1, bool C2, char *Output)
{
	char *Result;

	Result = Output;
	do {
		*Result++ = 'A';
		if (C1) {
			*Result++ = 'B';
			break;
		}

		*Result++ = 'C';
		if (C2) {
			*Result++ = 'D';
			break;
		}

		*Result++ = 'E';

	} while (false);

	*Result = '\0';
	return Output;
}

void
Test(bool C1, bool C2, const char *Expected)
{
	char Output[8];

	Evaluate(C1, C2, Output);
	printf("%s\n", Output);
	assert(!strcmp(Output, Expected));
}

int
main(void)
{
	Test(true, true, "AB");
	Test(true, false, "AB");
	Test(false, true, "ACD");
	Test(false, false, "ACE");

	return 0;
}
