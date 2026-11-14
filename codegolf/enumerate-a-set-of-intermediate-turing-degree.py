#!/usr/bin/env python3

"""

where 0 is the degree of computable sets and 0′ is the degree of the halting problem.

Your task is to write the shortest program that enumerates such a set.

Some history
Whether this challenge is even solvable is a surprisingly hard question from the early days of computability theory : it's called Post's problem, as it was first asked by Post in 1944. Its first answers came more than a decade later in 1956 from Muchnik and Friedberg (independently). Nowadays we know that there are many kinds of intermediate c.e. degrees : they can be low or high or neither, cappable or not, cuppable or not, splittable or not... You don't have to worry about that for this challenge though. Your goal is to enumerate a set of any intermediate Turing degree.

Objective
Write a program takes no input and must output strings separated by newlines.

Let A be the set of lines of the output. The program must ensure that A has intermediate Turing degree.

Your answer must include an explanation justifying why the enumerated set has intermediate Turing degree.

This is code-golf, so the shortest program wins.

"""

def evaluate(value, start, marked, steps):
    digits = str(value)
    positions = {0: start}
    digit_index = 0
    cursor = 0
    maximum = 0
    branch_stack = []

    while steps:
        if digit_index == len(digits):
            return maximum + 1

        digit = int(digits[digit_index])
        digit_index += 1

        current = positions.get(cursor, 0)
        steps -= 1

        if digit < 2:
            cursor += 1 - 2 * digit
        if 1 < digit and digit < 4:
            positions[cursor] = current + 5 - 2 * digit
        if digit == 6:
            maximum = max(maximum, current + 1)
            positions[cursor] = current in marked
        if digit == 4:
            branch_stack.append(digit_index)
        if digit == 5 and branch_stack:
            if current:
                digit_index = branch_stack[-1]
            else:
                branch_stack.pop()

    return None

"""

Ported from @Arlo solution

This enumerates a low simple set by a finite-injury construction.

f(e,x,a,s) runs program e on input x for at most s steps with oracle a.
The decimal digits encode a brainfuck variant: 0 and 1 move right and left, 2 and 3 increment and decrement,
4 and 5 form a do–while loop, and 6 replaces the current cell by its oracle-membership bit.
Other digits do nothing. The tape and integer cells are unbounded.
This gives a universal oracle-machine enumeration; do–while loops suffice.
A successful call returns a positive number greater than every oracle query; timeout returns None.

Let  Wi be the domain of program i with the empty oracle.
At stage s, requirement i searches for an  x∈Wi with  2i≤x<s,
above the restraints of all diagonal computations with indices at most i.
If found, it enumerates x and marks the requirement as finished using [i].
These list markers cannot affect integer oracle queries.

For each fixed e, only requirements i at most e can injure its protected computation, and each acts at most once.
After these actions, the restraint for e stabilises: either no convergence is seen, or the first one seen is preserved forever.
Genuine convergence relative to the final set is eventually seen, since it uses only finitely many oracle queries.
Inductively, every infinite Wi eventually supplies a witness above the finitely many stabilised restraints,
so the resulting set A meets every infinite c.e. set.

Each requirement contributes at most one number x≥2i, so |A∩[0,2n)|≤n.
Thus A is coinfinite and simple, hence noncomputable.
The computable convergence approximation stabilises to A′, giving  A′≤T0′.
Therefore A is low and has intermediate Turing degree.

"""

def generate(limit):
    count = 0
    marked = []
    steps = 0
    while True:
        steps += 1
        record = 0
        for value in range(steps):
            record = max(record, evaluate(value, value, marked, steps) or 0)
            if [value] not in marked:
                for start in range(max(2 * value, record), steps):
                    if evaluate(value, start, (), steps):
                        marked += [[value], start]
                        print(start)
                        count += 1
                        if count >= limit:
                            return
                        break

def main():
    generate(100)

main()
