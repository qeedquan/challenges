function ancestors(n)
	a, b = 1, 1
	for i=1,n do
		a, b = b, a + b
	end
	return a
end

assert(ancestors(1) == 1)
assert(ancestors(2) == 2)
assert(ancestors(3) == 3)

for i=1,80 do
	print(i, ancestors(i))
end
