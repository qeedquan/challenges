/*

Andrew is a chemist, interested in the acidity of solutions and in agriculture. After months of research (Google is not his friend), he came up with the following table* regarding the human-readable level of acidity in terms of the pH (potential of Hydrogen):

         Denomination        |         pH range
                             |
    -------------------------+-----------------------------
    Ultra acidic             |          below 3.5
    -------------------------+------------------------------
    Extremely acidic         |    between 3.5 and 4.4
    -------------------------+------------------------------
    Very strongly acidic     |    between 4.5 and 5.0
    -------------------------+------------------------------
    Strongly acidic          |    between 5.1 and 5.5
    -------------------------+------------------------------
    Moderately acidic        |    between 5.6 and 6.0
    -------------------------+------------------------------
    Slightly acidic          |    between 6.1 and 6.5
    -------------------------+------------------------------
    Neutral                  |    between 6.6 and 7.3
    -------------------------+------------------------------
    Slightly alkaline        |    between 7.4 and 7.8
    -------------------------+------------------------------
    Moderately alkaline      |    between 7.9 and 8.4
    -------------------------+------------------------------
    Strongly alkaline        |    between 8.5 and 9.0
    -------------------------+------------------------------
    Very strongly alkaline   |          over 9.0
Given a non-negative decimal number representing the pH of a substance, output its Denomination. You can take input and provide output by any standard method. The data types you are allowed to take input with are:

Float
Double
Your language's standard decimal number data type
String
And you must output a String representing the denomination. Built-ins related to chemistry are forbidden (Sorry, Mathematica!).

Approximation Rule: If the pH you receive is between an upper bound of a denomination and the lower bound of the next one (e.g. between 7.8 and 7.9), it gets approximated to the closest value between the two: if the pH ≥ upperBound of the first + 0.5, then it should receive the second denomination, but if the pH < upperBound of the first + 0.5, then it should receive the first one (e.g 7.85 is approximated to 7.9, but 7.84999 is approximated to 7.8). See the test cases for clarifications.

Test Cases:
Input ->  Output

6.40  ->  Slightly acidic
8.399 ->  Moderately alkaline
3.876 ->  Extremely acidic
10.60 ->  Very strongly alkaline
0.012 ->  Ultra acidic
7.30  ->  Neutral
7.85  ->  Moderately alkaline (the approximation rule is applied)
7.849 ->  Slightly alkaline (the approximation rule is applied)
6.55  ->  Neutral (the approximation rule is applied)
This is code-golf, so the shortest valid submission (in bytes) wins!

*Andrew did not come up with that, it was Wikipedia!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
denomination(double ph)
{
	static const struct Acidity {
		char type[32];
		double start;
		double end;
	} tab[] = {
	    {"Ultra acidic", -FLT_MAX, 3.5},
	    {"Extremely acidic", 3.5, 4.4},
	    {"Very strongly acidic", 4.5, 5.0},
	    {"Strongly acidic", 5.1, 5.5},
	    {"Moderately acidic", 5.6, 6.0},
	    {"Slightly acidic", 6.1, 6.5},
	    {"Neutral", 6.6, 7.3},
	    {"Slightly alkaline", 7.4, 7.8},
	    {"Moderately alkaline", 7.9, 8.4},
	    {"Strongly alkaline", 8.5, 9.0},
	    {"Very strongly alkaline", 9.0, FLT_MAX},
	};

	static const double eps = 1e-3;
	const struct Acidity *p, *q;
	size_t i;
	double d0, d1;

	for (i = 0; i < nelem(tab); i++) {
		p = tab + i;
		q = p + 1;
		if (p->start <= ph && ph <= p->end)
			return p->type;

		if (i + 1 < nelem(tab) && ph <= q->start) {
			d0 = fabs(ph - p->end);
			d1 = fabs(ph - q->start);
			if (fabs(d0 - d1) < eps || d1 < d0)
				return q->type;
			return p->type;
		}
	}
	return NULL;
}

void
test(double ph, const char *r)
{
	const char *p;

	p = denomination(ph);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(6.40, "Slightly acidic");
	test(8.399, "Moderately alkaline");
	test(3.876, "Extremely acidic");
	test(10.60, "Very strongly alkaline");
	test(0.012, "Ultra acidic");
	test(7.30, "Neutral");
	test(7.85, "Moderately alkaline");
	test(7.849, "Slightly alkaline");
	test(6.55, "Neutral");

	return 0;
}
