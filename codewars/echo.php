<?php

/*

Echo Program
Write an echoProgram function (or echo_program depend on language) that returns your solution source code as a string.

Note:
Function.prototype.toString has been disabled.

*/

function cat($name) {
	$fp = fopen($name, "rb");
	if (!$fp) {
		printf("%s: %s\n", $name, strerror($errno));
		return;
	}

	while (($ch = fgetc($fp)) !== false) {
		echo "$ch";
	}
	fclose($fp);
}

for ($i = 0; $i < count($argv); $i++) {
	cat($argv[$i]);
}

?>
