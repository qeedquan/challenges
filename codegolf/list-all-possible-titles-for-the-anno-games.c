/*

In the Anno video game series there are 6 games with a 7th one announced for early 2019. Their titles always feature a year in a specific pattern:

Anno 1602, Anno 1503, Anno 1701, Anno 1404, Anno 2070, Anno 2205, Anno 1800

The digital sum is always 9.
The years are four digits long.
They contain at least one zero.
Within these constrains there exist 109 possible titles:

[1008,1017,1026,1035,1044,1053,1062,1071,1080,1107,1170,1206,1260,1305,1350,1404,1440,1503,1530,1602,1620,1701,1710,1800,2007,2016,2025,2034,2043,2052,2061,2070,2106,2160,2205,2250,2304,2340,2403,2430,2502,2520,2601,2610,2700,3006,3015,3024,3033,3042,3051,3060,3105,3150,3204,3240,3303,3330,3402,3420,3501,3510,3600,4005,4014,4023,4032,4041,4050,4104,4140,4203,4230,4302,4320,4401,4410,4500,5004,5013,5022,5031,5040,5103,5130,5202,5220,5301,5310,5400,6003,6012,6021,6030,6102,6120,6201,6210,6300,7002,7011,7020,7101,7110,7200,8001,8010,8100,9000]

Your objective is to list them all in any reasonable form in the fewest number of bytes.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
digitsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

int
haszero(int n)
{
	for (; n > 0; n /= 10) {
		if ((n % 10) == 0)
			return 1;
	}
	return 0;
}

size_t
gen(int *r)
{
	size_t n;
	int i;

	n = 0;
	for (i = 1000; i <= 9999; i++) {
		if (digitsum(i) == 9 && haszero(i))
			r[n++] = i;
	}
	return n;
}

int
main(void)
{
	static const int tab[] = {
		1008, 1017, 1026, 1035, 1044, 1053, 1062, 1071, 1080, 1107, 1170, 1206,
		1260, 1305, 1350, 1404, 1440, 1503, 1530, 1602, 1620, 1701, 1710, 1800,
		2007, 2016, 2025, 2034, 2043, 2052, 2061, 2070, 2106, 2160, 2205, 2250,
		2304, 2340, 2403, 2430, 2502, 2520, 2601, 2610, 2700, 3006, 3015, 3024,
		3033, 3042, 3051, 3060, 3105, 3150, 3204, 3240, 3303, 3330, 3402, 3420,
		3501, 3510, 3600, 4005, 4014, 4023, 4032, 4041, 4050, 4104, 4140, 4203,
		4230, 4302, 4320, 4401, 4410, 4500, 5004, 5013, 5022, 5031, 5040, 5103,
		5130, 5202, 5220, 5301, 5310, 5400, 6003, 6012, 6021, 6030, 6102, 6120,
		6201, 6210, 6300, 7002, 7011, 7020, 7101, 7110, 7200, 8001, 8010, 8100,
		9000
	};

	int x[256];
	size_t n;

	n = gen(x);
	assert(n == nelem(tab));
	assert(!memcmp(x, tab, sizeof(tab)));

	return 0;
}
