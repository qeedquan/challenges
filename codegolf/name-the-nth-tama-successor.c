/*

Tama was a cat born 26 years ago today who gained fame for being a railway station master and operating officer at Kishi Station on the Kishigawa Line in Kinokawa, Wakayama Prefecture, Japan.

https://i.sstatic.net/6HXMExHB.jpg

Photo credit: User:Sanpei on Japanese Wikipedia, CC BY-SA 3.0

On her death, she was honored with a Shinto-style funeral at the station and was given the posthumous title "Honorary Eternal Stationmaster", and her successor was named Nitama (lit. "Second Tama")

By this point you understand the assignment. Given an integer in 2..10, return the name of that successor of Tama, that is to say, the preferred reading of n in japanese, concatenated with "tama". Undefined behavior is allowed outside of 2..10.

For the purposes of this challenge, disregard the fact that the cat supposed to be her 3rd successor was not strictly named according to this sequence, and also that Sun-tama-tama didn't actually become her 3rd successor because

the Public Relations representative who had been caring for Sun-tama-tama refused to give the cat up, writing, "I will not let go of this child, she will stay in Okayama."

Input: An integer between 2 and 10 included

Output: A string with the first (but no other) character capitalized, according to the following table (also exhaustive test cases):

input -> output
2 -> Nitama
3 -> Santama
4 -> Yontama
5 -> Gotama
6 -> Rokutama
7 -> Nanatama
8 -> Hachitama
9 -> Kyūtama
10 -> Jūtama
Outputting ū(U+016B) represented as U+0075 U+0304 (latin minuscule u + combining macron diacritic) is allowed. Additional whitespace around the string is allowed, but no other output is.

Translation builtins (such as google sheets' googletranslate()) are allowed.

Bonus brownie points if your solution is capable of handling any integer, but it is by no means required.

This is code-golf.

*/

#include <stdio.h>

const char *
successor(int n)
{
	switch (n) {
	case 2:
		return "Nitama";
	case 3:
		return "Santama";
	case 4:
		return "Yontama";
	case 5:
		return "Gotama";
	case 6:
		return "Rokutama";
	case 7:
		return "Nanatama";
	case 8:
		return "Hachitama";
	case 9:
		return "Kyūtama";
	case 10:
		return "Jūtama";
	default:
		return NULL;
	}
}

int
main()
{
	int i;

	for (i = 2; i <= 10; i++)
		puts(successor(i));

	return 0;
}
