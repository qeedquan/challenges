<?php

/*

Write a function that takes a string and returns an array containing binary numbers equivalent to the ASCII codes of the characters of the string. The binary strings should be eight digits long.

Example: 'man' should return [ '01101101', '01100001', '01101110' ] 
 
*/

function word2bin($word) {
	$result = array();
	foreach (str_split($word) as $char) {
		array_push($result, sprintf("%08b", ord($char)));
	}
	return $result;
}

print_r(word2bin("man"));

?>
