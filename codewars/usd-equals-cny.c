/*

Create a function that converts US dollars (USD) to Chinese Yuan (CNY) . The input is the amount of USD as an integer, and the output should
be a string that states the amount of Yuan followed by 'Chinese Yuan'

### Examples (Input -> Output)

```
15 -> '101.25 Chinese Yuan'
465 -> '3138.75 Chinese Yuan'
```

The conversion rate you should use is 6.75 CNY for every 1 USD. All numbers should be represented as a string with 2 decimal places. (e.g. "
21.00" NOT "21.0" or "21")

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
usdcny(long double usd, char *buf)
{
	sprintf(buf, "%.2Lf Chinese Yuan", 6.75 * usd);
	return buf;
}

void
test(long double usd, const char *res)
{
	char buf[64];

	usdcny(usd, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test(0, "0.00 Chinese Yuan");
	test(+15, "101.25 Chinese Yuan");
	test(-15, "-101.25 Chinese Yuan");
	test(+465, "3138.75 Chinese Yuan");
	test(-465, "-3138.75 Chinese Yuan");
	test(+122978293824730344l, "830103483316929822.00 Chinese Yuan");
	test(-122978293824730344l, "-830103483316929822.00 Chinese Yuan");
	return 0;
}
