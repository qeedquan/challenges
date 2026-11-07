NB. Find the sum of the digits of a given two-digit integer.
NB.
NB. Input
NB. A single line contains a two-digit integer n.
NB.
NB. Output
NB. Output the sum of the digits of n in a single line.
NB.
NB. Examples
NB. Input #1
NB. 23
NB. Answer #1
NB. 5

digsum =: +/@(10&#.inv)

