/*

We often see music videos on Youtube. Many Youtube channels that host music videos are "powered by VEVO". Those can be easily identified by both embedding VEVO at their video thumbnails and appending VEVO to their channel name.

Now write some code to test whether a string given by user is a VEVO user account or not.

Requirements for valid VEVO user account strings:

Must only contain uppercase, lowercase, and digit characters. (no whitespace or punctuation)

Must not exceed 80 characters length.

Must have "VEVO" substring at the end of string

Test cases:

Valid inputs:

AdeleVEVO
ConnieTalbotVEVO
SHMVEVO
justimberlakeVEVO
DJMartinJensenVEVO
test123VEVO

Invalid inputs:

syam kapuk
jypentertainment
Noche de Brujas
testVEVO123

Of course, because this is code-golf, I'm looking for the shortest code using any programming language.

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool
isvevo(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (!(isupper(s[i]) || islower(s[i]) || isdigit(s[i])))
			return false;
	}
	if (i < 4 || i > 80)
		return false;

	if (strcmp(s + i - 4, "VEVO") != 0)
		return false;

	return true;
}

int
main(void)
{
	assert(isvevo("AdeleVEVO") == true);
	assert(isvevo("ConnieTalbotVEVO") == true);
	assert(isvevo("SHMVEVO") == true);
	assert(isvevo("justimberlakeVEVO") == true);
	assert(isvevo("DJMartinJensenVEVO") == true);
	assert(isvevo("test123VEVO") == true);

	assert(isvevo("syam kapuk") == false);
	assert(isvevo("jypentertainment") == false);
	assert(isvevo("Noche de Brujas") == false);
	assert(isvevo("testVEVO123") == false);

	return 0;
}
