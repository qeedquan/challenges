#!/usr/bin/env pwsh

<#

Description

Calculate a+b
Input

Two integer a,b (0<=a,b<=10)
Output

Output a+b
Sample Input

1 2
Sample Output

3

#>

function table($n) {
	for ($i = 0; $i -le $n; $i++) {
		for ($j = 0; $j -le $n; $j++) {
			$sum = "{0,2:d} " -f ($i + $j)
			Write-Host $sum -nonewline
		}
		Write-Host ""
	}
}

table 10
