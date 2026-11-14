/*

Let's take a look on a typical loop, which usually performs 8 iterations:

for (int x=0; x<8; ++x);
You have to make it infinite!

It's a popularity-contest for all languages that support such form of for loop. So solution with highest score (upvotes minus downvotes) wins.

If your language has the other form of for loop, but you are sure, you can make something cool with it, feel free to post the answer and mark it as noncompeting. I reserve the right to enlarge scope of available constructions and languages, but it will never be shrinked, so don't be afraid of dropping previously correct solutions.

What is solution?
Solution consists of two programs.

The first program is a clean program. It's the typical program in your language with the for loop making 8 iterations. It should be the normal program, any developer could write. No any special hacks for preparation purposes. For example:

int main() 
{
  for (int x=0; x<8; ++x);
  return 0;
}
The second program is augmented. This program should contain all the code from clean program and some additional code. There are limited number of extension points, see complete rules section for details. An augmented program for the clean one above can be

inline bool operator < (const int &a, const int &b)
{
  return true;
}

int main() 
{
  for (int x=0; x<8; ++x);
  return 0;
}
That's just an example (noncompilable in C++) to show an idea. The real correct augmented program have to be compilable, working and having infinite loop.

Complete rules
Both programs:
Any language with support of such for loops is ok.
The loop body has to be empty. More precisely, you can place some output or other code into the loop, but loop behavior should be the same in case of empty loop.
Clean program:
Loop uses integer or numeric counter and performs 8 iterations:

for (int          x=0; x<8; ++x);   // C, C++, C#
for (var          x=0; x<8; ++x);   // C#, Javascript
for (auto         x=0; x<8; ++x);   // C, C++
for (auto signed  x=0; x<8; ++x);   // C, C++
for (register int x=0; x<8; ++x);   // C, C++
User-defined types are disallowed.

Using of property (except of global variable) instead of loop variable is disallowed.
Declaration of variable can be inside or outside of the loop. Following code is ok:

int x;
for(x=0; x<8; ++x);
Either prefix or postfix increment can be used.

Loop limit 8 should be written as a constant literal without saving to named constant or variable. It's made to prevent solutions based on declaring variable or constant equal to 8, and then reassigning, overriding or shadowing it by the other value:

const double n = 8;

int main()
{
  const double n = 9007199254740992;
  for (double x=0; x<n; ++x);
  return 0;
}
Augmented program:
Must contain all the code from the clean one.
Should extend clean program in limited number of extension points.
Must execute same for loop as an infinite loop itself.
Placing of the loop into another infinite construction is not ok.
Runtime or compile-time patching of the code is allowed as long as textual representation of it is unchanged.
Placing the construction into a string and passing to eval is disallowed.
Extension points:
Anywhere outside of the fragment with clean code, including other files or other assemblies.
for statement (as single piece - for construction and its body) must be kept unchanged.
Variable declaration must be kept the same.
Any place between simple statements can be used as extension point.
If and only if variable was declared outside of the loop and without immediate assignment of the value, such assignment can be added.
// extension point here
int main()
// extension point here
{
  // extension point here
  int x // extension point for assignment here
  // extension point here
  for (x=0; x<8; ++x);
  // extension point here
  return 0;
  // extension point here
}
// extension point here
int main() 
{
  // BEGIN: No changes allowed
  int x = 0;
  // END
  // extension point here
  // BEGIN: No changes allowed
  // for (x=0; x<8; ++x);
  // END
  return 0;
}
PS: If possible, please provide a link to online IDE.

*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Int
{
	Int(int)
	{
	}

	bool operator<(int)
	{
		return true;
	}

	Int operator++()
	{
		return Int(0);
	}
};

std::ostream &operator<<(std::ostream &os, Int const&)
{
	return os << rand();
}

int main()
{
	for (Int x = 0; x < 8; ++x)
		cout << x << endl;

	return 0;
}
