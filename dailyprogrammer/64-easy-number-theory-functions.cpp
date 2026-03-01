/*

The divisors of a number are those numbers that divide it evenly; for example, the divisors of 60 are 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, and 60.
The sum of the divisors of 60 is 168, and the number of divisors of 60 is 12.

The totatives of a number are those numbers less than the given number and coprime to it; two numbers are coprime if they have no common factors other than 1.
The number of totatives of a given number is called its totient.
For example, the totatives of 30 are 1, 7, 11, 13, 17, 19, 23, and 29, and the totient of 30 is 8.

Your task is to write a small library of five functions that compute the divisors of a number,
the sum and number of its divisors, the totatives of a number, and its totient.

taken from programmingpraxis.com

It seems the number of users giving challenges have been reduced.
Since my final exams are going on and its kinda difficult to think of all the challenges,
I kindly request you all to suggest us interesting challenges at r/dailyprogrammer_ideas .. Thank you!

*/

#include <cassert>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		auto t = b;
		b = a % b;
		a = t;
	}
	return a;
}

vector<int> get_divisors(int n)
{
	vector<int> d;
	int l = sqrt(n);
	for (int i = 1; i <= l; i++)
	{
		if (!(n % i))
		{
			d.push_back(i);
			d.push_back(n / i);
		}
	}
	sort(d.begin(), d.end());
	return d;
}

size_t number_of_divisors(int n)
{
	auto d = get_divisors(n);
	return d.size();
}

int sum_of_divisors(int n)
{
	auto d = get_divisors(n);
	return accumulate(d.begin(), d.end(), 0);
}

vector<int> get_totatives(int n)
{
	vector<int> t;
	for (int i = 1; i < n; i++)
	{
		if (gcd(n, i) == 1)
			t.push_back(i);
	}
	return t;
}

size_t get_totient(int n)
{
	auto t = get_totatives(n);
	return t.size();
}

int main()
{
	vector<int> r1 = { 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60 };
	vector<int> r2 = { 1, 7, 11, 13, 17, 19, 23, 29 };
	assert(get_divisors(60) == r1);
	assert(sum_of_divisors(60) == 168);
	assert(number_of_divisors(60) == 12);
	assert(get_totatives(30) == r2);
	assert(get_totient(30) == 8);

	return 0;
}
