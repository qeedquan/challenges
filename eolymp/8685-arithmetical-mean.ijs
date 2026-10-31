NB. The sequence of integers is given. Find its arithmetical mean.
NB.
NB. Input
NB. In one line the integers are given, each of the numbers is no more than 100 by absolute value.
NB.
NB. Output
NB. Print the arithmetical mean of all elements in the sequence. Print the answer with 4 decimal digits.
NB.
NB. Examples
NB. Input #1
NB. 1 2 3 4 5
NB.
NB. Answer #1
NB. 3.0000
NB.
NB. Input #2
NB. 5 5 7 1 2 9
NB.
NB. Answer #2
NB. 4.8333

avg =: +/ % #

1!:2&2 avg (1 2 3 4 5)
1!:2&2 avg (5 5 7 1 2 9)
