/*

Given two sparse vectors, compute their dot product.
Implement class SparseVector:
SparseVector(nums) Initializes the object with the vector nums

    dotProduct(vec) Compute the dot product between the instance of SparseVectorand vec

A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.
Follow up: What if only one of the vectors is sparse?

Example 1:
Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8

Example 2:
Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0

Example 3:
Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6

Constraints:
n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100

*/

package main

func main() {
	test([]int{1, 0, 0, 2, 3}, []int{0, 3, 0, 4, 0}, 8)
	test([]int{0, 1, 0, 0, 0}, []int{0, 0, 0, 0, 2}, 0)
	test([]int{0, 1, 0, 0, 2, 0, 0}, []int{1, 0, 0, 0, 3, 0, 4}, 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b []int, r int) {
	u := newsparse(a)
	v := newsparse(b)
	assert(dot(u, v) == r)
}

type Sparse [][2]int

func newsparse(a []int) Sparse {
	var s Sparse
	for i, v := range a {
		if v != 0 {
			s = append(s, [2]int{i, v})
		}
	}
	return s
}

func dot(a, b Sparse) int {
	v := 0
	for i, j := 0, 0; i < len(a) && j < len(b); {
		switch {
		case a[i][0] < b[j][0]:
			i++
		case a[i][0] > b[j][0]:
			j++
		default:
			v += a[i][1] * b[j][1]
			i, j = i+1, j+1
		}
	}
	return v
}
