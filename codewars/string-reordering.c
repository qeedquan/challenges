/*

The input will be an array of dictionaries.

Return the values as a string-seperated sentence in the order of their keys' integer equivalent (increasing order).

The keys are not reoccurring and their range is -999 < key < 999. The dictionaries' keys & values will always be strings and will always not be empty.

Example

Input:
List = [
        {'4': 'dog' }, {'2': 'took'}, {'3': 'his'},
        {'-2': 'Vatsan'}, {'5': 'for'}, {'6': 'a'}, {'12': 'spin'}
       ]

Output:
'Vatsan took his dog for a spin'

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int key;
	const char *val;
} Dict;

int
dictcmp(const void *a, const void *b)
{
	const Dict *d1, *d2;

	d1 = a;
	d2 = b;
	if (d1->key < d2->key)
		return -1;
	if (d1->key > d2->key)
		return 1;
	return strcmp(d1->val, d2->val);
}

void
sentence(Dict *dict, size_t ndict, char *buf)
{
	size_t i, len;

	qsort(dict, ndict, sizeof(*dict), dictcmp);

	len = 0;
	for (i = 0; i < ndict; i++)
		len += sprintf(buf + len, "%s ", dict[i].val);
	if (len > 0)
		len--;
	buf[len] = '\0';
}

void
test(Dict *dict, size_t ndict, char *res)
{
	char buf[64];

	sentence(dict, ndict, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	Dict dict[] = {
		{ 4, "dog" },
		{ 2, "took" },
		{ 3, "his" },
		{ -2, "Vatsan" },
		{ 5, "for" },
		{ 6, "a" },
		{ 12, "spin" },
	};

	test(dict, nelem(dict), "Vatsan took his dog for a spin");

	return 0;
}
