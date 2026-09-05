/*

You are given a main function which reads the enumeration values for two different types as input, then prints out the corresponding enumeration names.
Write a class template that can provide the names of the enumeration values for both types. If the enumeration value is not valid, then print unknown.

Input Format

The first line contains t, the number of test cases.
Each of the t subsequent lines contains two space-separated integers. The first integer is a color value, c, and the second integer is a fruit value, f.

Constraints

1 <= t <= 100
-2*10^9 <= c <= 2*10^9
-2*10^9 <= f <= 2*10^9

Output Format

The locked stub code in your editor prints t lines containing the color name and the fruit name corresponding to the input enumeration index.

Sample Input
2
1 0
3 3

Sample Output
green apple

unknown unknown
Explanation

Since t=2, there are two lines of output.

The two input index values, 1 and 0, correspond to green in the color enumeration and apple in the fruit enumeration. Thus, we print green apple.
The two input values, 3 and 3, are outside of the range of our enums. Thus, we print unknown unknown.


*/

#include <iostream>

using namespace std;

enum class Fruit
{
	apple,
	orange,
	pear
};

enum class Color
{
	red,
	green,
	orange
};

template <typename T>
struct Traits;

template <>
struct Traits<Color>
{
	static string name(int index)
	{
		switch (static_cast<Color>(index))
		{
		case Color::red:
			return "red";
		case Color::green:
			return "green";
		case Color::orange:
			return "orange";
		default:
			return "unknown";
		}
	}
};

template <>
struct Traits<Fruit>
{
	static string name(int index)
	{
		switch (static_cast<Fruit>(index))
		{
		case Fruit::apple:
			return "apple";
		case Fruit::orange:
			return "orange";
		case Fruit::pear:
			return "pear";
		default:
			return "unknown";
		}
	}
};

int main()
{
	for (auto index = 0; index <= 3; index++)
	{
		cout << Traits<Color>::name(index) << " ";
		cout << Traits<Fruit>::name(index) << "\n";
	}
	return 0;
}
