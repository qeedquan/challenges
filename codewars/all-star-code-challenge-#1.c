/*

This Kata is intended as a small challenge for my students

All Star Code Challenge #1

Write a function, called sumPPG, that takes two NBA player objects/struct/Hash/Dict/Class and sums their PPG

Examples:
function NBAplayer(name, team, ppg){
  this.name=name;
  this.team=team;
  this.ppg=ppg;
}

var iverson = new NBAplayer("Iverson", "76ers", 11.2);
var jordan = new NBAplaer("Jordan", "bulls", 20.2);
sumPPG(iverson, jordan); // => 31.4

*/

#include <assert.h>

typedef struct {
	const char *name;
	const char *team;
	double ppg;
} NBAPlayer;

double
sumppg(NBAPlayer *player1, NBAPlayer *player2)
{
	return player1->ppg + player2->ppg;
}

int
main()
{
	NBAPlayer player1 = { "Iverson", "76ers", 11.2 };
	NBAPlayer player2 = { "Jordan", "bulls", 20.2 };

	assert(sumppg(&player1, &player2) == 31.4);

	return 0;
}
