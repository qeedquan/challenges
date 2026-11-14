/*

Description:
Complete function minValue (min_value in Ruby). Two arguments will be given:

arr: An array that contains some integers(positve,negative or zero).

n: A positive integer. n <= arr.length.

Your task is to find the minimum value of each n adjacent elements in arr. Returns by a new array. For example:

arr = [1,2,3,10,-5], n = 2
The min value of each 2 adjacent elements are:
[(1,2)...] --> 1
[.(2,3)..] --> 2
[..(3,10).] --> 3
[...(10,-5)] --> -5

minValue(arr,n) === [1,2,3,-5]
Some Examples
minValue([1,-2,3,-4,5,-6,7,8],1) === [1,-2,3,-4,5,-6,7,8]
minValue([1,-2,3,-4,5,-6,7,8],2) === [-2,-2,-4,-4,-6,-6,7]
minValue([1,-2,3,-4,5,-6,7,8],3) === [-2,-4,-4,-6,-6,-6]
minValue([1,-2,3,-4,5,-6,7,8],4) === [-4,-4,-6,-6,-6]
Note:

You can assume that all inputs are valid.
This is a simple version, please look forward to the challenge version ;-)
A bit difficulty, A bit of fun, happy coding ;-)

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// ported from 9front

typedef struct Avl Avl;
typedef struct Avltree Avltree;
typedef struct Node Node;

struct Avl {
	Avl *c[2];
	Avl *p;
	int balance;
};

struct Avltree {
	int (*cmp)(Avl *, Avl *);
	Avl *root;
};

struct Node {
	Avl a;
	int v;
};

Avltree *avlinit(Avltree *, int (*)(Avl *, Avl *));
Avltree *avlcreate(int (*)(Avl *, Avl *));
Avl *avllookup(Avltree *, Avl *, int);
Avl *avldelete(Avltree *, Avl *);
Avl *avlinsert(Avltree *, Avl *);
Avl *avlmin(Avltree *);
Avl *avlmax(Avltree *);
Avl *avlnext(Avl *);
Avl *avlprev(Avl *);

Avltree *
avlcreate(int (*cmp)(Avl *, Avl *))
{
	Avltree *t;

	t = malloc(sizeof(*t));
	if (t == NULL)
		return NULL;
	return avlinit(t, cmp);
}

Avltree *
avlinit(Avltree *t, int (*cmp)(Avl *, Avl *))
{
	t->cmp = cmp;
	t->root = NULL;
	return t;
}

Avl *
avllookup(Avltree *t, Avl *k, int d)
{
	Avl *h, *n;
	int c;

	n = NULL;
	h = t->root;
	while (h != NULL) {
		c = (t->cmp)(k, h);
		if (c < 0) {
			if (d > 0)
				n = h;
			h = h->c[0];
			continue;
		}
		if (c > 0) {
			if (d < 0)
				n = h;
			h = h->c[1];
			continue;
		}
		return h;
	}
	return n;
}

static int insert(int (*)(Avl *, Avl *), Avl *, Avl **, Avl *, Avl **);

Avl *
avlinsert(Avltree *t, Avl *k)
{
	Avl *old;

	old = NULL;
	insert(t->cmp, NULL, &t->root, k, &old);
	return old;
}

static int insertfix(int, Avl **);

static int
insert(int (*cmp)(Avl *, Avl *), Avl *p, Avl **qp, Avl *k, Avl **oldp)
{
	Avl *q;
	int fix, c;

	q = *qp;
	if (q == NULL) {
		k->c[0] = NULL;
		k->c[1] = NULL;
		k->balance = 0;
		k->p = p;
		*qp = k;
		return 1;
	}

	c = cmp(k, q);
	if (c == 0) {
		*oldp = q;
		*k = *q;
		if (q->c[0] != NULL)
			q->c[0]->p = k;
		if (q->c[1] != NULL)
			q->c[1]->p = k;
		*qp = k;
		return 0;
	}
	c = c > 0 ? 1 : -1;
	fix = insert(cmp, q, q->c + (c + 1) / 2, k, oldp);
	if (fix)
		return insertfix(c, qp);
	return 0;
}

static Avl *singlerot(int, Avl *);
static Avl *doublerot(int, Avl *);

static int
insertfix(int c, Avl **t)
{
	Avl *s;

	s = *t;
	if (s->balance == 0) {
		s->balance = c;
		return 1;
	}
	if (s->balance == -c) {
		s->balance = 0;
		return 0;
	}
	if (s->c[(c + 1) / 2]->balance == c)
		s = singlerot(c, s);
	else
		s = doublerot(c, s);
	*t = s;
	return 0;
}

static int deletenod(int (*cmp)(Avl *, Avl *), Avl **, Avl *, Avl **);
static int deletemin(Avl **, Avl **);
static int deletefix(int, Avl **);

Avl *
avldelete(Avltree *t, Avl *k)
{
	Avl *old;

	if (t->root == NULL)
		return NULL;
	old = NULL;
	deletenod(t->cmp, &t->root, k, &old);
	return old;
}

static int
deletenod(int (*cmp)(Avl *, Avl *), Avl **qp, Avl *k, Avl **oldp)
{
	Avl *q, *e;
	int c, fix;

	q = *qp;
	if (q == NULL)
		return 0;

	c = cmp(k, q);
	if (c > 0)
		c = 1;
	else if (c < 0)
		c = -1;
	if (c == 0) {
		*oldp = q;
		if (q->c[1] == NULL) {
			*qp = q->c[0];
			if (*qp != NULL)
				(*qp)->p = q->p;
			return 1;
		}
		fix = deletemin(q->c + 1, &e);
		*e = *q;
		if (q->c[0] != NULL)
			q->c[0]->p = e;
		if (q->c[1] != NULL)
			q->c[1]->p = e;
		*qp = e;
		if (fix)
			return deletefix(-1, qp);
		return 0;
	}
	fix = deletenod(cmp, q->c + (c + 1) / 2, k, oldp);
	if (fix)
		return deletefix(-c, qp);
	return 0;
}

static int
deletemin(Avl **qp, Avl **oldp)
{
	Avl *q;
	int fix;

	q = *qp;
	if (q->c[0] == NULL) {
		*oldp = q;
		*qp = q->c[1];
		if (*qp != NULL)
			(*qp)->p = q->p;
		return 1;
	}
	fix = deletemin(q->c, oldp);
	if (fix)
		return deletefix(1, qp);
	return 0;
}

static Avl *rotate(int, Avl *);

static int
deletefix(int c, Avl **t)
{
	Avl *s;
	int a;

	s = *t;
	if (s->balance == 0) {
		s->balance = c;
		return 0;
	}
	if (s->balance == -c) {
		s->balance = 0;
		return 1;
	}
	a = (c + 1) / 2;
	if (s->c[a]->balance == 0) {
		s = rotate(c, s);
		s->balance = -c;
		*t = s;
		return 0;
	}
	if (s->c[a]->balance == c)
		s = singlerot(c, s);
	else
		s = doublerot(c, s);
	*t = s;
	return 1;
}

static Avl *
singlerot(int c, Avl *s)
{
	s->balance = 0;
	s = rotate(c, s);
	s->balance = 0;
	return s;
}

static Avl *
doublerot(int c, Avl *s)
{
	Avl *r, *p;
	int a;

	a = (c + 1) / 2;
	r = s->c[a];
	s->c[a] = rotate(-c, s->c[a]);
	p = rotate(c, s);
	assert(r->p == p);
	assert(s->p == p);

	if (p->balance == c) {
		s->balance = -c;
		r->balance = 0;
	} else if (p->balance == -c) {
		s->balance = 0;
		r->balance = c;
	} else
		s->balance = r->balance = 0;
	p->balance = 0;
	return p;
}

static Avl *
rotate(int c, Avl *s)
{
	Avl *r, *n;
	int a;

	a = (c + 1) / 2;
	r = s->c[a];
	s->c[a] = n = r->c[a ^ 1];
	if (n != NULL)
		n->p = s;
	r->c[a ^ 1] = s;
	r->p = s->p;
	s->p = r;
	return r;
}

static Avl *walk1(int, Avl *);

Avl *
avlprev(Avl *q)
{
	return walk1(0, q);
}

Avl *
avlnext(Avl *q)
{
	return walk1(1, q);
}

static Avl *
walk1(int a, Avl *q)
{
	Avl *p;

	if (q == NULL)
		return NULL;

	if (q->c[a] != NULL) {
		for (q = q->c[a]; q->c[a ^ 1] != NULL; q = q->c[a ^ 1])
			;
		return q;
	}
	for (p = q->p; p != NULL && p->c[a] == q; p = p->p)
		q = p;
	return p;
}

static Avl *bottom(Avltree *, int);

Avl *
avlmin(Avltree *t)
{
	return bottom(t, 0);
}

Avl *
avlmax(Avltree *t)
{
	return bottom(t, 1);
}

static Avl *
bottom(Avltree *t, int d)
{
	Avl *n;

	if (t == NULL)
		return NULL;
	if (t->root == NULL)
		return NULL;

	for (n = t->root; n->c[d] != NULL; n = n->c[d])
		;
	return n;
}

int
cmp(Avl *a, Avl *b)
{
	Node *x, *y;

	x = (Node *)a;
	y = (Node *)b;
	if (x->v < y->v)
		return -1;
	if (x->v == y->v)
		return 0;
	return 1;
}

ssize_t
minvalues(int *a, size_t n, size_t k, int *r)
{
	Avltree t[1];
	Node *e, *p;
	size_t i;

	if (k == 0)
		return 0;
	if (k > n)
		k = n;

	e = calloc(n, sizeof(*e));
	if (!e)
		return -errno;

	avlinit(t, cmp);
	for (i = 0; i < n; i++)
		e[i].v = a[i];
	for (i = 0; i < k; i++)
		avlinsert(t, (Avl *)&e[i]);

	for (i = 0; i <= n - k; i++) {
		p = (Node *)avlmin(t);
		r[i] = p->v;

		avldelete(t, (Avl *)&e[i]);
		if (i + k < n)
			avlinsert(t, (Avl *)&e[i + k]);
	}

	free(e);
	return n - k + 1;
}

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n, size_t k, int *r, ssize_t nr)
{
	int p[32];
	ssize_t np;

	np = minvalues(a, n, k, p);
	dump(p, np);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int a1[] = { 1, -2, 3, -4, 5, -6, 7, 8 };

	int r1[] = { 1, -2, 3, -4, 5, -6, 7, 8 };
	int r2[] = { -2, -2, -4, -4, -6, -6, 7 };
	int r3[] = { -2, -4, -4, -6, -6, -6 };
	int r4[] = { -4, -4, -6, -6, -6 };

	test(a1, nelem(a1), 1, r1, nelem(r1));
	test(a1, nelem(a1), 2, r2, nelem(r2));
	test(a1, nelem(a1), 3, r3, nelem(r3));
	test(a1, nelem(a1), 4, r4, nelem(r4));

	return 0;
}
