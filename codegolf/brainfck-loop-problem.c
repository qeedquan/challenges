/*

I have a problem for a cyber club that asks you to print:

ZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:9876543210/.-,+*)('&%$#"!
Using Brainf**k in 29 bytes or less without using the ',' character.

I have a working code:

++++++++++[>++++++>+++++++++<<-]>-->.<[>-.<-]
However my loop is too long, sending me 16 bytes over the limit.

Is there a more efficient way to set the second and third cell to 58 and 90 so I can run my second loop? Or is there a better way to do this all together that I am just not seeing?

*/

#include <stdio.h>

/*

@Sp3000

Spent a whole day basically writing up a brute forcer and watching the results come in. Now I can get back to doing some actual work... Another day of brute forcing later...

The component ++[<++[++<]>>>+] initialises the tape to

[130, 0, 0, 0, 91, 59, 0]
                       ^
which is just perfect for what we need!

*/

const char *
solve()
{
	return "++[<++[++<]>>>+]<[-<-.>]";
}

int
main()
{
	puts(solve());
	return 0;
}
