/*

The clock started running at midnight on the first day and continued until it stopped m minutes later.
Your task is to determine and output the day number, along with the time displayed on the clock in hours and minutes when it stopped.

Input
An integer m, where m<10^9.

Output
Provide three integers on a single line, separated by spaces.

Examples
Input #1
1624

Answer #1
2 3 4

*/

#include <print>

using namespace std;

void solve(int m)
{
	auto d = m / 1440;
	m -= d * 1440;

	auto h = m / 60;
	m -= h * 60;

	println("{} {} {}", d + 1, h, m);
}

int main()
{
	solve(1624);

	return 0;
}
