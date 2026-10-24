/*

Description:
The world championship in Tic Tac Toe, The X-Games is underway. We have been asked to write a program to see if there is a winning move possible. This tool will be used by live commentators to use in their play by play.

input
(Next player's Move either an X or an O)

(3 x 3 grid showing the current game)

The grid can have 3 characters

X for spot held by the X player

O for spot held by the O player


for an empty spot

Example Input 1:
X
XX-
-XO
OO-
Example Input 2:
O
O-X
-OX
---
Example Input 3:
X
--O
OXX
---
Output:
Shows the board with the winning move in place. If there is no winning move print out "No winning move"

Example Output 1:
XXX
-XO
OO-
Example Output 2:
O-X
-OX
--O
Example Output 3:
No Winning Move!
Extra Challenge:
Boards where several moves can "win" display all boards showing the winning moves with a message saying how many wins are possible

Boards with no winning move -- suggest a "block" move the player should make instead with a message saying "No winning move: Block here"

Challenge Credit:
This challenge was from u/202halffound

*/

#include <iostream>

using namespace std;

// ported from @skeeto solution
struct TicTacToe
{
	char grid[3][3] = { 0 };

	bool is_game_over() const
	{
		for (int y = 0; y < 3; y++)
		{
			if (grid[0][y] != '-')
			{
				if (grid[0][y] == grid[1][y] && grid[1][y] == grid[2][y])
					return true;
			}
		}
		for (int x = 0; x < 3; x++)
		{
			if (grid[x][0] != '-')
			{
				if (grid[x][0] == grid[x][1] && grid[x][1] == grid[x][2])
					return true;
			}
		}
		if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
			return true;
		if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])
			return true;
		return false;
	}

	bool place(char turn)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (grid[x][y] == '-')
				{
					grid[x][y] = turn;
					if (is_game_over())
						return true;
					grid[x][y] = '-';
				}
			}
		}
		return false;
	}
};

istream &operator>>(istream &in, TicTacToe &ttt)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
			in >> ttt.grid[x][y];
		in.ignore(1);
	}
	return in;
}

ostream &operator<<(ostream &out, const TicTacToe &ttt)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
			out << ttt.grid[x][y];
		out << endl;
	}
	return out;
}

int main()
{
	char turn;
	cin >> turn;
	TicTacToe ttt;
	cin >> ttt;
	if (ttt.place(turn))
		cout << ttt;
	else
		cout << "No Winning Move!" << endl;
	return 0;
}
