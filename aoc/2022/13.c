/*

--- Day 13: Distress Signal ---
You climb the hill and again try contacting the Elves. However, you instead receive a signal you weren't expecting: a distress signal.

Your handheld device must still not be working properly; the packets from the distress signal got decoded out of order. You'll need to re-order the list of received packets (your puzzle input) to decode the message.

Your list consists of pairs of packets; pairs are separated by a blank line. You need to identify how many pairs of packets are in the right order.

For example:

[1,1,3,1,1]
[1,1,5,1,1]

[[1],[2,3,4]]
[[1],4]

[9]
[[8,7,6]]

[[4,4],4,4]
[[4,4],4,4,4]

[7,7,7,7]
[7,7,7]

[]
[3]

[[[]]]
[[]]

[1,[2,[3,[4,[5,6,7]]]],8,9]
[1,[2,[3,[4,[5,6,0]]]],8,9]
Packet data consists of lists and integers. Each list starts with [, ends with ], and contains zero or more comma-separated values (either integers or other lists). Each packet is always a list and appears on its own line.

When comparing two values, the first value is called left and the second value is called right. Then:

If both values are integers, the lower integer should come first. If the left integer is lower than the right integer, the inputs are in the right order. If the left integer is higher than the right integer, the inputs are not in the right order. Otherwise, the inputs are the same integer; continue checking the next part of the input.
If both values are lists, compare the first value of each list, then the second value, and so on. If the left list runs out of items first, the inputs are in the right order. If the right list runs out of items first, the inputs are not in the right order. If the lists are the same length and no comparison makes a decision about the order, continue checking the next part of the input.
If exactly one value is an integer, convert the integer to a list which contains that integer as its only value, then retry the comparison. For example, if comparing [0,0,0] and 2, convert the right value to [2] (a list containing 2); the result is then found by instead comparing [0,0,0] and [2].
Using these rules, you can determine which of the pairs in the example are in the right order:

== Pair 1 ==
- Compare [1,1,3,1,1] vs [1,1,5,1,1]
  - Compare 1 vs 1
  - Compare 1 vs 1
  - Compare 3 vs 5
    - Left side is smaller, so inputs are in the right order

== Pair 2 ==
- Compare [[1],[2,3,4]] vs [[1],4]
  - Compare [1] vs [1]
    - Compare 1 vs 1
  - Compare [2,3,4] vs 4
    - Mixed types; convert right to [4] and retry comparison
    - Compare [2,3,4] vs [4]
      - Compare 2 vs 4
        - Left side is smaller, so inputs are in the right order

== Pair 3 ==
- Compare [9] vs [[8,7,6]]
  - Compare 9 vs [8,7,6]
    - Mixed types; convert left to [9] and retry comparison
    - Compare [9] vs [8,7,6]
      - Compare 9 vs 8
        - Right side is smaller, so inputs are not in the right order

== Pair 4 ==
- Compare [[4,4],4,4] vs [[4,4],4,4,4]
  - Compare [4,4] vs [4,4]
    - Compare 4 vs 4
    - Compare 4 vs 4
  - Compare 4 vs 4
  - Compare 4 vs 4
  - Left side ran out of items, so inputs are in the right order

== Pair 5 ==
- Compare [7,7,7,7] vs [7,7,7]
  - Compare 7 vs 7
  - Compare 7 vs 7
  - Compare 7 vs 7
  - Right side ran out of items, so inputs are not in the right order

== Pair 6 ==
- Compare [] vs [3]
  - Left side ran out of items, so inputs are in the right order

== Pair 7 ==
- Compare [[[]]] vs [[]]
  - Compare [[]] vs []
    - Right side ran out of items, so inputs are not in the right order

== Pair 8 ==
- Compare [1,[2,[3,[4,[5,6,7]]]],8,9] vs [1,[2,[3,[4,[5,6,0]]]],8,9]
  - Compare 1 vs 1
  - Compare [2,[3,[4,[5,6,7]]]] vs [2,[3,[4,[5,6,0]]]]
    - Compare 2 vs 2
    - Compare [3,[4,[5,6,7]]] vs [3,[4,[5,6,0]]]
      - Compare 3 vs 3
      - Compare [4,[5,6,7]] vs [4,[5,6,0]]
        - Compare 4 vs 4
        - Compare [5,6,7] vs [5,6,0]
          - Compare 5 vs 5
          - Compare 6 vs 6
          - Compare 7 vs 0
            - Right side is smaller, so inputs are not in the right order
What are the indices of the pairs that are already in the right order? (The first pair has index 1, the second pair has index 2, and so on.) In the above example, the pairs in the right order are 1, 2, 4, and 6; the sum of these indices is 13.

Determine which pairs of packets are already in the right order. What is the sum of the indices of those pairs?

--- Part Two ---
Now, you just need to put all of the packets in the right order. Disregard the blank lines in your list of received packets.

The distress signal protocol also requires that you include two additional divider packets:

[[2]]
[[6]]
Using the same rules as before, organize all packets - the ones in your list of received packets as well as the two divider packets - into the correct order.

For the example above, the result of putting the packets in the correct order is:

[]
[[]]
[[[]]]
[1,1,3,1,1]
[1,1,5,1,1]
[[1],[2,3,4]]
[1,[2,[3,[4,[5,6,0]]]],8,9]
[1,[2,[3,[4,[5,6,7]]]],8,9]
[[1],4]
[[2]]
[3]
[[4,4],4,4]
[[4,4],4,4,4]
[[6]]
[7,7,7]
[7,7,7,7]
[[8,7,6]]
[9]
Afterward, locate the divider packets. To find the decoder key for this distress signal, you need to determine the indices of the two divider packets and multiply them together. (The first packet is at index 1, the second packet is at index 2, and so on.) In this example, the divider packets are 10th and 14th, and so the decoder key is 140.

Organize all of the packets into the correct order. What is the decoder key for the distress signal?

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

enum {
	MAXLISTS = 512,
};

enum {
	TINT = 0,
	TLIST
};

typedef struct Obj Obj;

struct Obj {
	int type;
	union {
		int val;
		struct {
			Obj **ele;
			size_t len;
		};
	};
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		abort();
	return ptr;
}

void *
xrealloc(void *ptr, size_t size)
{
	ptr = realloc(ptr, size);
	if (!ptr)
		abort();
	return ptr;
}

void
objfree(Obj *obj)
{
	size_t i;

	if (!obj)
		return;

	switch (obj->type) {
	case TLIST:
		for (i = 0; i < obj->len; i++)
			objfree(obj->ele[i]);
		free(obj->ele);
		break;
	}
	free(obj);
}

int
objcmp(const Obj *a, const Obj *b)
{
	Obj list, listele, *ele[1];
	size_t minlen;
	size_t i;
	int cmp;

	if (a->type == TINT && b->type == TINT) {
		if (a->val < b->val)
			return -1;
		else if (a->val > b->val)
			return 1;
		return 0;
	}

	list.type = TLIST;
	list.len = 1;
	list.ele = ele;
	list.ele[0] = &listele;
	listele.type = TINT;

	if (a->type == TINT) {
		listele.val = a->val;
		a = &list;
	} else if (b->type == TINT) {
		listele.val = b->val;
		b = &list;
	}

	minlen = min(a->len, b->len);
	for (i = 0; i < minlen; i++) {
		cmp = objcmp(a->ele[i], b->ele[i]);
		if (cmp)
			return cmp;
	}

	if (a->len < b->len)
		return -1;
	else if (a->len > b->len)
		return 1;
	return 0;
}

Obj *
parselist(const char *s, const char **next)
{
	Obj *obj;
	Obj *ele;
	const char *nextptr;
	char buf[64];
	size_t len;

	while (isspace(s[0]))
		s++;

	obj = xcalloc(1, sizeof(*obj));
	if (s[0] == '-' || isdigit(s[0])) {
		len = 0;
		while ((*s == '-' || isdigit(*s)) && len < sizeof(buf) - 1)
			buf[len++] = *s++;
		buf[len] = 0;
		obj->type = TINT;
		obj->val = atoi(buf);
		if (next)
			*next = s;
	} else if (s[0] == '[') {
		obj->type = TLIST;
		obj->len = 0;
		obj->ele = NULL;
		s++;

		for (;;) {
			while (isspace(s[0]))
				s++;

			if (s[0] == ']') {
				if (next)
					*next = s + 1;
				return obj;
			}

			ele = parselist(s, &nextptr);
			if (!ele)
				goto error;

			obj->ele = xrealloc(obj->ele, sizeof(*obj->ele) * (obj->len + 1));
			obj->ele[obj->len++] = ele;
			s = nextptr;

			while (isspace(s[0]))
				s++;

			if (s[0] == ',')
				s++;
			else if (s[0] != ']')
				goto error;
		}
	} else
		goto error;

	if (0) {
	error:
		objfree(obj);
		obj = NULL;
	}

	return obj;
}

int
readlists(FILE *fp, Obj **lists, size_t listlen)
{
	char buf[1024];
	size_t len;
	size_t idx;

	idx = 0;
	while (fgets(buf, sizeof(buf), fp) && idx < listlen) {
		len = strlen(buf);
		if (len < 2)
			continue;
		if (buf[len - 1] == '\n')
			buf[--len] = '\0';
		lists[idx++] = parselist(buf, NULL);
	}
	return idx;
}

int
listcmp(const void *a, const void *b)
{
	const Obj *const *obja;
	const Obj *const *objb;

	obja = a;
	objb = b;
	return objcmp(obja[0], objb[0]);
}

int
load(const char *name, Obj **lists, size_t maxlists, size_t *numlists)
{
	FILE *fp;

	fp = fopen(name, "r");
	if (!fp)
		return -errno;

	*numlists = readlists(fp, lists, maxlists);
	fclose(fp);
	return 0;
}

int
part1(Obj **lists, size_t numlists)
{
	int pairs;
	int cmp;
	size_t i;

	assert(!(numlists % 2));
	pairs = 0;
	for (i = 0; i + 1 < numlists; i += 2) {
		cmp = objcmp(lists[i], lists[i + 1]);
		if (cmp == -1)
			pairs += (i / 2) + 1;
	}
	return pairs;
}

int
part2(Obj **lists, size_t numlists)
{
	Obj *div1, *div2;
	size_t div1idx, div2idx;
	size_t i;

	assert(numlists + 2 < MAXLISTS);
	div1 = parselist("[[2]]", NULL);
	div2 = parselist("[[6]]", NULL);
	lists[numlists++] = div1;
	lists[numlists++] = div2;
	qsort(lists, numlists, sizeof(*lists), listcmp);
	for (i = 0; i < numlists; i++) {
		if (lists[i] == div1)
			div1idx = i + 1;
		else if (lists[i] == div2)
			div2idx = i + 1;
	}
	return div1idx * div2idx;
}

int
main()
{
	Obj *lists[MAXLISTS];
	size_t numlists;
	size_t i;

	if (load("13.txt", lists, MAXLISTS, &numlists) < 0) {
		printf("Failed to load file: %s\n", strerror(errno));
		return 1;
	}

	printf("%d\n", part1(lists, numlists));
	printf("%d\n", part2(lists, numlists));

	for (i = 0; i < MAXLISTS; i++)
		objfree(lists[i]);

	return 0;
}
