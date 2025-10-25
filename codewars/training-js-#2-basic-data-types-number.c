/*

In javascript, Number is one of basic data types. It can be positive: 1,2,3, negative:-1,-100 , integer:123,456, decimal:3.1415926,-8.88 etc..

Numbers can use operators such as + - * / %

Task
I've written five function equal1,equal2,equal3,equal4,equal5, defines six global variables v1 v2 v3 v4 v5 v6, every function has two local variables a,b, please set the appropriate value for the two variables(select from v1--v6), making these function return value equal to 100. the function equal1 is completed, please refer to this example to complete the following functions.

When you have finished the work, click "Run Tests" to see if your code is working properly.

In the end, click "Submit" to submit your code pass this kata.

*/

#include <assert.h>

int v1 = 50;
int v2 = 100;
int v3 = 150;
int v4 = 200;
int v5 = 2;
int v6 = 250;

int
equal1()
{
	return v1 + v1;
}

int
equal2()
{
	return v3 - v1;
}

int
equal3()
{
	return v5 * v1;
}

int
equal4()
{
	return v4 / v5;
}

int
equal5()
{
	return v2 % v4;
}

int
main()
{
	assert(equal1() == 100);
	assert(equal2() == 100);
	assert(equal3() == 100);
	assert(equal4() == 100);
	assert(equal5() == 100);

	return 0;
}
