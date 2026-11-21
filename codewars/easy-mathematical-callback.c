/*

Task
Write the processArray function, which takes an array and a callback function as parameters. The callback function can be, for example, a mathematical function that will be applied on each element of this array. Optionally, also write tests similar to the examples below.

Examples
Array [4, 8, 2, 7, 5] after processing with function

var myArray = [4, 8, 2, 7, 5];
myArray = processArray(myArray,function (a) {
  return a * 2;
});

will be [ 8, 16, 4, 14, 10 ].

Array [7, 8, 9, 1, 2] after processing with function

var myArray = [7, 8, 9, 1, 2];
myArray = processArray(myArray, function (a) {
  return a + 5;
});

will be [ 12, 13, 14, 6, 7 ].

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef int (*mapfn)(int);

int
twice(int number)
{
	return number * 2;
}

int
add5(int number)
{
	return number + 5;
}

void
process(int *numbers, size_t length, mapfn map)
{
	size_t index;

	for (index = 0; index < length; index++)
		numbers[index] = map(numbers[index]);
}

int
main()
{
	int numbers_1[] = {4, 8, 2, 7, 5};
	int numbers_2[] = {7, 8, 9, 1, 2};

	process(numbers_1, nelem(numbers_1), twice);
	process(numbers_2, nelem(numbers_2), add5);

	return 0;
}
