/*

Some numbers are just, well, odd. For example, the number 3 is odd because it is not a multiple of two.
Numbers that are a multiple of two are not odd; they are even.
More precisely, if a number n can be expressed as n=2k for some integer k, then n is even. For example, 6=2×3 is even.

Some people get confused about whether numbers are odd or even.
To see a common example, do an internet search for the query "is zero even or odd?" (Don't search for this now! You have a problem to solve!)

Write a program to help these confused people.

Input
The first line contains the number of test cases n (1≤n≤20). Each of the next n lines contains a single integer x (−10≤x≤10).

Output
For each x, print either x is odd or x is even, depending on whether x is odd or even.

Examples

Input #1
3
10
9
-5

Answer #1
10 is even
9 is odd
-5 is odd

*/

function solve(numbers) {
	numbers.forEach(number => {
		if (number%2 == 0) {
			console.log(number + " is even");
		} else {
			console.log(number + " is odd");
		}
	});
}

solve([10, 9, -5]);

