/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version ( http://www.codewars.com/kata/570e6d8576f0cde131000129 )

Task:
Maybe you know such a game (or a magic), there are three hats (or cups, or other containers) on the table, one of them put in a thing(A ball, or a coin, or other small things), at this time quickly moving three hats(exchange their position), After stop moving, Let the player guess which hat has something in it.

Let's us play the game in this kata.

Suppose we have three hats on the table, Their positions are 1, 2 and 3. Put a thing in the middle of the hat(position 2), and then begin moving...

Give you a string array exchange, Array elements are similar to "1-2"(it means 1 and 2 exchange position),"3-1"(1 and 3 exchange position)...

Finally, please return the position of the hat (which one hidden something), "1", "2", or "3"(String form)

Example:
example1:
exchange=["1-2","1-3","2-3"]
at the beginning, put a ball into a hat at position 2
"1-2"==> exchange 1 and 2, then the ball move to position 1
"1-3"==> exchange 1 and 3, then the ball move to position 3
"2-3"==> exchange 2 and 3, then the ball move to position 2
the exchange ends, and finally, the ball at position 2.
So, sc(["1-2","1-3","2-3"]) should return "2"

example2:
exchange=["1-2","2-3","1-3"]
at the beginning, put a ball into a hat at position 2
"1-2"==> exchange 1 and 2, then the ball move to position 1
"2-3"==> exchange 2 and 3, then the ball still at position 1
"1-3"==> exchange 1 and 3, then the ball move to position 3
the exchange ends, and finally, the ball at position 3.
So, sc(["1-2","1-3","2-3"]) should return "3"

example3:
exchange=["1-2","1-3","2-3","2-1","3-1","3-2"]
ball moving: 2-->1-->3-->2-->1-->3--2
finally, the ball at position 2.
sc(["1-2","1-3","2-3","1-2","1-3","2-3"]) should return "2"

*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sc(const vector<string> &exchanges)
{
	int cup[3] = { 0, 1, 0 };
	for (auto &exchange : exchanges)
	{
		int i, j;
		if (!sscanf(exchange.c_str(), "%d-%d", &i, &j))
			return "invalid";

		i -= 1;
		j -= 1;

		if (i < 0 || i >= 3 || j < 0 || j >= 3)
			return "invalid";
		swap(cup[i], cup[j]);
	}

	for (size_t i = 0; i < 3; i++)
	{
		if (cup[i])
			return format("{0}", i + 1);
	}
	return "unreachable";
}

int main()
{
	assert(sc({ "1-2", "1-3", "2-3" }) == "2");
	assert(sc({ "1-2", "2-3", "1-3" }) == "3");
	assert(sc({ "1-2", "1-3", "2-3", "2-1", "3-1", "3-2" }) == "2");

	return 0;
}
