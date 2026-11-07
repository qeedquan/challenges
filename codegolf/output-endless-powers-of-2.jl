#!/usr/bin/env julia

#=

In any programming language, make a program that outputs infinite subsequent powers of two, starting at any power of two with finite integer exponent. Note: it only has to theoretically output infinite subequent powers of two given infinite integer size (so you can ignore any potential issues with floating-point). Each power of two sufficently sized (greater than some value) must be theoretically be able to be outputted within a finite amount of time. An example in js might look like this:

var num = 1;
while (true){
  console.log(num);
  num *= 2;
}

=#

function output()
	local n = big(1)
	while true
		println(n)
		n *= 2
	end
end

output()
