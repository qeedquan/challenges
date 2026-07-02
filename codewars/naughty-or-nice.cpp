/*

Happy Holidays fellow Code Warriors!
It's almost Christmas! That means Santa's making his list, and checking it twice. Unfortunately, elves accidentally mixed the Naughty and Nice list together! Santa needs your help to save Christmas!

Save Christmas!
Santa needs you to write two functions. Both of the functions accept a sequence of objects. The first one returns a sequence containing only the names of the nice people, and the other returns a sequence containing only the names of the naughty people. Return an empty sequence [] if the result from either of the functions contains no names.

The objects in the passed will represent people. Each object contains two properties: name and wasNice.
name - The name of the person
wasNice - True if the person was nice this year, false if they were naughty

Person Object Examples
{ name: 'Warrior reading this kata', wasNice: true }
{ name: 'xDranik', wasNice: false }

Test Examples

getNiceNames( [
    { name: 'Warrior reading this kata', wasNice: true },
    { name: 'xDranik', wasNice: false },
    { name: 'Santa', wasNice: true }
] )
// => returns [ 'Warrior reading this kata', 'Santa' ]

getNaughtyNames( [
    { name: 'Warrior reading this kata', wasNice: true },
    { name: 'xDranik', wasNice: false },
    { name: 'Santa', wasNice: true }
] )
// => returns [ 'xDranik' ]

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
	string name;
	bool wasNice;
};

vector<string> filterNames(const vector<Person> &people, bool wasNice)
{
	vector<string> result;
	for (auto person : people)
	{
		if (person.wasNice == wasNice)
			result.push_back(person.name);
	}
	return result;
}

vector<string> getNiceNames(const vector<Person> &people)
{
	return filterNames(people, true);
}

vector<string> getNaughtyNames(const vector<Person> &people)
{
	return filterNames(people, false);
}

int main()
{
	vector<Person> people =
	{
		{"Warrior reading this kata", true},
		{"xDranik", false},
		{"Santa", true},
	};

	auto nice = getNiceNames(people);
	auto naughty = getNaughtyNames(people);

	for (auto name : nice)
		cout << name << endl;
	cout << endl;
	for (auto name : naughty)
		cout << name << endl;

	return 0;
}
