#!/usr/bin/env python3

"""

A boolean circuit in TCS is basically a DAG consisting of And, Or, Not gates, and by what is known is "functional completeness" they can compute all possible functions. eg this is the basic principle in an ALU.

Challenge: create a circuit to determine whether an 8-binary-digit number is divisible by 3 and somehow visualize your result (ie in some kind of picture)

The judging criteria for voters is based on whether the code to generate the circuit generalizes nicely to arbitrary size numbers, and whether the algorithmically-created visualization is compact/balanced but yet still human-readable (ie visualization by hand arrangement not allowed). ie the visualization is for n=8 only but the code will ideally work for all 'n'. winning entry is just top voted.

Somewhat similar question: Build a multiplying machine using NAND logic gates

"""

"""

Ported from @Keith Randall solution

The graph maintains 3 booleans at each level i.
They represent the fact that the high-order i bits of the number are equal to 0, 1, or 2 mod 3.
At each level we compute the next three bits based on the previous three bits and the next input bit.

dot -Tps circuit.dot -o circuit.pdf

"""
def circuit(N, K):
    v = ["0"] * (K - 1) + ["1"]
    ops = {}

    ops["0"] = ["0"]
    ops["1"] = ["1"]
    v = ["0"]*(K - 1) + ["1"]
    for i in range(N):
        ops["bit%d" % i] = ["bit%d" % i]
        ops["not%d" % i] = ["not", "bit%d" % i]
        for j in range(K):
            ops["a%d_%d" % (i, j)] = ["and", "not%d" % i, v[(2 * j) % K]]
            ops["b%d_%d" % (i, j)] = ["and", "bit%d" % i, v[(2 * j + 1) % K]]
            ops["o%d_%d" % (i, j)] = ["or", "a%d_%d" % (i, j), "b%d_%d" % (i, j)]
        v = ["o%d_%d" % (i, j) for j in range(K)]

    for i in range(4):
        for n, op in ops.items():
            for j, a in enumerate(op[1:]):
                if ops[a][0] == "and" and ops[a][1] == "0":
                    op[j + 1] = "0"
                if ops[a][0] == "and" and ops[a][2] == "0":
                    op[j + 1] = "0"
                if ops[a][0] == "and" and ops[a][1] == "1":
                    op[j + 1] = ops[a][2]
                if ops[a][0] == "and" and ops[a][2] == "1":
                    op[j + 1] = ops[a][1]
                if ops[a][0] == "or" and ops[a][1] == "0":
                    op[j + 1] = ops[a][2]
                if ops[a][0] == "or" and ops[a][2] == "0":
                    op[j + 1] = ops[a][1]

    for i in range(4):
        used = set(["o%d_0" % (N - 1)]) | set(a for n, op in ops.items() for a in op[1:])
        newops = ops.copy()
        for n, op in ops.items():
            if n not in used:
                del newops[n]
        ops = newops

    print("digraph {")
    for n, op in ops.items():
        if op[0] == "and":
            print("\t%s [shape=invhouse]" % n)
        if op[0] == "or":
            print("\t%s [shape=circle]" % n)
        if op[0] == "not":
            print("\t%s [shape=invtriangle]" % n)
        if op[0].startswith("bit"):
            print("\t%s [color=red]" % n)
        print("\t%s [label=%s]" % (n, op[0]))
        for a in op[1:]:
            print("\t%s -> %s" % (a, n))
    print("}")

def main():
    circuit(8, 3)

main()
