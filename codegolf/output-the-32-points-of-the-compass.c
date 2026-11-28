/*

The 32 points of the compass are: N, NbE, NNE, NEbN, NE, NEbE, ENE, EbN, E, EbS, ESE, SEbE, SE, SEbS, SSE, SbE, S, SbW, SSW, SWbS, SW, SWbW, WSW, WbS, W, WbN, WNW, NWbW, NW, NWbN, NNW, NbW. (SEbE is pronounced "Southeast by east"...)

Write a program or function that outputs all of these, in any order.

Input
None

Output
Each point of the compass must be output as correctly-cased string of 1-4 characters length, and must be separated from the other points of the compass in some manner (so a single string like 'NNENESE...' is not ok). Other than that, anything goes.

Scoring
Code golf. Standard rules apply.

*/

#include <stdio.h>

void
output()
{
	puts("N, NbE, NNE, NEbN, NE, NEbE, ENE, EbN, E, EbS, ESE, SEbE, SE, SEbS, SSE, SbE, S, SbW, SSW, SWbS, SW, SWbW, WSW, WbS, W, WbN, WNW, NWbW, NW, NWbN, NNW, NbW");
}

int
main()
{
	output();
	return 0;
}
