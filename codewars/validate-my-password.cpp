/*

I will give you a string. You respond with "VALID" if the string meets the requirements or "INVALID" if it does not.

Passwords must abide by the following requirements:

More than 3 characters but less than 20.

Must contain only alphanumeric characters.

Must contain letters and numbers.

*/

#include <cassert>
#include <cctype>
#include <string>

using namespace std;

string validate(const string &password)
{
	auto length = password.size();
	if (!(3 < length && length < 20))
		return "INVALID";

	auto flags = 0;
	for (auto ch : password)
	{
		if (!isalnum(ch))
			return "INVALID";
		
		if (isdigit(ch))
			flags |= 1;
		else if (isalpha(ch))
			flags |= 2;
	}
	return (flags == 3) ? "VALID" : "INVALID";
}

int main()
{
	assert(validate("Username123") == "VALID");
	assert(validate("Username") == "INVALID");
	assert(validate("1Username") == "VALID");
	assert(validate("123") == "INVALID");
	assert(validate("a12") == "INVALID");
	assert(validate("1234") == "INVALID");
	assert(validate("a123") == "VALID");
	assert(validate("Username123!") == "INVALID");
	assert(validate("passw0rdIsntTooLong") == "VALID");
	assert(validate("passw0rd1CharTooLong") == "INVALID");

	return 0;
}
