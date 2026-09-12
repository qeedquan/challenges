%{

The program takes a single line of text as input, such as Google. Your task is to output the message Google is beautiful!

Input
A single line of text containing only Latin letters.

Output
The solution to the problem.

Examples

Input #1
Google

Answer #1
Google is beautiful!

%}

function result = solve(name)
	result = sprintf("%s is beautiful!", name);
end

solve("Google")
