/*

Based off a Scratch project

The pen extension in Scratch has a set pen color to () block. The () is normally a color dropdown, but you can also use the join()() block. In the join()() block, normally a hex value is in the first input, but the second is just an empty string.

However, many new Scratchers that want to take advantage of this find it hard (after all we count in decimal). Your task today, is: given three positive integers r,g,b, calculate the hex value and return it as #rrggbb.

Input:
r, g, b.

0≤r≤255
 
0≤g≤255
 
0≤b≤255
 
Input will always follow these rules
Input won't have leading zeros except for 0 itself
Output
A string in the format #rrggbb. Hexadecimal letters can be all uppercase or all lowercase.

Method
Convert r,g,b to hexadecimal
Concatenate r,g,b
Prepend a #
Return it
Testcases:
r, g, b     -> Output

0, 127, 255   -> #007fff
1, 1, 1       -> #010101
245, 43, 2    -> #f52b02
72, 1, 134    -> #480186
0, 0, 0       -> #000000
255, 255, 255 -> #ffffff
This is code-golf, so shortest answer wins!

NOTE: There's an earlier question that qualifies this as a duplicate, but it's closed (because the scoring criterion was ambiguous)

*/

#include <cassert>
#include <print>
#include <format>

using namespace std;

string solve(int r, int g, int b)
{
	return format("#{:02x}{:02x}{:02x}", r, g, b);
}

int main()
{
	assert(solve(0, 127, 255) == "#007fff");
	assert(solve(1, 1, 1) == "#010101");
	assert(solve(245, 43, 2) == "#f52b02");
	assert(solve(72, 1, 134) == "#480186");
	assert(solve(0, 0, 0) == "#000000");
	assert(solve(255, 255, 255) == "#ffffff");

	return 0;
}
