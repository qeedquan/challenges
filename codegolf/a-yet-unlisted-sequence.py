#!/usr/bin/env python3

"""

I was looking for a simple sequence that's not yet referenced on the OEIS and came up with this one(*):

a[1] = 2
a[2] = 3

For n>2 , a[n] is the smallest number of the form a[i]*a[j]+1 (with 1≤i≤j<n) that is not yet included in the sequence.

The first few terms are:

2 3 5 7 10 11 15 16 21 22 23 26 31 33 34 36 43 45 46 47 49 50 51 53 56 63 64 67 69 70 71 73 76 78 79 81 87 91 93 94 95 99
Your task is to output this sequence.

This is code-golf and standard sequence rules apply.

(*) As pointed out by ovs and Jonathan Allan, the OEIS does include two sequences in the same spirit: A009293 and A009388.

"""

def gen(n):
    r = []
    c = set({2, 3})
    s = set({})
    while len(r) < n:
        x = min(c - s)
        s |= {x}
        r.append(x)
        for y in s:
            c |= {x*y + 1}
    return r

def main():
    tab = [
        2, 3, 5, 7, 10, 11, 15, 16, 21, 22, 23, 26, 31, 33, 34, 36, 43, 45, 46,
        47, 49, 50, 51, 53, 56, 63, 64, 67, 69, 70, 71, 73, 76, 78, 79, 81, 87,
        91, 93, 94, 95, 99
    ]
    
    assert(gen(len(tab)) == tab)

main()
