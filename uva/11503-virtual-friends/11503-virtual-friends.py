#!/usr/bin/env python3

from scipy.cluster.hierarchy import DisjointSet

def add(uf, names, person):
    if person not in names:
        names[person] = True
        uf.add(person)

def solve(friends):
    uf = DisjointSet()
    names = {}
    for person0, person1 in friends:
        add(uf, names, person0)
        add(uf, names, person1)
        uf.merge(person0, person1)
        print(uf.subset_size(person0))

def main():
    solve([["Fred", "Barney"], ["Barney", "Betty"], ["Betty", "Wilma"]])

main()

