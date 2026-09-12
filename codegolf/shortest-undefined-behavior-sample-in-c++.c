/*

What's the shortest, well-formed C++ code that exhibits undefined behavior?

*/

void
f(char *s)
{
	*s = '\0';
}

int
main(void)
{
	char *s = "foo";

	f(s);
	return 0;
}
