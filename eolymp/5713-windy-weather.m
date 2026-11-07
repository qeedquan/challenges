%{

Piglet was lying on the lawn, watching the swaying blades of grass. He noticed that the grass was swaying because of the wind and immediately came up with a way to measure the wind's strength using them. According to Piglet's definition, the wind's strength is the difference between the height of the tallest blade of grass and the shortest one.

Input
The first line contains a single integer n — the number of blades of grass observed by Piglet. The second line contains n integers — the heights of the blades of grass.

All input numbers are positive integers not exceeding 100. This is because Piglet didn't like counting large numbers and couldn't do it, as he had never encountered numbers greater than 100 before.

Output
Print one number — the wind's strength as defined by Piglet.

Examples

Input #1
14
3 6 5 3 5 5 4 5 4 3 2 3 6 4

Answer #1
4

%}

function strength = solve(heights)
	if (length(heights) == 0)
		strength = 0;
	else
		strength = max(heights) - min(heights);
	end
end

solve([3 6 5 3 5 5 4 5 4 3 2 3 6 4])

