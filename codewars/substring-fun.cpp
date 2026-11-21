/*

Complete the function that takes an array of words.

You must concatenate the nth letter from each word to construct a new word which should be returned as a string, where n is the position of the word in the list.

For example:

["yoda", "best", "has"]  -->  "yes"
  ^        ^        ^
  n=0     n=1     n=2
  
Note: Test cases contain valid input only - i.e. a string array or an empty array; and each word will have enough letters.

*/

#include <cassert>
#include <string>
#include <vector>

using namespace std;

string nthchar(const vector<string> &words)
{
	string output = "";
	size_t index = 0;
	for (auto word : words)
	{
		output += word[index];
		index += 1;
	}
	return output;
}

int main()
{
	assert(nthchar({ "yoda", "best", "has" }) == "yes");
	return 0;
}
