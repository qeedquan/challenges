/*

Your task is to output the exact string

The Jabberwocky
without taking input. Normal rules for input and output apply, so both functions and programs are allowed.

Of course there is a catch, it wouldn't be fun without a catch. Your program, when stripped of non-alphabetic characters, must start the poem The Jabberwocky (case insensitive). To start the poem it must be a continuous substring of the poem starting at the beginning. The empty string is fine (although you probably won't score very well).

Here is the text for reference:

twasbrilligandtheslithytovesdidgyreandgimbleinthewabeallmimsyweretheborogovesandthemomerathsoutgrabebewarethejabberwockmysonthejawsthatbitetheclawsthatcatchbewarethejubjubbirdandshunthefrumiousbandersnatchhetookhisvorpalswordinhandlongtimethemanxomefoehesoughtsorestedhebythetumtumtreeandstoodawhileinthoughtandasinuffishthoughthestoodthejabberwockwitheyesofflamecamewhifflingthroughthetulgeywoodandburbledasitcameonetwoonetwoandthroughandthroughthevorpalbladewentsnickersnackheleftitdeadandwithitsheadhewentgalumphingbackandhastthouslainthejabberwockcometomyarmsmybeamishboyofrabjousdaycalloohcallayhechortledinhisjoytwasbrilligandtheslithytovesdidgyreandgimbleinthewabeallmimsyweretheborogovesandthemomerathsoutgrabe
Here is a program you can use to test this property.

If you run out of poem to use you may not use any additional alphabetic characters.

Alphabetic characters are characters a-z and A-Z here is the complete list:

ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Scoring
Your program will be scored in the number of non-alphabetic bytes used with fewer being better.

Here is a Haskell program that scores answers. (This assumes inputs are valid)

Example program
The following program would be valid:

twas&*brilliga77812nd Thesli thyt Oves didgy reand Gim bleinth ewab eal lmims ywe""""""""
ret h eb or o g o ve sa n dthemomerAthsoutgrabebewaretheJABBERWOCKmysonthe)(*)()((*98980908(()*(jawsthatbit
When stripped down to alphabetic characters it is:

twasbrilligandTheslithytOvesdidgyreandGimbleinthewabeallmimsyweretheb orogovesandthemomerAthsoutgrabebewaretheJABBERWOCKmysonthejawsthatbit
Which matches the first bit of the poem (case insensitive).

This program would score 59 because it contains these non-alphabetic characters:

&*77812           """"""""
          )(*)()((*98980908(()*(

*/

#include <stdio.h>

int
main()
{
	puts("The Jabberwocky");
	return 0;
}
