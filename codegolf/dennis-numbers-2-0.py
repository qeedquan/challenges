#!/usr/bin/env python3

"""

PPCG user and elected mod, @Dennis just became the second ever user to earn over 100k rep!

https://i.sstatic.net/5ME5N.png

This is a totally original idea, that I did not get from anybody else, but let's make a challenge based off of his user ID, 12012 as a tribute!

Looking at it, you'll notice that there are two distinct "sections" to his ID.

12

and

012

Both of these sections add up to a 3. That's a pretty interesting property.

Let's define a "Dennis 2.0 number" as any positive integer where every maximal subsequence of strictly increasing digits sums to the same number. For example,

123
is a Dennis 2.0 number because there is only one maximal sublist of strictly increasing digits, and it sums to 6. Additionally, 2,846,145 is also a Dennis 2.0 number because the three maximal sublists of increasing digits, namely

28
46
145
All sum to 10. Additionally, numbers that just repeat the same digit must be Dennis 2.0 numbers because, for example, 777 can be broken down into

7
7
7
which clearly all sum to seven.

A number such as 42 is not a Dennis 2.0 number, since it is broken down into

4
2
which clearly do not sum to the same number.

The challenge
You must write a program or function to determine if a given number is a Dennis 2.0 number or not. You can take input and output in any reasonable input format, e.g. as a string, as a number, from a file, funtion arguments/return, from STDIN/STDOUT, etc. and then return a truthy value if this number is a Dennis 2.0 number, and a falsy value if it is not. For reference, here is every Dennis 2.0 number up to 1,000:

1
2
3
4
5
6
7
8
9
11
12
13
14
15
16
17
18
19
22
23
24
25
26
27
28
29
33
34
35
36
37
38
39
44
45
46
47
48
49
55
56
57
58
59
66
67
68
69
77
78
79
88
89
99
101
111
123
124
125
126
127
128
129
134
135
136
137
138
139
145
146
147
148
149
156
157
158
159
167
168
169
178
179
189
202
222
234
235
236
237
238
239
245
246
247
248
249
256
257
258
259
267
268
269
278
279
289
303
312
333
345
346
347
348
349
356
357
358
359
367
368
369
378
379
389
404
413
444
456
457
458
459
467
468
469
478
479
489
505
514
523
555
567
568
569
578
579
589
606
615
624
666
678
679
689
707
716
725
734
777
789
808
817
826
835
888
909
918
927
936
945
999

Standard loopholes apply, and the shortest answer measured in bytes wins!

"""

"""

@Dennis

How it works
We initialize r to the string 0 and iterate over all digits d in the input.

If d is larger than the first digit of r (initially 0, then equal to the previous value of d), r<d evaluates to True and '=+'[r<d]*2 yields ++.

If d is smaller than the first digit of r, '=+'[r<d]*2 yields ==.

If d is equal to the first digit of r, r will be longer than the singleton string d, so '=+'[r<d]*2 yields once again ==.

In all cases, the digit d and the two generated characters get prepended to r.

Once all input digits have been processed, eval(r) evaluates the generated expression.

If the input consists of a single strictly increasing sequence of (positive) digits, the expression evaluates to their sum.

For example, the integer 12345 results in the expression 5++4++3++2++1++0, which yields 15 when evaluated. Note that each second + is a unary plus, so it doesn't affect the result. Dividing 1 by 15 is valid (the result is not important); the program exits normally.

If the input consists of two strictly increasing sequences of digits, the expression consists of a simple comparison.

For example, the integer 12012 results in the expression 2++1++0==2++1++0, which yields True when evaluated since both terms have sum 3. Dividing 1 by True (1) is valid (the result is not important); the program exits normally.

On the other hand, the integer 12366 results in the expression 6==6++3++2++1++0, which yields False when evaluated since the terms have sums 6 and 12. Dividing 1 by False (0) raises a ZeroDivisionError; the program exits with an error.

If the input consists of three or more strictly increasing sequences of digits, the expression consists of a chained comparison, which returns True if and only if all involved comparisons return True.

For example, the integer 94536 results in the expression 6++3==5++4==9++0, which yields True when evaluated since all terms have sum 9. As before, the program exits normally.

On the other hand, the integer 17263 results in the expression 3==6++2==7++1++0, which yields False when evaluated since the terms have sums 3, 8, and 8. As before, the program exits with an error.

"""

def isdennis(n):
    sym = "=+"
    r = "0"
    s = str(n)
    for d in s:
        i = r < d
        r = d + sym[i]*2 + r
    return eval(r) != 0

def main():
    for i in range(1001):
        if isdennis(i):
            print(i)

main()
