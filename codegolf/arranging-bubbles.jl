#!/usr/bin/env julia

#=

Note, challenge copied from question asked at math.stackexchange.
https://math.stackexchange.com/questions/2094351/arranging-bubbles

Recently, I attained quite some skill at blowing bubbles. At first I would blow bubbles like this:
https://i.sstatic.net/BRy52.png

But then things started getting strange:
https://i.sstatic.net/9jOdN.png

After a while, I was blowing some pretty weird bubbles:
https://i.sstatic.net/phz14.png

After blowing hundreds, maybe even thousands of such bubbles, my forehead suddenly wrinkled with the question: Given n bubbles, how many different ways can you arrange them? For example if n = 1, there is only 1 arrangement. If n = 2, there are 2 arrangements. If n = 3, there are 4 arrangements. If n = 4, there are 9 arrangements.

Here are the 9 arrangements of 4 bubbles:
https://i.sstatic.net/GveDF.png

After blowing all of these marvelous bubbles, I decided that I should share the delight of counting their arrangements with you. So here is your task:

Goal
Write a program, function, or similar that counts the number of ways you can arrange n bubbles.

Input
n, the number of bubbles. n > 0

Output
The number of ways you can arrange these bubbles.

Winning Criteria
It would be really cool if we can blow a bubble around your code. The smaller you make your code, the easier it will be to do so. So the person who makes the code with the least number of bytes will win the contest.

Extra information
OEIS
https://oeis.org/A000081

=#

using Primes

const cache = Dict{Int, BigInt}()

# https://oeis.org/A000081
function nurt(n)
	if n ∈ keys(cache)
		return cache[n]
	end

	if n < 0
		return 0
	end
	if n <= 1
		return n
	end

	r = big(0)
	for k in 1:n-1
		v = 0
		for d in divisors(k)
			v += d * nurt(d)
		end
		r += v * nurt(n-k)
	end
	r ÷= (n - 1)

	cache[n] = r
	return r
end

function main()
	tab = [0, 1, 1, 2, 4, 9, 20, 48, 115, 286, 719, 1842, 4766, 12486, 32973, 87811, 235381, 634847, 1721159, 4688676, 12826228, 35221832, 97055181, 268282855, 743724984, 2067174645, 5759636510, 16083734329, 45007066269, 126186554308, 354426847597, 997171512998]
	for i in 1:length(tab)
		@assert(nurt(i-1) == tab[i])
	end
end

main()
