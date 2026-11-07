#!/usr/bin/env python3

"""

Lighthouses on an island have blink codes that let ships know which lighthouse they are seeing. Input should be strings of S and L. Here is a (Python) example of codes for 4 lighthouses as a list of strings:

['SLS', 'SLL', 'SSS', 'LSL']
where:

S = short ON (1 sec)
L = long ON (3 sec)

Long and short ON's are both followed by 1 sec OFF, except the last in the code, which is followed by a 7-second LONG OFF pause to signify end of code. The code for the first lighthouse in the above example corresponds to this blink schedule in seconds :

1 ON, 1 OFF, 3 ON, 1 OFF, 1 ON, 7 OFF [repeat]

Challenge:

n Lighthouses come on simultaneously, each at the start of its schedule. Write a program that takes a series of blink codes (strings in the above format) and outputs the total number of seconds that exactly zero, one, two, three, ... n lighthouses were on at the same time after the first hour of lighthouse operation (So the output numbers will always total 3600.)

Test Cases:

Input -> Output
['SLS', 'SLL', 'SSS', 'LSL'] -> 1125, 890, 652, 590, 343
['S', 'L', 'SS'] -> 2250, 630, 540, 180
['SLSL', 'S'] -> 1850, 1450, 300
['SLS'] -> 2314, 1286
['SS', 'SS', 'L'] -> 2520, 360, 0, 720
Rules:

There can be one or more lighthouses (code strings).

All lighthouses come on simultaneously, each at the start of its code schedule.

Codes can be any length >= 1 and don't have to be unique (however off-shore mayhem may ensue).

Just for clarity, the 652 in the first example is the time in seconds that exactly 2 lighthouse (not 2 or more) were on.

The shortest code in bytes wins (code-golf).

"""

# Based on @SevC_10 solution
def calculate(lighthouses):
    lighthouses = [x.replace('S', '10') for x in lighthouses]
    lighthouses = [x.replace('L', '1110') for x in lighthouses]
    
    lighthouses = [x + '0'*6 for x in lighthouses]
    lighthouses = [x * 450 for x in lighthouses]

    total = [0] * (len(lighthouses) + 1)
    for i in range(3600):
        total[[c[i] for c in lighthouses].count('1')] += 1
    return total

def main():
    assert(calculate(['SLS', 'SLL', 'SSS', 'LSL']) == [1125, 890, 652, 590, 343])
    assert(calculate(['S', 'L', 'SS']) == [2250, 630, 540, 180])
    assert(calculate(['SLSL', 'S']) == [1850, 1450, 300])
    assert(calculate(['SLS']) == [2314, 1286])
    assert(calculate(['SS', 'SS', 'L']) == [2520, 360, 0, 720])

main()
