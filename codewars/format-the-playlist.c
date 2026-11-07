/*

Your task is to write a function, called format_playlist, that takes a list of songs as input.

Each song is a tuple, of the form (song_name, duration, artist). Your task is to create a string representation of these songs.

Your playlist should be sorted first by the artist, then by the name of the song.

Note:

All input will be valid.
The length of the song will be at least 1 minute long, but never 10 minutes or longer. It will be of the form m:ss.
There will never be empty fields (each song will have a name, duration and artist).

For example, if your function was passed the following songs.

songs = [
    ('In Da Club', '3:13', '50 Cent'),
    ('Candy Shop', '3:45', '50 Cent'),
    ('One', '4:36', 'U2'),
    ('Wicked', '2:53', 'Future'),
    ('Cellular', '2:58', 'King Krule'),
    ('The Birthday Party', '4:45', 'The 1975'),
    ('In The Night Of Wilderness', '5:26', 'Blackmill'),
    ('Pull Up', '3:35', 'Playboi Carti'),
    ('Cudi Montage', '3:16', 'KIDS SEE GHOSTS'),
    ('What Up Gangsta', '2:58', '50 Cent')
]

Then your function would return the following:

+----------------------------+------+-----------------+
| Name                       | Time | Artist          |
+----------------------------+------+-----------------+
| Candy Shop                 | 3:45 | 50 Cent         |
| In Da Club                 | 3:13 | 50 Cent         |
| What Up Gangsta            | 2:58 | 50 Cent         |
| In The Night Of Wilderness | 5:26 | Blackmill       |
| Wicked                     | 2:53 | Future          |
| Cudi Montage               | 3:16 | KIDS SEE GHOSTS |
| Cellular                   | 2:58 | King Krule      |
| Pull Up                    | 3:35 | Playboi Carti   |
| The Birthday Party         | 4:45 | The 1975        |
| One                        | 4:36 | U2              |
+----------------------------+------+-----------------+

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	char duration[8];
	char artist[32];
} Song;

size_t
max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

int
cmp(const void *s1, const void *s2)
{
	const Song *p, *q;
	int r;

	p = s1;
	q = s2;
	r = strcmp(p->artist, q->artist);
	if (r == 0)
		return strcmp(p->name, q->name);
	return r;
}

void
linef(const char *fmt, ...)
{
	va_list ap;
	size_t i, n, p;
	const char *s;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		switch (*fmt) {
		case '-':
			p = va_arg(ap, size_t) + 2;
			for (i = 0; i < p; i++)
				putchar(*fmt);
			break;

		case 's':
			s = va_arg(ap, const char *);
			p = va_arg(ap, size_t);

			printf(" ");
			n = printf("%s", s);
			for (i = 0; i < p - n; i++)
				printf(" ");
			printf(" ");
			break;

		default:
			putchar(*fmt);
			break;
		}
	}
	va_end(ap);
	putchar('\n');
}

void
playlist(Song *s, size_t n)
{
	Song *p;
	size_t w[3];
	size_t i;

	qsort(s, n, sizeof(*s), cmp);

	memset(w, 0, sizeof(w));
	for (i = 0; i < n; i++) {
		p = s + i;
		w[0] = max(w[0], strlen(p->name));
		w[1] = max(w[1], strlen(p->duration));
		w[2] = max(w[2], strlen(p->artist));
	}

	linef("+-+-+-+", w[0], w[1], w[2]);
	linef("|s|s|s|", "Name", w[0], "Time", w[1], "Artist", w[2]);
	linef("+-+-+-+", w[0], w[1], w[2]);
	for (i = 0; i < n; i++) {
		p = s + i;
		linef("|s|s|s|", p->name, w[0], p->duration, w[1], p->artist, w[2]);
	}
	linef("+-+-+-+", w[0], w[1], w[2]);
}

int
main()
{
	Song songs[] = {
		{ "In Da Club", "3:13", "50 Cent" },
		{ "Candy Shop", "3:45", "50 Cent" },
		{ "One", "4:36", "U2" },
		{ "Wicked", "2:53", "Future" },
		{ "Cellular", "2:58", "King Krule" },
		{ "The Birthday Party", "4:45", "The 1975" },
		{ "In The Night Of Wilderness", "5:26", "Blackmill" },
		{ "Pull Up", "3:35", "Playboi Carti" },
		{ "Cudi Montage", "3:16", "KIDS SEE GHOSTS" },
		{ "What Up Gangsta", "2:58", "50 Cent" },
	};

	playlist(songs, nelem(songs));

	return 0;
}
