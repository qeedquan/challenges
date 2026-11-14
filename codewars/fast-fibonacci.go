/*

Fast Fibonacci
The generic implementation of the fibonacci algorithm is usually something like the following

function fib(num) {
  if (num < 2) return num;
  return fib(num - 1) + fib(num - 2);
}

Now thats all and well and good but that function isn't too efficient. If I wanted to get the 1000th number in the series, I'd have to wait... days? maybe years?

Your task
Write a more efficient fibonacci function that can calculate the 1000th+ number series without breaking a sweat. Read up on tail call optimization for some help.

Starting values
fib(0) = 0;
fib(1) = 1;

*/

package main

import "fmt"

func main() {
	for i := range 50 {
		fmt.Println(fib(i))
	}
}

func fib(n int) int {
	r, _ := fib2(n)
	return r
}

// https://www.nayuki.io/page/fast-fibonacci-algorithms (fast doubling)
func fib2(n int) (int, int) {
	if n < 0 {
		return 0, 0
	}
	if n == 0 {
		return 0, 1
	}
	a, b := fib2(n / 2)
	c := a * (b*2 - a)
	d := a*a + b*b
	if n&1 == 0 {
		return c, d
	}
	return d, c + d
}
