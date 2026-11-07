/*

"First they came..." is a poem by Martin Niemöller:

First they came for the Socialists, and I did not speak out-
Because I was not a Socialist.

Then they came for the Trade Unionists, and I did not speak out-
Because I was not a Trade Unionist.

Then they came for the Jews, and I did not speak out-
Because I was not a Jew.

Then they came for me-and there was no one left to speak for me.
Your task is to output the above. This is code-golf, so shortest code in bytes wins!

Rules
You may include extra whitespace that does not affect appearance. A single trailing newline is allowed.
Otherwise, the output must match exactly, including the location of newlines.
As per meta standards, you may output a list of strings. However, you must include the empty lines.
Note that I personally believe this is not a dupe because of how the poem is laid out - it needs some creativity to golf. Meta discussion about whether this is a dupe or not can be found here.

*/

#include <stdio.h>

void
poem(void)
{
	puts("First they came for the Socialists, and I did not speak out-");
	puts("Because I was not a Socialist.");
	puts("");
	puts("Then they came for the Trade Unionists, and I did not speak out-");
	puts("Because I was not a Trade Unionist.");
	puts("");
	puts("Then they came for the Jews, and I did not speak out-");
	puts("Because I was not a Jew.");
	puts("");
	puts("Then they came for me-and there was no one left to speak for me.");
}

int
main(void)
{
	poem();
	return 0;
}
