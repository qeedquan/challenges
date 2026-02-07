/*

Write a function createHelloWorld. It should return a new function that always returns "Hello World".

Example 1:

Input: args = []
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".

Example 2:

Input: args = [{},null,42]
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".


Constraints:

0 <= args.length <= 10

*/

#include <stdio.h>

typedef const char *(*fn)(...);

const char *
hello_world(...)
{
	return "Hello World";
}

fn
create_hello_world()
{
	return hello_world;
}

int
main()
{
	fn f;

	f = create_hello_world();
	puts(f());
	puts(f((int[]){ 0 }, NULL, 42));

	return 0;
}
