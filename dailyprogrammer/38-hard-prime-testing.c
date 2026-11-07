/*

Write a function that tests whether large numbers are prime or not, with extremely high certainty. There are several primality tests that can do this. Fairly simple ones include the Fermat Test and the even better Miller-Rabin test. The Wikipedia articles have pseudocode you can implement.

Use your function and a random number generator to post a 100-digit prime. You can test your result at Wolfram|Alpha.

thanks to cosmologicon for the challenge at /r/dailyprogrammer_ideas

*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <gmp.h>

int reps = 250;

void
usage()
{
	fprintf(stderr, "usage: <num> ...\n");
	fprintf(stderr, "\t-h\tshow this message\n");
	fprintf(stderr, "\t-r\tspecify reps (default: %d)\n", reps);
	exit(2);
}

int
main(int argc, char *argv[])
{
	static const char *cat[] = {"Not Prime", "Probably Prime", "Prime"};

	int c, i, r;
	mpz_t x;

	while ((c = getopt(argc, argv, "hr:")) != -1) {
		switch (c) {
		case 'h':
			usage();
			break;
		case 'r':
			reps = atoi(optarg);
			break;
		}
	}
	argc -= optind;
	argv += optind;
	if (argc < 1)
		usage();

	mpz_init(x);
	for (i = 0; i < argc; i++) {
		mpz_set_str(x, argv[i], 0);
		r = mpz_probab_prime_p(x, reps);
		printf("%s: %s\n", argv[i], cat[r]);
	}
	mpz_clear(x);

	return 0;
}
