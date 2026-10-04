/*

Given the truth table of a non-trivial symmetric 2-input logic gate, output its name. The 6 possible input/output pairs are:

0001 -> AND
1110 -> NAND
0111 -> OR
1000 -> NOR
0110 -> XOR
1001 -> XNOR
(where the 4 symbols represent the outputs of the gate for inputs 00,01,10,11 respectively).

Input
You can take the input format to be a single sequence "0001" or [0,0,0,1], or a 2-dimensional array [[0,0],[0,1]] or a function g with g(0,1)=0 etc. You do not need to handle input other than the 6 cases above. You can accept False/True (or their equivalent in your language) instead of 0/1 respectively, as long as it is done consistently. But reversing the values or requiring arbitrary values is not allowed.

Output
The exact string "AND", etc. You can alternatively use all lower case but it must be done consistently. If printing, trailing whitespace is allowed.

And no, you can't use NXOR!

This is code-golf, so shortest solution in each language wins.

*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

string logic(int x)
{
	map<int, string> lut = {
		{ 0b0001, "AND" },
		{ 0b1110, "NAND" },
		{ 0b0111, "OR" },
		{ 0b1000, "NOR" },
		{ 0b0110, "XOR" },
		{ 0b1001, "XNOR" },
	};
	return lut[x];
}

int main()
{
	for (auto i = 0; i <= 0xF; i++)
		cout << i << ": " << logic(i) << endl;
	return 0;
}
