/*

Introduction
Long ago, when I used to code card games with usual playing cards, I used to specify a number for each card and call a function with some number to get a card. This somewhat inspired me to make this challenge.

So for the people unaware of the playing cards, a deck of cards consist of 52 cards (13 in each of the four suits, i.e, Hearts, Diamonds, Spades, Clubs). In each suit, there are 13 cards - firstly the cards numbered from 2-10, then the Jack(J), Queen(Q), King(K) and the Ace(A). This is the order

Challenge
The challenge is to take an integer between 1-52 as input and display the card at that position. But, your output must be in words. Also, order must be maintained, i.e, first 13 cards will be of Hearts, then Diamonds, then Spades and finally Clubs.

For example, if someone chooses the number 30.The card would then belong to the third suit, i.e, the Spades. Also, it would be the fourth card in the suit, which means the number 5. Hence your output in words must be: five of spades and it should always follow this format, i.e, first the card, followed by an of and the name of the suit at the end, with required spaces in between.

Input And Output
The input will be an integer between 1-52 (both inclusive). Note that here counting starts from 1. You may choose to start from 0. However, you must maintain the order of the cards which is mentioned above. Your output should be the card at that position written in words. You do not need to handle invalid inputs. Also, your output may be in lower-case or in upper-case.

Given below is the list of all the possible inputs and their outputs:

1 -> two of hearts
2 -> three of hearts
3 -> four of hearts
4 -> five of hearts
5 -> six of hearts
6 -> seven of hearts
7 -> eight of hearts
8 -> nine of hearts
9 -> ten of hearts
10 -> jack of hearts
11 -> queen of hearts
12 -> king of hearts
13 -> ace of hearts
14 -> two of diamonds
15 -> three of diamonds
16 -> four of diamonds
17 -> five of diamonds
18 -> six of diamonds
19 -> seven of diamonds
20 -> eight of diamonds
21 -> nine of diamonds
22 -> ten of diamonds
23 -> jack of diamonds
24 -> queen of diamonds
25 -> king of diamonds
26 -> ace of diamonds
27 -> two of spades
28 -> three of spades
29 -> four of spades
30 -> five of spades
31 -> six of spades
32 -> seven of spades
33 -> eight of spades
34 -> nine of spades
35 -> ten of spades
36 -> jack of spades
37 -> queen of spades
38 -> king of spades
39 -> ace of spades
40 -> two of clubs
41 -> three of clubs
42 -> four of clubs
43 -> five of clubs
44 -> six of clubs
45 -> seven of clubs
46 -> eight of clubs
47 -> nine of clubs
48 -> ten of clubs
49 -> jack of clubs
50 -> queen of clubs
51 -> king of clubs
52 -> ace of clubs

Scoring
This is code-golf, so the shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
cardname(unsigned n, char *b)
{
	static const char *nums[] = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};
	static const char *suits[] = {"hearts", "diamonds", "spades", "clubs"};

	unsigned m;

	*b = '\0';
	if (n < 1 || n > 52)
		return b;

	n -= 1;
	m = nelem(nums);
	sprintf(b, "%s of %s", nums[n % m], suits[n / m]);
	return b;
}

void
test(int n, const char *r)
{
	char b[64];

	cardname(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "two of hearts");
	test(2, "three of hearts");
	test(3, "four of hearts");
	test(4, "five of hearts");
	test(5, "six of hearts");
	test(6, "seven of hearts");
	test(7, "eight of hearts");
	test(8, "nine of hearts");
	test(9, "ten of hearts");
	test(10, "jack of hearts");
	test(11, "queen of hearts");
	test(12, "king of hearts");
	test(13, "ace of hearts");
	test(14, "two of diamonds");
	test(15, "three of diamonds");
	test(16, "four of diamonds");
	test(17, "five of diamonds");
	test(18, "six of diamonds");
	test(19, "seven of diamonds");
	test(20, "eight of diamonds");
	test(21, "nine of diamonds");
	test(22, "ten of diamonds");
	test(23, "jack of diamonds");
	test(24, "queen of diamonds");
	test(25, "king of diamonds");
	test(26, "ace of diamonds");
	test(27, "two of spades");
	test(28, "three of spades");
	test(29, "four of spades");
	test(30, "five of spades");
	test(31, "six of spades");
	test(32, "seven of spades");
	test(33, "eight of spades");
	test(34, "nine of spades");
	test(35, "ten of spades");
	test(36, "jack of spades");
	test(37, "queen of spades");
	test(38, "king of spades");
	test(39, "ace of spades");
	test(40, "two of clubs");
	test(41, "three of clubs");
	test(42, "four of clubs");
	test(43, "five of clubs");
	test(44, "six of clubs");
	test(45, "seven of clubs");
	test(46, "eight of clubs");
	test(47, "nine of clubs");
	test(48, "ten of clubs");
	test(49, "jack of clubs");
	test(50, "queen of clubs");
	test(51, "king of clubs");
	test(52, "ace of clubs");

	return 0;
}
