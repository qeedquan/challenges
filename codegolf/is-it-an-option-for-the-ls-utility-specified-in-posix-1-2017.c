/*

The ls utility lists specified directory content. It is infamous for stupidly lots of options which is known for anti-pattern design of implementing software (citation needed).

Given an alphanumeric character, decide whether the character is an option for the ls utility defined in POSIX.1-2017.

From POSIX.1-2017 (removed XSI-OPTION tags to include those options):

ls [-ikqrs] [-glno] [-A|-a] [-C|-m|-x|-1] [-F|-p] [-H|-L] [-R|-d] [-S|-f|-t] [-c|-u] [file...]

Input
An alphanumeric character, which is one of

0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Output
A boolean value whether the input is one of following characters:

ikqrsglnoAaCmx1FpHLRdSftc
The lowercase ell and number one are in, but the uppercase eye is not. If the input is not one of the characters above your program or function must return a falsey value.

Note
Don't expect the following shellscript works:

ls -$1
Many of your implementation has some extensions; for example I tried with toybox 0.8.0-android it had some extensions such as -b and -Z, which is not accepted. If you find an implementation who implemented what the standards says but nothing else, then this program is yours.

Rules
code-golf
desicion-problem
See also https://codegolf.meta.stackexchange.com/questions/tagged/defaults
Link
Description of ls utility
Utility Syntax Guidelines
sandbox
https://codegolf.meta.stackexchange.com/a/26414/113493

*/

#include <assert.h>
#include <string.h>

bool
option(int c)
{
	return strchr("ikqrsglnoAaCmx1FpHLRdSftc", c) != NULL;
}

int
main()
{
	assert(option('f') == true);
	assert(option('p') == true);

	return 0;
}
