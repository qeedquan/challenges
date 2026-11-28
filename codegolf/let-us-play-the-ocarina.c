/*

As we all know, the Zelda series are one of the best game series ever made. In honor of that, let us play some songs on the ocarina.

Challenge:
Write a program which, given a song, outputs the score to stdout for that particular song.

Input:
The song which you will have to output the score of will be given by a unique three character combination as seen below:

zel - Zelda's Lullaby
sas - Saria's Song
eps - Epona's Song
sos - Sun's Song
sot - Song of Time
sst - Song of Storms
Bonus songs, -7 % each:

mof - Minuet of Forest
bof - Bolero of Fire
sow - Serenade of Water
nos - Nocturne of Shadow
ros - Requiem of Spirit
pol - Prelude of Light
Bonus song 2, -8 %:

scs - Scarecrow's song
As we all know, the Scarecrow's song is a song you compose yourself. This song needs to have eight notes. Output a score you compose yourself which is different from all the other scores.

If you decide to include all songs, it will total to a -50 % bonus to your byte score.

Output:
The notes in the output are symbolized by the following characters:

^
<
>
V
A
Output a score on the following format:

-^-^-^-^-^-^-^-^-
-<-<-<-<-<-<-<-<-
->->->->->->->->-
-V-V-V-V-V-V-V-V-
-A-A-A-A-A-A-A-A-
Only one note per column is allowed. For simplicity's sake I've added another row to the original four rows.

Each note correspond to a different row:

^: ----------------
<: ----------------
>: ----------------
V: ----------------
A: ----------------
Output shall be written to stdout. Trailing newlines are allowed.

Examples:
Input (Zelda's Lullaby):

zel
Output:

---^-----^-------
-<-----<---------
----->----->-----
-----------------
-----------------
Input (Bolero of Fire):

bof
Output:

-----------------
-----------------
--------->--->---
-V---V-----V---V-
---A---A---------
Note cheat sheet:

zel
<^><^>
sas
V><V><
eps
^<>^<>
sos
>V^>V^
sot
>AV>AV
sst
AV^AV^
mof
A^<><>
bof
VAVA>V>V
sow
AV>><
nos
<>>A<>V
ros
AVA>VA
pol
^>^><^
Since we play the ocarina code golf, the shortest program in bytes wins!

Song references:
http://www.thonky.com/ocarina-of-time/ocarina-songs

http://www.zeldadungeon.net/Zelda05-ocarina-of-time-ocarina-songs.php

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char *const *t;

	t = b;
	return strcmp(a, t[0]);
}

int
play(const char *s)
{
	static const char *songs[][2] = {
	    {"bof", "VAVA>V>V"},
	    {"eps", "^<>^<>"},
	    {"mof", "A^<><>"},
	    {"nos", "<>>A<>V"},
	    {"pol", "^>^><^"},
	    {"ros", "AVA>VA"},
	    {"sas", "V><V><"},
	    {"sos", ">V^>V^"},
	    {"sot", ">AV>AV"},
	    {"sow", "AV>><"},
	    {"sst", "AV^AV^"},
	    {"zel", "<^><^>"},
	};

	static const char notes[] = "^<>VA";

	char grid[5][21] = {
	    "^: -----------------",
	    "<: -----------------",
	    ">: -----------------",
	    "V: -----------------",
	    "A: -----------------",
	};

	const char **t, *p;
	size_t i;
	int c;

	t = bsearch(s, songs, nelem(songs), sizeof(*songs), cmp);
	if (!t)
		return -1;

	for (i = 0; (c = t[1][i]); i++) {
		p = strchr(notes, c);
		if (!p)
			return -1;

		grid[p - notes][(2 * i) + 4] = c;
	}

	printf("%s\n", s);
	for (i = 0; i < nelem(grid); i++)
		printf("%s\n", grid[i]);
	printf("\n");

	return 0;
}

int
main(void)
{
	play("zel");
	play("bof");
	play("sst");

	return 0;
}
