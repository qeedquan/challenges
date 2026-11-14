#!/usr/bin/env python3

"""

As you most probably now, there are 2339 solutions to pentomino puzzle in a 6x10 grid. There are different labeling schemes for the 12 pentominoes, two of them are shown on the image below:

https://i.sstatic.net/pjRVg.png

Image credit: Wikipedia

For the purposes of the current task we will say that a normalized pentomino solution is a solution that uses the second labeling scheme (Conway’s).

Example:

O O O O O S S S Z Z
P P R R S S W W Z V
P P P R R W W Z Z V
U U X R T W Y V V V
U X X X T Y Y Y Y Q
U U X T T T Q Q Q Q
The piece with 5 squares in a row is denoted with letters O, according to the scheme. The same is true for all pieces.

Task:
Given a solution to the 6x10 pentomino in which the pieces are labeled with a random sheme, normalize it so that all pieces are labeled in Conway’s labeling scheme. You need to recognize the pieces and mark each square of a particular piece with the symbol of the piece.

Input:
The solution to be normalized, in any format that is convenient for you, for example:

A multiline string

A list of strings

A list of lists of characters

and so on

Output:
The same solution (all the pieces positions and orientation preserved), but each piece labeled according to Conway’s labeling scheme. Note: The output MUST be PRINTED as a 6x10 grid of characters. Leading and trailing newlines and spaces are permitted. You can also print a space between the characters (but not empty lines), as in the example above.

Test cases:
1. Input:

6623338888
6222344478
66A234BB70
1AAA94B770
11A99BB700
1199555550
Output:

UURTTTQQQQ
URRRTVVVSQ
UUXRTVZZSY
PXXXWVZSSY
PPXWWZZSYY
PPWWOOOOOY
2. Input:

45ookkkk00
455ooogk00
4a55gggdd0
4aaa3gnnd.
4am333ndd.
mmmm3nn...
Output:

OWSSQQQQPP
OWWSSSRQPP
OTWWRRRUUP
OTTTXRZZUV
OTYXXXZUUV
YYYYXZZVVV
Winning criteria:
The shortest solution in bytes in each language wins. Don’t be discouraged by the golfing languages. Explanations of the algorithms and implementations are welcome.

"""

"""

ported from @Kateba solution

The invariant under rotation/translation of the pentominoes is the sum of the distances of the position of each of the tiles and the midpoint.
This assumes that the solution space of the pentominoes only applies translations/rotations to a fixed number of existing pentominoes pieces at the start, it does not add/subtract any pentominoes pieces.

"""
def pentomino_normalizer(input_string):
    results = []
    for current_char in input_string:
        positions = [complex(i % 11, i / 11) for i, c in enumerate(input_string) if c == current_char]
        average_pos = sum(positions) / 5
        invariant = sum(abs(pos - average_pos) for pos in positions)
        results.append((invariant, current_char))

    sorted_results = [w for _, w in sorted(results)]

    chars = ['XPRTWZUYSVQO\n'[sorted_results.index(c)//5] for c in input_string]
    return "".join(chars)

print(pentomino_normalizer("""6623338888
6222344478
66A234BB70
1AAA94B770
11A99BB700
1199555550
"""))

print(pentomino_normalizer("""45ookkkk00
455ooogk00
4a55gggdd0
4aaa3gnnd.
4am333ndd.
mmmm3nn...
"""))
