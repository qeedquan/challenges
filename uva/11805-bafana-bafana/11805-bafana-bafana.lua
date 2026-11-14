#!/usr/bin/env lua

function bafana(n, k, p)
	for d=1,p do
		k = k + 1
		if k > n then
			k = 1
		end
	end
	
	return k
end

assert(bafana(5, 2, 5) == 2)
assert(bafana(6, 3, 5) == 2)
assert(bafana(4, 1, 3) == 4)
