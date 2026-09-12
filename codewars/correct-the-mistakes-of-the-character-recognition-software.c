/*

Character recognition software is widely used to digitise printed texts. Thus the texts can be edited, searched and stored on a computer.

When documents (especially pretty old ones written with a typewriter), are digitised character recognition softwares often make mistakes.

Your task is correct the errors in the digitised text. You only have to handle the following mistakes:

S is misinterpreted as 5
O is misinterpreted as 0
I is misinterpreted as 1
The test cases contain numbers only by mistake.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
correct(char *s)
{
	for (; *s; s++) {
		switch (*s) {
		case '5':
			*s = 'S';
			break;
		case '0':
			*s = 'O';
			break;
		case '1':
			*s = 'I';
			break;
		}
	}
	return s;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	correct(b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("1F-RUDYARD K1PL1NG", "IF-RUDYARD KIPLING");
	test("R0BERT MERLE - THE DAY 0F THE D0LPH1N", "ROBERT MERLE - THE DAY OF THE DOLPHIN");
	test("R1CHARD P. FEYNMAN - THE FEYNMAN LECTURE5 0N PHY51C5", "RICHARD P. FEYNMAN - THE FEYNMAN LECTURES ON PHYSICS");
	test("R1CHARD P. FEYNMAN - 5TAT15T1CAL MECHAN1C5", "RICHARD P. FEYNMAN - STATISTICAL MECHANICS");
	test("5TEPHEN HAWK1NG - A BR1EF H15T0RY 0F T1ME", "STEPHEN HAWKING - A BRIEF HISTORY OF TIME");
	test("5TEPHEN HAWK1NG - THE UN1VER5E 1N A NUT5HELL", "STEPHEN HAWKING - THE UNIVERSE IN A NUTSHELL");
	test("ERNE5T HEM1NGWAY - A FARWELL T0 ARM5", "ERNEST HEMINGWAY - A FARWELL TO ARMS");
	test("ERNE5T HEM1NGWAY - F0R WH0M THE BELL T0LL5", "ERNEST HEMINGWAY - FOR WHOM THE BELL TOLLS");
	test("ERNE5T HEM1NGWAY - THE 0LD MAN AND THE 5EA", "ERNEST HEMINGWAY - THE OLD MAN AND THE SEA");
	test("J. R. R. T0LK1EN - THE L0RD 0F THE R1NG5", "J. R. R. TOLKIEN - THE LORD OF THE RINGS");

	return 0;
}
