/*

Write a function that when given a buffer b (1 - 104857600 bytes long) and a number of bits n (1 <= n <= 64), splits the buffer into chunks of n bits. Right-pad the last chunk with 0s up to n bits.

e.g.

Given the buffer b = "f0oBaR" or equivalently [102,48,111,66,97,82] and n = 5, return

[12, 24, 24, 6, 30, 16, 19, 1, 10, 8]
This is because the above buffer, when represented as binary looks like:

01100110 00110000 01101111 01000010 01100001 01010010
And when re-grouped into 5s looks like:

01100 11000 11000 00110 11110 10000 10011 00001 01010 010[00]
Which when converted back into decimal gives the answer.

Notes
You may use whatever data type makes the most sense in your language to represent the buffer. In PHP you'd probably use a string, in Node you might want to use a Buffer
If you use a string to represent the buffer, assume it's ASCII for the char -> int conversion
You may use an array of ints (0-255) for input if you prefer
Return value must be an array or list of ints
Test Cases
> b = "Hello World", n = 50
318401791769729, 412278856237056

> b = [1,2,3,4,5], n = 1
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1

> b = "codegolf", n = 32
1668244581, 1735355494

> b = "codegolf" n = 64
7165055918859578470

> b = "codegolf" n = 7
49, 91, 108, 70, 43, 29, 94, 108, 51, 0

> b = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque vel est eu velit lacinia iaculis. Nulla facilisi. Mauris vitae elit sapien. Nullam odio nulla, laoreet at lorem eu, elementum ultricies libero. Praesent orci elit, sodales consectetur magna eget, pulvinar eleifend mi. Ut euismod leo ut tortor ultrices blandit. Praesent dapibus tincidunt velit vitae viverra. Nam posuere dui quis ipsum iaculis, quis tristique nisl tincidunt. Aliquam ac ligula a diam congue tempus sit amet quis nisl. Nam lacinia ante vitae leo efficitur, eu tincidunt metus condimentum. Cras euismod quis quam vitae imperdiet. Ut at est turpis.", n = 16
19567, 29285, 27936, 26992, 29557, 27936, 25711, 27759, 29216, 29545, 29728, 24941, 25972, 11296, 25455, 28275, 25955, 29797, 29813, 29216, 24932, 26992, 26995, 25449, 28263, 8293, 27753, 29742, 8272, 25964, 27749, 28276, 25971, 29045, 25888, 30309, 27680, 25971, 29728, 25973, 8310, 25964, 26996, 8300, 24931, 26990, 26977, 8297, 24931, 30060, 26995, 11808, 20085, 27756, 24864, 26209, 25449, 27753, 29545, 11808, 19809, 30066, 26995, 8310, 26996, 24933, 8293, 27753, 29728, 29537, 28777, 25966, 11808, 20085, 27756, 24941, 8303, 25705, 28448, 28277, 27756, 24876, 8300, 24943, 29285, 25972, 8289, 29728, 27759, 29285, 27936, 25973, 11296, 25964, 25965, 25966, 29813, 27936, 30060, 29810, 26979, 26981, 29472, 27753, 25189, 29295, 11808, 20594, 24933, 29541, 28276, 8303, 29283, 26912, 25964, 26996, 11296, 29551, 25697, 27749, 29472, 25455, 28275, 25955, 29797, 29813, 29216, 28001, 26478, 24864, 25959, 25972, 11296, 28789, 27766, 26990, 24946, 8293, 27749, 26982, 25966, 25632, 28009, 11808, 21876, 8293, 30057, 29549, 28516, 8300, 25967, 8309, 29728, 29807, 29300, 28530, 8309, 27764, 29289, 25445, 29472, 25196, 24942, 25705, 29742, 8272, 29281, 25971, 25966, 29728, 25697, 28777, 25205, 29472, 29801, 28259, 26980, 30062, 29728, 30309, 27753, 29728, 30313, 29793, 25888, 30313, 30309, 29298, 24878, 8270, 24941, 8304, 28531, 30053, 29285, 8292, 30057, 8305, 30057, 29472, 26992, 29557, 27936, 26977, 25461, 27753, 29484, 8305, 30057, 29472, 29810, 26995, 29801, 29045, 25888, 28265, 29548, 8308, 26990, 25449, 25717, 28276, 11808, 16748, 26993, 30049, 27936, 24931, 8300, 26983, 30060, 24864, 24864, 25705, 24941, 8291, 28526, 26485, 25888, 29797, 28016, 30067, 8307, 26996, 8289, 28005, 29728, 29045, 26995, 8302, 26995, 27694, 8270, 24941, 8300, 24931, 26990, 26977, 8289, 28276, 25888, 30313, 29793, 25888, 27749, 28448, 25958, 26217, 25449, 29813, 29228, 8293, 29984, 29801, 28259, 26980, 30062, 29728, 28005, 29813, 29472, 25455, 28260, 26989, 25966, 29813, 27950, 8259, 29281, 29472, 25973, 26995, 28015, 25632, 29045, 26995, 8305, 30049, 27936, 30313, 29793, 25888, 26989, 28773, 29284, 26981, 29742, 8277, 29728, 24948, 8293, 29556, 8308, 30066, 28777, 29486

> b = [2,31,73,127,179,233], n = 8
2, 31, 73, 127, 179, 233

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test(
		[]int64{102, 48, 111, 66, 97, 82}, 5,
		[]int64{12, 24, 24, 6, 30, 16, 19, 1, 10, 8},
	)

	test(
		string2int("Hello World"), 50,
		[]int64{318401791769729, 412278856237056},
	)

	test(
		[]int64{1, 2, 3, 4, 5}, 1,
		[]int64{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	)

	test(
		string2int("codegolf"), 32,
		[]int64{1668244581, 1735355494},
	)

	test(
		string2int("codegolf"), 64,
		[]int64{7165055918859578470},
	)

	test(
		string2int("codegolf"), 7,
		[]int64{49, 91, 108, 70, 43, 29, 94, 108, 51, 0},
	)

	test(
		string2int("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque vel est eu velit lacinia iaculis. Nulla facilisi. Mauris vitae elit sapien. Nullam odio nulla, laoreet at lorem eu, elementum ultricies libero. Praesent orci elit, sodales consectetur magna eget, pulvinar eleifend mi. Ut euismod leo ut tortor ultrices blandit. Praesent dapibus tincidunt velit vitae viverra. Nam posuere dui quis ipsum iaculis, quis tristique nisl tincidunt. Aliquam ac ligula a diam congue tempus sit amet quis nisl. Nam lacinia ante vitae leo efficitur, eu tincidunt metus condimentum. Cras euismod quis quam vitae imperdiet. Ut at est turpis."), 16,
		[]int64{19567, 29285, 27936, 26992, 29557, 27936, 25711, 27759, 29216, 29545, 29728, 24941, 25972, 11296, 25455, 28275, 25955, 29797, 29813, 29216, 24932, 26992, 26995, 25449, 28263, 8293, 27753, 29742, 8272, 25964, 27749, 28276, 25971, 29045, 25888, 30309, 27680, 25971, 29728, 25973, 8310, 25964, 26996, 8300, 24931, 26990, 26977, 8297, 24931, 30060, 26995, 11808, 20085, 27756, 24864, 26209, 25449, 27753, 29545, 11808, 19809, 30066, 26995, 8310, 26996, 24933, 8293, 27753, 29728, 29537, 28777, 25966, 11808, 20085, 27756, 24941, 8303, 25705, 28448, 28277, 27756, 24876, 8300, 24943, 29285, 25972, 8289, 29728, 27759, 29285, 27936, 25973, 11296, 25964, 25965, 25966, 29813, 27936, 30060, 29810, 26979, 26981, 29472, 27753, 25189, 29295, 11808, 20594, 24933, 29541, 28276, 8303, 29283, 26912, 25964, 26996, 11296, 29551, 25697, 27749, 29472, 25455, 28275, 25955, 29797, 29813, 29216, 28001, 26478, 24864, 25959, 25972, 11296, 28789, 27766, 26990, 24946, 8293, 27749, 26982, 25966, 25632, 28009, 11808, 21876, 8293, 30057, 29549, 28516, 8300, 25967, 8309, 29728, 29807, 29300, 28530, 8309, 27764, 29289, 25445, 29472, 25196, 24942, 25705, 29742, 8272, 29281, 25971, 25966, 29728, 25697, 28777, 25205, 29472, 29801, 28259, 26980, 30062, 29728, 30309, 27753, 29728, 30313, 29793, 25888, 30313, 30309, 29298, 24878, 8270, 24941, 8304, 28531, 30053, 29285, 8292, 30057, 8305, 30057, 29472, 26992, 29557, 27936, 26977, 25461, 27753, 29484, 8305, 30057, 29472, 29810, 26995, 29801, 29045, 25888, 28265, 29548, 8308, 26990, 25449, 25717, 28276, 11808, 16748, 26993, 30049, 27936, 24931, 8300, 26983, 30060, 24864, 24864, 25705, 24941, 8291, 28526, 26485, 25888, 29797, 28016, 30067, 8307, 26996, 8289, 28005, 29728, 29045, 26995, 8302, 26995, 27694, 8270, 24941, 8300, 24931, 26990, 26977, 8289, 28276, 25888, 30313, 29793, 25888, 27749, 28448, 25958, 26217, 25449, 29813, 29228, 8293, 29984, 29801, 28259, 26980, 30062, 29728, 28005, 29813, 29472, 25455, 28260, 26989, 25966, 29813, 27950, 8259, 29281, 29472, 25973, 26995, 28015, 25632, 29045, 26995, 8305, 30049, 27936, 30313, 29793, 25888, 26989, 28773, 29284, 26981, 29742, 8277, 29728, 24948, 8293, 29556, 8308, 30066, 28777, 29486},
	)

	test(
		[]int64{2, 31, 73, 127, 179, 233}, 8,
		[]int64{2, 31, 73, 127, 179, 233},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(array []int64, nbits int64, expected []int64) {
	result := bits(array, nbits)
	fmt.Println(result)
	assert(slices.Equal(result, expected))
}

func bits(array []int64, nbits int64) []int64 {
	var (
		count  int64
		total  int64
		result []int64
	)
	for {
		if nbits <= count {
			count -= nbits
			result = append(result, total>>count)
			total &= (1 << count) - 1
		} else if len(array) > 0 {
			count += 8
			total <<= 8
			total += array[0]
			array = array[1:]
		} else {
			if count != 0 {
				result = append(result, total<<(nbits-count))
			}
			return result
		}
	}
}

func string2int(input string) []int64 {
	var result []int64
	for _, symbol := range input {
		result = append(result, int64(symbol))
	}
	return result
}
