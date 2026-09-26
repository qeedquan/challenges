<?php

/*
 
The program takes a natural number n and a piece of text, such as Welcome. Your task is to print this text n times, with each instance appearing on a new line.

Input
The first line contains a natural number n, and the second line contains text made up of Latin letters.

Output
Print the text n times, each on a separate line.

Examples
Input #1
3
Welcome

Answer #1
Welcome
Welcome
Welcome
 
*/

function solve($n, $s) {
	for ($i = 0; $i < $n; $i++)
		printf("%s\n", $s);
}

solve(3, "Welcome");

?>
