#!/usr/bin/env python3

"""

To quote http://brainfuck.org/utm.b:

A tag-system transforms strings over an alphabet A = {a[1], a[2], ... a[n], a[n+1]} as follows: a positive integer m is chosen, and so is a function P that maps each a[i] for 1<=i<=n to a string P(a[i]) over the alphabet A. Now:

1. if the string being transformed has fewer than m elements, the whole process stops now.
2. m elements are removed from the beginning of the string
3. Call the first element removed a[k]; if k=n+1 the whole process stops now.
4. P(a[k]) is appended to the string.
5. steps 1-5 are repeated.

A more extensive definition is at https://en.wikipedia.org/wiki/Tag_system.

We will call a[n + 1] the "Halting symbol". Alphabet symbols (symbols in a) are ASCII alphanumeric chars.

2-tag systems are those where m=2.

The simulator should take two inputs.

A definition for P, which doubles as a definition for the alphabet. The definition format is given below.
An "initial word" to be transformed.
If it halts, it should output the "halting word", the word that is shorter then 2 alphabet symbols long or which has the halting symbol in its front.

IO
If possible, the input should be read from stdin or passed to a function in the following format (Or something equivalent).

symbol:listofsymbols symbol:listofsymbols symbol:listofsymbols [and so on]
initialword

The listofsymbols may be assumed to contain only valid symbols. Any symbol that is not explicitly defined should be treated as the halting symbol.

The test cases (from Wikipedia) are:
input:
  a:bc b:a c:aaa
  aaaa
output:
  a

input:
  a:ccbaH b:cca c:cc
  baa
output:
  Hcccccca

#This test case uses H as the halting symbol, but it might as well be using any alphanumeric ASCII char other than the defined a, b, and c.
Example implementation in Nim:
import tables, strutils
proc runTag(P: Table[char, string], inputstr: string): string =
  var haltingword: string;
  var str = inputstr
  while true:
    haltingword = str
    if str.len() < 2:
      break
    var cur = str[0]
    str.delete(0..1)
    if not P.hasKey(cur):
      break
    str.add(P[cur])
  return haltingword


var ruleinput = readLine(stdin).split(' ')
var rules: Table[char, string]
for i in ruleinput:
  var pair = i.split(':')
  rules[pair[0][0]] = pair[1]
var str = readLine(stdin)

echo runTag(P=rules, inputstr=str)

"""

def tag(initial, rules, step=2):
    text = initial
    while len(text) >= step:
        if text[0] not in rules:
            break
        text = text[step:] + rules[text[0]]
    return text

def main():
    assert(tag("aaaa", {"a": "bc", "b": "a", "c": "aaa"}) == "a")
    assert(tag("baa", {"a": "ccbaH", "b": "cca", "c": "cc"}) == "Hcccccca")

main()
