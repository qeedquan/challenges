/*

Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.

*/

#include <cassert>
#include <algorithm>
#include <vector>

typedef unsigned long long uvlong;

using namespace std;

uvlong sum_two_smallest_numbers(vector<uvlong> &&numbers)
{
	if (numbers.size() < 2)
		return 0;

	sort(numbers.begin(), numbers.end());
	return numbers[0] + numbers[1];
}

int main()
{
	assert(sum_two_smallest_numbers({19, 5, 42, 2, 77}) == 7);
	assert(sum_two_smallest_numbers({10, 343445353, 3453445, 3453545353453}) == 3453455);
	return 0;
}
