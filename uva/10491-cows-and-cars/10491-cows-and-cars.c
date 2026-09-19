#include <stdio.h>

double
solve(int cows, int cars, int show)
{
	double total;
	double carfirst;
	double cowfirst;

	total = cars + cows;
	carfirst = (cars / total) * ((cars - 1) / (total - show - 1));
	cowfirst = (cows / total) * (cars / (total - show - 1));
	return carfirst + cowfirst;
}

int
main()
{
	printf("%.5f\n", solve(2, 1, 1));
	printf("%.5f\n", solve(5, 3, 2));
	printf("%.5f\n", solve(2000, 2700, 900));

	return 0;
}
