#include <stdio.h>
#include <ctype.h>

void
solve(const char *src, char *dst)
{
	static const char lut[10] = { 'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P' };

	for (; *src; src++) {
		if (isdigit(*src))
			*dst++ = lut[*src - '0'];
		else
			*dst++ = *src;
	}
	*dst = '\0';
}

int
main()
{
	const char *src =
	    "H3LL0 MY L0V3, 1 M H499Y 83C4U53 500N 1 W1LL 83 70 Y0UR 51D3. 7H15 "
	    "71M3 W17H0U7 Y0U H45 833N 373RN4L. 1 1NV173 Y0U 70 7H3 200 0N3 70 "
	    "533 7H3 238R45 4ND 60R1L45.";

	char dst[256];

	solve(src, dst);
	puts(dst);

	return 0;
}
