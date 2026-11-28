/*

A newspaper is made of several sheets; for the purposes of this question, each sheet of newsprint holds four pages of the final newspaper. Here is an example of three sheets of newsprint making up a newspaper with twelve pages:

 ___________
|2    |   11|
|  ___|_____|_
| |4    |    9|
|_|  ___|_____|_
  | |6    |    7|
  |_|     |     |
    |     |     |
    |_____|_____|
(Pages 1, 3, 5, 8, 10 and 12 are on the reverse of these sheets so you can't see them here.)

Your challenge, should you choose to accept it, is to output all the sets of pages that are on each sheet of a given newspaper.

You can take either the number of sheets (which is always a positive integer) or the number of pages (which is always a positive multiple of 4), but please indicate which.

You can output the sets of pages in any reasonable order, as long as it is clear which pages belong in which set.

For example, given an input of 3 sheets or 12 pages, you could output (1, 2, 11, 12), (3, 4, 9, 10) and (5, 6, 7, 8); or you could output (8, 5, 7, 6), (10, 3, 9, 4) and (12, 1, 11, 2); or any variant thereof, but you cannot of course output 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12.

This is code golf, so please make your program or function as short as possible. (I will even accept the shortest overall program as the answer on request of its author if doing so will earn me a Winter Bash hat.)

*/

#include <stdio.h>

void
output(int n)
{
	int i;

	for (i = 1; 2 * i < n; i += 2)
		printf("%d %d %d %d\n", i + 1, i, n - i, n - i + 1);
	printf("\n");
}

int
main()
{
	output(4);
	output(8);
	output(12);
	return 0;
}
