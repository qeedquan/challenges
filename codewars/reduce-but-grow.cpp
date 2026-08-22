/*

Given a non-empty array of integers, return the result of multiplying the values together in order. Example:

[1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24

*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

template <typename T>
T multiply(vector<T> &&numbers)
{
	return accumulate(numbers.begin(), numbers.end(), 1, multiplies<T>());
}

int main()
{
	cout << multiply<int>({1, 2, 3, 4}) << endl;
	return 0;
}
