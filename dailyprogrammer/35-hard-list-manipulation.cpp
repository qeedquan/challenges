/*

The objective of this exercise is to maintain a list of Strings in memory that support undo and redo. Write a program that allows the user to add, edit, delete, undo, and redo entries in a list. You must be able to undo and redo everything you've done during the execution of this program. After each command is run, always print out the list (unless you're doing this in a UI). Before writing any code, first think about how to write add, edit, and remove with undo and redo in mind. If there are no submissions to this post, I'll reply with some hints.

Sample Run:

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): A

Enter text to add: Venus

Venus

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): A

Enter text to add: Mars

Venus

Mars

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): U

Venus

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): U

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): R

Venus

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): R

Venus

Mars

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): A

Enter text to add: Saturn

Venus

Mars

Saturn

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): E

Enter index to edit: 1

Enter text to edit: Earth

Venus

Earth

Saturn

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): U

Venus

Mars

Saturn

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): R

Venus

Earth

Saturn

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): D

Enter index to delete: 2

Venus

Earth

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): U

Venus

Earth

Saturn

Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo): R

Venus

Earth

*/

#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

void ui()
{
	const string help = "Enter command ('A'dd, 'E'dit, 'D'elete, 'U'ndo, 'R'edo, 'Q'uit)";

	char choice;
	size_t index;
	string input;
	deque<string> text;
	deque<decltype(text)> undo, redo;

	for (;;)
	{
		cout << help << endl;
		cout << "> ";
		cin >> choice;

		switch (tolower(choice))
		{
		case 'a':
			undo.push_back(text);
			cout << "Enter text to add: ";
			cin >> input;
			text.push_back(input);
			break;

		case 'e':
			undo.push_back(text);
			redo.clear();
			cout << "Enter index to edit ";
			cin >> index;
			if (index >= text.size())
				continue;
			cout << "Enter text to edit: ";
			cin >> input;
			text.at(index).swap(input);
			break;

		case 'd':
			undo.push_back(text);
			redo.clear();
			cout << "Enter index to delete: ";
			cin >> index;
			if (index < text.size())
				text.erase(text.begin() + index);
			break;

		case 'u':
			if (undo.empty())
				break;
			redo.push_back(move(text));
			undo.back().swap(text);
			undo.pop_back();
			break;

		case 'r':
			if (redo.empty())
				break;
			undo.push_back(move(text));
			redo.back().swap(text);
			redo.pop_back();
			break;

		case 'q':
			return;
		}

		copy(text.begin(), text.end(), ostream_iterator<string>(cout, "\n"));
	}
}

int main()
{
	ui();
	return 0;
}
