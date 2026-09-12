/*

Task
Given a non-empty string of lowercase ASCII letters a-z, take its first character, and:

Surround it with a square of copies of the second character,
Surround that with a diamond of copies of the third character,
Surround that with a square of copies of the fourth character…
…alternating between square and diamond borders until the end of the string. Empty space between the borders should be represented by ASCII spaces ().

To add a square border, draw a square exactly around the entire current “working array”:

                                               sssssssssss
                                t              s    t    s
                               t t             s   t t   s
                              t   t            s  t   t  s
                             t aaa t           s t aaa t s
                            t  aca  t    =>    st  aca  ts
                             t aaa t           s t aaa t s
                              t   t            s  t   t  s
                               t t             s   t t   s
                                t              s    t    s
                                               sssssssssss
To add a diamond border, draw a centered diamond shape that touches the outermost square diagonally, but not orthogonally:

                                                     s
                                                    s s
                                                   s   s
                                                  s     s
                                                 s       s
                                                s         s
                                               s           s
                    wwwwwwwwwww               s wwwwwwwwwww s
                    w    o    w              s  w    o    w  s
                    w   o o   w             s   w   o o   w   s
                    w  o   o  w            s    w  o   o  w    s
                    w o eee o w           s     w o eee o w     s
                    wo  eme  ow    =>    s      wo  eme  ow      s
                    w o eee o w           s     w o eee o w     s
                    w  o   o  w            s    w  o   o  w    s
                    w   o o   w             s   w   o o   w   s
                    w    o    w              s  w    o    w  s
                    wwwwwwwwwww               s wwwwwwwwwww s
                                               s           s
                                                s         s
                                                 s       s
                                                  s     s
                                                   s   s
                                                    s s
                                                     s
Your program must output the final array.

Each line may contain any amount of trailing spaces.
You may output a list of strings representing lines, or a single newline-separated string with an optional trailing newline.
Leading/trailing blank lines are disallowed.
Leading columns of spaces are also disallowed.
This is code-golf. The shortest code in bytes wins.

Test cases
The above examples are expected outputs for cat, cats, meow, and meows, in reading order. Some other cases worth handling:

For the input a, your program should output:

a
For the input ab, your program should output:

bbb
bab
bbb
For the input codegolf, your program should output:

fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
f                            l                            f
f                           l l                           f
f                          l   l                          f
f                         l     l                         f
f                        l       l                        f
f                       l         l                       f
f                      l           l                      f
f                     l             l                     f
f                    l               l                    f
f                   l                 l                   f
f                  l                   l                  f
f                 l                     l                 f
f                l                       l                f
f               l                         l               f
f              l                           l              f
f             l ooooooooooooooooooooooooooo l             f
f            l  o            g            o  l            f
f           l   o           g g           o   l           f
f          l    o          g   g          o    l          f
f         l     o         g     g         o     l         f
f        l      o        g       g        o      l        f
f       l       o       g         g       o       l       f
f      l        o      g           g      o        l      f
f     l         o     g eeeeeeeeeee g     o         l     f
f    l          o    g  e    d    e  g    o          l    f
f   l           o   g   e   d d   e   g   o           l   f
f  l            o  g    e  d   d  e    g  o            l  f
f l             o g     e d ooo d e     g o             l f
fl              og      ed  oco  de      go              lf
f l             o g     e d ooo d e     g o             l f
f  l            o  g    e  d   d  e    g  o            l  f
f   l           o   g   e   d d   e   g   o           l   f
f    l          o    g  e    d    e  g    o          l    f
f     l         o     g eeeeeeeeeee g     o         l     f
f      l        o      g           g      o        l      f
f       l       o       g         g       o       l       f
f        l      o        g       g        o      l        f
f         l     o         g     g         o     l         f
f          l    o          g   g          o    l          f
f           l   o           g g           o   l           f
f            l  o            g            o  l            f
f             l ooooooooooooooooooooooooooo l             f
f              l                           l              f
f               l                         l               f
f                l                       l                f
f                 l                     l                 f
f                  l                   l                  f
f                   l                 l                   f
f                    l               l                    f
f                     l             l                     f
f                      l           l                      f
f                       l         l                       f
f                        l       l                        f
f                         l     l                         f
f                          l   l                          f
f                           l l                           f
f                            l                            f
fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
Reference implementation
I wrote some Julia code that your program’s output should match (at least visually). Try it online!

input = readline(STDIN)
A = fill(input[1], 1, 1)

square = true
for letter in input[2:end]
  s = size(A)[1]
  if square then
    B = fill(letter, s + 2, s + 2)
    B[2:s+1, 2:s+1] = A
    A = B
  else
    margin = div(s, 2) + 2
    total = s + 2 * margin
    B = fill(' ', total, total)
    B[margin+1:margin+s, margin+1:margin+s] = A
    center = div(total, 2) + 1
    for i in 0:center-1
      B[    1+i, center+i] = letter
      B[    1+i, center-i] = letter
      B[total-i, center+i] = letter
      B[total-i, center-i] = letter
    end
    A = B
  end
  square = !square
end

s = size(A)[1]
A = hcat(A, fill('\n', s, 1))
print(rstrip(join(A')))

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int
bounds(int n)
{
	int i, r;

	r = 0;
	for (i = 1; i <= n; i++) {
		if (i & 1)
			r = r + 1;
		else
			r = (2 * r) + 2;
	}
	return r;
}

char **
alloc(size_t n)
{
	char **p, *t;
	size_t i;

	p = calloc(n, sizeof(*p));
	t = calloc(n * n, sizeof(*t));
	if (!p || !t)
		goto error;

	for (i = 0; i < n; i++)
		p[i] = t + (i * n);

	if (0) {
	error:
		free(p);
		free(t);
		p = NULL;
	}
	return p;
}

void
destroy(char **m)
{
	if (!m)
		return;

	free(m[0]);
	free(m);
}

void
print(char **m, size_t n)
{
	size_t x, y;

	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++)
			printf("%c", m[y][x]);
		printf("\n");
	}
	printf("\n");
}

int
at(const char *s, int l, int r, int x, int y)
{
	int X, Y, R;
	int c, i;

	c = ' ';
	X = abs(x - r);
	Y = abs(y - r);
	for (i = 0; i < l; i++) {
		R = bounds(i);
		if (!(X <= R && Y <= R))
			continue;

		if (i & 1) {
			if (X == R || Y == R)
				c = s[i];
		} else if (X + Y == R)
			c = s[i];
	}
	return c;
}

// ported from @NoddySevens solution
int
sd(const char *s)
{
	char **m;
	int x, y;
	int l, r;
	int n;

	l = strlen(s);
	r = bounds(l - 1);
	n = (r * 2) + 1;

	m = alloc(n);
	if (!m)
		return -errno;

	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++)
			m[y][x] = at(s, l, r, x, y);
	}
	print(m, n);
	destroy(m);
	return 0;
}

int
main()
{
	sd("cats");
	sd("a");
	sd("ab");
	sd("codegolf");
	sd("blah");
	sd("XXXXXX");
	sd("crosscode");

	return 0;
}
