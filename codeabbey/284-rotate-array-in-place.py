#!/usr/bin/env python3

"""

This exercise should be done in BASIC language - see instruction and use the corresponding button below to run the code.

You are given an array of N values - and you need to "rotate" it by K elements, just as in the Rotate String problem. This should be done without using additional memory (e.g. creating another array for result or temporary storage is not allowed). That is what we call in-place operation.

As a reminder, rotation by 1 is a shift of all elements to the left. Very first element "falls out" and we reinsert it in the end. Rotation by K elements is the same operation repeated K times. Example:

1 2 3 4 5 6 7 8     <- original array of N=8 elements

4 5 6 7 8 1 2 3     <- same array "rotated" by K=3
Motivation for this task - most modern languages provide ways which "spoil" the original problems of reverting and rotating string or array. BASIC is somewhat similar in syntax to Python and very easy to learn - but doesn't have such a "high-level" operations, so programmer needs to come up with some suitable sequence of element reassignments, swaps etc.

Consider the following program:

INPUT n, k
DIM a(n)
FOR i = 0 TO n-1 : INPUT a(i) : NEXT i

GOSUB rotate

FOR i = 0 to n-1 : PRINT a(i); " "; : NEXT i
PRINT
END

rotate:
REM all the magic should happen here
RETURN
This code inputs values for N and K, then allocates array A(N) and fills it with further values from the input.

Then it calls subroutine rotate after which array should be transformed. To visually control this the last loop, before END prints array content.

Copy-paste this program into code area and invent "rotation" logic inside the subroutine rotate, instead of comment line. When the code is tested on server, the main part will be ignored - so do not try to trick the checker by reading values in different order. Submitted answer is ignored, input is just an example for you to play with. Your solution will be tested against several (different) inputs.

Only your code for subroutine matters.

Assume that 0 < K < N.

"""

def reverse(a, i, j):
    while i < j:
        a[i], a[j] = a[j], a[i]
        i += 1
        j -= 1

def rotate_left(a, k):
    n = len(a)
    if n == 0:
        return a
    k %= n

    reverse(a, 0, k - 1)
    reverse(a, k, n - 1)
    reverse(a, 0, n - 1)
    return a

def main():
    assert(rotate_left([1, 2, 3, 4, 5, 6, 7, 8], 3) == [4, 5, 6, 7, 8, 1, 2, 3])

main()
