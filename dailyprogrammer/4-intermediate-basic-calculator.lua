#!/usr/bin/env lua5.4

--[[

create a calculator program that will take an input, following normal calculator input (5*5+4) and give an answer (29). This calculator should use all four operators.

For extra credit, add other operators (6(4+3), 3 ** 3, etc.)

]]--

function eval(s)
	return load('return '..s)()
end

print(eval('6*(4+3)'))
print(eval('3^3'))

