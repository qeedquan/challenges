#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

string successor(string str)
{
	if (next_permutation(str.begin(), str.end()))
		return str;
	return "No Successor";
}

int main()
{
	assert(successor("abaacb") == "ababac");
	assert(successor("cbbaa") == "No Successor");

	return 0;
}
