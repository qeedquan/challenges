/*

"Counter" is a language I've created for the purpose of this question.

Rules

Commands are read from left to right from the first character.
Each command may be executed as it is read, or you may execute all commands together at the end.
In case of an error, all commands up till the error must be executed.
A program is written in exactly one line.
Data is stored in counters. At the start, there is exactly one counter. More can be created and deleted.
A counter holds an integer value between -100 and 100 (limits inclusive).
Exactly one counter is the selected counter at any point in time.
Counters are arranged in a 1d array, so one can move left (previous) or right (next) to change selected counter.
Commands

Any number between -100 and 100 - Set the currently selected counter to that value.
c - Create a counter immediately after the currently selected counter, make it the selected counter, and set it to 0.
d - Delete the currently selected counter, and make the previous one selected. If it is the first one, this is an error.
+ - Make the next counter the selected one.
- - Make the previous counter the selected one. (Ensure that this command is not immediately followed by a number.)
o - Output the value in the selected counter, followed by a space.
? - If the value in the selected counter is 0, apply the d command on it.
# - If the value in the selected counter is 0, ignore the next command.
(space) - No meaning, but is to be treated like a command, if preceded by a #. Used to demarcate numbers.
Errors

Going left of the leftmost counter, or right of the rightmost counter.
Deleting the first counter.
Encountering a # as the last command. (Of course, this means all commands will get executed anyways)
A command that does not exist.
A number that's too long.
Task

Create an interpreter in any language. Code will be in a file or given as input (your choice). Shortest code wins.

Lengthy example

Consider the code:

7cc--13 12do?+?#0#o3od-7o
Here is a breakdown of the program. [] indicates the selected counter.

Cmd   Memory    Output

7     [7]
c     7 [0]
c     7 0 [0]
-     7 [0] 0
-13   7 [-13] 0
      7 [-13] 0
12    7 [12] 0
d     [7] 0
o     [7] 0     7
?     [7] 0
+     7 [0]
?     [7]
#     [7]
0     [0]
#     [0]
o     [0]
3     [3]
o     [3]       3
d     This is an error. Program terminates here.
Total output 7 3

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

typedef struct {
	const char *p;

	int ign;

	long *stk;
	size_t nstk;
	size_t sp;
} Ctr;

int
ctrinit(Ctr *c, const char *s)
{
	memset(c, 0, sizeof(*c));
	c->stk = calloc(strlen(s) + 1, sizeof(*c->stk));
	if (!c->stk)
		return -errno;
	c->nstk = 1;
	c->p = s;
	return 0;
}

void
ctrfree(Ctr *c)
{
	free(c->stk);
}

int
ctrlex(Ctr *c, long *v)
{
	char *ep;
	int t;

	if (!isspace(c->p[0])) {
		*v = strtol(c->p, &ep, 10);
		if (c->p != ep) {
			c->p = ep;
			return 'v';
		}
	}

	t = c->p[0];
	switch (c->p[0]) {
	case '\0':
		break;

	case ' ':
	case 'c':
	case 'd':
	case '+':
	case '-':
	case 'o':
	case '?':
	case '#':
		c->p++;
		break;

	default:
		return -1;
	}
	return t;
}

int
ctrxec(Ctr *c)
{
	int op;
	long v;

	op = ctrlex(c, &v);
	if (c->ign) {
		c->ign = 0;
		return 0;
	}

	switch (op) {
	case 0:
	case ' ':
		break;

	case 'v':
		c->stk[c->sp] = v;
		break;

	case 'c':
		c->stk[++c->sp] = 0;
		c->nstk++;
		break;

	case '?':
		if (c->stk[c->sp])
			break;
		// fallthrough
	case 'd':
		if (c->nstk < 2)
			return -EINVAL;
		memmove(c->stk + c->sp, c->stk + c->sp + 1, (c->nstk - c->sp - 1) * sizeof(*c->stk));
		c->sp--;
		c->nstk--;
		break;

	case '+':
		if (c->sp >= c->nstk)
			return -EINVAL;
		c->sp++;
		break;

	case '-':
		if (c->sp == 0)
			return -EINVAL;
		c->sp--;
		break;

	case 'o':
		printf("%ld ", c->stk[c->sp]);
		break;

	case '#':
		if (!c->stk[c->sp])
			c->ign = 1;
		break;

	default:
		return -EINVAL;
	}
	return 0;
}

int
ctrrun(const char *s)
{
	Ctr c[1];
	int r;

	if ((r = ctrinit(c, s)) < 0)
		return r;

	while (c->p[0]) {
		if ((r = ctrxec(c)) < 0)
			break;
	}
	printf("\n");

	ctrfree(c);
	return r;
}

int
main(void)
{
	ctrrun("7cc--13 12do?+?#0#o3od-7o");
	ctrrun("cccccc202o");

	return 0;
}
