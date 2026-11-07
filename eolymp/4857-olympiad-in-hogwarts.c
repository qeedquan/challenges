/*

Hogwarts is hosting its traditional annual Magic Theory Olympiad for first-year students. The school's caretaker, Argus Filch, has been tasked with assigning students to classrooms.

Each of the four houses has sent its best students to the Olympiad: g students from Gryffindor, s from Slytherin, h from Hufflepuff, and r from Ravenclaw. Filch has m classrooms at his disposal.

Each classroom is enchanted with an expansion charm, so it can accommodate any number of students. However, it must be taken into account that students from the same house, when placed in the same room, might take the opportunity to cheat by sharing ideas on how to solve the tasks. Therefore, the number of students from the same house in any single classroom should be minimized.

We define an optimal seating arrangement as one that minimizes the maximum number of students from the same house in any classroom.

Determine the minimum possible number of students from the same house that Filch will have to place in the same classroom, even under an optimal seating arrangement.

Input
The first line contains four integers g,s,h, and r (1≤g,s,h,r≤1000) — the number of students representing Gryffindor, Slytherin, Hufflepuff, and Ravenclaw, respectively.

The second line contains a single integer m (1≤m≤1000) — the number of available classrooms.

Output
Print a single integer — the minimum possible number of students from the same house that will have to be placed in the same classroom, even with an optimal arrangement.

Examples

Input #1
4 3 4 4
2

Answer #1
2

Input #2
15 14 13 14
5

Answer #2
3

*/

#include <assert.h>
#include <math.h>

int
solve(int g, int s, int h, int r, int m)
{
	return ceil(fmax(fmax(g, s), fmax(h, r)) / m);
}

int
main()
{
	assert(solve(4, 3, 4, 4, 2) == 2);
	assert(solve(15, 14, 13, 14, 5) == 3);

	return 0;
}
