/*

**In this Kata we are conducting important E.S.P. research**

You are in the lab and have been asked to focus your mind, harness all your psychic powers, and name the shape printed on the back of the card I am holding.

Suddenly, three things happen -
 * You realise that you have no psychic powers whatsoever
 * You notice that if you squint in the reflection of the window behind me you can see the back of my card
 * You decide to cheat in my experiment

## Kata Task

Name the shape on my card.

It is one of ```square```, ```diamond```, ```circle```


## Notes

Some real examples of my cards are shown below.

The card borders are all the same.

Shapes on each card are made of the same character, but it is not always ```*```


* **square**
/-------------------\
|                   |
|                   |
|    ***********    |
|    *         *    |
|    *         *    |
|    *         *    |
|    *         *    |
|    *         *    |
|    ***********    |
|                   |
|                   |
\-------------------/

* **diamond**
/-------------------\
|                   |
|         *         |
|        * *        |
|       *   *       |
|      *     *      |
|     *       *     |
|      *     *      |
|       *   *       |
|        * *        |
|         *         |
|                   |
\-------------------/

* **circle**
/-------------------\
|                   |
|                   |
|       *****       |
|     *       *     |
|    *         *    |
|    *         *    |
|    *         *    |
|     *       *     |
|       *****       |
|                   |
|                   |
\-------------------/

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef char Card[13][22];

const char *
shapename(Card card)
{
	if (card[2][10] != ' ')
		return "diamond";
	if (card[3][5] != ' ')
		return "square";
	return "circle";
}

int
main()
{
	Card square = {
		"/-------------------\\",
		"|                   |",
		"|                   |",
		"|    ***********    |",
		"|    *         *    |",
		"|    *         *    |",
		"|    *         *    |",
		"|    *         *    |",
		"|    *         *    |",
		"|    ***********    |",
		"|                   |",
		"|                   |",
		"\\-------------------/",
	};

	Card diamond = {
		"/-------------------\\",
		"|                   |",
		"|         *         |",
		"|        * *        |",
		"|       *   *       |",
		"|      *     *      |",
		"|     *       *     |",
		"|      *     *      |",
		"|       *   *       |",
		"|        * *        |",
		"|         *         |",
		"|                   |",
		"\\-------------------/",
	};

	Card circle = {
		"/-------------------\\",
		"|                   |",
		"|                   |",
		"|       *****       |",
		"|     *       *     |",
		"|    *         *    |",
		"|    *         *    |",
		"|    *         *    |",
		"|     *       *     |",
		"|       *****       |",
		"|                   |",
		"|                   |",
		"\\-------------------/",
	};

	assert(!strcmp(shapename(square), "square"));
	assert(!strcmp(shapename(diamond), "diamond"));
	assert(!strcmp(shapename(circle), "circle"));

	return 0;
}
