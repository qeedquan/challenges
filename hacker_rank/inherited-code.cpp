/*

You inherited a piece of code that performs username validation for your company's website. The existing function works reasonably well, but it throws an exception when the username is too short. Upon review, you realize that nobody ever defined the exception.

The inherited code is provided for you in the locked section of your editor. Complete the code so that, when an exception is thrown, it prints Too short: n (where n is the length of the given username).

Input Format

The first line contains an integer, t, the number of test cases.
Each of the t subsequent lines describes a test case as a single username string, u.

Constraints
1 <= t <= 1000
1 <= |u| <= 100
The username consists only of uppercase and lowercase letters.

Output Format

You are not responsible for directly printing anything to stdout. If your code is correct, the locked stub code in your editor will print either Valid (if the username is valid), Invalid (if the username is invalid), or Too short: n (where n is the length of the too-short username) on a new line for each test case.

Sample Input

3
Peter
Me
Arxwwz
Sample Output

Valid
Too short: 2
Invalid

*/

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class BadLengthException : public exception
{
private:
	int length;

public:
	BadLengthException(int length)
		: length(length)
	{
	}

	int what()
	{
		return length;
	}
};

bool check_username(const string &username)
{
	auto length = username.length();
	if (length < 5)
		throw BadLengthException(length);

	for (auto i = 0u; i < length - 1; i++)
	{
		if (username[i] == 'w' && username[i + 1] == 'w')
			return false;
	}
	return true;
}

void test(const string &username)
{
	try
	{
		if (check_username(username))
			cout << "Valid" << endl;
		else
			cout << "Invalid" << endl;
	}
	catch (BadLengthException &ex)
	{
		cout << "Too short: " << ex.what() << endl;
	}
}

int main()
{
	test("Peter");
	test("Me");
	test("Arxwwz");

	return 0;
}
