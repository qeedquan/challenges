/*

Mr. Cooper, the CEO of CozyWalk Co., receives a report of daily sales every day since the company
has been established. Starting from the second day since its establishment, on receiving the report, he
compares it with each of the previous reports in order to calculate the number of previous days whose
sales amounts are less than or equal to it. After obtaining the number of such days, he writes it in a
list.
This problem can be stated more formally as follows. Let A = (a1, a2, . . . , an) denote the list of
daily sales amounts. And let B = (b1, b2, . . . , bn−1) be another integer list maintained by Mr. Cooper,
each value representing the number of such previous days. On the i-th day (2 ≤ i ≤ n), he calculates
bi−1, the number of ak’s such that ak ≤ ai (1 ≤ k < i).
For example, suppose that A = (20, 43, 57, 43, 20). For the fourth day’s sales amount, a4 = 43, the
number of previous days whose sales amounts are less than or equal to it is 2 since a1 ≤ a4, a2 ≤ a4, and
a3 > a4. Therefore, b3 = 2. Similarly, b1, b2, and b4 can be obtained and it results in B = (1, 2, 2, 1).
Given an array of size n for the list of daily sales amounts, write a program that prints the sum of
the n − 1 integers in the list B.

Input
Your program is to read the input from standard input. The input consists of T test cases. The number
of test cases T is given in the first line of the input. Each test case starts with a line containing an
integer n (2 ≤ n ≤ 1, 000), which represents the size of the list A . In the following line, n integers are
given, each represents the daily sales amounts ai (1 ≤ ai ≤ 5, 000 and 1 ≤ i ≤ n) for the test case.

Output
Your program is to write to standard output. For each test case, print the sum of the n − 1 integers in
the list B which is obtained from the list A.
The following shows sample input and output for two test cases.

Sample Input
2
5
38 111 102 111 177
8
276 284 103 439 452 276 452 398

Sample Output
9
20

*/

#include <cassert>
#include <set>
#include <vector>

using namespace std;

int solve(const vector<int> &numbers)
{
	multiset<int> prev;
	auto sum = 0;
	for (auto number : numbers)
	{
		auto upper = prev.upper_bound(number);
		sum += distance(prev.begin(), upper);
		prev.insert(number);
	}
	return sum;
}

int main()
{
	assert(solve({ 38, 111, 102, 111, 177 }) == 9);
	assert(solve({ 276, 284, 103, 439, 452, 276, 452, 398 }) == 20);

	return 0;
}
