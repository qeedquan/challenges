/*

Objective
Given the distance between two keys in an octave, identify its name.

But there's a caveat. In this challenge, there are 22 keys in an octave, not usual 12.

Here, a porcupine[7] scale will be assumed.

Mapping
White keys are marked bold.

Distance	Name
0	Unison
1	Augmented Unison or Diminished Second
2	Minor Second
3	Major Second
4	Augmented Second
5	Diminished Third
6	Minor Third
7	Major Third
8	Augmented Third or Diminished Fourth
9	Perfect Fourth
10	Major Fourth
11	Augmented Fourth or Diminished Fifth
12	Minor Fifth
13	Perfect Fifth
14	Augmented Fifth or Diminished Sixth
15	Minor Sixth
16	Major Sixth
17	Augmented Sixth
18	Diminished Seventh
19	Minor Seventh
20	Major Seventh
21	Augmented Seventh or Diminished Octave
(others)	(don't care)

Rule
You can freely mix cases in output. Trailing whitespaces are permitted.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
edo(unsigned n)
{
	static const char *tab[] = {
	    "Unison",
	    "Augmented Unison",
	    "Minor Second",
	    "Major Second",
	    "Augmented Second",
	    "Diminished Third",
	    "Minor Third",
	    "Major Third",
	    "Augmented Third",
	    "Perfect Fourth",
	    "Major Fourth",
	    "Augmented Fourth",
	    "Minor Fifth",
	    "Perfect Fifth",
	    "Augmented Fifth",
	    "Minor Sixth",
	    "Major Sixth",
	    "Augmented Sixth",
	    "Diminished Seventh",
	    "Minor Seventh",
	    "Major Seventh",
	    "Augmented Seventh",
	};

	if (n >= nelem(tab))
		return NULL;
	return tab[n];
}

int
main(void)
{
	unsigned i;

	for (i = 0; i < 22; i++)
		printf("%s\n", edo(i));

	return 0;
}
