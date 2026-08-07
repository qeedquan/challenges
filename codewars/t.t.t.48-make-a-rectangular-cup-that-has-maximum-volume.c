/*

Description
We have a piece of cardboard square, side length is n cm. We use it to make a cuboid cup(The five side is paper, one side is empty):

_____________________________
|                           |
|                           |
|                           |
|                           |
|                           |
|                           |
|                           |
|___________________________|
First we need to cut four identical small squares in the four corners of the cardboard.

           _______________
      cut  |             |  cut
     ______|             |______
    |                           |
    |                           |
    |                           |
    |______              _______|
           |             |
      cut  |_____________|  cut
Then the four protruding part is folded upwards, a rectangular cup is made.

We can assume that the length of the small square is an integer. Please calculate, how much is the maximum volume of the cup we made?

Task
Complete function maximumVolume() that accepts a arguments n(a positive integer more than 4). Returns the maximum volume of the cup.

Example
maximumVolume(5)  === 9
3 * 3 * 1 = 9
maximumVolume(6)  === 16
4 * 4 * 1 = 16
maximumVolume(7)  === 25
5 * 5 * 1 = 25
maximumVolume(8)  === 36
6 * 6 * 1 = 36
maximumVolume(9)  === 50
5 * 5 * 2 = 50
maximumVolume(10)  === 72
6 * 6 * 2 = 72
maximumVolume(20)  === 588
14 * 14 * 3 = 588

*/

#include <assert.h>
#include <math.h>

int
maxvol(int n)
{
	int v0, v1;

	v0 = round(n / 6.0);
	v1 = n - (2 * v0);
	return v0 * v1 * v1;
}

int
main()
{
	assert(maxvol(5) == 9);
	assert(maxvol(6) == 16);
	assert(maxvol(7) == 25);
	assert(maxvol(8) == 36);
	assert(maxvol(9) == 50);
	assert(maxvol(10) == 72);
	assert(maxvol(20) == 588);

	return 0;
}
