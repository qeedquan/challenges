#!/usr/bin/env Rscript

comment <- "

Left and right Riemann sums are approximations to definite integrals.
Of course, in mathematics we need to be very accurate, so we aim to calculate them with a number of subdivisions that approaches infinity, but that's not needed for the purposes of this challenge.
You should instead try to write the shortest program, taking input and providing output through any of the default methods, in any programming language, which does the following:

Task
Given two rational numbers a and b (the limits of the definite integral), a positive integer n, a boolean k representing left / right and a black-box function f, calculate the left or right Riemann sum (depending on k) of
∫ [a, b] f(x) dx, using n equal subdivisions.

I/O Specs
a and b can be rational / floating-point numbers or fractions.

k can be represented by any two distinct and consistent values, but please keep in mind that you aren't allowed to take complete or partial functions as input.

f is a black-box function. Citing the meta answer linked above, the content (i.e. the code) of black-box-functions may not be accessed, you can only call them (passing arguments if applicable) and observe their output.
If needed, please include the necessary information about the syntax your language uses such that we can test your submission.

As output, you must provide a rational / floating-point / fraction representing the Riemann sum you are asked for.
As discussed in the past, floating-point imprecision can be ignored, as long as your output is accurate to at least three decimal places when rounded to the nearest multiple of 1 / 1000 (e.g. 1.4529999 is fine instead of 1.453).

Math Specs
f is guaranteed to be continuous between a and b (no jumps, no holes, no vertical asymptotes).

There are three possible cases you have to handle: a=b (The result should be 0 or its equivalents), a<b or a>b.

If b<a, the integral changes its sign. Also, the right sense of the integral in this case is towards a.

Areas under the graph are negative and those above the graph are positive.

Examples / Test Cases
The resolution is not optimal, because I had to shrink them down a bit, but they're still readable.

f(x) = 2x+1, a = 5, b = 13, n = 4, k = right:

The result should be 15⋅2+19⋅2+23⋅2+27⋅2=168, because the width of each rectangle is |b−a|/n = 2 and the corresponding heights are f(7)=15,f(9)=19,f(11)=23,f(13)=27.

f(x) = sqrt(x) a = 1, b = 2.5, n = 3, k = left
The output should be 1.8194792169.

f(x) = -3x + 4 + x^2/5, a = 12.5, b = 2.5, n = 10, k = right:

The expected output value is −(−4.05−5.45−6.45−7.05−7.25−7.05−6.45−5.45−4.05−2.25)=55.5 because the integral changes signs when flipping the boundaries (b<a).

f(x) = 9 − 4x + 2*x^2/7, a = 0, b = 15, n = 3, k = left:

Calculating our Riemann sum, we get 13.5714285715.

f(x) = 6, a = 1, b = 4, n = 2, k = right — Output: 18.

f(x) = x^7 + 165x + 1, a = 7, b = 7, n = 4, k = left — Output: 0.

f(x) = x*sin(x^-1), a = 0, b = 1, n = 50, k = right — Output: 0.385723952885505. Note that sine uses radians here, but feel free to use degrees instead.

"

LEFT = TRUE
RIGHT = FALSE

integrate <- function(a, b, n, k, f) {
	w = (b - a) / n
	x = sapply(a + w*(1:n-k), f)
	return (sum(x*w))
}

integrate(5, 13, 4, RIGHT, function(x) 2*x + 1)
integrate(1, 2.5, 3, LEFT, sqrt)
integrate(12.5, 2.5, 10, RIGHT, function(x) -3*x + 4 + x*x/5)
integrate(0, 15, 3, LEFT, function(x) 9 - 4*x + 2*x*x/7)
integrate(7, 7, 4, LEFT, function(x) x^7 + 165*x + 1)
integrate(0, 1, 50, RIGHT, function(x) x*sin(1/x))
integrate(0, 10, 500, LEFT, function(x) x)
