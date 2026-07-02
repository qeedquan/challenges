/*

An employee at a renowned bank unexpectedly discovered a flaw in some of the bank's operational software:
the subtraction of one number from another occasionally yields incorrect results, which, of course, poses a potential security threat to the bank.
For instance, a client reported that after withdrawing 125 from an account balance of 296,
the account was inexplicably empty, although it should have had 171 remaining.

You must urgently develop a straightforward yet crucial program that correctly performs the subtraction of
one number from another before electronic thieves can exploit this vulnerability in the security system.

Input
The input file contains two integers, each in the range from -2^63 to 2^63 - 1.

Output
Output the result of subtracting the second number from the first.

Examples

Input #1
296 125

Answer #1
171

*/

using System;
using System.Numerics;

class Program
{
    static void Main()
    {
        var result = solve("296", "125");
        Console.WriteLine($"{result}");
    }

    static BigInteger solve(String number1, String number2)
    {
        return BigInteger.Parse(number1) - BigInteger.Parse(number2);
    }
}
