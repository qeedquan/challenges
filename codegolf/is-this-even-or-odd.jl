#!/usr/bin/env julia

#=

Note: There is not been a vanilla parity test challenge yet (There is a C/C++ one but that disallows the ability to use languages other than C/C++, and other non-vanilla ones are mostly closed too), So I am posting one.

Given a positive integer, output its parity (i.e. if the number is odd or even) in truthy/falsy values. You may choose whether truthy results correspond to odd or even inputs.

Examples
Assuming True/False as even and odd (This is not required, You may use other Truthy/Falsy values for each), responsively:

(Input):(Output)
1:False
2:True
16384:True
99999999:False

=#

function parity(n)
	return n&1 == 0
end

@assert(parity(1) == false)
@assert(parity(2) == true)
@assert(parity(16384) == true)
@assert(parity(99999999) == false)
