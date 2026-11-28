/*

Context
So the Dutch "Ministerie van Binnenlandse Zaken en Koninkrijksrelaties" (NL) - "Ministry of the Interior and Kingdom Relations" (EN) recently released the source code of their digid-app.

They have some goofy code in there, which led to mockery and memes on reddit

Source code of the offending method can be found here. Here's a copy:

private static string GetPercentageRounds(double percentage)
{
    if (percentage == 0)
        return "⚪⚪⚪⚪⚪⚪⚪⚪⚪⚪";
    if (percentage > 0.0 && percentage <= 0.1)
        return "🔵⚪⚪⚪⚪⚪⚪⚪⚪⚪";
    if (percentage > 0.1 && percentage <= 0.2)
        return "🔵🔵⚪⚪⚪⚪⚪⚪⚪⚪";
    if (percentage > 0.2 && percentage <= 0.3)
        return "🔵🔵🔵⚪⚪⚪⚪⚪⚪⚪";
    if (percentage > 0.3 && percentage <= 0.4)
        return "🔵🔵🔵🔵⚪⚪⚪⚪⚪⚪";
    if (percentage > 0.4 && percentage <= 0.5)
        return "🔵🔵🔵🔵🔵⚪⚪⚪⚪⚪";
    if (percentage > 0.5 && percentage <= 0.6)
        return "🔵🔵🔵🔵🔵🔵⚪⚪⚪⚪";
    if (percentage > 0.6 && percentage <= 0.7)
        return "🔵🔵🔵🔵🔵🔵🔵⚪⚪⚪";
    if (percentage > 0.7 && percentage <= 0.8)
        return "🔵🔵🔵🔵🔵🔵🔵🔵⚪⚪";
    if (percentage > 0.8 && percentage <= 0.9)
        return "🔵🔵🔵🔵🔵🔵🔵🔵🔵⚪";

    return "🔵🔵🔵🔵🔵🔵🔵🔵🔵🔵";
}
Try it online:
https://dotnetfiddle.net/aMEUAM

Challenge
Write code in any language as short as possible to replicate the above function

Rule clarification
You must exactly match the input and output of the original function. Substituting the ball characters with something else is not allowed.
You must stick to the functions original boundaries. Meaning if the input is something unexpected like -1 or 42 you must still return the same result as the original function.

*/

#include <stdio.h>
#include <string.h>

char *
percentage(double p, char *b)
{
	double i;
	int l;

	l = 0;
	for (i = 0; i <= 0.9; i += 0.1) {
		if (p <= i || p <= 0)
			l += sprintf(b + l, u8"⚪");
		else
			l += sprintf(b + l, u8"🔵");
	}
	return b;
}

int
main(void)
{
	char b[128];
	double i, e;

	e = 0.1;
	for (i = 0; i <= 1.0; i += e)
		printf("%f | %s\n", i, percentage(i, b));

	return 0;
}
