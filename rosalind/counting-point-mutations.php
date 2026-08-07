<?php

/*
 
Problem

Figure 2. The Hamming distance between these two strings is 7. Mismatched symbols are colored red.
Given two strings s and t of equal length, the Hamming distance between s and t, denoted dH(s,t), is the number of corresponding symbols that differ in s and t.
See Figure 2.

Given: Two DNA strings s and t of equal length (not exceeding 1 kbp).

Return: The Hamming distance dH(s,t).

Sample Dataset
GAGCCTACTAACGGGAT
CATCGTAATGACGGCCT
Sample Output
7
 
*/

function hamming($s, $t) {
	$n = min(strlen($s), strlen($t));
	$m = max(strlen($s), strlen($t));
	$c = 0;
	for ($i = 0; $i < $n; $i++) {
		if ($s[$i] != $t[$i])
			$c++;
	}
	return $c + $m - $n;
}

assert(hamming("GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT") == 7);

?>
