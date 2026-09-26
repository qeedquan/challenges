/*

--- Day 23: Coprocessor Conflagration ---
You decide to head directly to the CPU and fix the printer from there. As you get close, you find an experimental coprocessor doing so much work that the local programs are afraid it will halt and catch fire. This would cause serious issues for the rest of the computer, so you head in and see what you can do.

The code it's running seems to be a variant of the kind you saw recently on that tablet. The general functionality seems very similar, but some of the instructions are different:

set X Y sets register X to the value of Y.
sub X Y decreases register X by the value of Y.
mul X Y sets register X to the result of multiplying the value contained in register X by the value of Y.
jnz X Y jumps with an offset of the value of Y, but only if the value of X is not zero. (An offset of 2 skips the next instruction, an offset of -1 jumps to the previous instruction, and so on.)
Only the instructions listed above are used. The eight registers here, named a through h, all start at 0.

The coprocessor is currently set to some kind of debug mode, which allows for testing, but prevents it from doing any meaningful work.

If you run the program (your puzzle input), how many times is the mul instruction invoked?

--- Part Two ---
Now, it's time to fix the problem.

The debug mode switch is wired directly to register a. You flip the switch, which makes register a now start at 1 when the program is executed.

Immediately, the coprocessor begins to overheat. Whoever wrote this program obviously didn't choose a very efficient implementation. You'll need to optimize the program if it has any hope of completing before Santa needs that printer working.

The coprocessor's ultimate goal is to determine the final value left in register h once the program completes. Technically, if it had that... it wouldn't even need to run the program.

After setting register a to 1, if the program were to run to completion, what value would be left in register h?

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

bool
isprime(long n)
{
	long i;

	if (n <= 1)
		return false;

	if (n <= 3)
		return true;

	if (!(n % 2) || !(n % 3))
		return false;

	for (i = 5; i * i <= n; i += 6) {
		if (!(n % i) || !(n % (i + 2)))
			return false;
	}
	return true;
}

long
load(const char *name)
{
	FILE *fp;
	char s1[8];
	char s2[8];
	long n;

	fp = fopen(name, "r");
	if (!fp) {
		printf("Failed to load file: %s\n", strerror(errno));
		exit(1);
	}

	n = 0;
	fscanf(fp, "%4s %4s %ld", s1, s2, &n);
	fclose(fp);
	return n;
}

long
part1(long n)
{
	n -= 2;
	return n * n;
}

long
part2(long n)
{
	long a, b;
	long i, r;

	r = 0;
	a = 100000 + (100 * n);
	b = a + 17001;
	for (i = a; i < b; i += 17) {
		if (!isprime(i))
			r += 1;
	}
	return r;
}

int
main()
{
	long n;

	n = load("23.txt");
	printf("%ld\n", part1(n));
	printf("%ld\n", part2(n));

	return 0;
}
