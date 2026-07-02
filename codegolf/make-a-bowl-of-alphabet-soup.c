/*

This is what we'll call a bowl of alphabet soup - a roughly circular ascii-art shape with the 26 uppercase English letters (A-Z) arranged clockwise to form the perimeter:

   XYZABC
 VW      DE
U          F
T          G
S          H
 RQ      JI
   PONMLK
Write a program that takes in a single letter character, A-Z, and outputs that same bowl of alphabet soup "rotated", so to speak, so the input letter appears where the A does in the example above and the rest of the alphabet cycles fully around clockwise.

So the output for input A would be that same original bowl of alphabet soup.

And the output for input B would be this one:

   YZABCD
 WX      EF
V          G
U          H
T          I
 SR      KJ
   QPONML
Likewise the output for H would be:

   EFGHIJ
 CD      KL
B          M
A          N
Z          O
 YX      QP
   WVUTSR
Or for Z:

   WXYZAB
 UV      CD
T          E
S          F
R          G
 QP      IH
   ONMLKJ
This needs to work for all 26 letters, A through Z.

Details:
You can assume the only input will be a single letter, A through Z.
If convenient you may use lowercase a-z for input and/or output, you can even mix and match lower and uppercase.
The alphabet order must cycle clockwise, not counter-clockwise.
You must use spaces, not something else, to indent and fill the soup bowl.
There may be leading or trailing newlines or spaces in the output as long as the soup bowl is arranged properly.
Note that the bowl shape is 12 characters wide by 7 tall to make it appear roughly circular as text. Your bowls need to be the same shape.
This is code golf so the shortest code wins!

*/

#include <stdio.h>
#include <string.h>

void
soup(int c)
{
	static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char *p;

	p = strchr(alpha, c);
	if (!p)
		return;

	printf("   %c%c%c%c%c%c\n", p[23], p[24], p[25], p[0], p[1], p[2]);
	printf(" %c%c      %c%c\n", p[21], p[22], p[3], p[4]);
	printf("%c          %c\n", p[20], p[5]);
	printf("%c          %c\n", p[19], p[6]);
	printf("%c          %c\n", p[18], p[7]);
	printf(" %c%c      %c%c\n", p[17], p[16], p[9], p[8]);
	printf("   %c%c%c%c%c%c\n", p[15], p[14], p[13], p[12], p[11], p[10]);
	printf("\n");
}

int
main()
{
	int i;

	for (i = 'A'; i <= 'Z'; i++)
		soup(i);

	return 0;
}
