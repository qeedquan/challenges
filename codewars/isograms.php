<?php

/*

An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true
"aba" --> false
"moOse" --> false (ignore letter case) 
 
*/

function isogram($s) {
	$m = [];
	$s = strtolower($s);
	$n = strlen($s);
	for ($i = 0; $i < $n; $i++) {
		$k = $s[$i];
		if (array_key_exists($k, $m))
			return false;
		$m[$k] = true;
	}
	return true;
}

assert(isogram("Dermatoglyphics") == true);
assert(isogram("aba") == false);
assert(isogram("moOse") == false);

?>
