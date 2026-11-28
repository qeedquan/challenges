#!/usr/bin/env python2

"""

So simple: Provide some code that outputs foo and with the reversed source outputs bar. But before you come up with something like this boring python 2:

print "foo"#"rab" tnirp
you should know the score: You multiply the number of bytes with (1 + dead bytes), where dead bytes are bytes that can be changed to most other characters without changing the behaviour in the current execution direction (in the sense that more can be changed than not). This is valid for comments or labels or code after some exit statement or such workarounds (you know what I mean, so don't feel a hero because your language has some feature with a different name to ignore code). I want to see your creativity in reusing code depending on the direction!

Examples for score count

In the example above, the # is no dead code, because you cannot simply replace it, but the following 11 bytes are dead code, thus we get a score of 23 * (1+11) = 276! Valid, but not so nice anymore.
A sh answer like echo foo # rab ohce would score a slightly better 190.
An sed answer s:^:foo:;:rab:^:s misuses the : label to hide code, but the label is still dead code, resulting in a score of 136.
foo//rab in /// has the open // as valid exit, so this would have only three bytes of dead code, reaching a score of 32.
Rules

Dead code can be different for both directions, so for scoring, the number of dead bytes for the worse direction is counted: If you have three deads bytes forward, but 7 backwards, your multiplier will be 8.
Your code must not output anything visible after the foo or bar, just something like whitespaces or newlines.
foo and bar can be lowercase or uppercase, as you like
Your program has to end execution by itself, so don't try to loophole through some infinite loop after output!
Don't use any non-empty input, of course.
Why do I add +1 to the dead bytes? Because I don't want a zero score for living-code-only answers like this /// solution (actual score 65):
foo/./::://:/\//:f.o.b.a.r::/\// //\/::r.a.b.o.f://\/://:::/./rab
Did I mention the smallest score wins?

"""

print "foo"#"rab" tnirp
