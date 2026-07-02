#!/usr/bin/env python3

"""

Rust's borrow checker enforces the requirement of "mutability XOR aliasing": a piece of data can either have multiple immutable references or a single mutable reference. This challenge revolves around implementing an extremely simplified version of this aspect of the borrow checker.

Task: given a list of immutable and mutable references to variables, determine whether the mutability XOR aliasing requirement is violated, or in other words, whether mutable aliasing occurs. Mutable aliasing occurs when a variable has two or more references, at least one of which is mutable.

Consider [&c, &mut g, &c, &c], where &x denotes an immutable reference to x and &mut x denotes a mutable reference to x. This list does not exhibit mutable aliasing -- c only has immutable references, and g only has a single, mutable reference.
On the other hand, [&c, &mut g, &mut c, &c] does have mutable aliasing, since c has multiple references, one of which is mutable.

This is code-golf -- shortest solution in each language wins.

I/O format
To increase golfing possibilities, input lists will have a maximum length of 7, and you are only required to support a pool of 7 distinct variables a, b, c, d, e, f, g.

Input and output can be in any reasonable format, including but not limited to:

taking a list of (<variable name>, <is mutable>) tuples as a function argument, and returning a truthy/falsy value representing whether mutable aliasing is present or absent;
taking a list of integers in [0..14), each representing one of the 14 possible values for references (7 variables * 2 types of references), and returning 0 or 1;
taking a space-separated list of references formatted as &x and &mut x from STDIN, and printing present or absent to STDOUT.
There's a relatively large gray area in terms of what I/O formats count as "reasonable", but the intent here is to be highly permissive. If you're not sure whether an I/O format counts as "reasonable", you're welcome to discuss it in the comments and/or include multiple variations of the same approach in your answer: longer ones with more standard I/O formats alongside golfed-down versions with less reasonable I/O formats.

Please indicate the I/O format of your solution(s) in your answer.

Test cases
[] => absent
[&a] => absent
[&mut a] => absent
[&b, &b] => absent
[&mut b, &b] => present (b)
[&b, &mut b] => present (b)
[&mut b, &mut b] => present (b)
[&c, &d] => absent
[&mut c, &mut d] => absent
[&a, &mut d, &mut d] => present (d)
[&mut a, &d, &mut d] => present (d)
[&mut a, &mut d, &mut d, &mut a] => present (a, d)
[&a, &mut d, &d, &a] => present (d)
[&c, &mut g, &c, &c] => absent
[&c, &mut g, &mut c, &c] => present (c)
[&a, &b, &c, &d, &e] => absent
[&mut f, &e, &e, &mut d] => absent
[&f, &e, &mut e, &d] => present (e)
[&a, &mut g, &b, &a, &b, &b, &mut f] => absent
[&mut a, &g, &b, &a, &b, &mut b, &f] => present (a, b)
[&a, &a, &a, &a, &a, &a, &a] => absent
[&a, &a, &a, &mut a, &a, &a, &a] => present (a)
[&mut a, &mut a, &mut a, &mut a, &mut a, &mut a, &mut a] => present (a)
[&mut g, &mut g, &mut g, &mut g, &mut g, &mut g, &mut g] => present (g)
[&a, &b, &mut c, &mut d, &e, &mut f, &g] => absent
[&a, &b, &c, &mut a, &mut b, &mut c] => present (a, b, c)
[&a, &mut a, &a, &mut g, &g, &mut g] => present (a, g)
With references in a more convenient format (<variable name>, <is mutable>):

Absent:

[],
[("a", false)],
[("a", true)],
[("b", false), ("b", false)],
[("c", false), ("d", false)],
[("c", true), ("d", true)],
[("c", false), ("g", true), ("c", false), ("c", false)],
[("a", false), ("b", false), ("c", false), ("d", false), ("e", false)],
[("f", true), ("e", false), ("e", false), ("d", true)],
[("a", false), ("g", true), ("b", false), ("a", false), ("b", false), ("b", false), ("f", true)],
[("a", false), ("a", false), ("a", false), ("a", false), ("a", false), ("a", false), ("a", false)],
[("a", false), ("b", false), ("c", true), ("d", true), ("e", false), ("f", true), ("g", false)],

Present:

[("b", true), ("b", false)],
[("b", false), ("b", true)],
[("b", true), ("b", true)],
[("a", false), ("d", true), ("d", true)],
[("a", true), ("d", false), ("d", true)],
[("a", true), ("d", true), ("d", true), ("a", true)],
[("a", false), ("d", true), ("d", false), ("a", false)],
[("c", false), ("g", true), ("c", true), ("c", false)],
[("f", false), ("e", false), ("e", true), ("d", false)],
[("a", true), ("g", false), ("b", false), ("a", false), ("b", false), ("b", true), ("f", false)],
[("a", false), ("a", false), ("a", false), ("a", true), ("a", false), ("a", false), ("a", false)],
[("a", true), ("a", true), ("a", true), ("a", true), ("a", true), ("a", true), ("a", true)],
[("g", true), ("g", true), ("g", true), ("g", true), ("g", true), ("g", true), ("g", true)],
[("a", false), ("b", false), ("c", false), ("a", true), ("b", true), ("c", true)],
[("a", false), ("a", true), ("a", false), ("g", true), ("g", false), ("g", true)],

"""

