/*

Create a function that returns the name of the winner in a fight between two fighters.

Each fighter takes turns attacking the other and whoever kills the other first is victorious. Death is defined as having health <= 0.

Each fighter will be a Fighter object/instance. See the Fighter class below in your chosen language.

Both health and damagePerAttack (damage_per_attack for python) will be integers larger than 0. You can mutate the Fighter objects.

Your function also receives a third argument, a string, with the name of the fighter that attacks first.

Example:
  declare_winner(Fighter("Lew", 10, 2), Fighter("Harry", 5, 4), "Lew") => "Lew"

  Lew attacks Harry; Harry now has 3 health.
  Harry attacks Lew; Lew now has 6 health.
  Lew attacks Harry; Harry now has 1 health.
  Harry attacks Lew; Lew now has 2 health.
  Lew attacks Harry: Harry now has -1 health and is dead. Lew wins.
class Fighter(object):
    def __init__(self, name, health, damage_per_attack):
        self.name = name
        self.health = health
        self.damage_per_attack = damage_per_attack

    def __str__(self): return "Fighter({}, {}, {})".format(self.name, self.health, self.damage_per_attack)
    __repr__=__str__

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[16];
	int health;
	int damage_per_attack;
} Fighter;

const char *
declare_winner(Fighter *fighter1, Fighter *fighter2, const char *first_attacker)
{
	int health1, health2;

	health1 = ceil((fighter2->health * 1.0) / fighter1->damage_per_attack);
	health2 = ceil((fighter1->health * 1.0) / fighter2->damage_per_attack);

	if (health1 < health2)
		return fighter1->name;
	if (health1 > health2)
		return fighter2->name;
	return first_attacker;
}

int
main()
{
	struct test {
		Fighter fighter1;
		Fighter fighter2;
		const char *first_attacker;
		const char *expected;
	} tests[] = {
		{ { "Lew", 10, 2 }, { "Harry", 5, 4 }, "Lew", "Lew" },
		{ { "Lew", 10, 2 }, { "Harry", 5, 4 }, "Harry", "Harry" },
		{ { "Harald", 20, 5 }, { "Harry", 5, 4 }, "Harry", "Harald" },
		{ { "Harald", 20, 5 }, { "Harry", 5, 4 }, "Harald", "Harald" },
		{ { "Jerry", 30, 3 }, { "Harald", 20, 5 }, "Jerry", "Harald" },
		{ { "Jerry", 30, 3 }, { "Harald", 20, 5 }, "Harald", "Harald" },
	};

	struct test *test;
	size_t index;
	const char *result;

	for (index = 0; index < nelem(tests); index++) {
		test = tests + index;
		result = declare_winner(&test->fighter1, &test->fighter2, test->first_attacker);
		assert(!strcmp(result, test->expected));
	}

	return 0;
}
