#!/usr/bin/env python3

"""

For any positive integer k, let  d(k) denote the number of divisors of k.
For example, d(6) is 4, because 6 has 4 divisors (namely 1,2,3,6).

Given a positive integer N, display a "skyline" in ASCII art using a fixed character,
such that the height of the "building" located at horizontal position k is d(k) for k=1,...,N.
See test cases below.

Rules
Any non-whitespace character may consistently be used, not necessarily # as shown in the test cases.
The algorithm should theoretically work for arbitrarily high N.
In practice, it is acceptable if the program is limited by time, memory, data-type size or screen size.
Horizontally or vertically leading or trailing spaces or newlines are allowed.
Input and output can be taken by any reasonable means.
Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.
Shortest code in bytes wins.

Test cases
N = 10:

     # # #
   # # ###
 #########
##########
N = 50:

                                               #
                                   #           #
                       #     #     #   # #     #
                       #     #     #   # #     #
           #     # #   #   # # #   #   # # ##  # #
           #   # # #   #   # # #   #   # # ##  # #
     # # # # ### # ### # ### # ##### ### # ### # #
   # # ### # ### # ### ##### # ##### ### # ### ###
 #################################################
##################################################
N = 200:

                                                                                                                                                                                   #
                                                                                                                                                                                   #
                                                                                                                       #                                               #           #
                                                                                                                       #                       #                       #           #
                                                                                                                       #                       #                       #           #           #
                                                                                                                       #                       #                       #           #           #
                                                           #           #           #     #     #           #           #     #     #       #   #     #     #   #       #           #           #     # #
                                                           #           #           #     #     #           #           #     #     #       #   #     #     #   #       #           #           #     # #
                                               #           #           #       #   #     #     #           #   #       #     #     #       #   #     #     #   # #     #       #   #           #     # #
                                   #           #           #           #       #   #     #     #   #       #   #       #     #     #       #   #     #     #   # #     #       #   #           #   # # #
                       #     #     #   # #     #     # #   #     #   # #     # #   #   # #     #   # # ##  # # # #     #     # # # #  ## # #   #     # # # #   # #  #  # #   # #   # # # #  ## #  ## # #
                       #     #     #   # #     #     # #   #   # #   # #     # #   #   # #     #   # # ##  # # # #     #     # # # #  ## # #   #     # # # #   # #  #  # #   # #   # # # #  ## #  ## # #
           #     # #   #   # # #   #   # # ##  # # # # #   #  ## # # # #  ## # #   #   # # #   # ### # ##  # # # # ##  #   # # # # #  ## # #   #  ## # ### #   # # ##  # ### ###   # # # # ### #  ## # #
           #   # # #   #   # # #   #   # # ##  # # # # #   #  ## # # # #  ## # ##  #   # # #   # ### # ##  # # # # ##  #   # # # # #  ## # #   #  ## # ### #   # # ##  # ### ###   # # # # ### #  ## # #
     # # # # ### # ### # ### # ##### ### # ### # ### ##### # ##### ### # ##### ### ##### ####### ### # ### # ### ####### ##### ### ##### # ######### # ##### ##### ### # ### ##### # ######### # ### # #
   # # ### # ### # ### ##### # ##### ### # ### ##### ##### # ##### ### # ##### ### ##### ####### ### # ### # ### ############# ### ##### # ######### # ##### ##### ### ##### ##### # ######### # ### # #
 #######################################################################################################################################################################################################
########################################################################################################################################################################################################

"""

from sympy import divisors

def skyline(n):
    d = [len(divisors(i)) for i in range(1, n + 1)]
    h = max(d)

    print("n=%d" % (n))
    for y in range(h):
        for x in range(n):
            if d[x] >= h-y:
                print("#", end='')
            else:
                print(" ", end='')
        print()
    print()

def main():
    skyline(10)
    skyline(50)
    skyline(200)

main()
