#=

https://static.e-olymp.com/content/1b/1b75ad22c090b6d827fa7b60ea216c00b3177429.jpg

Find the surface area and volume of the rectangular parallelepiped by its dimensions.

Input
The lengths of edges of rectangular parallelepiped a, b and c (a, b, c ≤ 10^6).

Output
Print the surface area and volume of the rectangular parallelepiped.

Examples
Input #1
2 3 4

Answer #1
52 24

=#

function solve(a, b, c)
	return  (2*(a*b + b*c + a*c), a*b*c)
end

println(solve(2, 3, 4))

