/*

Enter an integer for the number of iterations, and create a program that prints out a sierpinski triangle.

First 4 iterations as an example
https://imgur.com/fjlTg

Thanks to Rinfiyks for the challenge at /r/dailyprogrammer_ideas

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void iterate(vector<string> &triangle)
{
	string spaces(triangle.size(), ' ');
	auto previous = triangle;
	for (auto &line : triangle)
		line = spaces + line + spaces;
	for (auto line : previous)
		triangle.push_back(line + " " + line);
}

void sierpinski(int depth)
{
	vector<string> triangle = { "x" };
	for (auto i = 1; i < depth; i++)
		iterate(triangle);

	cout << "n=" << depth << endl;
	for (auto line : triangle)
		cout << line << endl;
	cout << endl;
}

int main()
{
	for (auto depth = 1; depth <= 6; depth++)
		sierpinski(depth);
	return 0;
}
