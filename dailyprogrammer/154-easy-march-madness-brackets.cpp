/*

It is that time of year again when across some of the lands you hear about March Madness and NCAA Basketball.
People ask about your brackets and how you are doing in your predictions.
Of course to those of us who perform the art of coding we always get a bit confused by this.

You see we think of brackets like [] or {} or () to use in our many wonderful languages.
As it turns out in a bit of madness some messages got the rough bracket treatment.
I am asking you to decode these messages by removing the brackets and decoding the message.
The order of the message should be ordered for the deepest bracket strings to be displayed first then the next deepest and so forth.

Input:
(String of words with matching bracket sets in an order that can only be called mad)

Example 1:
((your[drink {remember to}]) ovaltine)

Example 2:
[racket for {brackets (matching) is a} computers]

Example 3:
[can {and it(it (mix) up ) } look silly]

Output:
The words separated by a single space in order from deepest to shallow on the ordering of matched brackets.

Example 1:
remember to drink your ovaltine

Example 2:
matching brackets is a racket for computers

Example 3:
mix it up and it can look silly

Notes:
Assume your input is error checked.

Bracket groups can be either [] or () or {} and there will be no mismatches.

The pattern of when and what brackets are used is random. You could see all () or () then a [] then a () again. Etc.

Every closing bracket will have an opening one that matches. So ] matches to a [ and ) matches to a ( and } matches to a {.

Whitespace can be random and you need to clean it up. Sometimes there are spaces between bracket symbols and sometimes not. Words will be separated clearly with at least 1 whitespace.

Bracket levels will not be broken up between words. For example you would not see it like this.

{years [four score] ago (and seven) our fathers}

The [four score] (and seven) are on the same level but broken up between words. You would see this as

{years(and seven (four score)) ago our fathers}

Have fun! And good luck with those brackets!

Extra Challenge:
Prior to handling the problem you will proof read your string and look for 2 errors.

Mismatch bracket -- ending a ( with a ] or a } for an example causes an error to be detected and reported.

Missing bracket having 3 starting brackets but only 2 closing brackets causes an error to be detected and reported.

example:
((your[drink {remember to))) ovaltine)

Generates an error of "Mismatched bracket ) instead of } found"

example:
[can {and it(it (mix) up ) look silly]

Generates an error "Missing closing bracket"

example:
[racket for brackets (matching) is a} computers]

Generates an error "Missing opening bracket"

Also you can handle multiple sets on the same level broken up by words.

example:
{years [four score] ago (and seven) our fathers}

Generates the output:

four score and seven years ago our fathers

You would use left to right to give priority to which equal sets to output.

*/

#include <cassert>
#include <map>
#include <string>

using namespace std;

void trim(string &str)
{
	const string whitespace = " \n\r\t\f\v";

	size_t first = str.find_first_not_of(whitespace);
	if (string::npos == first)
	{
		str.clear();
		return;
	}
	str.erase(0, first);

	size_t last = str.find_last_not_of(whitespace);
	if (string::npos != last)
		str.erase(last + 1);
}

void replace_all(string &str, const string &from, const string &to)
{
	if (from.empty())
		return;

	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}

void clean(string &str)
{
	trim(str);
	for (;;)
	{
		auto nxt = str;
		replace_all(nxt, "  ", " ");
		if (str == nxt)
			break;
		str = nxt;
	}
}

string expand(string input)
{
	map<char, char> brackets{
		{ '{', '}' },
		{ '(', ')' },
		{ '[', ']' },
	};

	string result = "";
	auto begin = input.find_last_of("{([");
	while (begin != string::npos)
	{
		auto end = input.find_first_of(brackets[input[begin]], begin + 1);
		if (end == string::npos)
			return input;

		result += " " + input.substr(begin + 1, end - begin - 1) + " ";
		input.erase(begin, end - begin + 1);
		begin = input.find_last_of("{([");
	}
	clean(result);
	return result;
}

int main()
{
	assert(expand("((your[ drink {remember to}]) ovaltine)") == "remember to drink your ovaltine");
	assert(expand("[racket for {brackets (matching) is a} computers]") == "matching brackets is a racket for computers");
	assert(expand("[can {and it(it (mix) up ) } look silly]") == "mix it up and it can look silly");

	return 0;
}
