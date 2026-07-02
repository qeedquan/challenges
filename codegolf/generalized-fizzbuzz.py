#!/usr/bin/env python3

"""

Task
FizzBuzz, but instead of 3 and 5, you'll take the numbers and corresponding strings as input.

You can assume all inputted numbers are coprime (and ≥2).
You'll receive one or more numbers, and a string to print with each of them.
The normal FizzBuzz would be something like [[3, "Fizz"], [5, "Buzz"]], but you could also receive something like [[2, "Quux"]] or [[2, "a"], [5, "b"], [7, "c"], [33, "d"], [529, "e"]].

For output, you'll have two options:

Print this modified FizzBuzz infinitely
Take a number as input, and return the first n lines
You must return output with newline separators. An array of lines is not acceptable.

Details
To clarify exactly what this should look like, this is the process to determine what the nth line should look like (first line is always 1):

For each of the inputted numbers n is divisble by, append the corresponding string to the output (for example, 15 would result in "Fizz" + "Buzz" = "FizzBuzz" for normal FizzBuzz)
If n is not divisble by any of the numbers (i.e., the line is still empty), default to n
For example, the first 100 lines of the sample input [[4, "Foo"], [7, "Bar"], [9, "Baz"]] are:

1
2
3
Foo
5
6
Bar
Foo
Baz
10
11
Foo
13
Bar
15
Foo
17
Baz
19
Foo
Bar
22
23
Foo
25
26
Baz
FooBar
29
30
31
Foo
33
34
Bar
FooBaz
37
38
39
Foo
41
Bar
43
Foo
Baz
46
47
Foo
Bar
50
51
Foo
53
Baz
55
FooBar
57
58
59
Foo
61
62
BarBaz
Foo
65
66
67
Foo
69
Bar
71
FooBaz
73
74
75
Foo
Bar
78
79
Foo
Baz
82
83
FooBar
85
86
87
Foo
89
Baz
Bar
Foo
93
94
95
Foo
97
Bar
Baz
Foo

I/O
You can take input in any reasonable format. This includes dicts of numbers and their strings, a single list of pairs (like in the examples), two lists (one with numbers and ones with pairs), or similar.

For instances where there's two strings being appended, such as FooBar in the example above, any order is acceptable (BarFoo is also fine).

Other
This is code-golf, so shortest answer in bytes (per language) wins!

"""

def gen(n, d):
    for i in range(1, n + 1):
        f = 0
        for m, s in d:
            if i%m == 0:
                print(s, end='')
                f += 1
        
        if f == 0:
            print(i, end='')
        
        print()

def main():
    gen(100, [[4, "Foo"], [7, "Bar"], [9, "Baz"]])

main()
