/*

Every Friday and Saturday night, farmer counts amount of sheep returned back to his farm (sheep returned on Friday stay and don't leave for a weekend).

Sheep return in groups each of the days -> you will be given two arrays with these numbers (one for Friday and one for Saturday night). Entries are always positive ints, higher than zero.

Farmer knows the total amount of sheep, this is a third parameter. You need to return the amount of sheep lost (not returned to the farm) after final sheep counting on Saturday.

Example 1: Input: {1, 2}, {3, 4}, 15 --> Output: 5

Example 2: Input: {3, 1, 2}, {4, 5}, 21 --> Output: 6

Good luck! :-)

*/

func lostsheep(_ friday: [Int], _ saturday: [Int], _ total: Int) -> Int {
    return total - (friday.reduce(0, +) + saturday.reduce(0, +))
}

assert(lostsheep([1, 2], [3, 4], 15) == 5)
assert(lostsheep([3, 1, 2], [4, 5], 21) == 6)
