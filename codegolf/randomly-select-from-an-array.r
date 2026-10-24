#!/usr/bin/env Rscript

"

This challenge is rather simple:
You are given an array of positive (not including 0) integers, and have to select a random element from this array.

But here's the twist:
The probability of selecting an element is dependent on the value of the integer, meaning as the integer grows larger, the probability of it to get selected does too!

Example
You are given the array [4, 1, 5].

The probability of selecting 4 is equal to 4 divided by the sum of all elements in the array, in this case 4 / ( 4 + 1 + 5 ) = 4 / 10 = 40%.
The probability of selecting 1 is 1 / 10 or 10%.

Input
An array of positive integers.

Output
Return the selected integer if using a method, or directly print it to stdout.

Rules
This is code-golf so shortest code in bytes in any language wins.
Standard loopholes are forbidden.

"

select <- function(a, n=1) {
	sample(x=a, size=n, replace=TRUE, prob=a)
}

verify <- function(a, n) {
	table(select(a, n))/n
}

verify(c(4, 1, 5), 10000);
verify(c(1, 3, 6), 10000);
verify(c(8, 2), 10000);
