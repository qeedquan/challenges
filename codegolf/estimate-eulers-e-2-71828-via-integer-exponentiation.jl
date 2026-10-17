#!/usr/bin/env julia

#=

Euler's e (2.71828…), i.e. the base of exp() function, has a formal definition of

lim n->oo (1 + 1/n)^n

The code golfing challenge at hand is -

Given integer inputs x = [ 1 , 100000 ], estimate Euler's e by

raising some integer base of your choice,
to an integer exponent (algebraically related x) of your choice,
such that x is always exactly the number of accurate digits of e, sans its decimal point

Permissible :

Big-integer libraries, e.g. gnu GMP
Precision truncation along the way
Exponentiation operator (either ** or ^ in most languages), as long as both operands are integers
All string ops
All regular expression (regex) ops
All bitwise ops
All pointer arithmetic, even upon data types that aren't typically suitable for such tasks
Any combination of loops and recursion
Any amount of code obfuscation, intentional or otherwise
Turing-incomplete languages
Vendor proprietary languages, like SAS
Set/List/Dictionary/Array/Vector-Comprehension (or similar data types
Any sort of map() - filter() - reduce() -type functions
Lambdas, Anonymous Functions, and Closures
Memoization
Parallelism, Multithreading, Concurrency, and Distributed Workloads
Assembly code
Hardware assist e.g. SIMD vectorizations, GPUs, and/or Neutral Engines
Dis-allowed :

Submissions where \x80 - \xFF bytes constitute an outright majority
Code-pages that aren't either ASCII, UTF-8, 8859-1 "Latin-1" / Windows CP1252, or UTF-16/32 (of any endian)
Any word or character from either Russian or Belarusian languages (or via mimicry)
Big-float libraries, e.g. gnu MPFR

Big-num libraries that allow explicit declaration of precision

calling any transcendental function exp(), log(), sin(), cos(), atan(), atan2(), or the bessel function, and related derivatives
Factorials that constitute more than 5 % of total execution time
Intentional idle spinning to satisfy above criteria
Continued Fractions
Fast Fourier Transforms
Infinite summation of Taylor Series
Infinite products where any 2 terms a and b aren't cross related via either a being an integer root or integer power of b (given precision x, the input)
Extremely obscure languages with fewer than 100 users worldwide
This is code golfing. Shortest code wins. Goodluck to all.

=#

function limexp(n)
	return (1 + (1/n))^n
end

println(limexp(BigFloat(1e50)))
