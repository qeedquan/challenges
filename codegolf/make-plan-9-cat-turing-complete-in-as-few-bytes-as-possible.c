/*

Your task is to modify the original Plan 9 cat tool for UNIX, in order to make it a fully turing complete language interpreter. You may make use of ANSI escape codes and the backspace character (\x08) to aid in this.

You must submit:

A modified version of the Plan 9 cat tool
A hexdump of the turing machine that can be run like so: cat turing_machine where turing_machine is the file you wrote.
Your score is the number of bytes you changed in the Plan 9 cat source code (where replacing a character counts as two bytes because you have to remove it and then replace it).

Here is the Plan 9 cat source code, taken from here.

#include <u.h>
#include <libc.h>

void
cat(int f, char *s)
{
    char buf[8192];
    long n;

    while((n=read(f, buf, (long)sizeof buf))>0)
        if(write(1, buf, n)!=n)
            sysfatal("write error copying %s: %r", s);
    if(n < 0)
        sysfatal("error reading %s: %r", s);
}

void
main(int argc, char *argv[])
{
    int f, i;

    argv0 = "cat";
    if(argc == 1)
        cat(0, "<stdin>");
    else for(i=1; i<argc; i++){
        f = open(argv[i], OREAD);
        if(f < 0)
            sysfatal("can't open %s: %r", argv[i]);
        else{
            cat(f, argv[i]);
            close(f);
        }
    }
    exits(0);
}
The headers in the above source are u.h and libc.h. Your code must conform to the C99 standard.

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <err.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*

@pommicket

Real computers aren't actually Turing-complete, because they have a finite amount of memory, whereas a Turing-machine has an infinite amount of memory.
This is an implementation of a cyclic tag system with 9999 bytes of memory (although you could very easily change that),
and with an initial word of 1 (I'm not entirely sure if cyclic tag systems with a fixed initial word are Turing-complete, but they probably are).

The length of the program must be ≤8192, in this format:

00 (the first byte is ignored)
01 01 02 00 (first rule: 001 (null character to mark end))
02 02 02 01 02 00 (second rule: 11101)
03 (marks end of program)

*/

void
tag(char *buf, char *mem, size_t memlen)
{
	char *start, *end, *memend;
	char *i, *p;

	memend = mem + memlen - 1;
	start = mem;
	end = mem + 1;

	i = buf;
	do {
		for (p = start; p < end; p++)
			printf("%d", *p - 1);
		printf("\n");

		for (i++; *i; i++) {
			if (*i > 2)
				i = buf + 1;

			if (*start > 1) {
				*end++ = *i;
				if (end > memend)
					end = mem;
			}
		}

		if (++start > memend)
			start = mem;

	} while (*start);
}

void
cat(int f, char *s)
{
	char mem[9999];
	char buf[8192];
	ssize_t n;

	memset(buf, 0, sizeof(buf));
	memset(mem, 0, sizeof(mem));
	while ((n = read(f, buf, sizeof(buf))) > 0) {
		mem[0] = 2;
		mem[1] = 0;
		tag(buf, mem, sizeof(mem));
	}

	if (n < 0)
		errx(1, "cat: error reading: %s: %s", s, strerror(errno));
}

int
main(int argc, char *argv[])
{
	int f, i;

	if (argc == 1)
		cat(0, "<stdin>");
	else {
		for (i = 1; i < argc; i++) {
			f = open(argv[i], O_RDONLY);
			if (f < 0)
				errx(1, "cat: can't open %s: %s", argv[i], strerror(errno));
			else {
				cat(f, argv[i]);
				close(f);
			}
		}
	}
	return 0;
}
