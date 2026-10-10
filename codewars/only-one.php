<?php

/*

Given any number of boolean flags function should return true if and only if one of them is true while others are false. If function is called without arguments it should return false.

  onlyOne() --> false
  onlyOne(true, false, false) --> true
  onlyOne(true, false, false, true) --> false
  onlyOne(false, false, false, false) --> false   
 
*/

function onlyone($a) {
	$c = 0;
	for ($i = 0; $c < 2 && $i < count($a); $i++) {
		if ($a[$i])
			$c += 1;
	}
	return $c == 1;
}

printf("%d\n", onlyone([]));
printf("%d\n", onlyone([true, false, false]));
printf("%d\n", onlyone([true, false, false, true]));
printf("%d\n", onlyone([false, false, false, false]));

?>
