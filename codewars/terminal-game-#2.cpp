/*

Create the hero move method
Create a move method for your hero to move through the level.

Adjust the hero's position by changing the position attribute. The level is a grid with the following values:

00      01      02      03      04
10      11      12      13      14
20      21      22      23      24
30      31      32      33      34
40      41      42      43      44

The dir argument will be a string

up
down
left
right

If the position is not inside the level grid the method should throw an error and not move the hero

*/

#include <format>
#include <iostream>
#include <string>

using namespace std;

struct Hero
{
	int x, y;
	string position;

	Hero();
	void move(const string &direction);
};

Hero::Hero()
{
	x = y = 0;
	position = "00";
}

void Hero::move(const string &direction)
{
	auto X = x;
	auto Y = y;
	if (direction == "up")
		Y--;
	else if (direction == "down")
		Y++;
	else if (direction == "left")
		X--;
	else if (direction == "right")
		X++;

	if (X < 0 || Y < 0 || X > 4 || Y > 4)
		throw "Invalid direction!";

	x = X;
	y = Y;
	position = format("{}{}", y, x);
}

int main()
{
	Hero hero;
	hero.move("down");
	hero.move("right");
	cout << hero.position << endl;
	return 0;
}
