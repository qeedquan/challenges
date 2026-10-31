function summation(x)
	return x*x*(x+1)*(x+1)//4
end

assert(summation(1) == 1)
assert(summation(2) == 9)
assert(summation(3) == 36)
