/*

The Fizz Buzz problem is a very basic problem to solve that is used by some to weed out interviewees that don't know how to program. The problem is:

Set N = [0,100]
Set F = x in N where x % 3 == 0
Set B = x in N where x % 5 == 0
Set FB = F intersect B

For all N:
  if x in F: print fizz
  if x in B: print buzz
  if x in FB: print fizzbuzz
  if x not in F|B|FB print x
The object of this modification of the Fizz Buzz problem is to perform the above algorithm using C++ templates such that as few runtime operations are necessary as can be done.

You can reduce N to a smaller range if you need to in order to fit within TMP objects where necessary.

This isn't expected to be a "golf".

*/

#include <iostream>

using namespace std;

template <int N, int m3 = N % 3, int m5 = N % 5>
struct fizzbuzz_print
{
	static void print()
	{
		cout << N << endl;
	}
};

template <int N, int m5>
struct fizzbuzz_print<N, 0, m5>
{
	static void print()
	{
		cout << "fizz" << endl;
	}
};

template <int N, int m3>
struct fizzbuzz_print<N, m3, 0>
{
	static void print()
	{
		cout << "buzz" << endl;
	}
};

template <int N>
struct fizzbuzz_print<N, 0, 0>
{
	static void print()
	{
		cout << "fizzbuzz" << endl;
	}
};

template <int N>
struct fizzbuzz : public fizzbuzz<N - 1>
{
	fizzbuzz()
	{
		fizzbuzz_print<N>::print();
	}
};

template <>
struct fizzbuzz<1>
{
	fizzbuzz()
	{
		fizzbuzz_print<1>::print();
	}
};

int main()
{
	fizzbuzz<100>();
	return 0;
}
