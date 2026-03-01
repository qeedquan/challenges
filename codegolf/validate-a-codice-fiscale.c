/*

Validate a codice fiscale
Every Italian resident/citizen is given a 16-character alphanumeric codice fiscale

Challenge
The final letter is a check code, which is calculated as follows :

Characters of the code are split up into even and odd character according to their positions (check letter excluded)
Both sets are replaced according to the following tables :
ODD CHARACTERS (1st, 3rd...)
Character	Value	Character	Value	Character	Value	Character	Value
0	1	9	21	I	19	R	8
1	0	A	1	J	21	S	12
2	5	B	0	K	2	T	14
3	7	C	5	L	4	U	16
4	9	D	7	M	18	V	10
5	13	E	9	N	20	W	22
6	15	F	13	O	11	X	25
7	17	G	15	P	3	Y	24
8	19	H	17	Q	6	Z	23
EVEN CHARACTERS (2nd, 4th...)
Character	Value	Character	Value	Character	Value	Character	Value
0	0	9	9	I	8	R	17
1	1	A	0	J	9	S	18
2	2	B	1	K	10	T	19
3	3	C	2	L	11	U	20
4	4	D	3	M	12	V	21
5	5	E	4	N	13	W	22
6	6	F	5	O	14	X	23
7	7	G	6	P	15	Y	24
8	8	H	7	Q	16	Z	25

Sum both sets together
Get the remainder of sum/26 and replace according to the table
Remainder	Letter	Remainder	Letter	Remainder	Letter	Remainder	Letter
0	A	7	H	14	O	21	V
1	B	8	I	15	P	22	W
2	C	9	J	16	Q	23	X
3	D	10	K	17	R	24	Y
4	E	11	L	18	S	25	Z
5	F	12	M	19	T
6	G	13	N	20	U

Input
A 16-character codice fiscale in the XXXXXX00X00X000X form.

Assume the check letter will always be a letter

Output
Is the Codice Fiscale valid (the language truthy value) or not (language falsy value)?

For the purpose of the challenge, we consider a codice fiscale to be valid if the calculated check letter corresponds with the input's check letter.

Examples
TMDVSZ30T13L528J -> true
NWWFBE83P20A181A -> false
YNFLJC39E06C956L -> true
YNFLJC39E06C956E -> false

Scoring
This is code-golf, the shortest number of bytes wins

*/

#include <assert.h>
#include <stdio.h>

int
code(int c, size_t n)
{
	static const int odds[] = {1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 2, 4, 18, 20, 11, 3, 6, 8, 12, 14, 16, 10, 22, 25, 24, 23};
	static const int evens[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

	if ('0' <= c && c <= '9')
		c -= '0';
	else if ('a' <= c && c <= 'z')
		c -= (c - 'a') + 10;
	else if ('A' <= c && c <= 'Z')
		c = (c - 'A') + 10;
	else
		return 0;

	return (n & 1) ? odds[c] : evens[c];
}

int
checksum(const char *s)
{
	size_t i;
	int c;

	c = 0;
	for (i = 0; i < 15 && s[i]; i++)
		c += code(s[i], !(i & 1));
	c = 'A' + (c % 26);

	if (i != 15 || s[i] != c || s[i + 1])
		return -1;
	return c;
}

bool
validate(const char *s)
{
	return checksum(s) >= 0;
}

int
main(void)
{
	assert(validate("TMDVSZ30T13L528J") == true);
	assert(validate("NWWFBE83P20A181A") == false);
	assert(validate("YNFLJC39E06C956L") == true);
	assert(validate("YNFLJC39E06C956E") == false);

	return 0;
}
