#!/usr/bin/env python3

"""

The clustering coefficient of a graph (or network) is a:

measure of degree to which nodes in a graph tend to cluster together

The Wikipedia article gives a much better description of how network average clustering coefficient is calculated from local clustering coefficients than I could give.

https://en.wikipedia.org/wiki/Clustering_coefficient#Network_average_clustering_coefficient

The Challenge
Given an adjacency matrix a describing an undirected network (or graph) with no self loops, calculate it's network average clustering coefficient.

Details
You must write a program/function/procedure/code block which calculates the network average clustering coefficient for any undirected graph with no self loops.
The output may only contain the coefficient and nothing else.
You are to assume that your program (or whatever) has access to an adjacency matrix describing the graph through a variable/the stack/file/whatever
You may not use any inbuilt functionality your language may have to calculate clustering coefficients
Shortest code wins
Test Examples
Test inputs and outputs can be found in this pastebin

My solution: GNU Octave, 93 chars
(behind spoiler)

f=sum(a);c=0;for i=find(f>1)c+=sum(a(t=find(a(i,:)),t)(:))/(f(i)*(f(i)-1));endfor;c/length(a)
Which can be tested here, the matrix needs to be in the format a = [row ; row ; row ; ...]


"""

from itertools import *

def clavg(a, i, r):
    s = [b for b in r if a[i][b]]
    k = len(s)
    if k < 2:
        return 0
    return 2.0*sum(map(lambda x: a[x[0]][x[1]], combinations(s, 2)))/k/(k-1)

def clcoeff(a):
    n = len(a)
    r = range(n)
    return sum([clavg(a, i, r) for i in r]) / n

def test(a, r):
    x = clcoeff(a)
    print(x)
    assert(abs(x - r) < 1e-7)

def main():
    test([[1, 1, 1], [1, 1, 1], [1, 1, 1]], 1)
    
    test([[0, 1, 0, 0, 0, 1, 0, 0],
          [1, 0, 1, 1, 1, 0, 1, 0],
          [0, 1, 0, 0, 0, 1, 0, 0],
          [0, 1, 0, 0, 1, 0, 0, 0],
          [0, 1, 0, 1, 0, 1, 1, 0],
          [1, 0, 1, 0, 1, 0, 0, 1],
          [0, 1, 0, 0, 1, 0, 0, 1],
          [0, 0, 0, 0, 0, 1, 1, 0]], 0.233333333333)
    
    test([[0, 1, 0, 0, 1],
         [1, 0, 1, 0, 0],
         [0, 1, 0, 1, 0],
         [0, 0, 1, 0, 1],
         [1, 0, 0, 1, 0]], 0.0)

    test([[0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
          [1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1],
          [1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
          [1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1],
          [0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0],
          [1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1],
          [1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0],
          [1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
          [1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0],
          [0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0],
          [1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0],
          [0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0],
          [0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1],
          [0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0],
          [1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0],
          [0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1],
          [0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1],
          [0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0],
          [0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1],
          [1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0]], 0.389888167388)

    test([[0, 1, 1], [1, 0, 0], [1, 0, 0]], 0.0)

main()
