/*

Several years back, Hot Wheels made a simple flash game called "Formula Fuelers Racers"*.
To play the game, you select three ingredients from a fridge to put into your car, which is then raced against the computer's randomly-generated car.
It turns out the mechanics of this game are pretty simple. First off, the actual race "time" of your car is randomly generated and has no bearing on whether or not you win the race.
Secondly, the winner of the race is determined by a score which is calculated from the selected ingredients (duplicate ingredients are allowed, and the order matters).
Each ingredient has an associated "value" and an associated "operation" as shown in the following table:

#   ingredient     val  op
1   Hot Salsa       2   +
2   Root Beer       1   +
3   Milk            1   +
4   Pickle Juice    2   +
5   Mystery Lunch   -3  *
6   BBQ Sauce       2   +
7   Egg             1   +
8   Ketchup         2   +
9   Mustard         -1  *
10  Melon           1   +
11  Chocolate Milk  1   +
12  Mayonnaise      -2  *
13  Baby Food       0   +
14  Pepper          1   +
15  Salt            2   +
16  Syrup           -1  *
17  Salad Dressing  2   +
18  Orange Juice    1   +
19  Soy Sauce       2   +
For convenience, this challenge will be referring to ingredients by their number and not their name. Here are the steps to compute a score:

First, initialize the score with the value of the first ingredient.
Then, use the second ingredient's operation to combine the current score and the second ingredient's value to get an updated score.
Finally, use the third ingredient's operation to combine the current score and the third ingredient's value to get the final score.
Higher scores are better and always beat lower scores.

For example, the ingredients 1 2 3 have a score of (2+1)+1 = 4. The ingredients 7 5 6 have a score of (1*-3)+2 = -1. Therefore, 1 2 3 beats 7 5 6.

Challenge

In this challenge, you shall write a program which takes an ordered list of 3 integers and outputs the corresponding score.

Input

Your program may accept a list of three integers in the most convenient format. You are allowed to use either 1-indexing for the ingredient names (as above) or 0-indexing (subtract 1 from every index above).

Ouput

Your program must output a single integer indicating the score.

Test Cases

4 5 5  =>  18 // max score
5 5 5  =>  -27 // min score
13 13 13  =>  0
1 2 3  =>  4
7 5 6  =>  -1
16 2 19  =>  2
19 7 12  =>  -6
*This page is pretty outdated and doesn't work in some browsers, but you don't need to play the game for this challenge.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	int val;
	int op;
} Ingredient;

int
score(unsigned a[3])
{
	static const Ingredient tab[] = {
	    {"Hot Salsa", 2, '+'},
	    {"Root Beer", 1, '+'},
	    {"Milk", 1, '+'},
	    {"Pickle Juice", 2, '+'},
	    {"Mystery Lunch", -3, '*'},
	    {"BBQ Sauce", 2, '+'},
	    {"Egg", 1, '+'},
	    {"Ketchup", 2, '+'},
	    {"Mustard", -1, '*'},
	    {"Melon", 1, '+'},
	    {"Chocolate Milk", 1, '+'},
	    {"Mayonnaise", -2, '*'},
	    {"Baby Food", 0, '+'},
	    {"Pepper", 1, '+'},
	    {"Salt", 2, '+'},
	    {"Syrup", -1, '*'},
	    {"Salad Dressing", 2, '+'},
	    {"Orange Juice", 1, '+'},
	    {"Soy Sauce", 2, '+'},
	};

	const Ingredient *p;
	size_t i;
	int r;

	for (i = 0; i < 3; i++) {
		if (a[i] == 0 || a[i] > nelem(tab))
			return INT_MIN;
	}

	r = tab[a[0] - 1].val;
	for (i = 1; i < 3; i++) {
		p = tab + a[i] - 1;
		switch (p->op) {
		case '+':
			r += p->val;
			break;
		case '*':
			r *= p->val;
			break;
		}
	}
	return r;
}

int
main(void)
{
	unsigned a1[] = {4, 5, 5};
	unsigned a2[] = {5, 5, 5};
	unsigned a3[] = {13, 13, 13};
	unsigned a4[] = {1, 2, 3};
	unsigned a5[] = {7, 5, 6};
	unsigned a6[] = {16, 2, 19};
	unsigned a7[] = {19, 7, 12};

	assert(score(a1) == 18);
	assert(score(a2) == -27);
	assert(score(a3) == 0);
	assert(score(a4) == 4);
	assert(score(a5) == -1);
	assert(score(a6) == 2);
	assert(score(a7) == -6);

	return 0;
}
