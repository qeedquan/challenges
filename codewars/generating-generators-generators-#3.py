#!/usr/bin/env python3

"""

Generating Generators, you have had some experiences with generators now so you have decided to attempt something a little more interesting again to help your learning of times tables.

You want to create a generator, which yields generators, which yields strings.

Following from the Multiplication - Generators #2 kata you want to reuse your previous multiplication generator to yield the same tables as before but this time you want to yield multiplication tables within a range of numbers.

For example with an input of generate(1, 3) you must yield 3 separate generators each yielding 10 strings with the multiplication table.

generate(1, 3)

// generator 1
'1 x 1 = 1'
'1 x 2 = 2'
'1 x 3 = 3'
'1 x 4 = 4'
'1 x 5 = 5'
'1 x 6 = 6'
'1 x 7 = 7'
'1 x 8 = 8'
'1 x 9 = 9'
'1 x 10 = 10'

// generator 2
'2 x 1 = 2'
'2 x 2 = 4'
'2 x 3 = 6'
'2 x 4 = 8'
'2 x 5 = 10'
'2 x 6 = 12'
'2 x 7 = 14'
'2 x 8 = 16'
'2 x 9 = 18'
'2 x 10 = 20'

// generator 3
'3 x 1 = 3'
'3 x 2 = 6'
'3 x 3 = 9'
'3 x 4 = 12'
'3 x 5 = 15'
'3 x 6 = 18'
'3 x 7 = 21'
'3 x 8 = 24'
'3 x 9 = 27'
'3 x 10 = 30'

"""

def table(x):
    for y in range(1, 11):
        yield "%d x %d = %d" % (x, y, x * y)

def generate(a, b):
    return [table(i) for i in range(a, b + 1)]

def main():
    g = generate(1, 3)
    for f in g:
        for i in f:
            print(i)
        print()

main()
