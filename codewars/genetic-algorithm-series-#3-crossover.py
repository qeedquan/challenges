#!/usr/bin/env python3

"""

In genetic algorithms, crossover is a genetic operator used to vary the programming of chromosomes from one generation to the next.

The one-point crossover consists in swapping one's cromosome part with another in a specific given point. The image bellow shows the crossover being applied on chromosomes 1011011001111 and 1011100100110 with the cut point (index) 4:

http://i.imgur.com/nZ4hgnS.gif

In this kata you have to implement a function crossover that receives two chromosomes chromosome1, chromosome2 and a zero-based index and it has to return an array with the crossover result on both chromosomes [chromosome1, chromosome2].

Example:
crossover('111000', '000110', 3) should return ['111110', 000000']

"""

def crossover(chromosome1, chromosome2, index):
    return [chromosome1[:index] + chromosome2[index:], chromosome2[:index] + chromosome1[index:]]

def main():
    assert(crossover('111000', '000110', 3) == ['111110', '000000'])

main()
