{-

https://static.e-olymp.com/content/bd/bd5d3f32b730edaf7636c3febf8052d5647cb024.gif

You need to determine if a rook, positioned on a cell with specific coordinates (row and column numbers), can attack another piece located on a different cell.

Input
You will be given four numbers: the coordinates of the rook (two numbers) and the coordinates of the other piece (two numbers).
Each number is provided on a separate line.

Vasya, the boy who created this puzzle, hasn't learned chess notation yet.
Therefore, he describes the positions of the pieces using his own system,
which resembles the way points are positioned in the 1st quadrant of a coordinate plane rather than traditional chess notation.

Output
Print "YES" if the rook can attack the piece; otherwise, print "NO".

Examples

Input #1
1
1
1
2

Answer #1
YES

Input #2
4
4
3
3

Answer #2
NO

-}

solve :: Int -> Int -> Int -> Int -> (String)
solve a b c d
    | a == c || b == d = "YES"
    | otherwise        = "NO"
