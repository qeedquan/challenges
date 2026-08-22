#!/usr/bin/env python3

"""

In some forms of assembly, there are separate "short jump" and "long jump" instructions. However, these jumps can themselves have different lengths, which can affect the distance other jumps need to jump and thus their optimal jump length.

This assembly language will be bit based; there are no bytes and each measure is in bits.

For a jump of absolute length at most 2ⁿ-1, the jump instruction costs n*2 bits. It is impossible to jump 0 distance. Jump is the only instruction that exists in this language.

Your challenge
Given an array like this:

[1,2,0]

Which represents code like this:

0: goto 1;
1: goto 2;
2: goto 0;
Calculate how far each instruction needs to jump. Then output either:

The absolute location of each instruction when compiled, in bits

In this case, [0, 6, 12]. A 6 length jump instruction can jump up to 2³-1=7.

The length of each instruction when compiled. You may optionally exclude the last value.

In this case, [6, 6, 8]

How far each instruction jumps.

In this case, [6, 6, -12]

def f(m):
    lengths = [2 for i in m]
    valid = False
    while not valid:
        valid = True
        positions = [sum(lengths[:i])for i in range(len(m))]
        for i, u, length, position in zip(range(len(m)), m, lengths, positions):
            p2 = positions[u]
            distance = abs(p2 - position)
            if 2**(length//2) <= distance:
                lengths[i]+=2
                valid = False
                break
    return positions, lengths, [positions[u] - position for u,position in zip(m, positions)]
Example Code

Test Cases
Test Case	Absolute Locations	Lengths	jump distance
[1, 2, 0]	[0, 6, 12]	[6, 6, 8]	[6, 6, -12]
[2, 2, 0]	[0, 8, 14]	[8, 6, 8]	[14, 6, -14]
[3, 0, 0, 0]	[0, 10, 18, 28]	[10, 8, 10, 10]	[28, -10, -18, -28]
[4, 0, 0, 0, 0]	[0, 12, 20, 30, 40]	[12, 8, 10, 10, 12]	[40, -12, -20, -30, -40]
[8, 0, 6, 8, 8, 0, 7, 8, 0]	[0, 14, 22, 34, 46, 58, 70, 76, 82]	[14, 8, 12, 12, 12, 12, 6, 6, 14]	[82, -14, 48, 48, 36, -58, 6, 6, -82]
Reminder you only need to output one of absolute locations, lengths, or jump distances. Which one you choose is up to you.

"""

def f(m):
    lengths = [2 for i in m]
    valid = False
    while not valid:
        valid = True
        positions = [sum(lengths[:i]) for i in range(len(m))]
        for i, u, length, position in zip(range(len(m)), m, lengths, positions):
            p2 = positions[u]
            distance = abs(p2 - position)
            if 2**(length//2) <= distance:
                lengths[i] += 2
                valid = False
                break
    return positions, lengths, [positions[u] - position for u,position in zip(m, positions)]

def main():
    print(f([1, 2, 0]))
    print(f([2, 2, 0]))
    print(f([3, 0, 0, 0]))
    print(f([4, 0, 0, 0, 0]))
    print(f([8, 0, 6, 8, 8, 0, 7, 8, 0]))

main()
