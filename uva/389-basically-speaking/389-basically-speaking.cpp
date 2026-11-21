#include <cstdlib>
#include <string>
#include <format>
#include <print>
#include <utility>

using namespace std;

string solve(const string &number, int frombase, int tobase)
{
	char buffer[7];
	auto value = stoi(number, 0, frombase);
	auto result = to_chars(buffer, buffer + sizeof(buffer), value, tobase);
	if (result.ec != errc{})
		return format("ERROR");

	auto output = format("{}", buffer);
	transform(output.begin(), output.end(), output.begin(), [](unsigned char c) { return toupper(c); });

	return output;
}

int main()
{
	println("{}", solve("1111000", 2, 10));
	println("{}", solve("1111000", 2, 16));
	println("{}", solve("2102101", 3, 10));
	println("{}", solve("2102101", 3, 15));
	println("{}", solve("12312", 4, 2));
	println("{}", solve("1A", 15, 2));
	println("{}", solve("ABCD", 16, 15));
	println("{}", solve("03", 13, 10));

	return 0;
}
