/*

Given a list of strings in any convenient format display the amount of comparisons between individual characters that a merge sort algorithm would perform.

The merge-sort algorithm is a divide & conquer method for sorting lists. It divides the unsorted list into n sublists, each containing one element (a list of one element is considered sorted). We repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

The merging process compares elements from the array on the left to elements from the array on the right in order, filling in the resulting array.

In particular, we will use it with a comparator that naively scans the strings for the first difference and returns a value in range [-1, 0, 1].

The reference implementation to validate yours against: Try it online!

let c = 0;
const mergeSort = arr => {
  if (arr.length <= 1) return arr;
  const mid = Math.floor(arr.length / 2);
  return merge(mergeSort(arr.slice(0, mid)), mergeSort(arr.slice(mid)));
};
const merge = (left, right) => {
  let res = [];
  while (left.length && right.length) {
    res.push(cmp(left[0], right[0]) <= 0 ? left.shift() : right.shift());
  }
  return [...res, ...left, ...right];
};
const cmp = (s1, s2) => {
	console.log("XX", s1, s2);
  c++;
  for (let i = 0; i < Math.min(s1.length, s2.length); i++, c++) {
    if (s1[i] !== s2[i]) return s1[i] < s2[i] ? -1 : 1;
  }
  return s1.length - s2.length;
};
const strings = ["banana", "apple", "grape", "cherry", "mango"];
c = 0;
const sortedStrings = mergeSort(strings);
console.log(sortedStrings);
console.log(`Total character-wise comparisons: ${c}`);

Some test cases:

['banana','anana','nana','ana','na','a'] => 18
['aaaa','aaab','aaac','aaad'] => 16
['aaad','aaab','aaac','aaaa'] => 20
['mor','tor','rot','tor','rotor'] => 13
Shortest code wins.


*/

package main

import "fmt"

func main() {
	fmt.Println(mergesort([]string{"banana", "apple", "grape", "cherry", "mango"}))
}

func mergesort(a []string) ([]string, int) {
	if len(a) < 2 {
		return a, 0
	}

	i := len(a) / 2
	l, cl := mergesort(a[:i])
	r, cr := mergesort(a[i:])
	m, cm := merge(l, r)
	return m, cl + cr + cm
}

func merge(l, r []string) ([]string, int) {
	m := []string{}
	c := 0
	for len(l) > 0 && len(r) > 0 {
		i, nc := cmp(l[0], r[0])
		if i <= 0 {
			m = append(m, l[0])
			l = l[1:]
		} else {
			m = append(m, r[0])
			r = r[1:]
		}
		c += nc
	}
	m = append(m, l...)
	m = append(m, r...)
	return m, c
}

func cmp(s, t string) (int, int) {
	c := 1
	for i := range min(len(s), len(t)) {
		if s[i] < t[i] {
			return -1, c
		}
		if s[i] > t[i] {
			return 1, c
		}
		c += 1
	}
	return len(s) - len(t), c
}
