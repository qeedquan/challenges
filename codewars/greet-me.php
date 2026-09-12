<?php

/*

Write a method that takes one argument as name and then greets that name, capitalized and ends with an exclamation point.

Example:

"riley" --> "Hello Riley!"
"JACK"  --> "Hello Jack!" 
 
*/

function capitalize($name) {
	$result = strtolower($name);
	if (strlen($result) > 0) {
		$result = strtoupper(substr($name, 0, 1)) . substr($result, 1);
	}
	return $result;
}

function greet($name) {
	return sprintf("Hello %s!", capitalize($name));
}

assert(greet("riley") == "Hello Riley!");
assert(greet("JACK") == "Hello Jack!");

?>
