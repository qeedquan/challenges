/*

You know how in Mathematics, you can write something like 1 < 2 < 3 and it would be completely fine? Let's re-create that functionality!

You need to create a class called "Relational", which takes a single argument for its initial value. Then, by calling various methods, such as .equals(value) or .lessThan(value), we can build a similar expression you could do in Mathematics. Albeit with a load more characters.

You need to implement the following methods:

.equals(value), .notEquals(value)
.lessThan(value), .lessThanOrEqualTo(value)
.greaterThan(value), .greaterThanOrEqualTo(value)
.passed() should also return the evaluated expression as a true or false value.
And each much be able to compound with the previous statement.

For example: new Relational(1).lessThan(2).lessThan(3).passed() should be equivalent to the Mathematical 1 < 2 < 3, or the code (1 < 2) && (2 < 3).

You could, of course have longer expressions like 1 < 2 < 3 < 4 < 5, or even crazy, kinda useless stuff like 1 < 3 > 2 != 4.

*/

#include <cassert>

struct Relational
{
	int expression;
	bool result;
	bool unary;

	Relational(int value)
	{
		expression = value;
		result = value != 0;
		unary = true;
	}

	bool passed()
	{
		return result;
	}

	Relational &equals(int value)
	{
		return evaluate(expression == value, value);
	}

	Relational &notEquals(int value)
	{
		return evaluate(expression != value, value);
	}

	Relational &lessThan(int value)
	{
		return evaluate(expression < value, value);
	}

	Relational &lessThanOrEqualTo(int value)
	{
		return evaluate(expression <= value, value);
	}

	Relational &greaterThan(int value)
	{
		return evaluate(expression > value, value);
	}

	Relational &greaterThanOrEqualTo(int value)
	{
		return evaluate(expression >= value, value);
	}

private:
	Relational &evaluate(bool logical, int value)
	{
		if (unary)
		{
			unary = false;
			result = true;
		}
		result = result && logical;
		expression = value;
		return *this;
	}
};

int main()
{
	assert(Relational(1).lessThan(2).lessThan(3).passed() == true);
	assert(Relational(1).lessThan(2).lessThan(3).lessThan(4).lessThan(5).passed() == true);
	assert(Relational(1).lessThan(2).lessThan(3).lessThan(4).greaterThan(100).passed() == false);
	assert(Relational(1).lessThan(3).greaterThan(2).notEquals(4).passed() == true);
	assert(Relational(0).passed() == false);
	assert(Relational(1).lessThan(-2).notEquals(-2).passed() == false);
	return 0;
}
