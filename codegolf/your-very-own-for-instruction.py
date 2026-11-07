#!/usr/bin/env python3

r"""

Your very own "for" instruction
Assuming you have the following input : a, b, c, d

Input can be in one-line using any format "a/b/c/d" or "a,b,c,d" etc..

You can also have 4 inputs.

You must code the following behaviour (pseudo-code here) :

var i = <a>
while (i <b> <c>)
    print i
    i = i + <d>
    print "\n"
Here are some tests cases :

input : 1,<,10,1
output :
1
2
3
4
5
6
7
8
9
One more :

input : 20,>,10,1
output :
20
21
22
23
24
25
26
27
...
infinite loop / program crashes
a is an integer, the initial value of i.

b is a string or a char, it can't be something else, the comparator used in the ending condition of the for loop.

b can and must be one of the following strings :

- ">"
- "<"
c is an integer, the number used in the ending condition of the for loop.

d is an integer that is added to i at every loop.

This is code-golf, the shortest answer wins !

"""

def xfor(a, b, c, d):
    s = "i = <a>\nwhile i <b> <c>: print(i); i += <d>"
    s = s.replace("<a>", str(a))
    s = s.replace("<b>", b)
    s = s.replace("<c>", str(c))
    s = s.replace("<d>", str(d))
    exec(s)

def main():
    xfor(1, '<', 10, 1)
    xfor(20, '>', 10, -1)

main()
