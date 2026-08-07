/*

The sequence of segmented numbers or prime numbers of measurement (OEIS A002048) is the sequence of numbers such that each member is the smallest positive (greater than zero) number that can't be made of a sum of earlier consecutive numbers, with a(0) = 1.

Example
To calculate a(7) we first calculate a(0->6) = [1, 2, 4, 5, 8, 10, 14]. we then start from zero and go through numbers until we find one that is not the sum of one or more consecutive numbers in the sequence.

1  = 1
2  = 2
3  = 1 + 2
4  = 4
5  = 5
6  = 2 + 4
7  = 1 + 2 + 4
8  = 8
9  = 4 + 5
10 = 10
11 = 2 + 4 + 5
12 = 1 + 2 + 4 + 5
13 = 5 + 8
14 = 14
15 = ????
Since fifteen cannot be made by summing any consecutive subsequence and every number smaller can be fifteen is the next number in the sequence. a(7) = 15

Task
Your task is to take a number (via standard methods) and output the nth term in this sequence (via standard output methods). This is code-golf and you will be scored as such.

Test Cases
0 -> 1
1 -> 2
2 -> 4
3 -> 5
4 -> 8
5 -> 10
6 -> 14
7 -> 15
8 -> 16
9 -> 21

*/

#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

// https://oeis.org/A002048
vector<unsigned> gen(unsigned n)
{
	auto nmax = n * 4;

	vector<unsigned> nums;
	for (unsigned i = 0; i < nmax; i++)
		nums.push_back(i + 1);

	for (unsigned p = 2; p < nums.size(); p++)
	{
		for (unsigned i = 0; i < p - 1 && i < nums.size() - 1; i++)
		{
			auto val = nums[i] + nums[i + 1];
			remove(nums.begin(), nums.end(), val);
			for (unsigned j = i + 2; j < p && j < nums.size(); j++)
			{
				val += nums[j];
				remove(nums.begin(), nums.end(), val);
				if (val > nmax)
					break;
			}
		}
	}

	nums.resize(n);
	return nums;
}

int main()
{
	const vector<unsigned> tab = { 1, 2, 4, 5, 8, 10, 14, 15, 16, 21, 22, 25, 26, 28, 33, 34, 35, 36, 38, 40, 42, 46, 48, 49, 50, 53, 57, 60, 62, 64, 65, 70, 77, 80, 81, 83, 85, 86, 90, 91, 92, 100, 104, 107, 108, 116, 119, 124, 127, 132, 133, 137, 141, 144, 145, 148, 150, 151, 154, 158, 159, 163, 165 };

	auto nums = gen(tab.size());
	for (size_t i = 0; i < tab.size(); i++)
	{
		printf("%u %u\n", nums[i], tab[i]);
		assert(nums[i] == tab[i]);
	}

	return 0;
}
