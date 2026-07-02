/*

Challenge
Given the following C# method:

private static bool Test(bool a, bool b)
{
    if (a && b) return false;
    if (a) if (b) return true;
    return false;
}
Supply the values a and b so that true is returned.

Winning condition
The first entry who can supply the correct arguments to make the given method evaluate to true wins.

*/

#include <iostream>

using namespace std;

class Bool
{
private:
	int state;

public:
	Bool(int state)
	{
		this->state = state;
	}

	explicit operator bool()
	{
		if (state < 1)
		{
			state = 1;
			return false;
		}
		return true;
	}
};

ostream& operator<<(ostream& os, const Bool& value)
{
	auto copy = value;
	if (copy)
		cout << "true";
	else
		cout << "false";
	return os;
}

#define bool Bool
#define true Bool(1)
#define false Bool(0)

bool test(bool a, bool b)
{
	if (a && b)
		return false;

	if (a)
	{
		if (b)
			return true;
	}

	return false;
}

int main()
{
	bool a(1);
	bool b(0);

	cout << test(a, b) << endl;
	
	return 0;
}
