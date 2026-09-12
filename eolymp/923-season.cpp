/*

Determine the season name by the given month number using compound conditions.

Input
A single number m — the month number.

Output
For spring months, print Spring; for summer, print Summer; for autumn, print Autumn; and for winter, print Winter.

Examples
Input #1
5

Answer #1
Spring

*/

#include <cassert>
#include <string>

using namespace std;

string season(int m)
{
	if (3 <= m && m <= 5)
		return "Spring";
	if (6 <= m && m <= 8)
		return "Summer";
	if (9 <= m && m <= 11)
		return "Autumn";
	if (m == 12 || m == 1 || m == 2)
		return "Winter";
	return "Invalid";
}

int main()
{
	assert(season(5) == "Spring");

	return 0;
}
