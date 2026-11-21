/*

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id


Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation:
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5


Constraints:

1 <= length <= 5 * 10^4
0 <= index < length
0 <= val <= 10^9
0 <= snap_id < (the total number of times we call snap())
At most 5 * 10^4 calls will be made to set, snap, and get.

Hint 1
Use a list of lists, adding both the element and the snap_id to each index.

*/

package main

import "sort"

func main() {
	s := NewSnapshot(3)
	s.Set(0, 5)
	s.Snap()
	s.Set(0, 6)
	assert(s.Get(0, 0) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Snapshot struct {
	array    [][][2]int
	position int
}

func NewSnapshot(length int) *Snapshot {
	return &Snapshot{
		array: make([][][2]int, length),
	}
}

func (s *Snapshot) Set(index, value int) {
	s.array[index] = append(s.array[index], [2]int{s.position, value})
}

func (s *Snapshot) Snap() int {
	s.position += 1
	return s.position - 1
}

func (s *Snapshot) Get(index, snapid int) int {
	index2 := sort.Search(len(s.array[index]), func(i int) bool {
		return s.array[index][i][0] > snapid
	})

	if index2--; index2 < 0 {
		return 0
	}
	return s.array[index][index2][1]
}
