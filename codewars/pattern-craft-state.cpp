/*

The State Design Pattern can be used, for example, to manage the state of a tank in the StarCraft game.

The pattern consists in isolating the state logic in different classes rather than having multiple ifs to determine what should happen.

Your Task
Complete the code so that when a Tank goes into SiegeMode it cannot move and its damage goes to 20. When it goes to TankMode it should be able to move and the damage should be set to 5.

You have 3 classes:

Tank: has a state, canMove and damage properties
SiegeState and TankState: has canMove and damage properties
Note: The tank initial state should be TankState.

*/

#include <iostream>

using namespace std;

class SiegeState
{
	bool canMove = false;
	int damage = 20;
};

class TankState
{
	bool canMove = true;
	int damage = 5;

	friend class Tank;
};

class Tank : TankState
{
public:
	bool canMove()
	{
		return this->TankState::canMove;
	}

	int damage()
	{
		return this->TankState::damage;
	}
};

int main()
{
	Tank tank;
	cout << tank.canMove() << endl;
	cout << tank.damage() << endl;
	return 0;
}
