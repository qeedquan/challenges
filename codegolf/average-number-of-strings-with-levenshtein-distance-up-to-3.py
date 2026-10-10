#!/usr/bin/env python3

"""

The Levenshtein distance between two strings is the minimum number of single character insertions, deletions, or substitutions to convert one string into the other one.
Given a binary string S of length n, we are a interested in the number of different strings of length n which have distance at most 3 from S.

For example, if S=0000 there are four strings with Levenshtein distance exactly 3 from S, six with distance exactly 2, four with distance exactly 1 and exactly one with distance 0.
This makes a total of 15 distinct strings with distance at most 3 from the string 0000.
The only string with distance greater than 3 is 1111.

However, this number depends on the value of S.
For example if S=0010 then the number of distinct strings with distance at most 3 is 16, in other words all of them.

For this task the input is a value of n≥3. Your code must output the average number of binary strings of length n which have Levenshtein distance at most 3 from a uniform and randomly sampled string S.
Your answer can be output in any standard way you choose but it must be exact.

Examples
n = 3. Average = 8
n = 4. Average = 15 1/2
n = 5. Average = 28 13/16
n = 6. Average = 50 15/16
n = 7. Average = 85 23/64
n = 8. Average = 135 27/32
n = 9. Average = 206 77/256
n = 10. Average = 300 181/256
n = 11. Average = 423 67/1024
n = 12. Average = 577 99/256
n = 13. Average = 767 2793/4096.
n = 14. Average = 997 3931/4096.
n = 15. Average = 1272 3711/16384.

Score
Your score is the highest value of n you can reach.

"""

from sympy import *

r"""

@Christian Sievers

The average number is the number of pairs of words of length n with Levenshtein distance up to three, divided by 2n.

It is not very difficult to construct an nondeterministic finite automaton over the alphabet of pairs of bits that accepts the word (a1,b1)(a2,b2)…(an,bn)
iff the binary words a1a2…an and b1b2…bn have Levenshtein distance up to three.

My version uses 14 states. This automaton can be transformed into a minimal deterministic one, which has 39 states.
From its transition function we can get a matrix that describes the number of ways we can get from one state to another.
Now counting the number of ways we can get from the initial state to some accepting state is just a matter of multiplication.

The implicit recurrance could be simplified because some values are always equal, and it might be solved to give a closed formula, but it seems to be good enough as is.

LoadPackage("automata");

nfa := Automaton("nondet", 14, 4,
     [[[1,5,9],[2,7,11],3,4,[5,13],[7,13],[7,14],14,
       [9,13],[11,13],[11,14],14,13,14],
      [[2,5,10],[3,7,12],4,0,[7,14],[5,14],0,7,
       [10,14],[12,14],12,0,14,0],
      [[2,6,9],[3,8,11],4,0,[6,14],[8,14],8,0,
       [11,14],[9,14],0,11,14,0],
      [[1,6,10],[2,8,12],3,4,[8,13],[6,13],14,[8,14],
       [12,13],[10,13],14,[12,14],13,14] ],
     [1], [1..14] );

dfa := MinimalizedAut(nfa);

size := NumberStatesOfAutomaton(dfa);;

mat := NullMat(size, size);;
for row in TransitionMatrixOfAutomaton(dfa) do
  for i in [1..size] do
    mat[i][row[i]] := mat[i][row[i]]+1;
  od;
od;

init := 0 * [1..size];;
init[InitialStatesOfAutomaton(dfa)[1]] := 1;;

fin := 0 * [1..size];;
for i in FinalStatesOfAutomaton(dfa) do
  fin[i] := 1;
od;

f := function(n)
  local res, intpart, fraction;
  res := init * mat^n * fin / 2^n;
  intpart := Int(res);
  fraction := res-intpart;
  Print("n = ", n, ". Average = ", intpart);
  if fraction <> 0 then
    Print(" ",fraction);
  fi;
  Print(".\n");
end;

Put it in a file, start gap and read the file with a command like Read("l3.gap");, then try something like f(20); or for i in [0..100] do f(i); od;.

All the eigenvalues of the matrix are integers (could I have known or expected that?), and I found this formula for n≥2:
f(n)=(40+6*n-4*n^2)/2^n-83/2+331/12*n-6*n^2+2/3*n^3

"""

def anoswlev3(n):
    r = Rational(40 + 6*n - 4*n**2, 2**n) - Rational(83, 2) + Rational(331, 12)*n - 6*n**2 + Rational(2, 3)*n**3
    x, y = fraction(r)
    return (x//y, x%y, y)

def main():
    assert(anoswlev3(3) == (8, 0, 1))
    assert(anoswlev3(4) == (15, 1, 2))
    assert(anoswlev3(5) == (28, 13, 16))
    assert(anoswlev3(6) == (50, 15, 16))
    assert(anoswlev3(7) == (85, 23, 64))
    assert(anoswlev3(8) == (135, 27, 32))
    assert(anoswlev3(9) == (206, 77, 256))
    assert(anoswlev3(10) == (300, 181, 256))
    assert(anoswlev3(11) == (423, 67, 1024))
    assert(anoswlev3(12) == (577, 99, 256))
    assert(anoswlev3(13) == (767, 2793, 4096))
    assert(anoswlev3(14) == (997, 3931, 4096))
    assert(anoswlev3(15) == (1272, 3711, 16384))

main()
