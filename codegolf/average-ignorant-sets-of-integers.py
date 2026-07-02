#!/usr/bin/env python3

"""

Recently a friend of mine posed the following:

What subset of the integers satisfies the condition if distinct a and b are in the subset, their average is not in the subset? I know the set of non-0 squares satisfies the condition, but I wonder if there exists a more... dense set that satisfies the condition.

(It turns out my friend was wrong about "the set of non-0 squares satisfies the condition", just ignore that.)

Now, I thought I could turn this into a coding challenge.

The goal of this challenge is to submit a function f:N→{⊤,⊥} which takes in a positive integer and returns a boolean satisfying the conditions in the "Rules" section.

Your score is the length of your program in bytes. Program A is better than program B if A is shorter than B.

Rules
For any distinct a,b so that f(a) is true, f(b) is true and a+b is even, then f((a+b)/2) is false.
Let e:N→N be defined as e(x)=the xth number so that f(x) is true. Then, there exists some m so that e(n)<n2 for all n≥m.
The set {a:f(a) is true} is infinite, i.e. you can't make f hold for only finitely many values.

"""

# https://oeis.org/A005836
def dp3(n):
    return int(format(n-1, 'b'), 3)

"""

@xnor
@Jonathan Allan
The challenge specification just gives the properties required, it does not have to be A003278 itself. oeis.org/A005836 is numbers without any 2s in the ternary representation and is what xnor's code implements, and since it is just the same infinite sequence with all terms being one less it also satisfies the requirements. (it does include 1, although I don't think that is actually a requirement, and 0 is not part of the specified input domain anyway)

"""

def f(n):
    for i in range(1, n):
        v = dp3(i)
        if v == n:
            return True
        if v > n:
            break
    return False

def main():
    N = 500
    for a in range(1, N):
        for b in range(1, N):
            if a != b and f(a) and f(b) and (a+b)%2 == 0:
                assert(not f((a + b) // 2))

main()
