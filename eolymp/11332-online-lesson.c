/*

a students joined the videoconference lesson. But some of the students could not join due to the lack of Internet.
Determine how many students were unable to join the video conference if it is known that there are s students in the class.

Input
Two lines, each containing one integer:

the first line contains the number s (1≤s≤10^6) — the number of students in the class;

the second line contains the number a (0≤a≤10^6) — the number of students who could join the lesson.

Output
Print the number of students who were unable to join the video conference.

Examples

Input #1
30
6

Answer #1
24

*/

#include <assert.h>

int
solve(int s, int a)
{
	return s - a;
}

int
main()
{
	assert(solve(30, 6) == 24);

	return 0;
}
