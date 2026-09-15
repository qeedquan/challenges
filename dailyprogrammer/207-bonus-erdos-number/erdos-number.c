/*

In honor of the 102nd birthday of the famous mathematician, a problem named after him.

Description
Paul Erdős (1913–1996) was an influential mathematician who spent a large portion of his later life writing papers with a large number of colleagues, working on solutions to outstanding mathematical problems. The idea of the Erdős number was originally created by the mathematician's friends as a tribute to his enormous output. However, in later years it gained prominence as a tool to study how mathematicians cooperate to find answers to unsolved problems.

The Erdös number describes the "collaborative distance" between mathematician Paul Erdős and another person, as measured by authorship of mathematical papers. Erdös himself has a number of 0, anyone he co-authored a paper with has a number of 1, anyone they co-authored a paper with (without Erdös) has a number of 2, and so forth.

Several studies have shown that leading mathematicians tend to have particularly low Erdős numbers. For example, only 134,007 mathematicians have an Erdős number, with a median value of 5. In contrast, the median Erdős number of Fields Medalists is 3. Only 7,097 (about 5%) of mathematicians with a collaboration path have an Erdős number of 2 or less.

For this challenge you'll be working with a small, toy database of Erdős and related publications and be asked to calculate the Erdős number for several authors.

Input Description
You'll be given 2 integers on the first line, N and M. N is the number of of papers in APA format showing authors, titles, journals, and the like; think of it as a mini database. M is the number of authors to identify the Erdős number for. Note that all of the names should be in the same format of last name, then first and middle initials.

Output
Your program should emit the name of the mathematician and their Erdős number.

Challenge Input
7 4
Thomassen, C., Erdös, P., Alavi, Y., Malde, P. J., & Schwenk, A. J. (1989). Tight bounds on the chromatic sum of a connected graph. Journal of Graph Theory, 13(3), 353-357.
Burr, S., Erdös, P., Faudree, R. J., Rousseau, C. C., & Schelp, R. H. (1988). Some complete bipartite graph—tree Ramsey numbers. Annals of Discrete Mathematics, 41, 79-89.
Burris, A. C., & Schelp, R. H. (1997). Vertex-distinguishing proper edge-colorings. Journal of graph theory, 26(2), 73-82.
Balister, P. N., Gyo˝ ri, E., Lehel, J., & Schelp, R. H. (2007). Adjacent vertex distinguishing edge-colorings. SIAM Journal on Discrete Mathematics, 21(1), 237-250.
Erdös, P., & Tenenbaum, G. (1989). Sur les fonctions arithmétiques liées aux diviseurs consécutifs. Journal of Number Theory, 31(3), 285-311.
Hildebrand, A., & Tenenbaum, G. (1993). Integers without large prime factors. Journal de théorie des nombres de Bordeaux, 5(2), 411-484.
Balister, P. N., Riordan, O. M., & Schelp, R. H. (2003). Vertex‐distinguishing edge colorings of graphs. Journal of graph theory, 42(2), 95-109.
Schelp, R. H.
Burris, A. C.
Riordan, O. M.
Balister, P. N.
Challenge Output
Schelp, R. H. 1
Burris, A. C. 2
Riordan, O. M. 2
Balister, P. N. 2
Notes
This challenge is a shameless rip off of http://www.programming-challenges.com/pg.php?page=downloadproblem&format=html&probid=110206. It was too good to pass up; I did, however, compile my own challenge inputs and outputs.

A full list of Erdös publications is up here http://www.renyi.hu/~p_erdos/Erdos.html.

Finally
Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define min(a, b) (b) < (a) ? (b) : (a)

typedef struct Author Author;

struct Author {
	int order;
	Author *next;
	char fullname[];
};

void *
xmalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		abort();
	return ptr;
}

Author *
author_find(Author *authors, const char *fullname)
{
	Author *author;

	for (author = authors; author; author = author->next) {
		if (!strcmp(author->fullname, fullname))
			return author;
	}
	return NULL;
}

Author *
author_push(Author **authors, const char *last, const char *initals)
{
	size_t namelen;
	Author *author;

	namelen = strlen(last) + 2 + strlen(initals) + 1;
	author = xmalloc(sizeof(*author) + namelen);
	sprintf(author->fullname, "%s, %s", last, initals);
	author->order = INT_MAX;
	author->next = *authors;
	*authors = author;
	return author;
}

void
author_merge(Author **authors, Author *paper)
{
	Author *author;
	Author *original;
	int order;

	order = INT_MAX;
	for (author = paper; author; author = author->next) {
		original = author_find(*authors, author->fullname);
		if (original && original->order < INT_MAX)
			order = min(order, original->order + 1);
	}

	while (paper) {
		author = paper;
		original = author_find(*authors, author->fullname);
		paper = paper->next;
		if (original) {
			free(author);
			original->order = min(original->order, order);
		} else {
			author->order = order;
			author->next = *authors;
			*authors = author;
		}
	}
}

void
author_free(Author **authors)
{
	Author *dead;

	while (*authors) {
		dead = *authors;
		*authors = (*authors)->next;
		free(dead);
	}
	*authors = NULL;
}

void
erdos(FILE *fp)
{
	Author *authors, *author, *paper;
	int num_papers, num_authors;
	int i, c;
	char line[256], last[64], initials[8];
	bool final;

	authors = NULL;
	author = author_push(&authors, "Erdös", "P.");
	author->order = 0;

	fscanf(fp, "%d %d ", &num_papers, &num_authors);
	for (i = 0; i < num_papers; i++) {
		paper = NULL;
		final = false;
		while (!final) {
			if ((c = fgetc(fp)) == '&')
				final = true;
			else
				ungetc(c, fp);

			fscanf(fp, " %63[^, ], %7[^,(], ", last, initials);
			if (final)
				initials[strlen(initials) - 1] = '\0';

			author_push(&paper, last, initials);
		}

		while (fgetc(fp) != '\n')
			;

		author_merge(&authors, paper);
	}

	for (i = 0; i < num_authors; i++) {
		fgets(line, sizeof(line), fp);
		line[strlen(line) - 1] = '\0';

		author = author_find(authors, line);
		if (author && author->order < INT_MAX)
			printf("%s %d\n", author->fullname, author->order);
		else
			printf("%s %s\n", line, "infinity");
	}

	author_free(&authors);
}

int
main()
{
	erdos(stdin);
	return 0;
}
