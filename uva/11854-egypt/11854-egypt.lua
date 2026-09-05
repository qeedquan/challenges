#!/usr/bin/env lua

function right(a, b, c)
	if a > b then
		a, b = b, a
	end
	
	if a > c then
		a, c = c, a
	end
	
	if b > c then
		b, c = c, b
	end
	
	return a > 0 and a*a + b*b == c*c
end

assert(right(6, 8, 10) == true)
assert(right(25, 52, 60) == false)
assert(right(5, 12, 13) == true)
