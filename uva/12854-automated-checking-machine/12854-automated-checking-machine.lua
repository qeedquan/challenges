#!/usr/bin/env lua

function check(a, b)
	if #a ~= #b then
		return 'N'
	end

	for i=1,#a do
		if a[i] == b[i] then
			return 'N'
		end
	end

	return 'Y'
end

assert(check({1, 1, 0, 1, 0}, {0, 0, 1, 0, 1}) == 'Y')
assert(check({1, 0, 0, 1, 0}, {1, 0, 1, 1, 0}) == 'N')
