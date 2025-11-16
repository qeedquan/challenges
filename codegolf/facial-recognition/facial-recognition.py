#!/usr/bin/env python3

r"""

The aim of this task is to identify, clean up, and mark out all the faces in any given 'image'.

What's in a face?
A face will be a ZxZ square where Z is an odd integer greater than 1. The top left and right corners and the centre will be 'O' characters, and the bottom line will be a '\' and a '/' surrounding enough '_' characters to fill the rest of the line. Examples:

a 3x3 face:

O O
 O
\_/
a 5x5 face:

O   O

  O

\___/
a 7x7 face:

O     O


   O


\_____/
etc.

Input
Input will be on STDIN and will consist of a number of equal length strings of characters.

Output
Output should be the input with all recognizable faces cleared (i.e. all characters except the eyes, nose and mouth shoud be removed from within the face's bounds) and boxed (surrounded by +, -, and | characters). Where two or more faces overlap both should be cleared and boxed but priority should be given to the larger face (it should be placed on top); if both faces are the same size, the priority is left to the discretion of the implementer. If the input has no faces, output should be the same as input.

Some examples
Input:

*******
*******
**O*O**
***O***
**\_/**
*******
*******
Output:

*******
*+---+*
*|O O|*
*| O |*
*|\_/|*
*+---+*
*******
Input (incomplete face):

*******
*******
**O*O**
*******
**\_/**
*******
*******
Output:

*******
*******
**O*O**
*******
**\_/**
*******
*******
Input (nested faces):

*******
*O***O*
**O*O**
***O***
**\_/**
*\___/*
*******
Output:

+-----+
|O   O|
|     |
|  O  |
|     |
|\___/|
+-----+
Input (multiple faces):

~{$FJ*TBNFU*YBVEXGY%
FOCO$&N|>ZX}X_PZ<>}+
X$OOPN ^%£)LBU{JJKY%
@\_/$£!SXJ*)KM>>?VKH
SDY%£ILO(+{O:HO(UR$W
XVBFTER^&INLNLO*(&P:
>?LKPO)UJO$£^&L:}~{&
~@?}{)JKOINLM@~}P>OU
:@<L::@\___/GER%^*BI
@{PO{_):<>KNUYT*&G&^
Output:

+---+*TBNFU*YBVEXGY%
|O O|&N|>ZX}X_PZ<>}+
| O |N ^%£)LBU{JJKY%
|\_/|£+-----+M>>?VKH
+---+I|O   O|HO(UR$W
XVBFTE|     |LO*(&P:
>?LKPO|  O  |&L:}~{&
~@?}{)|     |@~}P>OU
:@<L::|\___/|ER%^*BI
@{PO{_+-----+YT*&G&^
Input (near boundary):

~{$FJ*TBNFU*YBVEXGY%
OCO$&N|>ZX}X_PZ<>}+^
$OOPN ^%£)LBU{JJKY%{
\_/$£!SXJ*)KM>>?VKHU
SDY%£ILO(+{8:HO(UR$W
XVBFTER^&INLNLO*(&P:
>?LKPO)UJ^$£^&L:}~{&
~@?}{)JKOINLM@~}P>OU
:@<L::@BJYT*GER%^*BI
@{PO{_):<>KNUYT*&G&^
Output:

---+J*TBNFU*YBVEXGY%
O O|&N|>ZX}X_PZ<>}+^
 O |N ^%£)LBU{JJKY%{
\_/|£!SXJ*)KM>>?VKHU
---+£ILO(+{8:HO(UR$W
XVBFTER^&INLNLO*(&P:
>?LKPO)UJ^$£^&L:}~{&
~@?}{)JKOINLM@~}P>OU
:@<L::@BJYT*GER%^*BI
@{PO{_):<>KNUYT*&G&^
Input (overlapping faces):

~{$FJ*TBNFU*YBVEXGY%
FXC£$&N|>ZX}X_PZ<>}+
X$*OPN O%£)LBO{JJKY%
@:U%$£!SXJ*)KM>>?VKH
SDY%£OLO(+{P:HO(UR$W
XVBFTER^&IOLNLO*(&P:
>?L\___/JR$£^&L:}~{&
~@?}{)JKOINLM@~}P>OU
:@<L::@\_____/R%^*BI
@{PO{_):<>KNUYT*&G&^
Output:

~{$FJ*TBNFU*YBVEXGY%
FX+---+-------+Z<>}+
X$|O  |O     O|JJKY%
@:|   |       |>?VKH
SD|  O|       |(UR$W
XV|   |   O   |*(&P:
>?|\__|       |:}~{&
~@+---|       |}P>OU
:@<L::|\_____/|%^*BI
@{PO{_+-------+*&G&^

"""

import fileinput, sys

# ported from @sgauria solution
matrix = [[c for c in l if c != "\n"] for l in fileinput.input()]

max_X = len(matrix[0])
max_Y = len(matrix)

tuples = []
for n in range(3, min(max_X, max_Y) + 1, 2):
    for x in range(max_X - n + 1):
        for y in range(max_Y - n + 1):
            # if is_face(matrix, x, y, n):
            if (
                matrix[y][x] == "O"
                and matrix[y][x + n - 1] == "O"
                and matrix[y + (n // 2)][x + (n // 2)] == "O"
                and matrix[y + n - 1][x] == "\\"
                and matrix[y + n - 1][x + n - 1] == "/"
                and "".join(matrix[y + n - 1][x + 1 : x + n - 1]) == "_" * (n - 2)
            ):
                tuples.append((x, y, n))

for x, y, n in tuples:
    # blank_and_border(matrix,x,y,n)
    def assign(dy, dx, c):
        xx = x + dx
        yy = y + dy
        if yy >= 0 and yy < len(matrix):
            if xx >= 0 and xx < len(matrix[y]):
                matrix[yy][xx] = c

    # blank
    for dy in range(n):
        for dx in range(n):
            assign(dy, dx, " ")

    # face
    assign(0, 0, "O")
    assign(0, n - 1, "O")
    assign(n // 2, n // 2, "O")
    assign(n - 1, 0, "\\")
    assign(n - 1, n - 1, "/")
    for w in range(1, n - 1):
        assign(n - 1, w, "_")

    # border
    for dy in [-1, n]:
        for dx in range(n):
            assign(dy, dx, "-")

    for dx in [-1, n]:
        for dy in range(n):
            assign(dy, dx, "|")

    assign(-1, -1, "+")
    assign(-1, n, "+")
    assign(n, -1, "+")
    assign(n, n, "+")

for l in matrix:
    for c in l:
        sys.stdout.write(c)
    print()

