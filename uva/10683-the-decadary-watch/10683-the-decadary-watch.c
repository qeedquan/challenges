#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

char *
solve(const char *input, char *output)
{
	vlong sum;
	vlong hour;
	vlong minute;
	vlong second;
	vlong centisecond;

	if (sscanf(input, "%2lld%2lld%2lld%2lld", &hour, &minute, &second, &centisecond) != 4)
		return NULL;

	sum = (centisecond * 10) + (second * 1000) + (minute * 60000) + (hour * 3600000);

	hour = sum / 8640000;
	sum %= 8640000;

	minute = sum / 86400;
	sum %= 86400;

	second = sum / 864;
	sum %= 864;

	centisecond = sum * 100 / 864;

	sprintf(output, "%lld%02lld%02lld%02lld", hour, minute, second, centisecond);
	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	solve(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("00000000", "0000000");
	test("23595999", "9999998");
	test("12000000", "5000000");
	test("14273467", "6024846");
	test("02475901", "1166552");

	return 0;
}
