#!/usr/bin/env python3
	
def solve(pot, bet, fpot):
	if abs(fpot-pot)%bet != 0:
		return "No accounting tablet"

	diff = abs(fpot-pot) // bet
	cnt = diff // 3
	if diff%3 != 0:
		cnt += 1
	return cnt

def main():
	assert(solve(10000, 1000, 22000) == 4)
	assert(solve(24, 13, 2) == "No accounting tablet")
	assert(solve(5100, 700, 200) == 3)
	assert(solve(54, 16, 158) == "No accounting tablet")
	assert(solve(360, 6, 72) == 16)
	assert(solve(25, 10, 5) == 1)

main()
