#!/usr/bin/env python3

r"""

Consider such a language using only ( and ):

Name := () | Name () ; Variable name
Expr := (Name)       ; Get the value of variable
      | (Expr Expr)  ; Call expr1(a function) with expr2 as arg
      | (Name Expr)  ; Define a function with argname and definition
Given the code length, output the amount of valid expressions of exactly that length. You can assume given length is positive and even. You may also choose to take input divided by 2.

Expressions with free variables (e.g. (()), or x1) or with reused name (e.g. (()(()(()))), or x1=>(x1=>x1)) are valid.

Test cases:

2 => 0
4 => 1 (())
6 => 1 (()())
8 => 2 (()()()) (()(()))
Shortest code in each language wins.

Accepted answer will go to an answer in this language. Since there's no IO in this language, you'd need to answer as a function.

A converter from this language to JavaScript is provided here.
x = `(()(()()((())(()()))))`.slice(1,-1);
y = x.replace(/(?:\(\))+/g, 'x');
while (y != (y = y.replace(/\(xe?\)|\(ee\)/g, 'e')));
if (y != 'e') console.log('syntax error'); else
console.log(x.replace(/(?:\(\))+/g, x=>'x'+x.length/2)
	.replace(/\d(?=\()/g, '$&=>'));

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def count(n):
    if n < 3:
        return 0

    r = 1
    for i in range(2, n, 2):
        r += (count(i) + 1) * count(n - i - 2)
    return r

def main():
    assert(count(2) == 0)
    assert(count(4) == 1)
    assert(count(6) == 1)
    assert(count(8) == 2)

main()

