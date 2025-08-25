/*

There exists a preloaded abstract class named Operation:

public abstract class Operation
{
  public double Result;
  public abstract void Execute(double variable1, double variable2);
}
Your job is to create 4 new classes which inherit the 'Operation' class. Within the class, create the proper execute method and save the mathematical operation to the proper result variable. The class names must be as follows:

Add
Subtract
Multiply
Divide

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Operation Operation;

struct Operation {
	double result;
	void (*execute)(Operation *, double, double);
};

void
addition(Operation *operation, double variable1, double variable2)
{
	operation->result = variable1 + variable2;
}

void
subtraction(Operation *operation, double variable1, double variable2)
{
	operation->result = variable1 - variable2;
}

void
multiplication(Operation *operation, double variable1, double variable2)
{

	operation->result = variable1 * variable2;
}

void
division(Operation *operation, double variable1, double variable2)
{
	operation->result = variable1 / variable2;
}

int
main()
{
	Operation operations[] = {
		{ .execute = addition },
		{ .execute = subtraction },
		{ .execute = multiplication },
		{ .execute = division },
	};
	const char symbol[] = "+-*/";

	Operation *operation;
	double variable1, variable2;
	size_t index;

	srand(time(NULL));
	for (index = 0; index < nelem(operations); index++) {
		operation = operations + index;
		variable1 = rand();
		variable2 = rand();
		operation->execute(operation, variable1, variable2);
		printf("%f %c %f = %f\n", variable1, symbol[index], variable2, operation->result);
	}

	return 0;
}
