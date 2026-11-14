/*

I'm starting with golf code. But im only do C# so I know wont be a breaking record, but I want give it a try. Leibniz

Challenge is here

The first line contains the number of test cases (N) which is less than 100. Each additional line is a test case for a positive integer value (T) less than 10^7.

I format the code to easy the reading, removing spaces I reduce it to 210 chars. The best code submit for this problem is 54 char, but For C# lenguaje the best is 172 chars.

My guess is should remove reading the N, but couldn't make it stop properly.

using System;
class S
{
    static void Main()
    {
        int n=Convert.ToInt32(Console.ReadLine()),i=0;
        for (;i++<n;)
        {
            double r=0,t=Convert.ToInt32(Console.ReadLine()),j=0;
            for(;j<t;)
                r+=(1-j%2*2)/(2*j+++1);
            Console.WriteLine(r);
        }
    }
}
NOTE

Mono C# compiler 3.2.8.0 .NET 4.0 CLR
So using C=System.Console doesn't work.

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 100000000; i *= 10 {
		fmt.Println(i, leibniz(i)*4)
	}
}

func leibniz(n int) float64 {
	r := 0.0
	s := 1.0
	for i := range n {
		r += s / float64(2*i+1)
		s = -s
	}
	return r
}
