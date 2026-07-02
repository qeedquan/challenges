<?php

/*

Given a string, you have to return a string in which each character (case-sensitive) is repeated once.

Examples (Input -> Output):
* "String"      -> "SSttrriinngg"
* "Hello World" -> "HHeelllloo  WWoorrlldd"
* "1234!_ "     -> "11223344!!__  "

Good Luck! 
 
*/

function doublechar($s) {
	$r = "";
	for ($i = 0; $i < strlen($s); $i++) {
		$r = $r . $s[$i] . $s[$i];
	}
	return $r;
}

assert(doublechar("String") == "SSttrriinngg");
assert(doublechar("Hello World") == "HHeelllloo  WWoorrlldd");
assert(doublechar("1234!_ ") == "11223344!!__  ");

?>
