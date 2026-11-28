#!/usr/bin/env julia

function modexp(b, p, m)
	return (big(b) ^ big(p)) % big(m)
end

@assert(modexp(3, 18132, 17) == 13)
@assert(modexp(17, 1765, 3) == 2)
@assert(modexp(2374859, 3029382, 36123) == 13195)
