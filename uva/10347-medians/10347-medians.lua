#!/usr/bin/env lua

function area(a, b, c)
	local d = (a + b + c) / 2
	local s = d*(d-a)*(d-b)*(d-c)
	if s <= 0 then
		return -1
	end
	return 4.0/3.0 * math.sqrt(s)
end

print(area(3, 3, 3))
