/*

As a strict big brother, I do limit my young brother Vasya on time he spends on computer games. I define a prime-time as a time period till which Vasya have a permission to play computer games. I specify start hour and end hour as pair of integers.

I need a function which will take three numbers - a present moment (current hour), a start hour of allowed time period and an end hour of allowed time period. The function should give answer to a question (as a boolean): "Can Vasya play in specified time?"

If I say that prime-time is from 12 till 15 that means that at 12:00 it's OK to play computer but at 15:00 there should be no more games.

I will allow Vasya to play at least one hour a day.

*/

#include <assert.h>

bool
playtime(int now, int start, int end)
{
	if (end < start) {
		if (now < start)
			now += 24;
		end += 24;
	}
	return start <= now && now < end;
}

int
main()
{
	assert(playtime(12, 10, 14) == true);
	assert(playtime(12, 13, 14) == false);
	assert(playtime(15, 12, 15) == false);
	assert(playtime(23, 22, 1) == true);
	return 0;
}