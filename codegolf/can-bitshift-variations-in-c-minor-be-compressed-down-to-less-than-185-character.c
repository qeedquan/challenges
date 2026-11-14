/*

Bitshift Variations in C Minor by Robert Miles is a Code Golf music piece written in C (with some additional bash commands). It was originally presented in a 2016 Computerphile video Code Golf & the Bitshift Variations. You can listen to clean renderings of it here (by Lucia Ceionia).

The original 2016 source code presented in the description under the YouTube video was 245 characters long:

echo "g(i,x,t,o){return((3&x&(i*((3&i>>16?\"BY}6YB6%\":\"Qj}6jQ6%\")[t%8]+51)>>o))<<4);};main(i,n,s){for(i=0;;i++)putchar(g(i,1,n=i>>14,12)+g(i,s=i>>17,n^i>>13,10)+g(i,s/3,n+((i>>11)%3),10)+g(i,s/5,8+n-((i>>10)%3),9));}"|gcc -xc -&&./a.out|aplay
A tweet from 2017 (or some other Rob Miles tweet, not sure) stands 216 characters:

gcc -xc -oa -<<<'i;n;g(x,t,o){return(3&x&(i*((3&i>>16?"BY}6YB6%":"Qj}6jQ6%")[t%8]+51)>>o))<<4;}main(s){for(;;)putchar(g(1,n=++i>>14,12)+g(s=i>>17,n^i>>13,10)+g(s/3,n+(i>>11)%3,10)+g(s/5,8+n-(i>>10)%3,9));}';./a|aplay
Another version using only 185 characters (written by MayMeta from Manifold Markets):

gcc -xc -oa -<<<'i;n;g(m,t,o){return("GTj?TG?5"[7&t]+!(n&12|t&2)*9)*i>>o&m&24;}main(s){for(;;)putchar(g(8,n=++i>>14,8)+g(n,n^(s=i>>10)/8,6)+g(n/3,n+s/2%3,6)+g(n/5,n-s%3,5));}';./a|aplay
Will someone be able to shrink it down below 185 characters, or the limit has been reached?

Extra Credit (Resolution criteria for a related betting market):

The bash command compiles the C source code and runs + plays it using aplay (or similar)
You ARE allowed to slightly change the played notes, but their relative frequencies should not differ more than 1.4% from the original, and the entire piece should not be shifted more than one semitone (6%) from the original.
Compiles and works as intended on an average linux machine.
Does not use the internet
A winning entry will be the shortest entry that is less than 185 characters, and follows the Extra Credit guidelines. Entries that do not follow the extra credit are appreciated, but will not be selected as the winner. Solutions that could be argued to be following the spirit extra credit guidelines in their attempt to get under 185 will be considered to be winners as well, as it's a bit subjective.

Related Links:

Deep analysis of Bitshift Variations in C Minor code
https://sylphe.ch/bitfiddle/index.html

BitShift-Variations-unrolled
https://github.com/JamesNewton/BitShift-Variations-unrolled

Bitshift Variations Humanized + Rust version
https://github.com/Bitshift-variations-humanized

*/

#include <stdio.h>
#include <limits.h>

int
g(int i, int x, int t, int o)
{
	const char *c;
	int b;

	b = (i >> 16) & 3;
	if (b != 0)
		c = "BY}6YB6%";
	else
		c = "Qj}6jQ6%";

	b = c[t & 7];
	b += 51;
	b *= i;
	b >>= o;
	b &= x;
	b &= 3;
	b <<= 4;
	return b;
}

int
main(void)
{
	int i, n, s;

	i = 0;
	for (;;) {
		n = i >> 14;
		s = i >> 17;
		putchar(g(i, 1, n, 12) +
		        g(i, s, n ^ i >> 13, 10) +
		        g(i, s / 3, n + ((i >> 11) % 3), 10) +
		        g(i, s / 5, 8 + n - ((i >> 10) % 3), 9));

		i = (i + 1) % INT_MAX;
	}
	return 0;
}
