/*

Something is wrong with our Warrior class. The strike method does not work correctly. The following shows an example of this code being used:

var ninja = new Warrior('Ninja');
var samurai = new Warrior('Samurai');

samurai.strike(ninja, 3);
// ninja.health should == 70

Can you figure out what is wrong?

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	char name[32];
	int health;
} Warrior;

void
strike(Warrior *, Warrior *enemy, int swings)
{
	enemy->health = max(0, enemy->health - (swings * 10));
}

int
main()
{
	Warrior ninja = { "Ninja", 100 };
	Warrior samurai = { "Samurai", 100 };

	strike(&samurai, &ninja, 3);
	assert(ninja.health == 70);

	return 0;
}
