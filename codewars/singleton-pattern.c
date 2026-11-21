/*

In software engineering, the singleton pattern is a design pattern that restricts the instantiation of a class to one object. This is useful when exactly one object is needed to coordinate actions across the system.

Create an Singleton pattern, so there is one object in system.

Example:

var obj1 = new Singleton();
var obj2 = new Singleton();
obj1 === obj2; // => true
obj1.test = 1;
obj2.test; // => 1

*/

#include <assert.h>
#include <stdio.h>

typedef struct {
	int test;
} Singleton;

Singleton *
newsingleton()
{
	static Singleton singleton = {1};

	return &singleton;
}

int
main()
{
	Singleton *obj1, *obj2;

	obj1 = newsingleton();
	obj2 = newsingleton();
	assert(obj1 == obj2);
	assert(obj1->test == 1);
	assert(obj2->test == 1);
	return 0;
}
