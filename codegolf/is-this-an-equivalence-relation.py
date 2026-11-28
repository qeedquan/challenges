#!/usr/bin/env python3

"""

Given a relation, and a domain, output whether the relation is an equivalence relation.

Context
For this challenge, a relation is defined as being a set of ordered pairs that is a subset of the cartesian product of a domain with itself.
That is, R⊂X×X.

For a relation R to be an equivalence relation on domain X, it needs to be: a) reflexive, b) symmetric and c) transitive.

If a relation is reflexive, for all items in the relation's domain, the item paired with itself is in the relation. That is:

∀a∈X:(a,a)∈R

or as one might write in Python:

all([(a, a) in R for a in X])
If a relation is symmetric, for all pairs of items in the relation, the reverse of the pair is also in the relation. That is:

∀a,b∈X:(a,b)∈R⟹(b,a)∈R
 

or as one might write in Python:

all([(y, x) in R for x in X for y in X if (x, y) in R])
If a relation is transitive, for all items a, b and c in the relation's domain, (a, b) being in the relation and (b, c) being in the relation means that (a, c) is in the relation. That is:

∀a,b,c∈X:(a,b)∈R∧(b,c)∈R⟹(a,c)∈R
 

or as one might write in Python:

all([(x, z) in R for x in X for y in X for z in X if (x, y) in R and (y, z) in R])
Worked Example
Let the domain of the relation be 1,2,3,4 and the relation be  (1,1),(2,2),(3,3),(4,4),(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)
 

The relation is reflexive, as (1,1), (2,2), (3,3) and (4,4) are all in the relation.

The relation is symmetric, as (1,2) and (2,1) are in the relation, as are (1,3) and (3,1). As are (2,3) and (3,2).

The relation is transitive, as (1,2), (2,3), and  (1,3) are in the relation.

Therefore, the relation is an equivalence relation.

Rules
The domain can be taken as a list of arbitrary objects (e.g. numbers, strings, a mix of numbers and strings) or any similar format. You do not need to take the domain if you take the relation as an adjacency matrix
The relation can be taken as a list of ordered pairs/tuples, as an adjacency matrix or any other reasonable format. It can not be taken as a function object though.
The domain will not be empty. That is, it will not be ∅ / {}
The relation will not be empty. That is, it will not be  ∅ / {}.
Default decision-problem output rules apply
Tests
Assuming the domain is given as a list of integers and that the relation is given as a list of lists

Domain, Relation => Equivalence?
[1, 2, 3, 4], [[1, 1], [2, 2], [3, 3], [4, 4]] => 1
[1, 2, 3, 4], [[1, 1], [2, 2], [3, 3], [4, 4], [1, 2], [2, 1], [1, 3], [3, 1], [2, 3], [3, 2]] => 1
[1, 2, 3, 4], [[1, 2], [2, 1], [3, 3]] => 0
[3, 4, 5], [[3, 4], [3, 5], [4, 5]] => 0
[1, 2, 3, 4, 5], [[1, 2], [1, 3], [1, 4], [1, 5], [2, 1], [2, 3], [2, 4], [2, 5], [3, 1], [3, 2], [3, 4], [3, 5], [4, 1], [4, 2], [4, 3], [4, 5], [5, 1], [5, 2], [5, 3], [5, 4]] => 0
[1, 2, 3], [[1, 1]] => 0
[1, 2, 3], [[1, 2], [2, 3], [3, 3]] => 0
[1, 2, 3], [[1, 1], [1, 2], [2, 2], [2, 3], [3, 1], [3, 3]] => 0
[1, 2], [[1, 2], [2, 2]] => 0
This is code golf, so aim to get your programs as short as possible.

"""

import numpy as np


"""

Ported from @loopy walt solution

Expects adjacency matrix.

How?
First note that arithmetic is boolean, so 1+1=1.

The test can only be satisfied if

there is no empty column
M is symmetric (M=M^T)
M is idempotent (M^2=M)
together these imply

the diagonal of M is set
4 corresponds to "reflexive", 3 to "transitive" and 2 to "symmetric"

"""

def equivalent(M):
    return (M ^ (M.T @ M) < M.any(axis=0)).all()

def adjacency(relation):
    (vertices, edges) = eval(relation)
    _, inverse = np.unique(edges, return_inverse=True)
    indices = inverse.reshape(len(edges), -1)
    adjacency = np.zeros((len(vertices), len(vertices)), dtype=bool)
    np.add.at(adjacency, tuple(indices.T), 1)
    return adjacency

def solve(relation):
    return equivalent(adjacency(relation))

def main():
    assert(solve("[1, 2, 3, 4], [[1, 1], [2, 2], [3, 3], [4, 4]]") == True)
    assert(solve("[1, 2, 3, 4], [[1, 1], [2, 2], [3, 3], [4, 4], [1, 2], [2, 1], [1, 3], [3, 1], [2, 3], [3, 2]]") == True)
    assert(solve("[1, 2, 3, 4], [[1, 2], [2, 1], [3, 3]]") == False)
    assert(solve("[3, 4, 5], [[3, 4], [3, 5], [4, 5]]") == False)
    assert(solve("[1, 2, 3, 4, 5], [[1, 2], [1, 3], [1, 4], [1, 5], [2, 1], [2, 3], [2, 4], [2, 5], [3, 1], [3, 2], [3, 4], [3, 5], [4, 1], [4, 2], [4, 3], [4, 5], [5, 1], [5, 2], [5, 3], [5, 4]]") == False)
    assert(solve("[1, 2, 3], [[1, 1]]") == False)
    assert(solve("[1, 2, 3], [[1, 2], [2, 3], [3, 3]]") == False)
    assert(solve("[1, 2, 3], [[1, 1], [1, 2], [2, 2], [2, 3], [3, 1], [3, 3]]") == False)
    assert(solve("[1, 2], [[1, 2], [2, 2]]") == False)

main()
