/*

Your task is to write function factorial.

https://en.wikipedia.org/wiki/Factorial

*/

using System;

class Program
{
	static void Main(string[] args)
	{
		for (var Term = 0; Term <= 10; Term++)
			Console.WriteLine(Factorial(Term));
	}

	static int Factorial(int Term)
	{
		if (Term < 0)
			return 0;

		var Result = 1;
		for (var Index = 2; Index <= Term; Index++)
			Result *= Index;
		return Result;
	}
}
