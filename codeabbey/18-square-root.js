/*

Many mathematical problems are solved in programming not precisely, but approximately, by several computations of the result, each of which is more and more close to the goal.

Let us practice the method of approximate calculation of the square root with the following approach:

Let us search for square root r of the given value X.
Use some arbitrary value, say r = 1 as the first approximation (surely it is too rough).
For proper square root the equation r = X / r should hold.
So let us calculate d = X / r (it would not be equal to r since r is not precise root).
And take average between r and d as the new approximation.
E.g. overall formula of the calculation step is (here := is an assignment):

      r  +  X / r
r := -------------
           2
Refer to Square Root Approximation article for more details on the Heron's Method.

So we are given values X for which to perform calculations and number of steps N to perform.
Use r = 1 at the beginning, and output resulting approximation (after N steps).

Input data will give the number of test-cases in first line.
Next lines will contain test-cases themselves, each containing the value X for which square root should be calculated and N - the number of calculation steps.
Answer should contain calculated approximations for each case, separated by space.

Example:

input data:
3
150 0
5 1
10 3

answer:
1 3 3.196
Results should have precision of 1e-7 = 0.0000001 or better!

*/

function sqrt(x, n) {
	let r = 1;
	for (let i = 0; i < n; i++) {
		r = (r + x/r) * 0.5;
	}
	return r;
}

console.log(sqrt(150, 0));
console.log(sqrt(5, 1));
console.log(sqrt(10, 3));
