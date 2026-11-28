/*

More Random Strings

In “Introduction to Random Strings”, we discussed searching for motifs in large genomes, in which random occurrences of the motif are possible. Our aim is to quantify just how frequently random motifs occur.

One class of motifs of interest are promoters, or regions of DNA that initiate the transcription of a gene. A promoter is usually located shortly before the start of its gene, and it contains specific intervals of DNA that provide an initial binding site for RNA polymerase to initiate transcription. Finding a promoter is usually the second step in gene prediction after establishing the presence of an ORF (see “Open Reading Frames”).

Unfortunately, there is no quick rule for identifying promoters. In Escherichia coli, the promoter contains two short intervals (TATAAT and TTGACA), which are respectively located 10 and 35 base pairs upstream from the beginning of the gene's ORF. Yet even these two short intervals are consensus strings (see “Consensus and Profile”): they represent average-case strings that are not found intact in most promoters. Bacterial promoters further vary in that some contain additional intervals used to bind to specific proteins or to change the intensity of transcription.

Eukaryotic promoters are even more difficult to characterize. Most have a TATA box (consensus sequence: TATAAA), preceded by an interval called a B recognition element, or BRE. These elements are typically located within 40 bp of the start of transcription. For that matter, eukaryotic promoters can hold a larger number of additional "regulatory" intervals, which can be found as far as several thousand base pairs upstream of the gene.

Problem
Our aim in this problem is to determine the probability with which a given motif (a known promoter, say) occurs in a randomly constructed genome. Unfortunately, finding this probability is tricky; instead of forming a long genome, we will form a large collection of smaller random strings having the same length as the motif; these smaller strings represent the genome's substrings, which we can then test against our motif.

Given a probabilistic event A, the complement of A is the collection Ac of outcomes not belonging to A. Because Ac takes place precisely when A does not, we may also call Ac "not A."

For a simple example, if A is the event that a rolled die is 2 or 4, then Pr(A)=13. Ac is the event that the die is 1, 3, 5, or 6, and Pr(Ac)=23. In general, for any event we will have the identity that Pr(A)+Pr(Ac)=1.

Given: A positive integer N≤100000, a number x between 0 and 1, and a DNA string s of length at most 10 bp.

Return: The probability that if N random DNA strings having the same length as s are constructed with GC-content x (see “Introduction to Random Strings”), then at least one of the strings equals s. We allow for the same random string to be created more than once.

Sample Dataset
90000 0.6
ATAGCCGA
Sample Output
0.689

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
solve(long n, double x, const char *s)
{
	double at, gc, p;

	for (at = gc = 0; *s; s++) {
		switch (*s) {
		case 'A':
		case 'T':
			at++;
			break;
		case 'G':
		case 'C':
			gc++;
			break;
		}
	}

	p = pow(x * 0.5, gc) * pow((1 - x) * 0.5, at);
	p = 1 - pow(1 - p, n);
	return p;
}

void
test(long n, double x, const char *s, double r)
{
	double p;

	p = solve(n, x, s);
	printf("%.3f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main()
{
	test(90000, 0.6, "ATAGCCGA", 0.689);
	test(93651, 0.448381, "GTTGATTTGA", 0.120);

	return 0;
}
