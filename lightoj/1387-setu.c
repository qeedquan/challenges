/*

Rahaduzzaman Setu, (Roll - 12) of 13th batch, CSE, University of Dhaka. He passed away on 18th April 2012. May he rest in peace. This problem is dedicated to him. This problem was written during his treatment. He will be in our prayers, always.

In this problem, you have to build a software that can calculate donations. Initially the total amount of money is 0 and in each time, two types of operations will be there:

donate K (100 ≤ K ≤ 105), then you have to add K to the account.
report, report all the money currently in the account.
Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing an integer N (1 ≤ N ≤ 100) denoting the number of operations. Then there will be N lines each containing two types of operations as given.

You may assume that the input follows the restrictions above. Initially the account is empty for each case.

Output
For each case, print the case number in a single line. Then for each report operation, print the total amount of money in the account in a single line.

Sample
Input	Output
2
4
donate 1000
report
donate 500
report
2
donate 10000
report

Case 1:
1000
1500

Case 2:
10000

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(const char **operations, size_t length)
{
	int amount;
	int total;
	size_t i;

	total = 0;
	for (i = 0; i < length; i++) {
		if (sscanf(operations[i], "donate %d", &amount) == 1)
			total += amount;
		else if (!strcmp(operations[i], "report"))
			printf("%d\n", total);
	}
}

int
main()
{
	const char *operations_1[] = {
		"donate 1000",
		"report",
		"donate 500",
		"report",
	};

	const char *operations_2[] = {
		"donate 10000",
		"report",
	};

	solve(operations_1, nelem(operations_1));
	solve(operations_2, nelem(operations_2));

	return 0;
}
