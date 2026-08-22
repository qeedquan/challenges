/*

This is a simple one: print an ASCII Gantt chart.

Given tasks' ranges (start-time - end-time Tuples), print a Gantt timeline in the form of - characters for each task duration - each task in a new line.

Example
Say my tasks ranges are 28->35, 34->40, 39->44, the Gantt will look like this:

                            -------
                                  ------
                                       -----
Specifications
You can write a full program, a named function or an anonymous function.
Your program/function should accept the tasks via STDIN or as arguments.
Each task should be represented as a string of start->end where start and end are Integers. Tasks are separated by spaces or commas. Alternatively, you may get it as a Tuple of Integers, or as an Array/Collection of 2 Integers. (For example, in JavaScript you can get it as [start,end] - this is allowed).
Any non-negative number of tasks (arguments) should be supported.
To make it clear, a single argument of tasks collection is not allowed. You can either parse a single string argument, or support zero-or-more tasks arguments. Where task is a tuple or a collection of size 2.
You can assume only valid input will be given. That means, each task has a positive duration.
Return value does not matter, your code must print the timeline on STDOUT.
Output: per task, start spaces followed by (end-start) dashes and a \n.
Needless to say, output lines should be ordered correspondingly with the input (tasks) order.
Trailing spaces before the \n are allowed, if that helps you.
Test cases
Input:
(empty)

Output:
(empty)


Input:
0->7,5->6,3->6

Output:
-------
     -
   ---


Input:
5->20,5->20,2->10,15->19

Output:
     ---------------
     ---------------
  --------
               ----
Winning
This is code-golf so the least code length (in bytes) wins.
Traditionally, tie breaker is earlier post.
"Standard loopholes are no longer funny".
-----

EDIT
As many of you understood that it is allowed to have a single tasks collection argument, and since there's no much different between that and the original varargs requirement, it is now allowed to have a single collection argument, if you don't want to use the varargs option, or in case your language does not support varargs.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

void
gantt(Point *p, size_t n)
{
	size_t i;
	int j;

	printf("%zu intervals\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < p[i].x; j++)
			putchar(' ');
		for (j = 0; j < p[i].y - p[i].x; j++)
			putchar('-');
		puts("");
	}
	puts("");
}

int
main()
{
	Point p1[] = {
	    {28, 35},
	    {34, 40},
	    {39, 44},
	};

	Point p2[] = {
	    {0, 7},
	    {5, 6},
	    {3, 6},
	};

	Point p3[] = {
	    {5, 20},
	    {5, 20},
	    {2, 10},
	    {15, 19},
	};

	gantt(NULL, 0);
	gantt(p1, nelem(p1));
	gantt(p2, nelem(p2));
	gantt(p3, nelem(p3));

	return 0;
}