def aliased(variables):
    database = {}
    for (variable, mutable) in variables:
        if variable not in database:
            database[variable] = mutable
        elif database[variable] or database[variable] != mutable:
            return False
    return True

def main():
    assert(aliased([]) == True)
    assert(aliased([("a", False)]) == True)
    assert(aliased([("a", True)]) == True)
    assert(aliased([("b", False), ("b", False)]) == True)
    assert(aliased([("c", False), ("d", False)]) == True)
    assert(aliased([("c", True), ("d", True)]) == True)
    assert(aliased([("c", False), ("g", True), ("c", False), ("c", False)]) == True)
    assert(aliased([("a", False), ("b", False), ("c", False), ("d", False), ("e", False)]) == True)
    assert(aliased([("f", True), ("e", False), ("e", False), ("d", True)]) == True)
    assert(aliased([("a", False), ("g", True), ("b", False), ("a", False), ("b", False), ("b", False), ("f", True)]) == True)
    assert(aliased([("a", False), ("a", False), ("a", False), ("a", False), ("a", False), ("a", False), ("a", False)]) == True)
    assert(aliased([("a", False), ("b", False), ("c", True), ("d", True), ("e", False), ("f", True), ("g", False)]) == True)

    assert(aliased([("b", True), ("b", False)]) == False)
    assert(aliased([("b", False), ("b", True)]) == False)
    assert(aliased([("b", True), ("b", True)]) == False)
    assert(aliased([("a", False), ("d", True), ("d", True)]) == False)
    assert(aliased([("a", True), ("d", False), ("d", True)]) == False)
    assert(aliased([("a", True), ("d", True), ("d", True), ("a", True)]) == False)
    assert(aliased([("a", False), ("d", True), ("d", False), ("a", False)]) == False)
    assert(aliased([("c", False), ("g", True), ("c", True), ("c", False)]) == False)
    assert(aliased([("f", False), ("e", False), ("e", True), ("d", False)]) == False)
    assert(aliased([("a", True), ("g", False), ("b", False), ("a", False), ("b", False), ("b", True), ("f", False)]) == False)
    assert(aliased([("a", False), ("a", False), ("a", False), ("a", True), ("a", False), ("a", False), ("a", False)]) == False)
    assert(aliased([("a", True), ("a", True), ("a", True), ("a", True), ("a", True), ("a", True), ("a", True)]) == False)
    assert(aliased([("g", True), ("g", True), ("g", True), ("g", True), ("g", True), ("g", True), ("g", True)]) == False)
    assert(aliased([("a", False), ("b", False), ("c", False), ("a", True), ("b", True), ("c", True)]) == False)
    assert(aliased([("a", False), ("a", True), ("a", False), ("g", True), ("g", False), ("g", True)]) == False)

main()
