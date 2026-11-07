/*

Problem
Recreate the UI from a torrent program

Given no input, output the following:

+----------+----------+----------+
|a.exe     |##########|seeding   |
+----------+----------+----------+
|b.exe 10% |#         |leeching  |
+----------+----------+----------+
|c.exe     |##########|seeding   |
+----------+----------+----------+
|d.exe 20% |##        |leeching  |
+----------+----------+----------+
|e.exe     |##########|seeding   |
+----------+----------+----------+
|f.exe 30% |###       |leeching  |
+----------+----------+----------+
|g.exe     |##########|seeding   |
+----------+----------+----------+
|h.exe 40% |####      |leeching  |
+----------+----------+----------+
|i.exe     |##########|seeding   |
+----------+----------+----------+
|j.exe 50% |#####     |leeching  |
+----------+----------+----------+
|k.exe     |##########|seeding   |
+----------+----------+----------+
|l.exe 60% |######    |leeching  |
+----------+----------+----------+
|m.exe     |##########|seeding   |
+----------+----------+----------+
|n.exe 70% |#######   |leeching  |
+----------+----------+----------+
|o.exe     |##########|seeding   |
+----------+----------+----------+
|p.exe 80% |########  |leeching  |
+----------+----------+----------+
|q.exe     |##########|seeding   |
+----------+----------+----------+
|r.exe 90% |######### |leeching  |
+----------+----------+----------+
|s.exe     |##########|seeding   |
+----------+----------+----------+
|t.exe     |##########|seeding   |
+----------+----------+----------+
|u.exe     |##########|seeding   |
+----------+----------+----------+
|v.exe     |##########|seeding   |
+----------+----------+----------+
|w.exe     |##########|seeding   |
+----------+----------+----------+
|x.exe     |##########|seeding   |
+----------+----------+----------+
|y.exe     |##########|seeding   |
+----------+----------+----------+
|z.exe     |##########|seeding   |
+----------+----------+----------+
progress for programs are:

b=10% d=20% f=30% h=40% j=50% l=60% n=70% p=80% r=90%

amount of #'s for leeching programs is progress/10

the rest are all seeding with full progress bars.

Rules
Leading and trailing newlines allowed.
Leading and trailing spaces allowed as long as it doesn't change shape of output.
stdout and functions for output allowed.
Shortest code in bytes win

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[8];
	int percent;
} File;

void
ui(File *files, size_t nfiles)
{
	File *f;
	size_t i;
	int p;

	for (i = 0; i < nfiles; i++) {
		f = files + i;
		if (i == 0)
			printf("+----------+----------+----------+\n");

		printf("|%5s ", f->name);
		if (f->percent != 100)
			printf("%02d%% ", f->percent);
		else
			printf("%4s", " ");

		printf("|");
		for (p = 0; p < 10; p++) {
			if (p < (f->percent / 10))
				printf("#");
			else
				printf(" ");
		}

		printf("|%-10s", (f->percent == 100) ? "seeding" : "leeching");
		printf("|\n");
		printf("+----------+----------+----------+\n");
	}
}

void
gen(File *files)
{
	static const char fmt[] = "b=10% d=20% f=30% h=40% j=50% l=60% n=70% p=80% r=90% ";

	File *f;
	int i, p;
	char c;

	for (i = 0; i < 26; i++) {
		f = files + i;
		f->percent = 100;
		snprintf(f->name, sizeof(f->name), "%c.exe", 'a' + i);
	}

	for (i = 0; fmt[i]; i += 6) {
		sscanf(fmt + i, "%c=%d", &c, &p);
		f = files + c - 'a';
		f->percent = p;
	}
}

int
main(void)
{
	File files[26];

	gen(files);
	ui(files, nelem(files));

	return 0;
}
