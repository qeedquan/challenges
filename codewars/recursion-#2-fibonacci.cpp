/*

 Do you know recursion?
This is a kata series that you can only solve using recursion.
##2 - Fibonacci number

In mathematical terms, the sequence f(n) of fibonacci numbers is defined by the recurrence relation

f(n) = f(n-1) + f(n-2)

with seed values

f(1) = 1 and f(2) = 1

#Your task

You have to create the function fibonacci that receives n and returns f(n). You have to use recursion.

*/

#include <iostream>

using namespace std;

int fib(int n, int a = 1, int b = 1)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return a;
	if (n == 2)
		return b;
	return fib(n - 1, b, a + b);
}

int main()
{
	for (auto i = 1; i <= 10; i++)
		cout << fib(i) << endl;

	return 0;
}
