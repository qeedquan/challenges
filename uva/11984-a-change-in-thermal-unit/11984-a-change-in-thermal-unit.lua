#!/usr/bin/env lua

function cel2fahr(c)
	return 9.0/5*c + 32
end

function fahr2cel(f)
	return 5.0/9*(f - 32)
end

function increase(c, f)
	return fahr2cel(cel2fahr(c) + f)
end

print(increase(100, 0))
print(increase(0, 100))
