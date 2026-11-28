/*

Description

You are given an object street of class Street that represents a circular street and a positive integer k which represents
a maximum bound for the number of houses in that street (in other words, the number of houses is less than or equal to k).
Houses' doors could be open or closed initially.

Initially, you are standing in front of a door to a house on this street. Your task is to count the number of houses in the street.

The class Street contains the following functions which may help you:

    void openDoor(): Open the door of the house you are in front of.
    void closeDoor(): Close the door of the house you are in front of.
    boolean isDoorOpen(): Returns true if the door of the current house is open and false otherwise.
    void moveRight(): Move to the right house.
    void moveLeft(): Move to the left house.

Return ans which represents the number of houses on this street.

Example 1:

Input: street = [0,0,0,0], k = 10
Output: 4
Explanation: There are 4 houses, and all their doors are closed.
The number of houses is less than k, which is 10.

Example 2:

Input: street = [1,0,1,1,0], k = 5
Output: 5
Explanation: There are 5 houses, and the doors of the 1st, 3rd, and 4th house (moving in the right direction) are open, and the rest are closed.
The number of houses is equal to k, which is 5.

Constraints:

    n == number of houses
    1 <= n <= k <= 10^3

*/

#include <assert.h>
#include <stdio.h>

typedef struct Street Street;
typedef struct Track Track;

struct Street {
	void *aux;
	void (*opendoor)(Street *);
	void (*closedoor)(Street *);
	bool (*isdooropen)(Street *);
	void (*moveright)(Street *);
	void (*moveleft)(Street *);
};

struct Track {
	int *house;
	size_t size;
	size_t position;
};

void
trackopendoor(Street *s)
{
	Track *t;

	t = s->aux;
	t->house[t->position] = 1;
}

void
trackclosedoor(Street *s)
{
	Track *t;

	t = s->aux;
	t->house[t->position] = 0;
}

bool
trackisdooropen(Street *s)
{
	Track *t;

	t = s->aux;
	return t->house[t->position];
}

void
trackmoveright(Street *s)
{
	Track *t;

	t = s->aux;
	t->position = (t->position + 1) % t->size;
}

void
trackmoveleft(Street *s)
{
	Track *t;

	t = s->aux;
	if (t->position == 0)
		t->position = t->size - 1;
	else
		t->position -= 1;
}

void
trackinit(Street *s, Track *t)
{
	t->position = 0;
	s->aux = t;
	s->opendoor = trackopendoor;
	s->closedoor = trackclosedoor;
	s->isdooropen = trackisdooropen;
	s->moveright = trackmoveright;
	s->moveleft = trackmoveleft;
}

int
housecount(Street *s, int k)
{
	int i;

	for (i = 0; i < k; i++) {
		s->closedoor(s);
		s->moveright(s);
	}

	for (i = 0; i < k; i++) {
		if (s->isdooropen(s))
			break;
		s->opendoor(s);
		s->moveright(s);
	}
	return i;
}

void
test(Track *t, int k, int r)
{
	Street s;

	trackinit(&s, t);
	assert(housecount(&s, k) == r);
}

int
main()
{
	Track t1 = {
		.house = (int[4]){ 0, 0, 0, 0 },
		.size = 4,
	};

	Track t2 = {
		.house = (int[5]){ 1, 0, 1, 1, 0 },
		.size = 5,
	};

	test(&t1, 10, 4);
	test(&t2, 5, 5);

	return 0;
}
