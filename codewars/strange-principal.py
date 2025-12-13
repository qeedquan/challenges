#!/usr/bin/env python3

"""

A high school has a strange principal. On the first day, he has his students perform an odd opening day ceremony:

There are number of lockers "n" and number of students "n" in the school. The principal asks the first student to go to every locker and open it. Then he has the second student go to every second locker and close it. The third goes to every third locker and, if it is closed, he opens it, and if it is open, he closes it. The fourth student does this to every fourth locker, and so on. After the process is completed with the "n"th student, how many lockers are open?

The task is to write a function which gets any number as an input and returns the number of open lockers after last sudent complets his activity. So input of the function is just one number which shows number of lockers and number of students. For example if there are 1000 lockers and 1000 students in school then input is 1000 and function returns number of open lockers after 1000th student completes his action.

The given input is always an integer greater than or equal to zero that is why there is no need for validation.

"""

from math import isqrt

# https://oeis.org/A000196
def openlockers(n):
    if n > 0:
        return isqrt(n)
    return 0

def main():
    tab = [
        0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 10, 10
    ]

    for i in range(len(tab)):
        assert(openlockers(i) == tab[i])

    assert(openlockers(0) == 0)
    assert(openlockers(1) == 1)
    assert(openlockers(4) == 2)
    assert(openlockers(56) == 7)
    assert(openlockers(128) == 11)
    assert(openlockers(4521) == 67)
    assert(openlockers(203) == 14)

main()
