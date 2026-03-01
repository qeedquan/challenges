#!/usr/bin/env python3

"""

Originally sandboxed by @xnor

Left-or-right is a very simple language @xnor made up. Its expressions are made of arrows < (left), > (right), and parentheses. The goal is to evaluate an expression to either < or >.

An expression A<B picks the left item A, while A>B picks the right one B. Think of < and > as arrows pointing to the item we want, not as comparison operators.

Take, for example, ><>. The operator in the middle is <, and confusingly, the items on each side A and B are also arrows. Since the operator tells us to take the left one A, which is >. So, ><> equals >.

Expressions also nest. We can replace the expression with its value. So, for example, (><>)<< equals ><< equals >. And, >(><>)< equals >>< equals <. For another example, (><>)(<<<)(>><) equals ><< equals >.

In the input, you'll be given a well-formed expression consisting of either a trio of arrows like ><> or the result of repeatedly replacing some arrow by a trio of arrows in parens like ><(><>) . You can assume the input won't already be a lone arrow. You may alternately accept the whole inputs encased in parens like (><>) or (<(><>)>).

The input is given as a flat string consisting of symbols <>(). You may not take it in a pre-parsed form like a tree.

The shortest code in bytes wins.

Test cases
Generated using this script.

Evaluates to <
>><
<<(<><)
(>>>)><
(<(<<>)(<<<))<<
((>(>><)>)(><>)>)><
(<<(>(<>>)<))((><>)(><<)>)(<<<)
((<<<)<>)((>><)<(<><))((>>>)<<)
>(>((><>)<>)(<>>))((>><)((><>)<<)<)
((><<)(><<)(<<>))(<(>><)(>><))(<<(<<>))
(<(><<)(>(>>>)>))((>>>)>>)((<>(>><))<<)

Evaluates to >
<>>
((<<<)>(<<>))(><<)>
((>>>)<>)<((<<<)>>)
>(>>(<<<))(>((<>>)<<)<)
((><>)(<<>)>)(<<(<<<))(<(>>>)<)
(><((><>)><))(>(>>(>>>))(<><))(>>>)
(((>><)<>)(><>)(><>))(<<(<>>))(<<>)
((><>)<(<<(<<>)))((<(<<>)<)(<><)>)(>>>)
(<<(<><))(((<>>)><)(><<)(><>))(<(><>)>)
((>>>)<<)(<(<><)<)((<<(<<<))>(>(><>)<))

"""

import re

def recurse(s):
    if not s or not s[1:]:
        return s
    
    t = re.sub(r'\(((.)<.|.>(.))\)', r'\2\3', s)
    if s == t:
        return s
    
    return recurse(t)

def solve(s):
    return recurse("(" + s + ")")

def main():
    assert(solve(">><") == '<')
    assert(solve("<<(<><)") == '<')
    assert(solve("(>>>)><") == '<')
    assert(solve("(<(<<>)(<<<))<<") == '<')
    assert(solve("((>(>><)>)(><>)>)><") == '<')
    assert(solve("(<<(>(<>>)<))((><>)(><<)>)(<<<)") == '<')
    assert(solve("((<<<)<>)((>><)<(<><))((>>>)<<)") == '<')
    assert(solve(">(>((><>)<>)(<>>))((>><)((><>)<<)<)") == '<')
    assert(solve("((><<)(><<)(<<>))(<(>><)(>><))(<<(<<>))") == '<')
    assert(solve("(<(><<)(>(>>>)>))((>>>)>>)((<>(>><))<<)") == '<')
    
    assert(solve("<>>") == '>')
    assert(solve("((<<<)>(<<>))(><<)>") == '>')
    assert(solve("((>>>)<>)<((<<<)>>)") == '>')
    assert(solve(">(>>(<<<))(>((<>>)<<)<)") == '>')
    assert(solve("((><>)(<<>)>)(<<(<<<))(<(>>>)<)") == '>')
    assert(solve("(><((><>)><))(>(>>(>>>))(<><))(>>>)") == '>')
    assert(solve("(((>><)<>)(><>)(><>))(<<(<>>))(<<>)") == '>')
    assert(solve("((><>)<(<<(<<>)))((<(<<>)<)(<><)>)(>>>)") == '>')
    assert(solve("(<<(<><))(((<>>)><)(><<)(><>))(<(><>)>)") == '>')
    assert(solve("((>>>)<<)(<(<><)<)((<<(<<<))>(>(><>)<))") == '>')

main()
