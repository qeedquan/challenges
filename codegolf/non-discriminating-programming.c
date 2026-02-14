/*

We say a string is non-discriminating if each of the string's characters appears the same number of times and at least twice.

Examples
"aa!1 1 !a !1" is non-discriminating because each of the characters  , !, a and 1 appear three times.
"abbaabb" is not non-discriminating because b appears more often than a.
"abc" is also not non-discriminating because the characters don't appear at least twice.
Task
Write a non-discriminating program or function which returns a truthy value if a given string is non-discriminating, and a falsy value otherwise.

That is, the program run on its own source code should return a truthy value.

Each submission must be able to handle non-empty strings containing printable ASCII, as well as all characters appearing in the source code of the submission.

Test Cases

Truthy:

<your program's source code>
"aaaa"
"aa!1 1 !a !1"
"aabbccddeeffgg"
"1Q!V_fSiA6Bri{|}tkDM]VjNJ=^_4(a&=?5oYa,1wh|R4YKU #9c!#Q T&f`:sm$@Xv-ugW<P)l}WP>F'jl3xmd'9Ie$MN;TrCBC/tZIL*G27byEn.g0kKhbR%>G-.5pHcL0)JZ`s:*[x2Sz68%v^Ho8+[e,{OAqn?3E<OFwX(;@yu]+z7/pdqUD"

Falsy:

"a"
"abbaabb"
"abc"
"bQf6ScA5d:4_aJ)D]2*^Mv(E}Kb7o@]krevW?eT0FW;I|J:ix %9!3Fwm;*UZGH`8tV>gy1xX<S/OA7NtB'}c u'V$L,YlYp{#[..j&gTk8jp-6RlGUL#_<^0CCZKPQfD2%s)he-BMRu1n?qdi/!5q=wn$ora+X,POzzHNh=(4{m`39I|s[+E@&y>"

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
nondisc(const char *s)
{
	size_t c, i, h[256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	for (c = i = 0; i < 256; i++) {
		if (!h[i])
			continue;
		if (!c)
			c = h[i];
		if (c != h[i])
			return false;
	}
	return (c == 0) || (c > 1);
}

int
main(void)
{
	assert(nondisc("aaaa") == true);
	assert(nondisc("aa!1 1 !a !1") == true);
	assert(nondisc("aabbccddeeffgg") == true);
	assert(nondisc("1Q!V_fSiA6Bri{|}tkDM]VjNJ=^_4(a&=?5oYa,1wh|R4YKU #9c!#Q T&f`:sm$@Xv-ugW<P)l}WP>F'jl3xmd'9Ie$MN;TrCBC/tZIL*G27byEn.g0kKhbR%>G-.5pHcL0)JZ`s:*[x2Sz68%v^Ho8+[e,{OAqn?3E<OFwX(;@yu]+z7/pdqUD") == true);

	assert(nondisc("a") == false);
	assert(nondisc("abbaabb") == false);
	assert(nondisc("abc") == false);
	assert(nondisc("bQf6ScA5d:4_aJ)D]2*^Mv(E}Kb7o@]krevW?eT0FW;I|J:ix %9!3Fwm;*UZGH`8tV>gy1xX<S/OA7NtB'}c u'V$L,YlYp{#[..j&gTk8jp-6RlGUL#_<^0CCZKPQfD2%s)he-BMRu1n?qdi/!5q=wn$ora+X,POzzHNh=(4{m`39I|s[+E@&y>") == false);

	return 0;
}
