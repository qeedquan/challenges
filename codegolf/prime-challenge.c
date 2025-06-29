/*

CODE GOLF & Coding Challenges: In today's challenge, you'll be asked to print the following very special AND tricky AND satisfying Prime Number...! Are you golfers ready?

6779686932717976703238326711110010511010332671049710810810111010310111558327311032116111100971213911532991049710810810111010310144321211111173910810832981013297115107101100321161113211211410511011632116104101321021111081081111191051101033211810111412132115112101991059710832657868321161141059910712132657868321159711610511510212110511010332801141051091013278117109981011144646463332651141013212111111732103111108102101114115321141019710012163

Your task is to output this 442-digit Prime Number

Rules

Your code must not contain any odd decimal digits. So numbers 1,3,5,7,9 (ASCII 49,51,53,55,57) are forbidden.

This is code-golf. The shortest code in bytes wins.

So... what is so special about this prime number anyway?
You may find this out yourselves. If you don't, I'll tell you next week!

EDIT
Since this challenge is going to close, I will give a hint to my friend @xnor:
The challenge IS the number (this is why it is called "Prime Challenge")

*/

#include <stdio.h>

void
solve()
{
	static const char secret[] = "CODE GOLF & Coding Challenges: In today's challenge, you'll be asked to print the following very special AND tricky AND satisfying Prime Number...! Are you golfers ready?";

	const char *p;

	for (p = secret; *p; p++)
		printf("%d", *p);
	printf("\n");
}

int
main()
{
	solve();
	return 0;
}
