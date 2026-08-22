#!/usr/bin/env python3

r"""

Challenge
Given the formula of a chemical, output the Mr of the compound.

Equation
Each element in the compound is followed by a number that denotes the number of said atom in the compound. If there isn't a number, there is only one of that atom in the compound.

Some examples are:

Ethanol (C2H6O) would be C2H6O where there are two carbon atoms, 6 hydrogen atoms and 1 oxygen atom
Magnesium Hydroxide (MgO2H2) would be MgO2H2 where there is one magnesium atom, two oxygen atoms and two hydrogen atoms.
Note that you will never have to handle brackets and each element is included only once in the formula.

Whilst most people will probably stick to the order they feel most comfortable with, there is no strict ordering system. For example, water may be given as either H2O or OH2.

Mr
Note: Here, assume formula mass is the same as molecular mass

The Mr of a compound, the molecular mass, is the sum of the atomic weights of the atoms in the molecule.

The only elements and their atomic weights to 1 decimal place that you have to support (hydrogen to calcium, not including noble gases) are as follows. They can also be found here

H  - 1.0      Li - 6.9      Be - 9.0
B  - 10.8     C  - 12.0     N  - 14.0
O  - 16.0     F  - 19.0     Na - 23.0
Mg - 24.3     Al - 27.0     Si - 28.1
P  - 31.0     S  - 32.1     Cl - 35.5
K  - 39.1     Ca - 40.1
You should always give the output to one decimal place.

For example, ethanol (C2H6O) has an Mr of 46.0 as it is the sum of the atomic weights of the elements in it:

12.0 + 12.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 16.0
(2*C + 6*H + 1*O)
Input
A single string in the above format. You can guarantee that the elements included in the equation will be actual elemental symbols.

The given compound isn't guaranteed to exist in reality.

Output
The total Mr of the compound, to 1 decimal place.

Rules
Builtins which access element or chemical data are disallowed (sorry Mathematica)

Examples
Input > Output
CaCO3 > 100.1
H2SO4 > 98.1
SF6 > 146.1
C100H202O53 > 2250.0
Winning
Shortest code in bytes wins.

This post was adopted with permission from caird coinheringaahing. (Post now deleted)
https://codegolf.meta.stackexchange.com/questions/2140/sandbox-for-proposed-challenges#comment43964_12506

"""

import re

r"""

@Jonathan Allan

How?
Uses a regex to split the input, s, into the elements and their counts using:
re.findall("(\D[a-z]?)(\d*)",s)
\D matches exactly one non-digit and [a-z]? matches 0 or 1 lowercase letter, together matching elements. \d* matches 0 or more digits. The parentheses make these into two groups, and as such findall("...",s) returns a list of tuples of strings, [(element, number),...].

The number is simple to extract, the only thing to handle is that an empty string means 1, this is achieved with a logical or since Python strings are falsey: int(n or 1).

The element string is given a unique number by taking the product of its first and last character's ordinals (usually these are the same e.g. S or C, but we need to differentiate between Cl, C, Ca, and Na so we cannot just use one character).

These numbers are then hashed to cover a much smaller range of [0,18], found by a search of the modulo space resulting in %1135%98%19. For example "Cl" has ordinals 67 and 108, which multiply to give 7736, which, modulo 1135 is 426, which modulo 98 is 34, which modulo 19 is 15; this number is used to index into a list of integers - the 15th (0-indexed) value in the list:
[16,31,40.1,32.1,0,24.3,12,39.1,28.1,19,0,9,10.8,23,27,35.5,6.9,14,1]
is 35.5, the atomic weight of Cl, which is then multiplied by the number of such elements (as found above).

These products are then added together using sum(...).

"""

def mr(s):
    W = [16, 31, 40.1, 32.1, 0, 24.3, 12, 39.1, 28.1, 19,0, 9, 10.8, 23, 27, 35.5, 6.9, 14, 1]
    r = 0
    for x, n in re.findall("(\\D[a-z]?)(\\d*)", s):
        if n == "":
            n = "1"
        i = (ord(x[0]) * ord(x[-1])) % 1135 % 98 % 19
        r += W[i] * int(n)
    return r

def main():
    assert(mr("CaCO3") == 100.1)
    assert(mr("H2SO4") == 98.1)
    assert(mr("SF6") == 146.1)
    assert(mr("C100H202O53") == 2250.0)

main()
