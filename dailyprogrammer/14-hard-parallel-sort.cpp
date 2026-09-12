/*

Write a program that will generate a random array/collection of 1 million integers, then sort them using a multi-threaded algorithm.

Your program should take the number of threads through standard input.

Bonus points if you can find the most efficient number of threads for your program.

*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <execution>
#include <algorithm>

using namespace std;

// https://stackoverflow.com/questions/28520720/c-parallel-sort
int main()
{
	srand(time(NULL));

	vector<int> input;
	for (auto i = 0; i < 1'000'000; i++)
		input.push_back(rand());
	
	sort(execution::par_unseq, input.begin(), input.end());
	
	for (auto value : input)
		printf("%d\n", value);

	return 0;
}
