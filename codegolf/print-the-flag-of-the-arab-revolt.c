/*

It seems flags are a trend now, so what better place to start an account? I thought bars could use a twist to them, so I found this flag.

Produce the following in the console output the fewest possible bytes:

+----------------------------------+
|XXXXX                             |
|XXXXXXXX                          |
|XXXXXXXXX-------------------------+
|XXXXXXXXXXX                       |
|XXXXXXXXXXX                       |
|XXXXXXXXX-------------------------+
|XXXXXXXX                          |
|XXXXX                             |
+----------------------------------+
This crude rendition of the flag is 36 x 10 characters. A trailing newline on the last line is optional. You may use any language you choose. If it is an obscure language, please post a link to the language in your answer.

*/

#include <stdio.h>

void
arab(void)
{
	puts("+----------------------------------+");
	puts("|XXXXX                             |");
	puts("|XXXXXXXX                          |");
	puts("|XXXXXXXXX-------------------------+");
	puts("|XXXXXXXXXXX                       |");
	puts("|XXXXXXXXXXX                       |");
	puts("|XXXXXXXXX-------------------------+");
	puts("|XXXXXXXX                          |");
	puts("|XXXXX                             |");
	puts("+----------------------------------+");
}

int
main(void)
{
	arab();
	return 0;
}
