#!/usr/bin/env julia

function clockhand(s)
	t = {}
	for f in (s..":"):gmatch("(.-):") do
		table.insert(t, tonumber(f))
	end
	
	if #t ~= 2 then
		return -1
	end

	h = t[1]*30 - t[2]*5.5
	m = t[2]
	
	if h >= 0 and h <= 180 then
		return h
	elseif h > 180 then
		return 360 - h
	elseif h < 0 and h >= -180 then
		return -h
	else
		return h + 360
	end
end

print(clockhand("12:00"))
print(clockhand("9:00"))
print(clockhand("8:10"))
