<?php

/*

Bob is preparing to pass IQ test. The most frequent task in this test is to find out which one of the given numbers differs from the others. Bob observed that one number usually differs from the others in evenness. Help Bob — to check his answers, he needs a program that among the given numbers finds one that is different in evenness, and return a position of this number.

! Keep in mind that your task is to help Bob solve a real IQ test, which means indexes of the elements start from 1 (not 0)

Examples:
iqTest("2 4 7 8 10") => 3 // Third number is odd, while the rest of the numbers are even

iqTest("1 2 1 1") => 2 // Second number is even, while the rest of the numbers are odd
  
*/

function iqtest($a) {
	$i0 = $i1 = 0;
	$n0 = $n1 = 0;
	for ($i = 0; $i < count($a); $i++) {
		if ($a[$i] & 1) {
			$i0 = $i + 1;
			$n0 += 1;
		} else {
			$i1 = $i + 1;
			$n1 += 1;
		}
	}
	return ($n0 < $n1) ? $i0 : $i1;
}

assert(iqtest([2, 4, 7, 8, 10]) == 3);
assert(iqtest([1, 2, 1, 1]) == 2);

?>
