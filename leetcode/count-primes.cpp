/*

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 
Constraints:

0 <= n <= 5 * 10^6

*/

#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

int eratosthenes(int n, vector<int> &primes)
{
	auto limit = sqrt(n);
	auto crossed = vector<int>(n);
	for (auto i = 2; i <= limit; i++)
	{
		for (auto j = i + i; j < n; j += i)
			crossed[j] = true;
	}

	primes.clear();
	for (auto i = 2; i < n; i++)
	{
		if (!crossed[i])
			primes.push_back(i);
	}
	return primes.size();
}

int countprimes(int n)
{
	vector<int> primes;
	return eratosthenes(n, primes);
}

int main()
{
	assert(countprimes(10) == 4);
	assert(countprimes(0) == 0);
	assert(countprimes(1) == 0);
	assert(countprimes(3) == 1);
	assert(countprimes(2) == 0);
	assert(countprimes(100) == 25);
	assert(countprimes(1000000) == 78498);

	return 0;
}
