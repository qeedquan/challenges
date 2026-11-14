#!/usr/bin/env pwsh

<#

Description

Zombies love to eat brains. Yum.
Input

The first line contains a single integer n indicating the number of data sets.

The following n lines each represent a data set. Each data set will be formatted according to the following description:

A single data set consists of a line "X Y", where X is the number of brains the zombie eats and Y is the number of brains the zombie requires to stay alive.
Output

For each data set, there will be exactly one line of output. This line will be "MMM BRAINS" if the number of brains the zombie eats is greater than or equal to the number of brains the zombie requires to stay alive. Otherwise, the line will be "NO BRAINS".
Sample Input

3
4 5
3 3
4 3
Sample Output

NO BRAINS
MMM BRAINS
MMM BRAINS
Source

South Central USA 2004

#>

function brains($x, $y) {
	if ($x -ge $y) {
		echo "MMM BRAINS"
	} else {
		echo "NO BRAINS"
	}
}

brains 4 5
brains 3 3
brains 4 3
