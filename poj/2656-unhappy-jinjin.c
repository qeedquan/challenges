/*

Description

Jinjin is a junior school student. Besides the classes in school, Jinjin's mother also arranges some supplementary classes for her. However, if Jinjin studies for more than eight hours a day, she will be unhappy on that day. On any day she gets unhappy, the more time she studies, the unhappier she will be. Now we got Jinjin's class schedule for the next several days and your task is to find out whether she will be unhappy on these days; if she will be unhappy, on which day she will be the unhappiest.
Input

There may be several test cases. In the first line of each test case, there is an integer N (1 <= N <= 7), which represents the number of days you should analyze. Then there comes N lines, each contains two non-negative integers (each smaller than 10). The first integer represents how many hours Jinjin studies at school on the day, and the second represents how many hours she studies in the supplementary classes on the same day.

A case with N = 0 indicates the end of the input, and this case should not be processed.
Output

For each test case, output a line contains a single integer. If Jinjin will always be happy, the integer should be 0; otherwise, the integer should be a positive integer K, which means that Jinjin will be the unhappiest on the K-th day. If the unhappiest day is not unique, just output the earliest one among these unhappiest days.

Sample Input

7
5 3
6 2
7 2
5 3
5 4
0 4
0 6
1
4 4
0

Sample Output

3
0

Hint

Here is a sample solution of this problem using C language:
#include <stdio.h>

int main(){

        while(1) {

                int i, n;

                int maxday, maxvalue = -1;

                scanf("%d", &n);

                if (n == 0) break;

                for (i = 1; i <= n; i++) {

                        int a, b;

                        scanf("%d%d", &a, &b);

                        if (a + b > maxvalue) {

                                maxvalue = a + b;

                                maxday = i;

                        }

                }

                if (maxvalue <= 8) printf("0\n");

                else printf("%d\n", maxday);

        }

        return 0;

}

Source

NOIP 2004

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mood(int a[][2], size_t n)
{
	int m, r, v;
	size_t i;

	r = 0;
	m = -1;
	for (i = 0; i < n; i++) {
		v = a[i][0] + a[i][1];
		if (m < v) {
			r = i + 1;
			m = v;
		}
	}
	return (m <= 8) ? 0 : r;
}

int
main(void)
{
	int a1[][2] = {
	    {5, 3},
	    {6, 2},
	    {7, 2},
	    {5, 3},
	    {5, 4},
	    {0, 4},
	    {0, 6},
	};

	int a2[][2] = {
	    {4, 4},
	};

	assert(mood(a1, nelem(a1)) == 3);
	assert(mood(a2, nelem(a2)) == 0);

	return 0;
}
