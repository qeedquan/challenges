#!/usr/bin/env julia

#=

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
Task:
Write

smallest(n)

that will find the smallest positive number that is evenly divisible by all of the numbers from 1 to n (n <= 40).
E.g

smallest(5) == 60 // 1 to 5 can all divide evenly into 60
smallest(10) == 2520

=#

# https://oeis.org/A003418
function smallest(n)
	r = 1
	for i in 2:n
		r = lcm(r, i)
	end
	return r
end

tab = [
	1, 1, 2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360,
	360360, 360360, 720720, 12252240, 12252240, 232792560, 232792560, 232792560,
	232792560, 5354228880, 5354228880, 26771144400, 26771144400, 80313433200,
	80313433200, 2329089562800, 2329089562800
]

for (i, v) in pairs(tab)
	@assert(smallest(i - 1) == v)
end
