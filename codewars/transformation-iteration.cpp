/*

Write

function transform(source, target){}

that takes in 2 strings and transforms source into the target string.

For example

transform('car','see') === ["car", "sar", "ser", "see"]
transform('floor','brake') === ["floor", "bloor", "broor", "braor", "brakr", "brake"]
transform('kata','math') === ["kata", "mata", "math"]

source and target will always be of the same length

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> transform(const string &source, const string &target)
{
	vector<string> result;

	auto size = source.size();
	if (size == 0 || size != target.size())
		return result;

	string morph = source;
	result.push_back(morph);
	for (size_t index = 0; index < size && morph != target; index++)
	{
		if (morph[index] != target[index])
		{
			morph[index] = target[index];
			result.push_back(morph);
		}
	}

	return result;
}

void test(const string &source, const string &target)
{
	auto result = transform(source, target);
	for (auto str : result)
		cout << str << " ";
	cout << endl;
}

int main()
{
	test("car", "see");
	test("floor", "brake");
	test("kata", "math");

	return 0;
}
