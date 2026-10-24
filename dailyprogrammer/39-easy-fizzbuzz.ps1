#!/usr/bin/env pwsh

<#

You are to write a function that displays the numbers from 1 to an input parameter n, one per line, except that if the current number is divisible by 3 the function should write “Fizz” instead of the number, if the current number is divisible by 5 the function should write “Buzz” instead of the number, and if the current number is divisible by both 3 and 5 the function should write “FizzBuzz” instead of the number.

For instance, if n is 20, the program should write 1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16, 17, Fizz, 19, and Buzz on twenty successive lines.

#>

function fizzbuzz($n) {
	for ($i = 1; $i -le $n; $i++) {
		if ($i%15 -eq 0) {
			echo "FizzBuzz"
		} elseif ($i%3 -eq 0) {
			echo "Fizz"
		} elseif ($i%5 -eq 0) {
			echo "Buzz"
		} else {
			echo $i
		}
	}
}

fizzbuzz 20
