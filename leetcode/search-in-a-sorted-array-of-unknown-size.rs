/*

Given an integer array sorted in ascending order, write a function to search target in nums.
If target exists, then return its index, otherwise return -1.
However, the array size is unknown to you.
You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.

Example 1:

Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: array = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Note:

    You may assume that all elements in the array are unique.
    The value of each element in the array will be in the range [-9999, 9999].

*/

fn main() {
    for value in 0..=10000 {
        let number = Number { value: value };
        assert_eq!(search(&number, value), value);
    }

    assert_eq!(search(&vec![-1, 0, 3, 5, 9, 12], 9), 4);
    assert_eq!(search(&vec![-1, 0, 3, 5, 9, 12], 2), -1);
}

struct Number {
    value: isize,
}

trait ArrayReader {
    fn get(&self, _: isize) -> isize;
}

impl ArrayReader for Number {
    fn get(&self, index: isize) -> isize {
        if index <= self.value {
            return index;
        }
        return (1 << 31) - 1;
    }
}

impl ArrayReader for Vec<isize> {
    fn get(&self, index: isize) -> isize {
        let index = index as usize;
        if index < self.len() {
            return self[index];
        }
        return (1 << 31) - 1;
    }
}

fn search(reader: &dyn ArrayReader, target: isize) -> isize {
    let mut right = 1;
    while reader.get(right) < target {
        right <<= 1;
    }

    let mut left = right >> 1;
    let mut index = -1;
    while left <= right {
        let mid = left + (right - left) / 2;
        let response = reader.get(mid);
        if response >= target {
            index = mid;
            right = mid - 1;
        } else if response < target {
            left = mid + 1;
        }
    }
    if index != -1 && reader.get(index) == target {
        return index;
    }
    return -1;
}
