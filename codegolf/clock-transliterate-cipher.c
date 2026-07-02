/*

Introduction:
I have loads of different ciphers stored in a document I once compiled as a kid, I picked a few of the ones I thought were best suitable for challenges (not too trivial, and not too hard) and transformed them into challenges.
Most of them are still in the sandbox, and I'm not sure yet whether I'll post all of them, or only a few. Here is the third and easiest one (after the Computer Cipher and Trifid Cipher I posted earlier).

With a Clock Cipher we use the following image to encipher text:

https://i.sstatic.net/yqHRk.jpg

So a sentence like this is a clock cipher would become:

t  h i s     i s     a     c l  o  c k     c i p  h e r    (without additional spaces of course, but added as clarification)
19:7:8:18:00:8:18:00:AM:00:2:11:14:2:10:00:2:8:15:7:4:17

Challenge:
Given a string sentence_to_encipher, encipher it as described above.

Challenge rules:
You can assume the sentence_to_encipher will only contain letters and spaces.
You can use either full lowercase or full uppercase (please state which one you've used in your answer).
You are not allowed to add leading zeros for the single-digit enciphered letters b through j, but two zeros 00 are mandatory for spaces.
You should use : as separator, and an additional leading or trailing : is not allowed.
You are allowed to use lowercase am and pm instead of uppercase AM and PM, as long as it's consistent.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.
Test cases:
Input:  "this is a clock cipher"
Output: "19:7:8:18:00:8:18:00:AM:00:2:11:14:2:10:00:2:8:15:7:4:17"

Input:  "test"
Output: "19:4:18:19"

Input:  "what time is it"
Output: "22:7:AM:19:00:19:8:12:4:00:8:18:00:8:19"

Input:  "acegikmoqsuwy bdfhjlnprtvxz"
Output: "AM:2:4:6:8:10:12:14:16:18:20:22:24:00:1:3:5:7:9:11:13:15:17:19:21:23:PM"

Input:  "easy peazy"
Output: "4:AM:18:24:00:15:4:AM:PM:24"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
encipher(const char *s, char *b)
{
	size_t i, l;
	int c;

	*b = '\0';
	for (i = l = 0; s[i]; i++) {
		c = toupper(s[i]);
		if (c == 'A')
			l += sprintf(b + l, "AM");
		else if (c == 'Z')
			l += sprintf(b + l, "PM");
		else if ('B' <= c && c <= 'Y')
			l += sprintf(b + l, "%d", c - 'A');
		else if (c == ' ')
			l += sprintf(b + l, "00");
		else
			l += sprintf(b + l, "%c", s[i]);

		if (s[i + 1])
			l += sprintf(b + l, ":");
	}
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	encipher(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("EXAMPLE", "4:23:AM:12:15:11:4");
	test("HI BOB", "7:8:00:1:14:1");
	test("this is a clock cipher", "19:7:8:18:00:8:18:00:AM:00:2:11:14:2:10:00:2:8:15:7:4:17");
	test("test", "19:4:18:19");
	test("what time is it", "22:7:AM:19:00:19:8:12:4:00:8:18:00:8:19");
	test("acegikmoqsuwy bdfhjlnprtvxz", "AM:2:4:6:8:10:12:14:16:18:20:22:24:00:1:3:5:7:9:11:13:15:17:19:21:23:PM");
	test("easy peazy", "4:AM:18:24:00:15:4:AM:PM:24");

	return 0;
}
