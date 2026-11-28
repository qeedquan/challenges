// https://maskray.me/blog/c-minifier-with-clang
#include <stdint.h>
#include <string.h>

#pragma GCC diagnostic ignored "-Wpragmas"
static float foo(int, int);
static float
foo(int aaa, int bbb)
{
	aaa = 3;
	bbb = 5;
	return 1.0f;
}

struct NimStrPayload;
typedef struct NimStrPayload NimStrPayload;
struct NimStringV2;
typedef struct NimStringV2 NimStringV2;

struct NimStrPayload {
	int64_t cap;
	char data[];
};
struct NimStringV2 {
	int64_t cap;
	NimStrPayload *p;
};

#define XX NimStringV2

float
goo()
{
	int u, v, w, x, y, z;
	int s1, t1, u1, v1, w1, x1, y1, z1;
	NimStringV2 s;
	XX t;
	return 1.0f;
}

int
main()
{
	char a[10];
	memset(a, 0, 10);
	float _ = foo(3, 5) + goo();
	return 0;
}
