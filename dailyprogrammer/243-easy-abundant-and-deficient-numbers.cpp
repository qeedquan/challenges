/*

Description
In number theory, a deficient or deficient number is a number n for which the sum of divisors sigma(n)<2n, or, equivalently, the sum of proper divisors (or aliquot sum) s(n)<n. The value 2n - sigma(n) (or n - s(n)) is called the number's deficiency. In contrast, an abundant number or excessive number is a number for which the sum of its proper divisors is greater than the number itself

As an example, consider the number 21. Its divisors are 1, 3, 7 and 21, and their sum is 32. Because 32 is less than 2 x 21, the number 21 is deficient. Its deficiency is 2 x 21 - 32 = 10.

The integer 12 is the first abundant number. Its divisors are 1, 2, 3, 4, 6, and 12, and their sum is 28. Because 28 is greater than 2 x 12, the number 12 is abundant. It's abundant by is 28 - 24 = 4. (Thanks u/Rev0lt_ for the correction.)

Input Description
You'll be given an integer, one per line. Example:

18
21
9
Output Description
Your program should emit if the number if deficient, abundant (and its abundance), or neither. Example:

18 abundant by 3
21 deficient
9 ~~neither~~ deficient
Challenge Input
111  
112 
220 
69 
134 
85 
Challenge Output
111 ~~neither~~ deficient 
112 abundant by 24
220 abundant by 64
69 deficient
134 deficient
85 deficient

OOPS
I had fouled up my implementation, 9 and 111 are deficient, not perfect. See http://sites.my.xs.edu.ph/connor-teh-14/aste/mathematics-asteroids/perfect-abundant-and-deficient-numbers-1-100.

*/

#include <cassert>
#include <iostream>
#include <format>
#include <string>

using namespace std;

string classify(int number)
{
	if (number < 0)
		return format("{} neither", number);

	auto sum = 0;
	for (auto i = 1; i < number; i++)
	{
		if (!(number % i))
			sum += i;
	}
	if (sum < number)
		return format("{} deficient", number);
	if (sum > number)
		return format("{} abundant by {}", number, sum - number);
	return format("{} neither", number);
}

int main()
{
	assert(classify(18) == "18 abundant by 3");
	assert(classify(21) == "21 deficient");
	assert(classify(9) == "9 deficient");
	assert(classify(111) == "111 deficient");
	assert(classify(112) == "112 abundant by 24");
	assert(classify(220) == "220 abundant by 64");
	assert(classify(69) == "69 deficient");
	assert(classify(134) == "134 deficient");
	assert(classify(85) == "85 deficient");

	return 0;
}
