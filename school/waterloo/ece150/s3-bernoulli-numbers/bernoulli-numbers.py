#!/usr/bin/env python3

"""

The calculation of Bernoulli numbers has a special place in the history of computer programming: the first program written for the Babbage machine by Ada, Countess of Lovelace, was to generate the Bernoulli numbers.

B[n] = 1                                                 if n = 0
      -1/2                                               if n = 1
      -Sum[k=0, n-1] binomial(n, k) * B[k]/(n - k + 1)   if n >= 2

You will write a program that calculates the Bernoulli numbers from 0 to n and return a dynamically allocated array storing these numbers.

double *bernoulli( std::size_t n );
Once you take a look at your output, you may notice something peculiar about many of the numbers. After reading the Wikipedia page on Bernoulli numbers, what simplification could you introduce to your function to improve the efficiency and perhaps even the results?

Next, the exact value of B14=76=1.1666⋯. How close is your approximation to this value? Can you think of how you could improve the accuracy of your implementation?

If you are just writing a recursive function, consider using the following main program:

#include <iostream>
int main();
double bernoulli( std::size_t n );

int main() {
    std::size_t const MAX_BERNOULLI{ 20 };

    // Set the output to display 16 significant decimal digits
    //  - this is close to the precision of the double-precision
    //    floating-point representation
    std::cout.precision( 16 );

    for ( std::size_t k{0}; k <= MAX_BERNOULLI; ++k ) {
        // This formatting lines up the output more nicely by ensuring
        // that the equal signs and the leading digits are lined up
        std::cout << "  B_" << k << "\t= "
                  << ((bernoulli( k ) >= 0) ? " " : "")
                  << bernoulli( k ) << std::endl;
    }

    return 0;
}

double bernoulli( std::size_t n ) {
    return 0.0;
}
If, however, you're writing a function that calculates all Bernoulli numbers up to n at once, here is a program you can use:

#include <iostream>
int main();
double *bernoulli( std::size_t n );

int main() {
    std::size_t const MAX_BERNOULLI{ 20 };
    double *bernoulli_numbers{ bernoulli( MAX_BERNOULLI ) };

    // Set the output to display 16 significant decimal digits
    //  - this is close to the precision of the double-precision
    //    floating-point representation
    std::cout.precision( 16 );

    for ( std::size_t k{0}; k <= MAX_BERNOULLI; ++k ) {
        // This formatting lines up the output more nicely by ensuring
        // that the equal signs and the leading digits are lined up
        std::cout << "  B_" << k << "\t= "
                  << ((bernoulli_numbers[k] >= 0) ? " " : "")
                  << bernoulli_numbers[k] << std::endl;
    }

    delete[] bernoulli_numbers;

    return 0;
}

double *bernoulli( std::size_t n ) {
    double result{ new double[n + 1] };

    return result;
}

Finally, how long does it take for your algorithm to print the first 30 Bernoulli numbers? Is it reasonably fast or there a noticable delay of at least a few seconds? What algorithm did you use for calcluating (nk)?

"""

from fractions import *
from math import *

# https://oeis.org/A027641
# https://oeis.org/A027642
def bernoulli(n):
    r = []
    if n >= 1:
        r.append(Fraction(1, 1))
    
    if n >= 2:
        r.append(Fraction(-1, 2))

    for i in range(2, n):
        x = Fraction(0, 1)
        for k in range(0, i):
            x += Fraction(comb(i, k)*r[k], (i - k + 1))
        r.append(-x)

    return r

def main():
    A027641tab = [1, -1, 1, 0, -1, 0, 1, 0, -1, 0, 5, 0, -691, 0, 7, 0, -3617, 0, 43867, 0, -174611, 0, 854513, 0, -236364091, 0, 8553103, 0, -23749461029, 0, 8615841276005, 0, -7709321041217, 0, 2577687858367, 0, -26315271553053477373, 0, 2929993913841559, 0, -261082718496449122051]
    
    A027642tab = [1, 2, 6, 1, 30, 1, 42, 1, 30, 1, 66, 1, 2730, 1, 6, 1, 510, 1, 798, 1, 330, 1, 138, 1, 2730, 1, 6, 1, 870, 1, 14322, 1, 510, 1, 6, 1, 1919190, 1, 6, 1, 13530, 1, 1806, 1, 690, 1, 282, 1, 46410, 1, 66, 1, 1590, 1, 798, 1, 870, 1, 354, 1, 56786730, 1]

    b = bernoulli(max(len(A027641tab), len(A027642tab)))
    for i in range(len(A027641tab)):
        assert(b[i].numerator == A027641tab[i])
    
    for i in range(len(A027642tab)):
        assert(b[i].denominator == A027642tab[i])

main()
