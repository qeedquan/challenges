/*

Challenge
Write 2≤n≤10 distinct, valid non-halting full programs in your language of choice.
If all of them are concatenated in order, the resulting full program should be a valid halting program, but if any of them are left out, the result should still be a valid non-halting program.

More formally, write 2≤n≤10 distinct programs P1,P2,⋯,Pn in a language L of your choice, which satisfy the following property:

P1P2⋯Pn (where XY means string concatenation of two programs X and Y) is valid full program in L and, given no input, halts in finite time.
If you delete any of 1≤x≤n−1 program segments (Pi's where 1≤i≤n) from the above, the result is still a valid full program in L, but does not halt in finite time.
In other words, any nonempty proper subsequence of P1P2⋯Pn should be a valid non-terminating program in L.
A program is valid if a compiler can successfully produce an executable or an interpreter finishes any pre-execution check (syntax parser, type checker, and any others if present) without error.
A valid program is halting if the execution finishes for any reason, including normally (end of program, halt command) or abnormally (any kind of runtime error, including out-of-memory and stack overflow).
The output produced by any of the programs does not matter in this challenge.

For example, a three-segment submission foo, bar, and baz is valid if

foobarbaz halts in finite time, and each of foo, bar, baz, foobar, foobaz, and barbaz does not halt in finite time in the same language.
(The behavior of barfoo or bazbar does not matter, since the segments are not in order.)
The score of your submission is the number n (the number of program segments). The higher score wins, tiebreaker being code golf (lower number of bytes wins for the same score).
It is encouraged to find a general solution that works beyond n=10, and to find a solution that does not read its own source code (though it is allowed).

*/

/*

ported from @tsh solution

Node.js will keep running if there is any timers been scheduled, and halt as soon as timer callback queue is cleared.

The order of these programs does not matter. After append an extra ; to the last one, you may shuffle them and it still meets the requirement of this challenge.
It halts as long as you collected all 10 programs, and never halts if anyone is missing. You may also duplicate some programs here, and it works same as the program appears only once. :)

*/

(A = _ => setTimeout(A, B = _ => 0))();
(B = _ => setTimeout(B, C = _ => 0))();
(C = _ => setTimeout(C, D = _ => 0))();
(D = _ => setTimeout(D, E = _ => 0))();
(E = _ => setTimeout(E, F = _ => 0))();
(F = _ => setTimeout(F, G = _ => 0))();
(G = _ => setTimeout(G, H = _ => 0))();
(H = _ => setTimeout(H, I = _ => 0))();
(I = _ => setTimeout(I, J = _ => 0))();
(J = _ => setTimeout(J, A = _ => 0))();

