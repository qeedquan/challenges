/*

Alex is transitioning from website design to coding and wants to sharpen his skills with CodeWars.
He can do ten kata in an hour, but when he makes a mistake, he must do pushups. These pushups really tire poor Alex out, so every time he does them they take twice as long. His first set of redemption pushups takes 5 minutes. Create a function, alexMistakes, that takes two arguments: the number of kata he needs to complete, and the time in minutes he has to complete them. Your function should return how many mistakes Alex can afford to make.

*/

#include <assert.h>
#include <stdio.h>

int
mistakes(int katas, int timelimit)
{
	int time;
	int pushtime;
	int count;

	time = timelimit - (katas * 6);
	count = 0;
	pushtime = 5;
	while (pushtime <= time) {
		time -= pushtime;
		pushtime *= 2;
		count += 1;
	}
	return count;
}

void
test(int katas, int timelimit, int expected)
{
	int value;

	value = mistakes(katas, timelimit);
	printf("%d\n", value);
	assert(value == expected);
}

int
main()
{
	test(10, 120, 3);
	test(11, 120, 3);
	test(3, 45, 2);
	test(8, 120, 3);
	test(6, 60, 2);
	test(9, 180, 4);
	test(20, 120, 0);
	test(20, 125, 1);
	test(20, 130, 1);
	test(20, 135, 2);

	return 0;
}
