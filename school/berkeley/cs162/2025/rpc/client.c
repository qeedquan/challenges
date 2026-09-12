#include <stdio.h>
#include <rpc/rpc.h>
#include "kv_store.h"

int
main(int argc, char *argv[])
{
	CLIENT *cl;
	int i1, *i2;
	char *s1, **s2;

	if (argc != 2) {
		printf("Usage: client hostname\n");
		exit(1);
	}

	cl = clnt_create(argv[1], KVSTORE, KVSTORE_V1, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	s1 = "hello";
	i1 = 13;
	i2 = example_1(&i1, cl);
	s2 = echo_1(&s1, cl);
	if (i2 == NULL || s2 == NULL) {
		clnt_perror(cl, argv[1]);
		exit(1);
	}

	printf("example(%d)=%d\n", i1, *i2);
	printf("echo(%s)=%s\n", s1, *s2);

	xdr_free((xdrproc_t)xdr_int, i2);
	xdr_free((xdrproc_t)xdr_string, s2);
	clnt_destroy(cl);

	return 0;
}
