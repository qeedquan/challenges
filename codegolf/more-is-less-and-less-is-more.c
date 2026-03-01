/*

Anybody can make the output of a program bigger by adding characters, so let's do the exact opposite.

Write a full program, an inner function or a snippet for a REPL environment in a language of your choice that satisfies the following criteria:

Your code must be at least 1 character long.

Running the original code produces x characters of output to STDOUT (or closest alternative), where 0 ≤ x < +∞.

Removing any arbitrary single character from the original code results again in valid code, which produces at least x + 1 characters of output to STDOUT.

Neither the original code nor the modifications may produce any error output, be to STDOUT, STDERR, syslog or elsewhere. The only exceptions to this rule are compiler warnings.

Your program may not require any flags or settings to suppress the error output.

Your program may not contain any fatal errors, even if they don't produce any output.

Both the original code and the modifications must be deterministic and finish eventually (no infinite loops).

Neither the original code nor the modifications may require input of any kind.

Functions or snippets may not maintain any state between executions.

Considering that this task is trivial is some languages and downright impossible in others, this is a popularity-contest.

When voting, please take the "relative shortness" of the code into account, i.e., a shorter answer should be considered more creative than a longer answer in the same language.

*/

/*

@feersum
11^11 is of course 0. The only other possibilities are 1^11 or 11^1 which are 10, or 1111 which produces itself.

*/

int
f()
{
	return 11 ^ 11;
}

int
main()
{
	return f();
}
