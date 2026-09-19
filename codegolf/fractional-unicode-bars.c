/*

Your program should take as input a number n that is greater than 0 and output a bar composed of n // 8 ▉ characters (U+2588), as well as a final character which should be one of ▉ ▊ ▋ ▌ ▍ ▎▏(U+2589 to U+258F) representing n % 8. If n % 8 is 0, your program should not output any additional characters. This is difficult to explain well in text, so here are some examples:

Input: 8
Output: █
Input: 32
Output: ████
Input: 33
Output: ████▏
Input: 35
Output: ████▍
Input: 246
Output: ██████████████████████████████▊

This is code-golf, so shortest answer wins.

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
bars(int n)
{
	static const char *fracts[] = {
	    u8"▉",
	    u8"▏",
	    u8"▎",
	    u8"▍",
	    u8"▌",
	    u8"▋",
	    u8"▊",
	    u8"▉",
	};

	int b, i;

	printf("n=%d\n", n);
	for (i = 0; i < n; i += b) {
		b = min(8, n - i);
		printf("%s", fracts[b & 7]);
	}
	printf("\n\n");
}

int
main(void)
{
	bars(8);
	bars(32);
	bars(33);
	bars(35);
	bars(246);

	return 0;
}
