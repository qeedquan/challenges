#!/usr/bin/env python3

"""

Related:
https://codegolf.stackexchange.com/questions/25378/regex-in-reverse-decompose-regular-expressions?rq=1

For this challenge, we'll be using a simplified dialect of regular expressions, where:

A lowercase letter from a to z matches itself.
(expr1|expr2) matches either of expr1 and expr2. You will not have to handle more than two operands, and you can assume there will always be parentheses around this. Instead of (a|b|c) you'll recieve ((a|b)|c).
(expr)* matches zero or more copies of expr. You can assume there will always be parentheses around the expression, i.e. you'll recieve (a)* and not a*.
(expr)? matches either nothing or expr. You can assume there will always be parentheses around the expression, i.e. you'll recieve (a)? and not a?.
expr1expr2 matches expr1 followed by expr2. If taking an AST (see below) you may assume concatenation will always have exactly two arguments i.e. ["concat", ["concat",["a","b"]],"c"] to represent abc rather than ["concat",["a","b","c"]].
You may instead take the expression as some sort of AST. For example, this would be an acceptable format for the regex (be)*((a)?|((c|d))*), but you can use any reasonable format as long as it doesn't contain any information not present in the original regex. You may assume the expression and all subexpressions are nonempty - ()*, (a|), ()? and similar will never occur in the input. You can also assume there will be no redundant parentheses - ((a)), (a)b and similar will never occur.

Your challenge is to, given a simplified regex in this format, output all finite strings that the regex matches. However, there will be (countably) infinitely many strings that are matched, and every single one of them must appear at some finite index in the output. You can assume the regex will have infinitely many potential matches, and your output may contain duplicate strings so long as every string eventually appears.

For example, given (a)*(b)*, your output should contain all strings consisting of zero or more as followed by zero or more bs. Given this regex, outputting , a, aa, aaa, aaaa, aaaaa... (note the empty string) would not be allowed as this output would never include any string containing one or more bs. Outputting , a, b, aa, ab, bb, aaa, aab, abb, bbb, aaaa, aaab, aabb, abbb, bbbb..., however, using Cantor diagonalization to enumerate all possibilities, is fine as it will eventually output every string.

Standard sequence output rules apply - you may output all matches infinitely, or take an 0/1-indexed n and output the nth / first n terms. If you output multiple strings, they should be output either as an array or separated by some consistent non-alphabetic delimiter. This is code-golf, shortest wins!

Testcases
These are potential sequences of the first 20 terms for the given regex. It's fine if your solution outputs a different sequence as long as it eventually outputs everything.

a(b)* -> a, ab, abb, abbb, abbbb, abbbbb, abbbbbb, abbbbbbb, abbbbbbbb, abbbbbbbbb, abbbbbbbbbb, abbbbbbbbbbb, abbbbbbbbbbbb, abbbbbbbbbbbbb, abbbbbbbbbbbbbb, abbbbbbbbbbbbbbb, abbbbbbbbbbbbbbbb, abbbbbbbbbbbbbbbbb, abbbbbbbbbbbbbbbbbb, abbbbbbbbbbbbbbbbbbb
(a)*(b)* -> , b, a, bb, ab, aa, bbb, abb, aab, aaa, bbbb, abbb, aabb, aaab, aaaa, bbbbb, abbbb, aabbb, aaabb, aaaab
(a)*(c)?(b)*d -> d, cd, bd, cbd, ad, acd, bbd, cbbd, abd, acbd, aad, aacd, bbbd, bbbcd, abbd, acbbd, aabd, aacbd, aaad, aaacd
((a|b))* -> , a , b , aa , ab , ba , bb , aaa , aab , aba , abb , baa , bab , bba , bbb , aaaa , aaab , aaba , aabb , abaa
(a(a)*b)* -> , ab, aab, aaab, abab, aaaab, aabab, abaab, aaaaab, aaabab, aabaab, abaaab, ababab, aaaaaab, aaaabab, aaabaab, aabaaab, abaaaab, aababab, abaabab
(a)*(a)* -> , a, aa, aaa, aaaa, aaaaa, aaaaaa, aaaaaaa, aaaaaaaa, aaaaaaaaa, aaaaaaaaaa, aaaaaaaaaaa, aaaaaaaaaaaa, aaaaaaaaaaaaa, aaaaaaaaaaaaaa, aaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaaaaa
((a)*)* -> , a, aa, aaa, aaaa, aaaaa, aaaaaa, aaaaaaa, aaaaaaaa, aaaaaaaaa, aaaaaaaaaa, aaaaaaaaaaa, aaaaaaaaaaaa, aaaaaaaaaaaaa, aaaaaaaaaaaaaa, aaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaaaa, aaaaaaaaaaaaaaaaaaa
(((a)?|b))* -> , a , b , aa , ab , ba , bb , aaa , aab , aba , abb , baa , bab , bba , bbb , aaaa , aaab , aaba , aabb , abaa
(a(b)?c)* ->  , ac , abc , acac , acabc , abcac , abcabc , acacac , acacabc , acabcac , acabcabc , abcacac , abcacabc , abcabcac , abcabcabc , acacacac , acacacabc , acacabcac , acacabcabc , acabcacac
((ab|cd))* ->  , ab , cd , abab , abcd , cdab , cdcd , ababab , ababcd , abcdab , abcdcd , cdabab , cdabcd , cdcdab , cdcdcd , abababab , abababcd , ababcdab , ababcdcd , abcdabab

"""

