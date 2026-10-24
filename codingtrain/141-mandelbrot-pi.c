/*

http://www.pi314.net/eng/mandelbrot.php

*/

#include <stdio.h>
#include <gmp.h>

typedef unsigned uint;

typedef struct {
	uint digits;

	mpf_t one;
	mpf_t two;
	mpf_t hundred;

	mpf_t c;
	mpf_t e;
	mpf_t z;
	mpz_t n;
} MPI;

void
mpi_init(MPI *m, uint digits)
{
	uint prec;

	prec = (digits * digits) + 128;
	m->digits = digits;

	mpf_init(m->one);
	mpf_init(m->two);
	mpf_init(m->hundred);

	mpf_set_prec(m->one, prec);
	mpf_set_prec(m->two, prec);
	mpf_set_prec(m->hundred, prec);

	mpf_set_d(m->one, 1);
	mpf_set_d(m->two, 2);
	mpf_set_d(m->hundred, 100);

	mpf_init(m->c);
	mpf_init(m->e);
	mpf_init(m->z);
	mpz_init(m->n);

	mpf_set_prec(m->c, prec);
	mpf_set_prec(m->e, prec);
	mpf_set_prec(m->z, prec);

	mpf_set_d(m->c, 0.25);
	mpf_set_d(m->z, 0);
	mpz_set_ui(m->n, 0);

	mpf_pow_ui(m->e, m->hundred, digits - 1);
	mpf_div(m->e, m->one, m->e);
	mpf_add(m->c, m->c, m->e);
}

void
mpi_free(MPI *m)
{
	mpf_clear(m->one);
	mpf_clear(m->two);
	mpf_clear(m->hundred);
	mpf_clear(m->c);
	mpf_clear(m->e);
	mpf_clear(m->z);
	mpz_clear(m->n);
}

bool
mpi_next(MPI *m)
{
	uint i;

	for (i = 0; i < 25691; i++) {
		if (mpf_cmp(m->z, m->two) >= 0)
			return false;

		mpf_mul(m->z, m->z, m->z);
		mpf_add(m->z, m->z, m->c);
		mpz_add_ui(m->n, m->n, 1);
	}
	return true;
}

void
mpi_show(MPI *m)
{
	char buf[128];
	char iters[64];
	char *ptr;
	int diff;
	int len;
	int i;

	len = gmp_snprintf(iters, sizeof(iters), "%Zd", m->n);
	diff = m->digits - len;
	ptr = buf;
	for (i = 0; i < diff; i++)
		*ptr++ = '0';
	ptr += sprintf(ptr, "%s", iters);

	printf("%c.%s\n", buf[0], &buf[1]);
}

int
main()
{
	MPI m[1];

	mpi_init(m, 9);
	while (mpi_next(m))
		mpi_show(m);
	mpi_free(m);
	return 0;
}
