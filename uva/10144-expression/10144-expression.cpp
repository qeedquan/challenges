#include <cassert>
#include <string>
#include <format>

using namespace std;

string solve(int n)
{
	if (n < 1)
		return "";

	string s = "((A0|B0)|(A0|B0))";
	for (auto i = 1; i < n; i++)
		s = format("((A{}|B{})|({}|((A{}|A{})|(B{}|B{}))))", i, i, s, i, i, i, i);
	return s;
}

int main()
{
	assert(solve(2) == "((A1|B1)|(((A0|B0)|(A0|B0))|((A1|A1)|(B1|B1))))");
	return 0;
}
