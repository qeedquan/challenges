/*

Two friends spent eighteen consecutive hours drinking cold milkshakes and eating ice cream.
As a result, one of them caught a terrible chill, and the other decided to install central heating in his friend's lodge.
The number of radiators must be calculated strictly according to Standard 800333-90-06. To keep things simple, he will buy only standard radiators.

According to Table 14.1.3 of this Standard, each radiator can heat exactly k cubic meters of air. The room that needs to be heated has the following dimensions:

height h;

width w;

length l.

Find the minimum number of radiators needed to ensure the lodge remains at or above the Standard's temperature requirement.
If the temperature falls below the Standard, the sick friend will never recover.

Input
Four integers: h, w, l, k (1≤h,w,l≤10^5, 1≤k≤2⋅10^9).

Output
Print the minimum number of radiators needed.

Examples

Input #1
2 3 4 1

Answer #1
24

Input #2
2 3 4 5

Answer #2
5

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong h, vlong w, vlong l, vlong k)
{
	vlong d, r;

	if (k == 0)
		return 0;

	d = h * w * l;
	r = d / k;
	if (!(d % k))
		return r;
	return r + 1;
}

int
main()
{
	assert(solve(2, 3, 4, 1) == 24);
	assert(solve(2, 3, 4, 5) == 5);

	return 0;
}
