#!/usr/bin/env python3

"""

Do Not Find the Fox is a non-game where you repeat the following up to 16 times:

Pick an empty square in a 4×4 grid
Draw a tile from a bag – there are 5 Fs, 6 Os and 5 Xs at first – and place it in the picked square (you pick the square before drawing the tile)
You win iff you fill the grid without a FOX spelled in three orthogonally or diagonally consecutive tiles in any direction.
It is a non-game because there is no strategy; any permutation of picked cells results in the same uniform distribution of F, O, X in the filled grid. Thus the only question is how often you win, and for the basic variant described above there are 255304 winning grids out of (165,5,6)=2018016
 equally likely filled grids, for a chance of 455936036=0.126512…
 or just over 18
. Your task here is to print out all winning grids, where two grids are different iff they differ in at least one position (i.e. no factoring through symmetries is to be done here).

Here is an example of a winning grid:

XFOO
FXFX
OOFX
FXOO
Conditions on the output
You must use exactly the symbols F O X, but you may choose to output each grid as a 2D grid or as a flattened form of that grid. In either case any reasonable output format is acceptable.

You must print each winning grid exactly once, but they may be printed in any order. Each grid must have 5 Fs, 6 Os and 5 Xs.

Ungolfed example
#!/usr/bin/env python3
from itertools import combinations

lines = []
for mx in range(4):
    for my in range(4):
        for (dx, dy) in ((1, 0), (1, 1), (0, 1), (1, -1), (-1, 0), (-1, -1), (0, -1), (-1, 1)):
            if all(0 <= c < 4 for c in (mx-dx, my-dy, mx+dx, my+dy)):
                indices = [4*cy+cx for (cx, cy) in ((mx-dx, my-dy), (mx, my), (mx+dx, my+dy))]
                lines.append(tuple(indices))

for Fs in combinations(range(16), 5):
    for Xs in combinations(filter(lambda p: p not in Fs, range(16)), 5):
        grid = ['F' if i in Fs else 'X' if i in Xs else 'O' for i in range(16)]
        if not any((grid[line[0]], grid[line[1]], grid[line[2]]) == ('F', 'O', 'X') for line in lines):
            print("".join(grid))
This produces 255304 flattened winning grids:

FFFFFXXXXXOOOOOO
FFFFFXXXXOXOOOOO
FFFFFXXXXOOXOOOO
FFFFFXXXXOOOXOOO
FFFFFXXXXOOOOXOO
FFFFFXXXXOOOOOOX
FFFFFXXXOXXOOOOO
...
OOOOXXOOXXXFFFFF
OOOOXOXOXXXFFFFF
OOOOXOOXXXXFFFFF
OOOOOXXXOXXFFFFF
OOOOOXXOXXXFFFFF
OOOOOXOXXXXFFFFF
OOOOOOXXXXXFFFFF

"""

from itertools import combinations

lines = []
for mx in range(4):
    for my in range(4):
        for (dx, dy) in ((1, 0), (1, 1), (0, 1), (1, -1), (-1, 0), (-1, -1), (0, -1), (-1, 1)):
            if all(0 <= c < 4 for c in (mx-dx, my-dy, mx+dx, my+dy)):
                indices = [4*cy+cx for (cx, cy) in ((mx-dx, my-dy), (mx, my), (mx+dx, my+dy))]
                lines.append(tuple(indices))

for Fs in combinations(range(16), 5):
    for Xs in combinations(filter(lambda p: p not in Fs, range(16)), 5):
        grid = ['F' if i in Fs else 'X' if i in Xs else 'O' for i in range(16)]
        if not any((grid[line[0]], grid[line[1]], grid[line[2]]) == ('F', 'O', 'X') for line in lines):
            print("".join(grid))

