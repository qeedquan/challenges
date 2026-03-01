#!/usr/bin/env python3

"""

Background
A fractal sequence is an integer sequences where you can remove the first occurrence of every integer and end up with the same sequence as before.

A very simple such sequence is called Kimberling's paraphrases. You start with the positive natural numbers:

1, 2, 3, 4, 5, 6, 7, 8, 9, ...
Then you riffle in some blanks:

1, _, 2, _, 3, _, 4, _, 5, _, 6, _, 7, _, 8, _, 9, ...
And then you repeatedly fill in the blanks with the sequence itself (including the blanks):

1, 1, 2, _, 3, 2, 4, _, 5, 3, 6, _, 7, 4, 8, _, 9, ...
1, 1, 2, 1, 3, 2, 4, _, 5, 3, 6, 2, 7, 4, 8, _, 9, ...
1, 1, 2, 1, 3, 2, 4, 1, 5, 3, 6, 2, 7, 4, 8, _, 9, ...
1, 1, 2, 1, 3, 2, 4, 1, 5, 3, 6, 2, 7, 4, 8, 1, 9, ...
That's our fractal sequence! Now let's take the partial sums:

1, 2, 4, 5, 8, 10, 14, 15, 20, 23, 29, 31, 38, 42, 50, 51, 60, ...
But what if we iterate this process? "Fractalise" the new sequence (i.e. the partial sums obtained from the steps above):

1, _, 2, _, 4, _, 5, _, 8, _, 10, _, 14, _, 15, _, 20, _, 23, ...
1, 1, 2, _, 4, 2, 5, _, 8, 4, 10, _, 14, 5, 15, _, 20, 8, 23, ...
1, 1, 2, 1, 4, 2, 5, _, 8, 4, 10, 2, 14, 5, 15, _, 20, 8, 23, ...
1, 1, 2, 1, 4, 2, 5, 1, 8, 4, 10, 2, 14, 5, 15, _, 20, 8, 23, ...
1, 1, 2, 1, 4, 2, 5, 1, 8, 4, 10, 2, 14, 5, 15, 1, 20, 8, 23, ...
And take the partial sums again:

1, 2, 4, 5, 9, 11, 16, 17, 25, 29, 39, 41, 55, 60, 75, 76, 96, ...
Rinse, repeat. It turns out that this process converges. Every time you repeat this process, a larger prefix of the sequence will remain fixed. After an infinite amount of iterations, you would end up with OEIS A085765.

Fun fact: This process would converge to the same sequence even if we didn't start from the natural numbers as long as the original sequence starts with 1. If the original sequence starts with any other x, we'd obtain x*A085765 instead.

The Challenge
Given a positive integer N, output the Nth element of the converged sequence.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

You may choose whether the index N is 0- or 1-based.

Test Cases
The sequence starts with:

1, 2, 4, 5, 9, 11, 16, 17, 26, 30, 41, 43, 59, 64, 81, 82, 108, 117, 147, 151, 192, 203, 246, 248, 307, 323, 387, 392, 473, 490, 572, 573, 681, 707, 824, 833, 980, 1010, 1161, 1165, 1357, 1398, 1601, 1612, 1858, 1901, 2149, 2151, 2458, 2517
So input 5 should result in output 9.

Here is a naive CJam reference implementation which generates the first N numbers (given N on STDIN). Note that your code should only return the Nth element, not the entire prefix.

"""

# https://oeis.org/A085765
def fractal(n):
    if n < 1:
        return 0

    x = [0] * (n*n + 4)
    x[1] = 1
    for i in range(1, n + 1):
        x[2*i] = x[i]
        x[2*i + 1] = sum(x[1 : i+2])
    return sum(x[1 : n+1])

def main():
    tab = [1, 2, 4, 5, 9, 11, 16, 17, 26, 30, 41, 43, 59, 64, 81, 82, 108, 117, 147, 151, 192, 203, 246, 248, 307, 323, 387, 392, 473, 490, 572, 573, 681, 707, 824, 833, 980, 1010, 1161, 1165, 1357, 1398, 1601, 1612, 1858, 1901, 2149, 2151, 2458, 2517]

    for i in range(len(tab)):
        assert(fractal(i + 1) == tab[i])

main()
