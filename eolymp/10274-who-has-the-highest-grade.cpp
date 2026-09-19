/*

Petryk, Marichka, and Olenka have just got their grades. They decided to play a game: the winner is a person who got the highest grade.

Please help them to figure out who is the winner.

Input
The first line contains three integers p, m, o (1≤p,m,o≤12) — the grades of Petryk, Marichka, and Olenka.

It is guaranteed that all grades are different.

Output
Print out «Petryk» if Petryk has the highest grade; print out «Marichka» if Marichka has the highest grade; otherwise, print out «Olenka».

Examples

Input #1
8 10 12

Answer #1
Olenka

Input #2
7 9 3

Answer #2
Marichka

*/

#include <cassert>
#include <string>

using namespace std;

string solve(int p, int m, int o)
{
	if (p > m && p > o)
		return "Petryk";
	else if (m > p && m > o)
		return "Marichka";
	return "Olenka";
}

int main()
{
	assert(solve(8, 10, 12) == "Olenka");
	assert(solve(7, 9, 3) == "Marichka");

	return 0;
}
