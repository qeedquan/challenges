/*

Description

Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let's say the phone catalogue listed these numbers:

Emergency 911
Alice 97 625 999
Bob 91 12 54 26
In this case, it's not possible to call Bob, because the central would direct your call to the emergency line as soon as you had dialled the first three digits of Bob's phone number. So this list would not be consistent.

Input

The first line of input gives a single integer, 1 ≤ t ≤ 40, the number of test cases. Each test case starts with n, the number of phone numbers, on a separate line, 1 ≤ n ≤ 10000. Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.

Output

For each test case, output "YES" if the list is consistent, or "NO" otherwise.

Sample Input

2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

Sample Output

NO
YES

Source

Nordic 2007

*/

#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const string consistent(vector<string> &&phonelist)
{
	sort(phonelist.begin(), phonelist.end());
	for (size_t i = 1; i < phonelist.size(); i++)
	{
		if (!phonelist[i].compare(0, phonelist[i - 1].size(), phonelist[i - 1]))
			return "NO";
	}
	return "YES";
}

int main()
{
	assert(consistent({ "911", "97625999", "91125426" }) == "NO");
	assert(consistent({ "113", "12340", "123440", "12345", "98346" }) == "YES");

	return 0;
}
