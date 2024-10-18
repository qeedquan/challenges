/*

--- Day 1: Trebuchet?! ---
Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.

You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the sky ("of course, where do you think snow comes from") when you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to strap you in").

As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the values on the document.

The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?

--- Part Two ---
Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

Equipped with this new information, you now need to find the real first and last digit on each line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen

In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

What is the sum of all of the calibration values?

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
count1(const char *s)
{
	vlong x, y;
	size_t i;

	x = y = -1;
	for (i = 0; s[i]; i++) {
		if (!isdigit(s[i]))
			continue;

		if (x < 0)
			x = y = s[i] - '0';
		else
			y = s[i] - '0';
	}

	return (x * 10) + y;
}

vlong
count2(const char *s)
{
	static const char *nums[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	static const size_t numslen[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};

	size_t i, j;
	vlong x, y, v;

	x = y = -1;
	for (i = 0; s[i]; i++) {
		v = -1;
		for (j = 0; j < nelem(nums); j++) {
			if (!strncmp(s + i, nums[j], numslen[j])) {
				v = j + 1;
				break;
			}
		}
		if (isdigit(s[i]))
			v = s[i] - '0';

		if (v < 0)
			continue;

		if (x < 0)
			x = y = v;
		else
			y = v;
	}

	return (x * 10) + y;
}

vlong
solve(const char *name, vlong (*count)(const char *))
{
	FILE *fp;
	char buf[128];
	vlong r;

	fp = fopen(name, "r");
	if (!fp)
		return -errno;

	r = 0;
	while (fgets(buf, sizeof(buf), fp))
		r += count(buf);
	fclose(fp);
	return r;
}

int
main(void)
{
	printf("%lld\n", solve("1.txt", count1));
	printf("%lld\n", solve("1.txt", count2));

	return 0;
}