"""

Ported from @Bubbler solution

I guess we need at least one answer that solves the problem from scratch, so here is one. The regex is input as an AST in the following form:

(A|B) -> (ALT, [A, B])
ABC.. -> (SEQ, [A, B, C, ..])
(A)*  -> (STAR, A)
(A)?  -> (OPT, A)
a     -> 'a'
where ALT, SEQ, STAR, and OPT are integer constants.

The lambda at the top takes a regex and a 0-based index, and outputs a generated string.

The index i is treated as a stream of bits (which ends with infinitely many zeros), and all decisions are made in binary fashion:

Given an atom, simply return that.
Given an alteration (A|B), consume one bit and choose to generate from either A or B.
Given a sequence ABC.., consume some bits to generate from A, next bits for B, and so on.
Given a star (A)*, consume one bit. If it is zero, stop. Otherwise, consume some bits to generate from A and return to the beginning. This always terminates because there are only finitely many one bits in i.
Given (A)?, proceed similarly to (A)* but stop after the first iteration.
This solves the challenge because every finite matching string has a path that generates it, which can be encoded in a finite number of bits. It is explicitly allowed to output the same string multiple times, and this solution actually outputs the same string infinitely many times (since the bits other than the part used to encode the output can be anything).

The way of passing around the remaining bits of i is similar to passing remaining buffer in recursive descent parsing.

"""
def f(r, i):
    return g(r, i)[0]

def g(r, i, s=""):
    try:
        c, k = r
        j = i // 2
        if c > 2:
            R = g(k[i % 2], j)
        elif c > 1:
            for r in k:
                S, i = g(r, i)
                s += S
            R = s, i
        else:
            while i % 2:
                S, i = g(k, j)
                s += S
                j = i // 2
                i *= c
            R = s, j
    except:
        R = r, i
    return R

def atom(s):
    if 'a' <= s[0] <= 'z': ret = (s[0], s[1:]) # parse single char
    else:
        alt, rest = alteration(s[1:]) # discard '(' and parse alteration
        ret = (alt, rest[1:]) # discard ')'
    return ret

def alteration(s):
    l = []
    seq, rest = sequence(s) # parse first option
    l.append(seq)
    while rest and rest[0] == '|':
        seq, rest = sequence(rest[1:]) # parse next option
        l.append(seq)
    if len(l) == 1: ret = (l[0], rest)
    else: ret = ((ALT, l), rest)
    return ret

def sequence(s):
    l = []
    star, rest = kleene_star(s) # parse first item
    l.append(star)
    while rest and rest[0] not in '|)':
        star, rest = kleene_star(rest) # parse next item
        l.append(star)
    if len(l) == 1: ret = (l[0], rest)
    else: ret = ((SEQ, l), rest)
    return ret

def kleene_star(s):
    atm, rest = atom(s)
    while rest and rest[0] in '*?':
        atm = (STAR if rest[0] == '*' else OPT, atm)
        rest = rest[1:]
    ret = (atm, rest)
    return ret

ALT = 3
SEQ = 2
STAR = 1
OPT = 0
parse = alteration

testcases = ['a(b)*', '(a)*(b)*', '(a)*(c)?(b)*d', '((a|b))*', '(a(a)*b)*', '(a)*(a)*', '((a)*)*', '(((a)?|b))*', '(a(b)?c)*']
for tc in testcases:
    ast = parse(tc)[0]
    print(','.join(f(ast, i) for i in range(256)))

