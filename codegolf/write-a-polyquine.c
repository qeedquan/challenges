#define A polyquine is both quine and polyglot.1 You are to write a quine which is valid in at least two different languages. This is code golf, so the shortest answer (in bytes) wins.
#define I made that up. Or rather, Geobits did. Apparently, he wasn't the first one either, though.
#define _
#define Rules for Quines
#define Only true quines are accepted. That is, you need to print the entire source code verbatim to STDOUT, without:
#define reading your source code, directly or indirectly.
#define relying on a REPL environment which just simply evaluates and prints every expression you feed it.
#define relying on language features which just print out the source in certain cases.
#define using error messages or STDERR to write all or part of the quine. (You may write things to STDERR or produce warnings/non-fatal errors as long as STDOUT is a valid quine and the error messages are not part of it.)
#define Furthermore, your code must contain a string literal.
#define _
#define Rules for Polyglots
#define The two languages used must be distinctly different. In particular:
#define _
#define They must not be different versions of the same language (e.g. Python 2 vs. Python 3).
#define They must not be different dialects of the same language (e.g. Pascal vs. Delphi).
#define One language may not be a subset of the other one (e.g. C vs. C++).

#include <stdio.h>

#define print(x) int main() { puts(x); return 0; }

print("quine")
