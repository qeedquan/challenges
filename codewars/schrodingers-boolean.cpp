/*

Can a value be both true and false?

Define omniBool so that it returns true for the following:

omniBool == true && omniBool == false
If you enjoyed this kata, be sure to check out my other katas.

*/

#include <iostream>

using namespace std;

struct Bool
{
	bool operator==(bool)
	{
		return true;
	}
};

int main()
{
	Bool omnibool;
	if (omnibool == true && omnibool == false)
		cout << "OMNIBOOL" << endl;
	return 0;
}
