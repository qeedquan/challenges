/*

Every Brazilian citizen has a national identification number associated with them, named CPF.

This number has 11 digits (formatted as XXX.XXX.XXX-XX) and it's validated by the following (real) algorithm1:

Take the 9 most significant digits of the number. Call it c.
Multiply the n-th least significant digit of c by n+1, where 1 ≤ n ≤ 9.
Add all the products and evaluate the remainder of the division between that and 11.
If the remainder r is less than 2, consider 0. Otherwise, consider 11 - r. Update c to contain that as an appended least significant digit.
First time on step 4? Go back to step 1, but now 1 ≤ n ≤ 10. Otherwise, go to step 5.
Is c the same as your initial number? If yes, then your CPF is valid.
Let's take 111.444.777-35.

Take the 9 most significant digits of the number. Call it c:
c = 111444777

Multiply the n-th least significant digit of c by n+1, where 1 ≤ n ≤ 9:
c	1	1	1	4	4	4	7	7	7
10	9	8	7	6	5	4	3	2
result	10	9	8	28	24	20	28	21	14
Add all the products and evaluate the remainder of the division between that and 11:
10+9+8+28+24+20+28+21+14 = 162 mod 11 = 8

If the remainder r is less than 2, consider 0. Otherwise, consider 11 - r. Update c to contain that as an appended least significant digit:
Considering 11 - 8 = 3, c = 1114447773.

Go back to step 1, but now 1 ≤ n ≤ 10.
c	1	1	1	4	4	4	7	7	7	3
11	10	9	8	7	6	5	4	3	2
result	11	10	9	32	28	24	35	28	21	6
11+10+9+32+28+24+35+28+21+6 = 204 mod 11 = 6

Considering 11 - 6 = 5, c = 11144477735.

Is c the same as your initial number?
Yes. Therefore, the CPF is valid.

Input
You can accept one of the following (or all of them):

a string containing exactly 11 digits
a string containing exactly 14 characters formatted as XXX.XXX.XXX-XX, where X is a digit
a number 0 ≤ n ≤ 99999999999
you must read it from the most to the least significant digit: n = 12345678901 corresponds to 123.456.789-01
you must pad it to 11 digits: n = 3 corresponds to 000.000.000-03
a list/array of numbers 0 ≤ n ≤ 9 containing exactly 11 elements
you must read it from the left-most to the right-most element: [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1] corresponds to 123.456.789-01
Always assume the input meets these constraints.

Output
Whether the input is a valid CPF. You may either

output truthy/falsy using your language's convention
use two distinct, fixed values to represent true and false
Truthies
11144477735
52398680002
05830033542
06865086376
39385258001
39290600780
01871863759
03337363466
66377805292
71462831435
54669275895
24029901557
83190130205
97727810509
70159591945
68730451957
55829849330
30162341903
56684732365
60505376660
29535063731
Falsies
10433218196
00133890838
63794026542
35116155940
78161849593
10341316475
25534192832
76483503056
41395376724
23884969653
28710122691
66978480184
51462704828
14893252880
95701543039
11718227824
89638346578
71331509839
30103105183
47382997376
Try to create your code with fewest bytes as possible.

The standard I/O is applied.

1 Source (in Portuguese).
https://www.geradorcpf.com/algoritmo_do_cpf.htm

*/

#include <assert.h>
#include <stdio.h>

bool
cpf(const char *s)
{
	int i, j, r;

	for (i = 10; i >= 9; i--) {
		r = 0;
		for (j = 0; j < i; j++)
			r += (s[j] - '0') * (i - j + 1);
		r %= 11;
		r = (r < 2) ? 0 : (11 - r);

		if (r != s[i] - '0')
			return false;
	}
	return true;
}

int
main()
{
	assert(cpf("00000000000") == true);
	assert(cpf("11144477735") == true);
	assert(cpf("52398680002") == true);
	assert(cpf("05830033542") == true);
	assert(cpf("06865086376") == true);
	assert(cpf("39385258001") == true);
	assert(cpf("39290600780") == true);
	assert(cpf("01871863759") == true);
	assert(cpf("03337363466") == true);
	assert(cpf("66377805292") == true);
	assert(cpf("71462831435") == true);
	assert(cpf("54669275895") == true);
	assert(cpf("24029901557") == true);
	assert(cpf("83190130205") == true);
	assert(cpf("97727810509") == true);
	assert(cpf("70159591945") == true);
	assert(cpf("68730451957") == true);
	assert(cpf("55829849330") == true);
	assert(cpf("30162341903") == true);
	assert(cpf("56684732365") == true);
	assert(cpf("60505376660") == true);
	assert(cpf("29535063731") == true);

	assert(cpf("00000000001") == false);
	assert(cpf("10433218196") == false);
	assert(cpf("00133890838") == false);
	assert(cpf("63794026542") == false);
	assert(cpf("35116155940") == false);
	assert(cpf("78161849593") == false);
	assert(cpf("10341316475") == false);
	assert(cpf("25534192832") == false);
	assert(cpf("76483503056") == false);
	assert(cpf("41395376724") == false);
	assert(cpf("23884969653") == false);
	assert(cpf("28710122691") == false);
	assert(cpf("66978480184") == false);
	assert(cpf("51462704828") == false);
	assert(cpf("14893252880") == false);
	assert(cpf("95701543039") == false);
	assert(cpf("11718227824") == false);
	assert(cpf("89638346578") == false);
	assert(cpf("71331509839") == false);
	assert(cpf("30103105183") == false);
	assert(cpf("47382997376") == false);

	return 0;
}
