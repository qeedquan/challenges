/*

Challenge: implement calculation of a Delacorte Number in any language. Shortest code wins.
For a given square matrix of distinct integers 1..n² (possible side length n at least between 3 and 27), its Delacorte Number is the sum of the products gcd(a, b) × distance²(a, b) for each distinct pair of integers {a, b}.

The following example shows a 3×3 square with a Delacorte Number of 160.

3 2 9
4 1 8
5 6 7
In this square we have 36 distinct pairs to calculate, for example the pair 4 and 6: gcd(4, 6) × distance²(4, 6) = 4

Another example square for testing - this has a Delacorte Number of 5957:

10  8 11 14 12
21  4 19  7  9
 5 13 23  1 16
18  3 17  2 15
24 22 25  6 20
Delacorte Numbers are taken from this programming contest - see there for further details... The contest ended in January 2015. It was great fun!

Rules:
Necessary line breaks count as 1 char. You may post your golfed solution with line breaks, but they are only counted if necessary in that language.

You can choose how to handle input and output and you don't have to count the necessary framework of your language, like standard-includes or main function headers. Only the actual code counts (including shortcut/alias definitions), like in this C# example:

namespace System
{
    using Collections.Generic;
    using I=Int32; //this complete line counts
    class Delacorte
    {
        static I l(I[]a){return a.Length;} //of course this complete line counts

        static void CalculateSquare(int[] a, out int r)
        {
            r=0;for(I i=l(a);i-->0;)r+=a[i]; //here only this line counts
        }

        static void Main()
        {
            int result;
            CalculateSquare(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, out result);
            Console.Write(result); //should output 140 for the example
            Console.ReadKey();
        }
    }
}
You may also input the square as 2-dimensional array or from a prompt or as string or some standard collection type. A 2-dimensional array is the only way not having to calculate the side length of the square yourself.
A sub-function for the actual work is not required, you could also put the code directly within Main().

Even more preparation is allowed for free, like here:

using System;
unsafe class Delacorte
{
    static void CalculateSquare(int* a, out int r)
    {
        r=0;while(*a>0)r+=*a++; //only this line counts
    }

    static void Main()
    {
        var input = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; //adding a terminator
        int result;
        fixed (int* a = &input[0]) //necessary in C#
            CalculateSquare(a, out result);
        Console.Write(result);
        Console.ReadKey();
    }
}
If you are unsure whether your lengthy preparation is in the spirit of these rules or could be called cheating, just ask :)

*/

package main

func main() {
	assert(delacorte([][]int{
		{4, 1, 3},
		{6, 5, 2},
	}) == 53)

	assert(delacorte([][]int{
		{3, 2, 9},
		{4, 1, 8},
		{5, 6, 7},
	}) == 160)

	assert(delacorte([][]int{
		{10, 8, 11, 14, 12},
		{21, 4, 19, 7, 9},
		{5, 13, 23, 1, 16},
		{18, 3, 17, 2, 15},
		{24, 22, 25, 6, 20},
	}) == 5957)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func delacorte(m [][]int) int {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0
	}

	r := 0
	h := len(m)
	w := len(m[0])
	s := w * h
	for i := 0; i < s; i++ {
		x, y := i%w, i/w
		for j := i + 1; j < s; j++ {
			X, Y := j%w, j/w
			r += gcd(m[y][x], m[Y][X]) * distance2(x, y, X, Y)
		}
	}
	return r
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func distance2(x0, y0, x1, y1 int) int {
	dx := x1 - x0
	dy := y1 - y0
	return dx*dx + dy*dy
}
