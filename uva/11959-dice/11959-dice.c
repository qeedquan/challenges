#include <assert.h>
#include <stdio.h>
#include <string.h>

void
shift(char a[6], int i, int j, int k, int l)
{
	char t;

	t = a[i];
	a[i] = a[j];
	a[j] = a[k];
	a[k] = a[l];
	a[l] = t;
}

bool
equal(const char *s, const char *t)
{
	char a[7], b[7];
	int i, j, k;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	snprintf(a, sizeof(a), "%s", s);
	snprintf(b, sizeof(b), "%s", t);

	for (i = 0; i < 4; i++) {
		shift(a, 0, 4, 1, 2);
		for (j = 0; j < 4; j++) {
			shift(a, 2, 5, 4, 3);
			for (k = 0; k < 4; k++) {
				shift(a, 0, 5, 1, 3);
				if (!memcmp(a, b, 6))
					return true;
			}
		}
	}
	return false;
}

int
main()
{
	assert(equal("345678", "345678") == true);
	assert(equal("123123", "123456") == false);
	assert(equal("123456", "351624") == true);

	return 0;
}
