#!/usr/bin/env lua

function g(n)
	while n >= 10 do
		n = n//10 + n%10
	end
	return n
end

assert(g(2) == 2)
assert(g(11) == 2)
assert(g(47) == 2)
assert(g(1234567892) == 2)
