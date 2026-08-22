/*

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.


Constraints:

-2^31 <= val <= 2^31 - 1
At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.

*/

package main

import (
	"math/rand"
	"time"
)

func main() {
	r := NewRandomSet()
	assert(r.Insert(1) == true)
	assert(r.Remove(2) == false)
	assert(r.Insert(2) == true)
	x := r.Random()
	assert(x == 1 || x == 2)
	assert(r.Remove(1) == true)
	assert(r.Insert(2) == false)
	for i := 0; i < 1e6; i++ {
		assert(r.Random() == 2)
	}
	assert(r.Remove(2) == true)

	for i := 10; i <= 20; i++ {
		assert(r.Insert(i) == true)
	}
	for i := 12; i <= 20; i += 2 {
		assert(r.Remove(i) == true)
	}
	for i := 0; i < 1e6; i++ {
		x := r.Random()
		assert(10 <= x && x <= 20)
		assert(x == 10 || (x&1) != 0)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type RandomSet struct {
	rng     *rand.Rand
	indices map[int]int
	values  []int
}

func NewRandomSet() *RandomSet {
	now := time.Now()
	source := rand.NewSource(now.UnixNano())
	return &RandomSet{
		rng:     rand.New(source),
		indices: make(map[int]int),
	}
}

func (r *RandomSet) Insert(val int) bool {
	_, exist := r.indices[val]
	if exist {
		return false
	}

	r.indices[val] = len(r.values)
	r.values = append(r.values, val)
	return true
}

func (r *RandomSet) Remove(val int) bool {
	i, exist := r.indices[val]
	if !exist {
		return false
	}

	n := len(r.values) - 1
	x := r.values[n]
	r.indices[x] = i
	r.values[i], r.values[n] = r.values[n], r.values[i]
	r.values = r.values[:n]
	delete(r.indices, val)

	return true
}

func (r *RandomSet) Random() int {
	n := len(r.values)
	if n == 0 {
		return 0
	}

	i := r.rng.Intn(n)
	return r.values[i]
}
