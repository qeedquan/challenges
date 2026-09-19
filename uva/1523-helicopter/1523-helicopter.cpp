#include <cstdio>
#include <cfloat>
#include <vector>
#include <algorithm>

using namespace std;

double solve(vector<int> &&A)
{
	sort(A.begin(), A.end());

	double r = DBL_MAX;
	do
	{
		double v = A[0] + A[1] + A[2] - A[5] - A[6] - A[7];
		double h = A[0] + A[3] + A[5] - A[2] - A[4] - A[7];
		r = min(r, v * v + h * h);
	} while (next_permutation(A.begin(), A.end()));

	return r;
}

int main()
{
	printf("%.3f\n", solve({ 1, 2, 3, 4, 5, 6, 7, 8 }));

	return 0;
}
