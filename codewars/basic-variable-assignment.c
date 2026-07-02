/*

This code should store "codewa.rs" as a variable called name but it's not working. Can you figure out why?

*/

#include <stdio.h>

void
solve()
{
	const char *a = "code";
	const char *b = "wa.rs";
	char name[16];

	snprintf(name, sizeof(name), "%s%s", a, b);
	puts(name);
}

int
main()
{
	solve();
	return 0;
}
