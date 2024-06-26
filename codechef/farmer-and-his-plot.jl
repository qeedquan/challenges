#!/usr/bin/env julia

#=

Santosh has a farm at Byteland. He has a very big family to look after. His life takes a sudden turn and he runs into a financial crisis.
After giving all the money he has in his hand, he decides to sell his plots. The speciality of his land is that it is rectangular in nature.
Santosh comes to know that he will get more money if he sells square shaped plots. So keeping this in mind, he decides to divide his land into minimum possible number of square plots, such that each plot has the same area, and the plots divide the land perfectly.
He does this in order to get the maximum profit out of this.

So your task is to find the minimum number of square plots with the same area, that can be formed out of the rectangular land, such that they divide it perfectly.

Input

The first line of the input contains T, the number of test cases. Then T lines follow.
The first and only line of each test case contains two space-separated integers, N and M, the length and the breadth of the land, respectively.

Output

For each test case, print the minimum number of square plots with equal area, such that they divide the farm land perfectly, in a new line.

Constraints
1≤T≤20
1≤M≤10000
1≤N≤10000

=#

function plot(n, m)
	l = gcd(n, m)
	n/l * m/l
end

@assert(plot(10, 15) == 6)
@assert(plot(4, 6) == 6)
