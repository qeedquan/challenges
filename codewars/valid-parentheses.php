<?php

/*

Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return true if the string is valid, and false if it's invalid.

Examples
"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true
Constraints
0 <= input.length <= 100

Along with opening (() and closing ()) parenthesis, input may contain any valid ASCII characters. Furthermore, the input string may be empty and/or not contain any parentheses at all. Do not treat other forms of brackets as parentheses (e.g. [], {}, <>).

*/

function valid($s) {
	$n = strlen($s);
	$l = 0;
	$r = 0;
	for ($i = 0; $i < $n; $i++) {
		if ($s[$i] == '(')
			$l += 1;
		else if ($s[$i] == ')')
			$r += 1;

		if ($r > $l)
			return false;
	}
	return $l == $r;
}

assert(valid("()") == true);
assert(valid(")(()))") == false);
assert(valid("(") == false);
assert(valid("(())((()())())") == true);

?>
