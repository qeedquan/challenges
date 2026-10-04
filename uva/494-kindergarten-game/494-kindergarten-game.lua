#!/usr/bin/env lua

function isletter(c)
	return ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z')
end

function count(s)
	local r = 0
	local f = 0
	for i=1,#s do
		local c = s:sub(i, i)
		if f == 0 and isletter(c) then
			r = r + 1
			f = 1
		elseif not isletter(c) then
			f = 0
		end
	end

	return r
end

assert(count("Meep Meep!") == 2)
assert(count("I tot I taw a putty tat.") == 7)
assert(count("I did! I did! I did taw a putty tat.") == 10)
assert(count("Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...") == 9)
