#!/usr/bin/env python3

"""

From Wikipedia Set-theoretic definition of natural numbers

The set N of natural numbers is defined as the smallest set containing 0 and closed under the successor function S defined by S(n) = n ∪ {n}.

The first few numbers defined this way are 0 = {}, 1 = {0} = {{}}, 2 = {0,1} = {{},{{}}}, 3 = {0,1,2} = {{},{{}},{{},{{}}}}.

Using this definition of natural numbers count the length of a string.

Input a string of characters from a-zA-Z of any length

Output the length of the string in set notation without separators

Examples

Input Empty string

Output {}

Input a

Output {{}}

Input aaaa

Output {{}{{}}{{}{{}}}{{}{{}}{{}{{}}}}}

For readability output for 'aaaa' with separators is

{
    {}
    {{}}
    {{} {{}} }
    {{}   {{}}   {{} {{} } }   }
}
Conditions

No digits 0 to 9 to appear in the code;
No use of character code conversion to generate numbers;
No use of +-*/ for arithmetic calculations including increment and decrement;
No mathematical operations other than Boolean Logic;
Input string does not count in determining byte length;
Winner Shortest code length in bytes.

As this is my first question I hope I have made it clear and rigorous enough. Friendly advice accepted.

"""

def build(s):
    r = ['{}']
    for _ in s:
        r += ['{'+ ''.join(r) + '}']
    return r.pop()

def main():
    assert(build("") == "{}")
    assert(build("a") == "{{}}")
    assert(build("aaaa") == "{{}{{}}{{}{{}}}{{}{{}}{{}{{}}}}}")

main()
