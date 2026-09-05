#!/usr/bin/env pwsh

<#

Print this text:

 _________
|         |
|         |
|         |
|_________|

Shortest code wins. Notice the space at the start of the first line.

#>

function square() {
	echo " _________"
	for (($i = 0); $i -lt 3; $i++) {
		echo "|         |"
	}
	echo "|_________|"
}

square
