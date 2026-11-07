#!/usr/bin/env Rscript

comment <- "

When given a a list of values and a positive integer n, your code should output the cartesian product of the list with itself n times.

For example, in pseudocode your function could be similar to:

for x1 in list:
    for x2 in list:
        for x3 in list:
            ...
            for xn in list:
                print x1, x2, x3, ... , xn
Example:

repeated_cart([1,2,3], 3)

1 1 1  
1 1 2  
1 1 3  
1 2 1  
1 2 2  
1 2 3  
1 3 1  
1 3 2  
1 3 3  
2 1 1  
2 1 2  
2 1 3  
2 2 1  
2 2 2  
2 2 3  
2 3 1  
2 3 2  
2 3 3  
3 1 1  
3 1 2  
3 1 3  
3 2 1  
3 2 2  
3 2 3  
3 3 1  
3 3 2  
3 3 3
Built in functions (or functions from imported libraries) that compute the Cartesian product or Cartesian power are not allowed due to the resulting code being somewhat boring.

Inputs and outputs should be delimited but can be taken in any reasonable method. The order the output is given does not matter but duplicates are not allowed.

This is code-golf so shortest code wins

"

cartesian_product_n <- function(list, times) {
	unique(t(combn(rep(list, times), times)))
}

cartesian_product_n(1:3, 3)
