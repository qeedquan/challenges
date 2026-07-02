/*

Write a program that simulates a calculator display, showing the image of a number as it would appear on such a display. The sign of the number should be displayed directly before the first digit.

The image of each digit or sign is created by turning on or off seven segments of a liquid crystal display. The program should print the display state using the symbols '|' (vertical bar), '_' (underscore), and ' ' (space). The digits and the minus sign on the display should be depicted as follows:

https://static.e-olymp.com/content/4a/4aee9fb0de9fdae9c92f2b9b9b6615e2a693e002.jpg

Each character is displayed as a 3×3 matrix of symbols (including trailing spaces in each row).

Input
An integer N (∣N∣<10^10).

Output
The representation of the number on the calculator display.
https://static.e-olymp.com/content/8b/8bf4016065a7c341a94173dd307c4cca5cbfea8a.jpg

An example of the output data is shown in the figure:

Examples

Input #1
-123

Answer #1
       _  _
 _   | _| _|
     ||_  _|

*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<pair<char, int>, string> LEDS = {
	{ { '0', 0 }, " _ " },
	{ { '0', 1 }, "| |" },
	{ { '0', 2 }, "|_|" },
	{ { '1', 0 }, "   " },
	{ { '1', 1 }, "  |" },
	{ { '1', 2 }, "  |" },
	{ { '2', 0 }, " _ " },
	{ { '2', 1 }, " _|" },
	{ { '2', 2 }, "|_ " },
	{ { '3', 0 }, " _ " },
	{ { '3', 1 }, " _|" },
	{ { '3', 2 }, " _|" },
	{ { '4', 0 }, "   " },
	{ { '4', 1 }, "|_|" },
	{ { '4', 2 }, "  |" },
	{ { '5', 0 }, " _ " },
	{ { '5', 1 }, "|_ " },
	{ { '5', 2 }, " _|" },
	{ { '6', 0 }, " _ " },
	{ { '6', 1 }, "|_ " },
	{ { '6', 2 }, "|_|" },
	{ { '7', 0 }, " _ " },
	{ { '7', 1 }, "  |" },
	{ { '7', 2 }, "  |" },
	{ { '8', 0 }, " _ " },
	{ { '8', 1 }, "|_|" },
	{ { '8', 2 }, "|_|" },
	{ { '9', 0 }, " _ " },
	{ { '9', 1 }, "|_|" },
	{ { '9', 2 }, " _|" },
	{ { '-', 0 }, "   " },
	{ { '-', 1 }, " _ " },
	{ { '-', 2 }, "   " }

};

void solve(const string &input)
{
	for (auto line = 0; line < 3; line++)
	{
		for (auto symbol : input)
			cout << LEDS[{ symbol, line }];
		cout << endl;
	}
}

int main()
{
	solve("-123");
	solve("0123456789");

	return 0;
}
