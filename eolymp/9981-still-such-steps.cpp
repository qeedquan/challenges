/*

https://static.eolymp.com/content/av/avaeskpjr140j2tj2rrcvs9dho.jpg

The program takes an integer n as input, representing the number of steps. Your task is to print the steps using spaces and hash symbols #, as illustrated in the example image.

Input
A natural number n, where 1≤n≤100.

Output
Print the steps in the format shown in the image.

Examples
Input #1
5
Answer #1
#####
 ####
  ###
   ##
    #

*/

#include <print>

using namespace std;

void solve(int n)
{
	for (auto i = n; i > 0; i--)
	{
		for (auto j = 0; j < n - i; j++)
			print(" ");
		for (auto j = 0; j < i; j++)
			print("#");
		println();
	}
}

int main()
{
	solve(5);
	return 0;
}
