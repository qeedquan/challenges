/*

Create a function called _if which takes 3 arguments: a value bool and 2 functions (which do not take any parameters): func1 and func2

When bool is truthy, func1 should be called, otherwise call the func2.

Example:
def truthy():
  print("True")

def falsey():
  print("False")

_if(True, truthy, falsey)
# prints 'True' to the console

*/

#include <stdio.h>

void
f1()
{
	printf("%s:%d\n", __func__, __LINE__);
}

void
f2()
{
	printf("%s:%d\n", __func__, __LINE__);
}

void
_if(bool b, void (*f)(), void (*g)())
{
	(b) ? f() : g();
}

int
main()
{
	_if(true, f1, f2);
	_if(false, f1, f2);
	return 0;
}
