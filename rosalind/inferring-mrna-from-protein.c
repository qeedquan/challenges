/*

Pitfalls of Reversing Translation

When researchers discover a new protein, they would like to infer the strand of mRNA from which this protein could have been translated, thus allowing them to locate genes associated with this protein on the genome.

Unfortunately, although any RNA string can be translated into a unique protein string, reversing the process yields a huge number of possible RNA strings from a single protein string because most amino acids correspond to multiple RNA codons (see the RNA Codon Table).

Because of memory considerations, most data formats that are built into languages have upper bounds on how large an integer can be: in some versions of Python, an "int" variable may be required to be no larger than 2^31-1, or 2,147,483,647.
As a result, to deal with very large numbers in Rosalind, we need to devise a system that allows us to manipulate large numbers without actually having to store large numbers.

Problem
For positive integers a and n, a modulo n (written a mod n in shorthand) is the remainder when a is divided by n.
For example, 29 mod 11 = 7 because 29 = 11*2 + 7.

Modular arithmetic is the study of addition, subtraction, multiplication, and division with respect to the modulo operation.
We say that a and b are congruent modulo n if a mod n = b mod n; in this case, we use the notation a≡bmodn.

Two useful facts in modular arithmetic are that if a ≡ b mod n and c ≡ d mod n, then a + c ≡ b + d mod n and a*c ≡ b*d mod n.
To check your understanding of these rules, you may wish to verify these relationships for a=29, b=73, c=10, d=32, and n=11.

As you will see in this exercise, some Rosalind problems will ask for a (very large) integer solution modulo a smaller number to avoid the computational pitfalls that arise with storing such large numbers.

Given: A protein string of length at most 1000 aa.

Return: The total number of different RNA strings from which the protein could have been translated, modulo 1,000,000. (Don't neglect the importance of the stop codon in protein translation.)

Sample Dataset
MA
Sample Output
12

Hint
What does it mean intuitively to take a number modulo 1,000,000?

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
infer(const char *s)
{
	static const vlong rev[] = {
		['A'] = 4,
		['C'] = 2,
		['D'] = 2,
		['E'] = 2,
		['F'] = 2,
		['G'] = 4,
		['H'] = 2,
		['I'] = 3,
		['K'] = 2,
		['L'] = 6,
		['M'] = 1,
		['N'] = 2,
		['P'] = 4,
		['Q'] = 2,
		['R'] = 6,
		['S'] = 6,
		['T'] = 4,
		['V'] = 4,
		['W'] = 1,
		['Y'] = 2,
	};

	vlong m, p;

	m = 1000000;
	for (p = 1; *s; s++)
		p = (p * rev[*s & 0xff]) % m;
	p = (p * 3) % m;
	return p;
}

int
main()
{
	assert(infer("MA") == 12);
	assert(infer("MWDSTPSRIHCPEASRMPTGWDEMVDLHHQHITIRPSTTRFECEICSMTLKQQVHSNVEQWPKFCSANNTQHGIPGMQEYFAINCNYDEFTMYYCAYPHSRARWRGVILLYQLSHMSQFEDIHGFHQMAKPDHNDCIFTHSTSQFAHEQVFQRLVQIKNNYTEQSNSFCPENHPDWAVMKTYRCKAHICYIVFGVTQSEFSPIMERNNVYCYIWFRWTPFMNCKQRLLAPGWKNHVAQYAGEKIYNYSQLNDADLICWRKAREDWQMYLQGMFENRTGPQCWYWHPEYPGWYIDLPWDWGHFYWVDHVSEYDYYELCQAGNNMHEHDMFREFCVYDTATKMSYLSADDAEMSNELAMTKTNQMSQVHSQCHPVTAECTWQVMLWTLMIKSPDCMYKEGTWSTAHWTCFQMCWAWPCEASRHTLMITYHGVFHLAYAIRYQHKLKECEAQKSCQLDKKQNMIVDDQIRGQDEPIASQYNEETQVNQMNNFKWQHWAMVTKAGWSNDGFWQHFHCKNSWGMKPEKNSAYWPMLYYDACVTYPNTIKSGGYTWPTCWSLQLNSEDNYHRCARYPRWNNCKDQLISNHVLPMCNAHCCEETILMTHGTWRDHFMNYMQVLNQGGWMEWYFAMDSFETDCPKFSEGTIFYSWQWKPTFMMFWGVDFFLMAMRIHYMLIYDPQQNGFRCEYVEYLRRFTQYKRASKIKFKKLCHDRYTPSWDNSKPAIAKNGLHCSNELSFNAPPERYHHSYMEDTWDTCSCIESNFYFLVLSEVWCYFFYYCAYGAIPSRKMFIQVFYFHFMRVMPSADMDIRYSFECIQASIPDFKRAKYWDDKLCVGCGFGFTGDLNNCQYSYIYLWAVRGGAFAEWNFLQSAEWDLWQEMEEENAFITGSLLCDQSTPRNRQCGEKVMSSLVPYFLFRFPTNLRYDFHVAMFKPCLCCLGFRIHMMDEQIMVDCSIERPDVTNAFARIIIVMHPCVQNYTFAGFAIYPSKQWYMNCKKWN") == 221312);

	return 0;
}
