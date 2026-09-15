/*

Imagine you have a digital clock which paints the whole screen with a color instead of showing you what time it is. While it looks good on your wall and you get to impress your guests, you also want to be able to tell what time it is. Luckily, the clock also prints the hex code in the bottom right of the screen. Using that, you should be able to tell the time, which is another way to impress your guests :)

The hex code will come to you in this format: #0d242c

And you will return the time in this format: hh:mm:ss

Note: The hexCode you will be provided will always be in the correct format. However, it might not point to a correct time. So make sure to throw an error if the time you have calculated is invalid.

*/

#include <stdio.h>

char *
hextime(const char *hex, char *out)
{
	unsigned int h, m, s;

	if (sscanf(hex, "#%02x%02x%02x", &h, &m, &s) != 3)
		return NULL;
	if (h > 23 || m > 59 || s > 59)
		return NULL;

	sprintf(out, "%02u:%02u:%02u", h, m, s);
	return out;
}

int
main()
{
	char out[16];

	printf("%s\n", hextime("#0d242c", out));

	return 0;
}
