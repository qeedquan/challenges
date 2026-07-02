/*

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Node Node;

struct Node {
	Node *child[256];
	bool leaf;
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

Node *
trienew(void)
{
	return xcalloc(1, sizeof(Node));
}

void
trieinsert(Node *n, const char *s)
{
	size_t i;
	int c;

	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (n->child[c] == NULL)
			n->child[c] = xcalloc(1, sizeof(*n->child[c]));
		n = n->child[c];
	}
	n->leaf = true;
}

Node *
trieget(Node *n, const char *s)
{
	size_t i;
	int c;

	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		n = n->child[c];
		if (n == NULL)
			return NULL;
	}
	return n;
}

bool
triesearch(Node *n, const char *s)
{
	Node *p;

	p = trieget(n, s);
	return p != NULL && p->leaf;
}

bool
trieprefix(Node *n, const char *s)
{
	return trieget(n, s) != NULL;
}

void
triefree(Node *n)
{
	size_t i;

	if (!n)
		return;

	for (i = 0; i < nelem(n->child); i++) {
		if (n->child[i])
			triefree(n->child[i]);
	}
	free(n);
}

int
main(void)
{
	Node *t;

	t = trienew();
	trieinsert(t, "apple");
	assert(triesearch(t, "apple") == true);
	assert(triesearch(t, "app") == false);
	assert(trieprefix(t, "app") == true);
	trieinsert(t, "app");
	assert(triesearch(t, "app") == true);
	assert(triesearch(t, "applet") == false);
	assert(trieprefix(t, "applet") == false);
	triefree(t);

	return 0;
}
