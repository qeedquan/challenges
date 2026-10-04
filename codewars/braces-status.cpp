/*

Write a function that checks the braces status in a string, and return True if all braces are properly closed, or False otherwise. Available types of brackets: (), [], {}.

Please note, you need to write this function without using regex!

Examples
"([[some](){text}here]...)"  =>  true
"{([])}"                     =>  true
"()[]{}()"                   =>  true
"(...[]...{(..())}[abc]())"  =>  true
"1239(df){"                  =>  false
"[()])"                      =>  false
")12[x]34("                  =>  false
Don't forget to rate this kata! Thanks :)

*/

#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool braces_status(const string &input)
{
	char pairs[128];
	pairs['('] = ')';
	pairs['['] = ']';
	pairs['{'] = '}';

	vector<int> braces;
	for (auto symbol : input)
	{
		switch (symbol)
		{
		case '(':
		case '[':
		case '{':
			braces.push_back(symbol);
			break;

		case ')':
		case ']':
		case '}':
			if (braces.size() == 0 || pairs[braces.back()] != symbol)
				return false;
			braces.pop_back();
			break;
		}
	}
	return braces.size() == 0;
}

int main()
{
	assert(braces_status("([[some](){text}here]...)") == true);
	assert(braces_status("{([])}") == true);
	assert(braces_status("()[]{}()") == true);
	assert(braces_status("(...[]...{(..())}[abc]())") == true);
	assert(braces_status("1239(df){") == false);
	assert(braces_status("[()])") == false);
	assert(braces_status(")12[x]34(") == false);

	return 0;
}
