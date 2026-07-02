#!/usr/bin/env pwsh

<#

With roughly one second (plus or minus 10 ms) between outputs, output anything.
The first output must be at most one second after the start of the program, but can be as soon as right when the program starts.
So, the first output can be up to a second after the program starts, the second exactly one second after that, the third a second after that, and so on to infinity.

The outputs do not need to be consistent, nor have any sort of delimiter. However, they must be visible (even if it's only visible when highlighted).

#>

while ($true) {
	Start-Sleep -Seconds 1
	echo "."
}
