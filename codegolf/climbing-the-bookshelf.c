/*

Introduction

Introduction
You're making a robot that can navigate a set of books of varying heights. It can climb books and jump off books, but if the distance is too big it will stop to prevent damage. To figure out the ideal design, you're writing a simulator.

Your program will take as input a list of numbers, representing the heights of the books in the bookshelf, as well as a number indicating the durability of the robot. Starting from the first item of the list, your robot will traverse the bookshelf. If the robot comes across a change in height, it will only be able to continue if the change is less than or equal to the robot's durability. Your job is to output which book the robot is on when it stops, starting from either 0 or 1. You may safely assume that the height of the first book the robot is on will be equal to or less than the robot's durability.

Scoring
This is code-golf, so shortest answer wins.

Examples (starting from 1)
[1, 1, 1], 1 -> 3
[0, 1, 0], 0 -> 1
[1, 2, 3, 2], 1 -> 4
[1, 3, 4, 4, 0], 2 -> 4
[1, 3, 4, 4, 0, 1], 2 -> 4

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
location(int *a, size_t n, int d)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (abs(a[i] - a[i - 1]) > d)
			break;
	}
	return i;
}

int
main(void)
{
	int a1[] = {1, 1, 1};
	int a2[] = {0, 1, 0};
	int a3[] = {1, 2, 3, 2};
	int a4[] = {1, 3, 4, 4, 0};
	int a5[] = {1, 3, 4, 4, 0, 1};

	assert(location(a1, nelem(a1), 1) == 3);
	assert(location(a2, nelem(a2), 0) == 1);
	assert(location(a3, nelem(a3), 1) == 4);
	assert(location(a4, nelem(a4), 2) == 4);
	assert(location(a5, nelem(a5), 2) == 4);

	return 0;
}
