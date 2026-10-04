/*

Task
Given Two integers a , b , find The sum of them , BUT You are not allowed to use the operators + and -

Notes
The numbers (a,b) may be positive , negative values or zeros .

Returning value will be an integer .

Javascript: the Array reduce methods are disabled, along with eval, require, and module .
Input >> Output Examples
1- Add (5,19) ==> return (24) 

2- Add (-27,18) ==> return (-9)

3- Add (-14,-16) ==> return (-30)

*/

using System;

class Program
{
	static void Main(string[] Args)
	{
		var N = 10;
		for (var x = -N; x <= N; x++)
		{
			for (var y = -N; y <= N; y++)
			{
				if (x + y != Add(x, y))
					Console.WriteLine("MISMATCH: {0} + {1} = {2} | {3}", x, y, x + y, Add(x, y));
			}
		}
	}

	static int Add(int x, int y)
	{
		if (y == 0)
			return x;
		return Add(x ^ y, (x & y) << 1);
	}
}
