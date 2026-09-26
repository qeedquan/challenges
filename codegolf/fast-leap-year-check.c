/*

The task is to find parameters that make a fast leap year check correct for the widest range of years.

We assume the Proleptic Gregorian calendar, which extends the Gregorian calendar backward from its introduction in 1582 and includes a year 0. The standard way of checking for leap years is this:

bool is_leap_year(uint64_t year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    if (year % 400 == 0) return true;
    return false;
}
This gives the correct result for every year, but needs either several multiplications or data-dependent jumps, and could be a bottleneck. An alternative is a function of this form, for some constants f, m, and t:

bool fast_is_leap_year(uint64_t year) {
    return ((year * f) & m) <= t;
}
This compiles to efficient straight-line code which will take only about 7 cycles on a modern CPU. However, it is correct only for a limited number of years, depending on the chosen constants f, m, and t. This might be acceptable for certain applications.

The task is to find constants f, m, and t. The score to be maximized is the smallest year for which fast_is_leap_year with these constants returns the wrong result.

The constants can have at most 64 bit. All calculations are unsigned.

*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

/*

@Exalted Toast

(f, m, t) = (13835058055969358479, 13835058121854156815, 66571993088)

How
Found with Z3 Theorem prover. I bounced around a bunch figuring out how to encode the problem as an SMT. It turns out that an iterative solution works really well here. We maintain a list of values to check, starting with just [0], and incrementally add to the checks:

seen_checks = set()
def find_constants(solver: z3.Solver, checks: list[int], bit_len: int) -> tuple[int, int, int]:
    global seen_checks
    f, m, t = z3.BitVecs("f m t", bit_len)

    for year in checks:
        if year in seen_checks:
            continue
        if is_leap(year):
            solver.add(z3.ULE((year * f) & m, t)) # ULE: unsigned less-eq
        else:
            solver.add(z3.UGT((year * f) & m,  t))
        seen_checks.add(year)

    result = solver.check()
    if result == z3.sat:
        model = solver.model()
        return tuple(map(lambda x: int(str(x)) if str(x) != 'None' else 0, (model[f], model[m], model[t])))
    else:
        print(f"Terminal result:", result)
        return None
This is wrapped with some plumbing that adds the earliest counterexample to the list of checks and asks for a new solution:

import z3

# ...

def validate(f, m, t) -> int:
    year = 0
    while True:
        fast_check = (year * f) & m <= t
        if fast_check != is_leap(year):
            return year
        year += 1

bit_len = 64
checks = [0]
solver = z3.Solver()
while (constants := find_constants(solver, checks, bit_len)) is not None:
    print("Found constants:", constants)
    counterex = validate(*constants)
    print("Earliest counterexample:", counterex)
    checks.append(counterex)
It happens that this doesn't lead to an explosion, the search space for constants starts filtering very rapidly: 48 bits is proven with only 241 such constraints, and this answer gets found after only 290 constraints. Originally I tried seeding the solver with lots values (say, the first 1000 ints), but this only slows it down as most values turn out to be irrelevant for solving. For example, most 2-digit integers don't show up in the final proof.

Eventually the solver outputs unsat, which means there provably exists no constants will output correct results for every counterexample we've seen so far. At that point, we know we've found optimal (but not necessarily unique) constants, and we output the constants that yielded the highest counterexample.

In this case, we get unsat after finding 294 such values, here they are sorted.

0,1,2,3,4,5,6,7,8,9,12,13,14,15,16,19,20,24,28,32,39,40,41,43,44,47,48,51,52,55,56,60,63,64,68,72,76,80,81,84,88,92,96,97,100,103,104,108,112,116,124,128,131,132,136,140,148,152,156,164,168,180,184,192,196,200,204,208,228,248,256,264,272,284,292,296,300,304,308,312,332,344,368,392,400,408,412,416,420,452,468,484,492,496,500,536,544,556,596,600,612,628,644,708,744,788,800,801,803,804,876,900,916,1000,1068,1076,1100,1124,1132,1300,1508,1528,1572,1588,1600,1628,1676,1776,1886,1888,1900,2000,2100,2108,2128,2148,2156,2200,2308,2400,2500,2600,2845,2847,2900,2988,3600,4196,4300,4308,4428,5200,5352,6800,7700,8000,8292,8352,8400,8504,8800,8852,9200,10000,10400,10800,11792,12000,12800,12900,12957,12959,13900,17068,18700,19284,25576,25600,25604,25700,25800,32868,33268,37492,38296,39064,42011,42012,42932,43692,46580,49000,51004,51200,51300,51400,58500,58515,58516,65536,65636,88769,89720,102400,102404,102500,116900,131172,174796,204800,204804,208880,233800,257004,262244,396900,406428,409600,409601,409700,524388,819200,819201,819204,819300,841524,844844,1638400,1638404,1638500,1651400,1673188,1681388,1683048,2097252,2184800,2524472,3276804,3276900,3346376,3365996,3383892,3744916,4365700,5018600,5228600,6423784,6553604,6731992,10457300,10508500,10924836,13107300,13256104,20649012,24403396,24672500,26214401,26214403,26214404,26214500,32095548,36472300,40046396,46684488,52428801,52428803,52428804,54024788,63161372,76260100,87039700,89478552,104857604,160739800,199765944,209715201,209715203,239674516,250289500,394758100,419430404,477218644,745654100,838860804,954437188,1073741924,1579032100,1677721604,2982616200,3355443204,4473924267,4473924268,5965232500

*/

bool
isleapfast(uint64_t y)
{
	uint64_t f, m, t;

	f = 13835058055969358479ULL;
	m = 13835058121854156815ULL;
	t = 66571993088ULL;

	return ((y * f) & m) <= t;
}

bool
isleap(uint64_t y)
{
	if (y % 4 != 0)
		return false;
	if (y % 100 != 0)
		return true;
	if (y % 400 == 0)
		return true;
	return false;
}

int
main()
{
	uint64_t i;

	for (i = 0; i < UINT64_MAX; i++) {
		if (isleap(i) != isleapfast(i)) {
			printf("%" PRIu64 "\n", i);
			break;
		}
	}

	return 0;
}
