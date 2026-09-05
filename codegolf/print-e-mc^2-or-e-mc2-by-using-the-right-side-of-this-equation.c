/*

Your task – if you choose to accept it – is to have your program print, literally, either one of the following:

E=mc² (if your language supports Unicode (so no HTML trickery, for instance))

E=mc^2 (if your language doesn't support Unicode)

Here are the conditions:

Your program must consist of exactly two expressions (one representing the m, the other the c, in mc²), which, when fed into your language's representation of the formula mc², and whose result is then printed, will show one of the above results.

Both expression may be assigned to variables before feeding them into mc², but the expressions themselves are not allowed to use intermediate variables.

Both expressions must evaluate to an absolute value larger than 1 (e.g abs(expression) > 1).

You may assign the result of mc² to an intermediate variable, representing the E, before printing this E, but that is not necessary – you may print the result of mc² directly as well.

When printing the final result, you are allowed to use your language's libraries to convert the possibly numeric or binary result to it's string representation.

Added condition: no operator overloading in the final expression that represents mc². The result must be the algebraic result of expression m times expression c squared.

Here's an example template, of what I'm looking for, expressed in PHP:

$m = // some expression;
$c = // some expression;
$E = $m * pow( $c, 2 );
print $E; // should print on of the results mentioned at the beginning of this challenge
To be honest, I'm not even sure this challenge is doable, but my gut says it must be possible in at least one, or even a few, languages.

Winning solution is the one with the shortest code, in characters, in a week from now.

For clarification, it's perfectly fine to merely do something like this as well — if your language allows for it:

print( someExpression * someOtherExpression ** 2 ); // or something to that effect
... in other words: without assigning anything to any intermediate variables. Just as long as the algebraic calculation remains intact.

*/

#include <stdio.h>

int
main(void)
{
	printf(u8"E=mc²\n");
	return 0;
}
