#!/usr/bin/env python3

"""

Challenge:
NSDT is like a calculus model invented by me that contains only 4 commands and grouping. Your task is to check in which way the program ends. The program is read from left to right. There are three ways in which a program runs:

Halting program: The program will end in some way
Unhalting non-extending program: The program will not end but will repeat the same state.
Unhalting extending program: The program will not end and will not repeat the same state.
And there are four commands; they are

N: get the first argument and return nothing: f(x):
S: return the first argument applied once f(x): x
D: return the first argument applied twice f(x): x(x)
T: return the first argument applied thrice f(x): x(x)(x)
For example, SS returns S and TS returns SSS

The commands are groupable; for example, D(TS)D has (TS) grouped, it returns (TS)(TS)D which is the same as TS(TS)D.

Your task is to determine in which way the program runs. The input must be infix, but you don't have to manually parse from strings to lists, so something like ['D', ['D', 'N']] or ["D", ["DN"]] is fine. The output can be anything as long as the program outputs it consistently like 0, 1 and 2. The shortest code in bytes wins.

I will give an example for each way:

Halting
T(NTDS)T
NTDS(NTDS)(NTDS)T
DS(NTDS)(NTDS)T
SS(NTDS)(NTDS)T
S(NTDS)(NTDS)T
NTDS(NTDS)T
...
NTDST
DST
SST
ST
T
(halted)
Unhalting non-extending
S(TSD(TSD))
TSD(TSD)
SSSD(TSD)
SSD(TSD)
SD(TSD)
D(TSD)
TSD(TSD)
... (repeating)
Unhalting extending
ST(ST)
T(ST)
ST(ST)(ST)
T(ST)(ST)
ST(ST)(ST)(ST)
T(ST)(ST)(ST)
ST(ST)(ST)(ST)(ST)
... (extending)
And that's it. These are all the examples. All of the above can be used as test cases. More test cases are introduced below:

Test cases:
Halting
N
NT
SS
S(TNT)
D(D(NN)N)
TN
TS
TNT
T(NTDS)T
T(T(T(NTDS)))
Unhalting non-extending
DD
D(SD)
TDD
D(NSDD)
DD(TT)
T(TN)
S(TSD(TSD))
Unhalting extending
TT
ST(ST)
NTTT
NT(DT)
ST(ST)N
TTD
D(T(TT)T)NSNS

"""

"""

Ported from @A. Helmer solution

Explanation
R is the result, H is an history of all the steps. The code runs each step, extracts the 2 first elements of the list and applies the N/S/D/T rules.

If the result is found in the history, it returns 1 (loop)
If something in the history is a prefix or a suffix of the result, it returns 2 (expanding)
otherwise, the loop will end and return 0 (halting)

"""

def nsdt(sequence):
    remaining = sequence
    history = []
    while len(remaining) > 1:
        first, second, *rest = remaining
        count = "NSDT".index(first)
        if count:
            remaining = list(second) + [second] * (count - 1) + rest
        elif rest:
            remaining = list(rest[0]) + rest[1:]
        else:
            remaining = rest

        if remaining in history:
            return 1

        for previous in history:
            if previous in (remaining[1:], remaining[:len(previous)]):
                return 2
        history.append(remaining)
    return 0

def parse(cmd):
    result = []
    group = []
    depth = 0
    for char in cmd:
        if char == "(":
            if depth == 0:
                group = []
            else:
                group.append(char)
            depth += 1
        elif char == ")":
            depth -= 1
            if depth < 0:
                raise ValueError("Unmatched closing parenthesis")
            if depth == 0:
                result.append(parse("".join(group)))
            else:
                group.append(char)
        elif depth == 0:
            result.append(char)
        else:
            group.append(char)
    if depth != 0:
        raise ValueError("Unmatched opening parenthesis")
    return result

def main():
    # test cases:
    T_0 = [
        "N",
        "NT",
        "SS",
        "S(TNT)",
        "D(D(NN)N)",
        "TN",
        "TS",
        "TNT",
        "T(NTDS)T",
        "T(T(T(NTDS)))"
    ]


    T_1 = [
        "DD",
        "D(SD)",
        "TDD",
        "D(NSDD)",
        "DD(TT)",
        "S(TSD(TSD))"
    ]

    T_2 = [
        "TT",
        "TTD",
        "ST(ST)",
        "NTTT",
        "NT(DT)",
        "ST(ST)"
    ]

    print("Halting")
    for test in T_0:
        print(nsdt(parse(test)))

    print("Loops")
    for test in T_1:
        print(nsdt(parse(test)))

    print("Expanding")
    for test in T_2:
        print(nsdt(parse(test)))

main()
