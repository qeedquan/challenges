#!/usr/bin/env lua

function ilog2(n)
	p = 1
	r = 0
	while p < n do
		p = p << 1
		r = r + 1
	end
	return r
end

assert(ilog2(2) == 1)
assert(ilog2(10) == 4)
assert(ilog2(0) == 0)
assert(ilog2(1024) == 10)
assert(ilog2(32767) == 15)
assert(ilog2(1<<31) == 31)
