/*

I did the IMC this year. Did anyone else here do it?

In a UKMT Intermediate Maths Challenge paper, there are twenty-five questions. The first fifteen questions give you five marks if you get them right. For the other ten questions, you get six marks for getting them right. In the last ten questions, you lose marks if you get them wrong! For questions sixteen to twenty, you lose one marks and for the last five questions, you lose two marks. If you leave a question blank, no marks are awarded or deducted. No marks are deducted for getting any of the first fifteen questions wrong. The paper is multiple choice; you can choose any answer out of A, B, C, D and E for each question. There is always just one right answer for each question.

Create a program/function that takes two strings and outputs a score. The first string will be your answers to the paper. If you skip a question, use a space, a null byte or an underscore. Otherwise, use the letter A, B, C, D or E for the answer. You can either have the inputs uppercase or lowercase. The second string will be the correct answers for each question in the paper. Your program/function will then output a score. Make your code short.

Test cases:

DDDDDDDDDDDDDDDDDDDDDDDDD
ABCDEABCDEABCDEABCDEABCDE
15

BDBEACCECEDDBDABBCBDAEBCD
BDBEACCECEDDBDABBCBDAEBCD
135

DBACBDCDBAEDABCDBEECACDC_
DBADBDCDBAEDABCDBEEDACDCA
117

_________________________
DABDABDABDABDABDABDABDABD
0

DBADBDCDBAEDABCD_E__A__C_
DBADBDCDBAEDABCDBEEDACDCA
99

_______________BBBBBBBBBB
AAAAAAAAAAAAAAAAAAAAAAAAA
-15

*/

#include <assert.h>
#include <stdio.h>

int
mark(const char *s, const char *t)
{
	size_t i;
	int r, a, b;

	r = 0;
	for (i = 0; s[i] && t[i] && i < 25; i++) {
		if (i < 15) {
			a = 5;
			b = 0;
		} else if (i < 20) {
			a = 6;
			b = 1;
		} else {
			a = 6;
			b = 2;
		}

		if (s[i] == t[i])
			r += a;
		else if (s[i] != '_')
			r -= b;
	}

	return r;
}

int
main(void)
{
	assert(mark("DDDDDDDDDDDDDDDDDDDDDDDDD", "ABCDEABCDEABCDEABCDEABCDE") == 15);
	assert(mark("BDBEACCECEDDBDABBCBDAEBCD", "BDBEACCECEDDBDABBCBDAEBCD") == 135);
	assert(mark("DBACBDCDBAEDABCDBEECACDC_", "DBADBDCDBAEDABCDBEEDACDCA") == 117);
	assert(mark("DBACBDCDBAEDABCDBEECACDC_", "DBADBDCDBAEDABCDBEEDACDCA") == 117);
	assert(mark("_________________________", "DABDABDABDABDABDABDABDABD") == 0);
	assert(mark("DBADBDCDBAEDABCD_E__A__C_", "DBADBDCDBAEDABCDBEEDACDCA") == 99);
	assert(mark("_______________BBBBBBBBBB", "AAAAAAAAAAAAAAAAAAAAAAAAA") == -15);

	return 0;
}
