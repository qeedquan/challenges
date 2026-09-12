/*

Task
Write a function/full program that will be able to produce two different sequences of integers in [0, ..., 9].
You will take an input seed to decide whether to output your specific sequence or the common one.
For that matter, you must choose one non-negative integer, let us call it k.
When the input seed is equal to k, you will be dealing with your specific sequence s; when the input seed is anything else, you will be dealing with your common sequence c.

Both sequences should be such that the relative frequencies with which each digit appears tend to 10%.
Be prepared to prove this if needed.
Said another way, the running fraction of that digit's appearances needs to have a defined limit that equals 0.1. Formally, this means that for every d∈{0,...,9},

limn→∞|{i:i∈{1…n},si=d}|n=0.1

Adapted from What an Odd Function

There should be one extra restriction your sequences should satisfy: when zipped together* to form a sequence a of terms in [0, ..., 99], the relative frequency of each number should converge to 0.01 via a limit like the formula above.

*That is, the nth term of the sequence a is the two-digit number built this way: the digit in the tens place is the nth term of the sequence c and the digit in the units place is the nth term of the sequence s.

Input
A non-negative integer representing the "seed", which you use to decide whether to output the common sequence or the specific one.

Output
Your output may be one of the following:

an infinite stream with the sequence (and you take no additional input);
output the nth term of the sequence (by taking an additional input n that is 0- or 1-indexed);
output the first n terms of the sequence (by taking an additional positive input n).

Example pseudo-algorithm
Assuming I have defined seed as an integer, and for these choices I made for s and c:

input_seed ← input()
n ← input()
if input_seed = seed: print (n mod 10) # this is my sequence s
else: print ((integer div of n by 10) mod 10) # this is my sequence c

Both sequences output numbers in [0, ..., 9] and the frequency with which each digit appears tends to 0.1 as n → infinity.
Similarly, zipping c and s together gives n mod 100 so it is also true that as n → infinity we have that the relative frequency with which each number in [0, ..., 99] shows up goes to 0.01.

*/

#include <stdio.h>

int
prng(int s, int n)
{
	int r;

	r = (s) ? (n / 10) : n;
	return r % 10;
}

int
main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		printf("%d %d\n", prng(0, i), prng(1, i));

	return 0;
}
