/*

Khinchin's constant is a curious mathematical constant that, according to Wolfram MathWold, is "notoriously difficult to calculate to high precision".

Here it is to 100 digits:

2.685452001065306445309714835481795693820382293994462953051152345557218859537152002801141174931847697...

Write a program in 64 bytes or less that outputs Khinchin's constant to the maximum number of correct decimal places.

You may not use any built in library constants or functions directly relating to Khinchin's constant. (e.g. Math.Khinchin(precision) is definitely not allowed.)
You may use math libraries to compute logarithms, summations, etc.
You may hardcode all or part of your answer.
Your program must produce finite output and run in less than an hour on a reasonably modern computer (such as those listed here).
You must output to stdout. There is no input.
You may use any characters you want as long as http://mothereff.in/byte-counter registers 64 bytes or less.
Scoring

Your score is the number of successive digits in Khinchin's constant your program outputs correctly, starting with 2.68... You may output incorrect digits but only the last correct digit is counted towards your score.

For example, an output of

2.68545200206530644530971483548179569382038229399446295305115234555721

would score 9 points. One for each of the digits 2 6 8 5 4 5 2 0 0 but nothing after the 2 that should be a 1.

*/

#include <stdio.h>

const char *
khichin()
{
	return "2.685452001065306445309714835481795693820382293994462953051152345557218859537152002801141174931847697";
}

int
main()
{
	puts(khichin());
	return 0;
}
