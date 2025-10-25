#!/usr/bin/env python3

"""

You are given two arbitrary integer lists, e.g. [-10, 99, -6, 43], [100, 32, 44]. You are to pick one integer from each list and sum them up, then sort the best pairs ordered by the absolute distance to 100 in ascending order. Paired up integers from each list shall not be repeated in the output.

For instance, we have

Pair	Calculation	Absolute distance from 100
(-10, 100)	100 - (-10 + 100)	= 10
(-10, 32)	100 - (-10 + 32 )	= 78
(-10, 44)	100 - (-10 + 44 )	= 66
(99, 100)	100 - (99 + 100 )	= 99
(99, 32 )	100 - (99 + 32 )	= 31
(99, 44 )	100 - (99 + 44 )	= 43
(-6, 100)	100 - (-6 + 100 )	= 6
(-6, 32 )	100 - (-6 + 32 )	= 74
(-6, 44 )	100 - (-6 + 44 )	= 62
(43, 100)	100 - (43 + 100 )	= 43
(43, 32 )	100 - (43 + 32 )	= 25
(43, 44 )	100 - (43 + 44 )	= 13
After pairing with the first item -10, it is tempted to pick the pair (-10, 100) as the best pair as it has the least distance to 100. But further checking down the list, (-6, 100) in fact has a lesser distance to 100, hence it should be the best pair picked. After picking the pair, they are removed from their lists, leaving us

Pair	Calculation	Absolute distance from 100
(-10, 32)	100 - (-10 + 32)	= 78
(-10, 44)	100 - (-10 + 44)	= 66
(99, 32 )	100 - (99 + 32 )	= 31
(99, 44 )	100 - (99 + 44 )	= 43
(43, 32 )	100 - (43 + 32 )	= 25
(43, 44 )	100 - (43 + 44 )	= 13
Then next pair to pick will be (43, 44). Notice that the distance to 100 is 13 for this pair, which is higher than the pair (-10, 100), but only because 100 has been paired with -6 and hence the pair (-10, 100) is gone. Moving on, we have these remaining

Pair	Calculation	Absolute distance from 100
(-10, 32) :	100 - (-10 + 32)	= 78
(99, 32 ) :	100 - (99 + 32 )	= 31
And finally (99, 32) is picked. Hence the output (-6, 100), (43, 44), (99, 32). Ignore the rest that have nothing to pair up.

Note: when there is a tie, just pick any pair, without worrying the consequence to the remaining candidates.

The challenge here is to complete the task with the least number of comparisons operating on the inputs. i.e. if all comparison result has to come from a function comp(a, b), then the least number of call to this function wins. Looping control etc. are not included. Three way comparison is essentially 2 operations. General purpose code only and no special purpose optimisation is required. Favour code that can verify the number of comparison calls, however, when using build in functions, please explain their complexity for us to examine.

"""

"""

ported from @PieCot solution

O(mn log mn)
The best pairs can be found computing the distances of all the possible pairs, and iteratively choosing the best pair among those remaining after filtering out the already chosen items.

The find_nearest_pairs_to_100 function takes the two lists in input and returns an ordered list with the chosen pairs.

The sorted function in Python is based on Timsort algorithm, that requires O(n log n) comparisons in the worst case (where n is the length of the list).

In this case the length of the list is the cardinality of the Cartesian product of the two input lists, i.e. mn (with n > m). Therefore, the total cost of this implementation is of O(mn log mn) comparisons, excluding the other comparison operations needed for filtering.

Including comparisons for filtering, at each iteration, in the worst case, all the items of the list are checked against the elements of the chosen pair; the length the pair_list is mn at the first iteration, (n-1)(m-1) at the second, (n-2)(m-2) at the third, and n-m+1 at the last step. So the total number of comparisons for filtering is O(n^3).

"""
def find_nearest_pairs_to_100(l, m):
    pair_list = sorted([((i, j), abs(100 - i - j)) for i in l for j in m], key=lambda x: x[1])
    chosen_pairs = []
    while pair_list:
        best_pair = pair_list[0][0]
        chosen_pairs.append(best_pair)
        pair_list = [(p, s) for (p, s) in pair_list if p[0] != best_pair[0] and p[1] != best_pair[1]]
    return chosen_pairs

def main():
    assert(find_nearest_pairs_to_100([-10, 99, -6, 43], [100, 32, 44]) == [(-6, 100), (43, 44), (99, 32)])

main()
