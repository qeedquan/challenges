/*

Objective
Given a date, spell it out in Romanized Japanese.

I/O Format
The input format is flexible. The output format is <month spelling> <day spelling>; note the space. You can freely mix cases in output. You may output trailing newline.

Mapping
Months
Month	Spelling
January	Ichigatsu
February	Nigatsu
March	Sangatsu
April	Shigatsu or Yongatsu
May	Gogatsu
June	Rokugatsu
July	Shichigatsu or Nanagatsu
August	Hachigatsu
September	Kugatsu or Kyuugatsu
October	Juugatsu
November	Juuichigatsu
December	Juunigatsu
Days
Irregular ones are marked *.

Day	Spelling
1st	Tsuitachi*
2nd	Futsuka*
3rd	Mikka*
4th	Yokka*
5th	Itsuka*
6th	Muika*
7th	Nanoka*
8th	Youka*
9th	Kokonoka*
10th	Tooka*
11th	Juuichinichi
12th	Juuninichi
13th	Juusannichi
14th	Juuyokka*
15th	Juugonichi
16th	Juurokunichi
17th	Juunananichi
18th	Juuhachinichi
19th	Juukyuunichi
20th	Hatsuka*
21st	Nijuuichinichi
22nd	Nijuuninichi
23rd	Nijuusannichi
24th	Nijuuyokka*
25th	Nijuugonichi
26th	Nijuurokunichi
27th	Nijuunananichi
28th	Nijuuhachinichi
29th	Nijuukyuunichi
30th	Sanjuunichi
31st	Sanjuuichinichi

Examples
May 5th → Gogatsu Itsuka
September 29th → Kugatsu Nijuukyuunichi or Kyuugatsu Nijuukyuunichi
October 9th → Juugatsu Kokonoka

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
jdate(const char *s, char *b)
{
	static const char months[][2][16] = {
	    {"January", "Ichigatsu"},
	    {"February", "Nigatsu"},
	    {"March", "Sangatsu"},
	    {"April", "Shigatsu"},
	    {"May", "Gogatsu"},
	    {"June", "Rokugatsu"},
	    {"July", "Shichigatsu"},
	    {"August", "Hachigatsu"},
	    {"September", "Kugatsu"},
	    {"October", "Juugatsu"},
	    {"November", "Juuichigatsu"},
	    {"December", "Juunigatsu"},
	};

	static const char days[][2][16] = {
	    {"1st", "Tsuitachi"},
	    {"2nd", "Futsuka"},
	    {"3rd", "Mikka"},
	    {"4th", "Yokka"},
	    {"5th", "Itsuka"},
	    {"6th", "Muika"},
	    {"7th", "Nanoka"},
	    {"8th", "Youka"},
	    {"9th", "Kokonoka"},
	    {"10th", "Tooka"},
	    {"11th", "Juuichinichi"},
	    {"12th", "Juuninichi"},
	    {"13th", "Juusannichi"},
	    {"14th", "Juuyokka"},
	    {"15th", "Juugonichi"},
	    {"16th", "Juurokunichi"},
	    {"17th", "Juunananichi"},
	    {"18th", "Juuhachinichi"},
	    {"19th", "Juukyuunichi"},
	    {"20th", "Hatsuka"},
	    {"21st", "Nijuuichinichi"},
	    {"22nd", "Nijuuninichi"},
	    {"23rd", "Nijuusannichi"},
	    {"24th", "Nijuuyokka"},
	    {"25th", "Nijuugonichi"},
	    {"26th", "Nijuurokunichi"},
	    {"27th", "Nijuunananichi"},
	    {"28th", "Nijuuhachinichi"},
	    {"29th", "Nijuukyuunichi"},
	    {"30th", "Sanjuunichi"},
	    {"31st", "Sanjuuichinichi"},
	};

	size_t i, j;
	char m[16], d[16];

	*b = '\0';

	if (sscanf(s, "%15s %15s", m, d) != 2)
		return NULL;

	for (i = 0; i < nelem(months); i++) {
		if (!strcmp(m, months[i][0]))
			break;
	}
	for (j = 0; j < nelem(days); j++) {
		if (!strcmp(d, days[j][0]))
			break;
	}

	if (i == nelem(months) || j == nelem(days))
		return NULL;

	sprintf(b, "%s %s", months[i][1], days[j][1]);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	jdate(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("May 5th", "Gogatsu Itsuka");
	test("September 29th", "Kugatsu Nijuukyuunichi");
	test("October 9th", "Juugatsu Kokonoka");

	return 0;
}
