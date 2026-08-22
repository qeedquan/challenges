/*

Given integers  a,b,m,k,n and array
F=(f1,f2,...,fn) defined as:
f[1] = a
f[2] = b
f[i] = f[i-1] + f[i-2] mod m, ∀i>2

When F array is sorted into a non-decreasing sequence, your task is to find the k-th integer of the sorted F array where k≤n.

Sample I/O
I/O format is flexible.

# I/O format
# a, b, m, k, n -> Output
  1, 1, 10, 8, 10 -> 5
  8, 2, 15, 7, 63 -> 2
  21948, 12412, 42124, 85217, 92412 -> 38508
  102492, 128282, 87421, 242122, 341247 -> 61572
  42424, 76767, 97487, 3784274, 10421244 -> 35377
  50127, 31229, 99887, 9784274, 17421244 -> 56002
  11127, 93229, 94823, 20084263, 20421244 -> 93278

Visualization
Let's take the 1st Sample I/O.
After generating the array  F, our array would be:

f1 = 1
f2 = 1
f3 = 2
f4 = 3
f5 = 5
f6 = 8
f7 = 3
f8 = 1
f9 = 4
f10 = 5

When sorting the array F into a non-decreasing sequence, we will get:
f1 = 1
f2 = 1
f3 = 1
f4 = 2
f5 = 3
f6 = 3
f7 = 4
f8 = 5
f9 = 5
f10 = 8

Since our given k was 8 as per our sample, we will print out the value of fk or f8 of the sorted F array, the value of which is 5.
Therefore, for our 1st sample, the output returned was 5.

Winning Criterion
This is a fastest-code challenge.
Timing will be based on the timing shown in the tio.run link provided, in the Debug section, User Time.
A more precise one with times tested on my machine will be conducted later, since performance on tio.run may vary over time.
The time will be measured by how long it takes to complete all 7 test cases provided in the Sample I/O section.

*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long vlong;

// Ported from @emanresu A solution
vlong
f(vlong a, vlong b, vlong m, vlong k, vlong n)
{
	vlong v1, v2, vt;
	vlong llen, mul, rem;
	vlong *cache;
	vlong i;

	v1 = a;
	v2 = b;
	vt = 0;

	cache = calloc(max(a, max(b, m)) + 1, sizeof(*cache));
	if (!cache)
		return -1;

	cache[a]++;
	cache[b]++;
	for (i = 2; i < n; i++) {
		vt = v2;
		v2 = (v2 + v1) % m;
		v1 = vt;
		if (v1 == a && v2 == b) {
			cache[v1]--;

			llen = i - 1;
			mul = n / llen;
			rem = n % llen;

			for (i = 0; i < m; i++)
				cache[i] *= mul;

			for (i = 0; i < rem; i++) {
				vt = v2;
				v2 = (v2 + v1) % m;
				v1 = vt;
				cache[v2]++;
			}
			break;
		}
		cache[v2]++;
	}

	for (i = 0; k >= 0; i++)
		k -= cache[i];

	free(cache);
	return i - 1;
}

int
main()
{
	assert(f(1, 1, 10, 8, 10) == 5);
	assert(f(8, 2, 15, 7, 63) == 2);
	assert(f(21948, 12412, 42124, 85217, 92412) == 38508);
	assert(f(102492, 128282, 87421, 242122, 341247) == 61572);
	assert(f(42424, 76767, 97487, 3784274, 10421244) == 35377);
	assert(f(50127, 31229, 99887, 9784274, 17421244) == 56002);
	assert(f(11127, 93229, 94823, 20084263, 20421244) == 93278);

	return 0;
}
