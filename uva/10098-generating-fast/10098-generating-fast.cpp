#include <print>
#include <string>

using namespace std;

void generate(string input)
{
	sort(input.begin(), input.end());
	do
	{
		println("{}", input);
	} while (next_permutation(input.begin(), input.end()));
	println();
}

int main()
{
	generate("ab");
	generate("abc");
	generate("bca");

	return 0;
}
