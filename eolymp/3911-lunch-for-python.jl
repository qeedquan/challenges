#=

A python accustomed to eating rabbits daily has prepared A rabbits. However, its dietary needs require it to consume B rabbits each day.
The python is curious to find out how many days its supply will last and how many rabbits will remain for its final meal.

Input
You will receive two numbers as input, separated by a space: A and B (1≤A,B≤10^1000).

Output
Output two numbers: the quotient of the integer division of A by B, and the remainder of this division.

Examples

Input #1
5 2

Answer #1
2 1

=#

function solve(a, b)
    return a÷b, a%b
end

println(solve(5, 2))
