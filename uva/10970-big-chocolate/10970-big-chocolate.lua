#!/usr/bin/env lua

function cuts(m, n)
	return m * n - 1
end

assert(cuts(2, 2) == 3)
assert(cuts(1, 1) == 0)
assert(cuts(1, 5) == 4)
