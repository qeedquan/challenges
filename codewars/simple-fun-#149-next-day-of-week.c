/*

Task
You have set an alarm for some of the week days.

Days of the week are encoded in binary representation like this:

0000001 - Sunday
0000010 - Monday
0000100 - Tuesday
0001000 - Wednesday
0010000 - Thursday
0100000 - Friday
1000000 - Saturday```

For example, if your alarm is set only for Sunday and Friday, the representation will be `0100001`.

 Given the current day of the week, your task is to find the day of the week when alarm will ring next time.

# Example

 For `currentDay = 4, availableWeekDays = 42`, the result should be `6`.

currentDay = 4 means the current Day is Wednesday availableWeekDays = 42 convert to binary is "0101010" So the next day is 6 (Friday)

```

Input/Output
[input] integer currentDay
The weekdays range from 1 to 7, 1 is Sunday and 7 is Saturday

[input] integer availableWeekDays
An integer. Days of the week are encoded in its binary representation.

[output] an integer
The next day available.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
nextdayofweek(int day, int available)
{
	static const int lut[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	for (;;) {
		day = (day + 1) % nelem(lut);
		if (lut[day] & available)
			break;
	}
	return day + 1;
}

int
main()
{
	assert(nextdayofweek(4, 42) == 6);
	assert(nextdayofweek(6, 42) == 2);
	assert(nextdayofweek(7, 42) == 2);

	return 0;
}
