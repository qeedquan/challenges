/*

Print all numbers up to 3rd parameter which are multiple of both 1st and 2nd parameter.

Python, Javascript, Java, Ruby versions: return results in a list/array

NOTICE:

Do NOT worry about checking zeros or negative values.
To find out if 3rd parameter (the upper limit) is inclusive or not, check the tests, it differs in each translation

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> multiples(int multiple0, int multiple1, int limit)
{
	vector<int> result;
	for (auto number = multiple0; number <= limit; number += multiple0)
	{
		if (!(number % multiple1))
			result.push_back(number);
	}
	return result;
}

void test(int multiple0, int multiple1, int limit)
{
	auto values = multiples(multiple0, multiple1, limit);
	for (auto value : values)
		cout << value << " ";
	cout << endl;
}

int main()
{
	test(3, 4, 120);
	test(2, 7, 85);
	test(14, 15, 185);
	test(14, 17, 480);
	test(2, 5, 90);
	test(4, 7, 97);

	return 0;
}
