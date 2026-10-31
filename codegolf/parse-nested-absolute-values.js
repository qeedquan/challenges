/*

The absolute value of a number x is normally written as |x|.
The left and right side of the absolute value uses the same symbol, so it is not immediately obvious how to parse nested absolute values e.g. ||1−2|+|3−|4−5|||

Your goal is to parse such an expression containing nested absolute values:

The expression will be given as a string of characters.
For simplicity the expression will only contain single-digit numbers (or letters if that is easier in your language), the operators + and - (you can use any two distinct characters to represent these operations), and the symbol | for the left and right side of an absolute value.
You do not need to handle the case where a number is directly adjacent to an absolute value (e.g. 2|3| or |2|3)

Your output should be the same expression in a form that allows you to determine how the absolute values are bracketed.

The output has to satisfy the following rules:

The expression within an absolute value must not end with an operator ( + or - )
The expression within an absolute value cannot be empty
Each | has to be part of exactly one absolute value
You may assume there is a valid way to parse the given input.

Examples:

|2|                ->  (2)
|2|+|3|            ->  (2)+(3)
||2||              ->  ((2))
||2|-|3||          ->  ((2)-(3))
|-|-2+3||          ->  (-(-2+3))
|-|-2+3|+|4|-5|    ->  (-(-2+3)+(4)-5)
|-|-2+|-3|+4|-5|   ->  (-(-2+(-3)+4)-5)
||1-2|+|3-|4-5|||  ->  ((1-2)+(3-(4-5)))
This is code-golf the shortest solution wins.

Optional additional requirement:
Also support expressions that allow a number direct before or after a bracket. If the result is not unique, you may return any valid solution.

test-cases (for optional requirement):

|2|3|4|  -> (2(3)4)
|2|3|4|  -> (2)3(4)
||3|4|   -> ((3)4)
|2|3-|4| -> (2)3-(4)
|1+|2|3| -> (1+(2)3)
|1+2|3|| -> (1+2(3))

*/

var assert = require('assert');

// ported from @Arnauld solution
function parse(string) {
	for (;;) {
		let next = string.replace(/\|(.*?[\d)])\|/, "($1)");
		if (string == next)
			break;
		string = next;
	}
	return string;
}

assert(parse("|2|") == "(2)");
assert(parse("|2|+|3|") == "(2)+(3)");
assert(parse("||2||") == "((2))");
assert(parse("||2|-|3||") == "((2)-(3))");
assert(parse("|-|-2+3||") == "(-(-2+3))");
assert(parse("|-|-2+3|+|4|-5|") == "(-(-2+3)+(4)-5)");
assert(parse("|-|-2+|-3|+4|-5|") == "(-(-2+(-3)+4)-5)");
assert(parse("||1-2|+|3-|4-5|||") == "((1-2)+(3-(4-5)))");

