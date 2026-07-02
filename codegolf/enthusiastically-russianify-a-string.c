/*

Many of you may have interacted with people from Russia on the internet at some point, and a subset of you may have noticed the slightly odd method they have of expressing themselves.

e.g. удали игру нуб)))

where the ))) are added for emphasis on the previous statement, I have been working on a theory that the ratio of )'s to the rest of the string is directly proportional to the amount of implied emphasis, however I oftentimes find it difficult to compute the ratio on the fly, as I am also trying to cope with a slew of abuse, so I would like the shortest possible code to help me calculate what the resulting string should be, for a value of enthusiasm between 0 and 500%, given the original, unenthusiastic string, this will aid my research greatly as I will not have to type out bulky scripts every time I wish to test my hypothesis.

So, the challenge:

write a full program or function, which, provided two arguments, a string of unknown length, and a number, in either integer format (between 0 and 500) or in decimal format (between 0 and 5, with 2 points of accuracy) will

return/display the original string, suffixed with a number of )'s
the number will be the calculated as a ratio of the input number to the string length.
so if the number 200, or 2.00 was provided, 200% of the string must be suffixed as )'s
the number of brackets rounded to in decimal situations does not matter.
script is required to support Printable ASCII characters.
only has to support one input number format, of your choice.
Examples:

"codegolf" 125      = codegolf))))))))))
"codegolf" 75       = codegolf))))))
"noob team omg" 0.5 = noob team omg)))))))
"hi!" 4.99          = hi!)))))))))))))))
Example code (PowerShell) (with decimal input):

Function Get-RussianString ([string]$InputStr,[decimal]$Ratio){
    $StrLen = $InputStr.Length
    $SuffixCount = $StrLen * $Ratio
    $Suffix = [string]::New(")",$SuffixCount)
    return $InputStr + $Suffix
}

Get-RussianString "codegolf" 0.5
codegolf))))

This is code-golf so shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
russianify(const char *s, double r, char *b)
{
	size_t i, l, n;

	l = sprintf(b, "%s", s);
	n = ceil(l * r);
	for (i = 0; i < n; i++)
		l += sprintf(b + l, ")");
	return b;
}

void
test(const char *s, double r, const char *t)
{
	char b[128];

	russianify(s, r, b);
	printf("%s\n", b);
	assert(!strcmp(b, t));
}

int
main(void)
{
	test("codegolf", 1.25, "codegolf))))))))))");
	test("codegolf", 0.75, "codegolf))))))");
	test("noob team omg", 0.5, "noob team omg)))))))");
	test("hi!", 4.99, "hi!)))))))))))))))");
	test("codegolf", 0.5, "codegolf))))");

	return 0;
}
