/*

It's Friday... so let's go golfing! Write code that determines the player's scoring on a hole in a game of golf. The code can be either a function or entire program. As the genre suggests, shortest code wins.

Input (parameters or stdin, your choice):

An integer representing the hole's par, guaranteed to be between 3 and 6
An integer representing the golfer's score, guaranteed to be between 1 and 64
Output (print to stdout or return, trailing newline allowed but not required, your choice):

if score is 1, output "Hole in one"
if score == par - 4 and par > 5, output "Condor"
if score == par - 3 and par > 4, output "Albatross"
if score == par - 2 and par > 3, output "Eagle"
if score == par - 1, output "Birdie"
if score == par, output "Par"
if score == par + 1, output "Bogey"
if score == par + 2, output "Double Bogey"
if score == par + 3, output "Triple Bogey"
if score > par + 3, output "Haha you loser"
EDIT Congrats to Dennis on having the shortest answer!

*/

#include <stdio.h>

const char *
score(int p, int s)
{
	if (s == 1)
		return "Hole in one";
	if (s == p - 4 && p > 5)
		return "Condor";
	if (s == p - 3 && p > 4)
		return "Albatross";
	if (s == p - 2 && p > 3)
		return "Eagle";
	if (s == p - 1)
		return "Birdie";
	if (s == p)
		return "Par";
	if (s == p + 1)
		return "Bogey";
	if (s == p + 2)
		return "Double Bogey";
	if (s == p + 3)
		return "Triple Bogey";
	if (s > p + 3)
		return "Haha you loser";
	return "Not Sure";
}

int
main()
{
	int p, s;

	for (p = 0; p <= 16; p++) {
		for (s = 0; s <= 16; s++)
			printf("p=%d s=%d | %s\n", p, s, score(p, s));
	}

	return 0;
}
