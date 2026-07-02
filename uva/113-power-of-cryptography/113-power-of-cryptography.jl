#!/usr/bin/env julia

function nth_root(n, p)
	return BigInt(round(p^(1/n)))
end

@assert(nth_root(2, 16) == 4)
@assert(nth_root(3, 27) == 3)
@assert(nth_root(7, 4357186184021382204544) == 1234)
