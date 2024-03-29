#!/usr/bin/env pwsh

<#

Description

Here is a simple game. In this game, there are several piles of matches and two players. The two player play in turn. In each turn, one can choose a pile and take away arbitrary number of matches from the pile (Of course the number of matches, which is taken away, cannot be zero and cannot be larger than the number of matches in the chosen pile). If after a player’s turn, there is no match left, the player is the winner. Suppose that the two players are all very clear. Your job is to tell whether the player who plays first can win the game or not.
Input

The input consists of several lines, and in each line there is a test case. At the beginning of a line, there is an integer M (1 <= M <=20), which is the number of piles. Then comes M positive integers, which are not larger than 10000000. These M integers represent the number of matches in each pile.
Output

For each test case, output "Yes" in a single line, if the player who play first will win, otherwise output "No".
Sample Input

2 45 45
3 3 6 9
Sample Output

No
Yes
Source

POJ Monthly,readchild

#>

function winnable($a) {
	$r = 0
	$a.ForEach({ $r = $r -bxor $_ })
	if ($r -ne 0) {
		echo "Yes"
	} else {
		echo "No"
	}
}

winnable @(45, 45)
winnable @(3, 6, 9)
