/*

Given a printable ASCII string representing a path to a file on a POSIX-compliant system, return just the filename, i.e. remove everything until and including the last slash (/):

/full/path/file.name.ext → file.name.ext

nopath.here → nopath.here

dir/.hidden → .hidden

/dirs.can/have.exts/file → file

./here → here

don't\do this → don't\do this

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <libgen.h>

void
test(const char *s, const char *r)
{
	char b[PATH_MAX];
	char *p;

	snprintf(b, sizeof(b), "%s", s);
	p = basename(b);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("/full/path/file.name.ext", "file.name.ext");
	test("nopath.here", "nopath.here");
	test("dir/.hidden", ".hidden");
	test("/dirs.can/have.exts/file", "file");
	test("./here", "here");
	test("don't\\do this", "don't\\do this");

	return 0;
}
