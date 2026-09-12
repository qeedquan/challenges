/*

Given an array of integers of any length, return an array that has 1 added to the value represented by the array.

If the array is invalid (empty, or contains negative integers or integers with more than 1 digit), return nil (or your language's equivalent).

Examples
Valid arrays

[4, 3, 2, 5] would return [4, 3, 2, 6] (4325 + 1 = 4326)
[1, 2, 3, 9] would return [1, 2, 4, 0] (1239 + 1 = 1240)
[9, 9, 9, 9] would return [1, 0, 0, 0, 0] (9999 + 1 = 10000)
[0, 1, 3, 7] would return [0, 1, 3, 8] (0137 + 1 = 0138)
Invalid arrays

[] is invalid because it is empty
[1, -9] is invalid because -9 is not a non-negative integer
[1, 2, 33] is invalid because 33 is not a single-digit integer

*/

fn main() {
    assert_eq!(plus1(&[4, 3, 2, 5]), Some(vec![4, 3, 2, 6]));
    assert_eq!(plus1(&[1, 2, 3, 9]), Some(vec![1, 2, 4, 0]));
    assert_eq!(plus1(&[9, 9, 9, 9]), Some(vec![1, 0, 0, 0, 0]));
    assert_eq!(plus1(&[0, 1, 3, 7]), Some(vec![0, 1, 3, 8]));
    assert_eq!(plus1(&[2, 3, 9]), Some(vec![2, 4, 0]));
    assert_eq!(plus1(&[0]), Some(vec![1]));

    assert_eq!(plus1(&[]), None);
    assert_eq!(plus1(&[1, -9]), None);
    assert_eq!(plus1(&[1, 2, 33]), None);
}

fn plus1(digits: &[isize]) -> Option<Vec<isize>> {
    if digits.len() == 0 {
        return None;
    }

    let (mut carry, mut result) = (1, vec![]);
    for &value in digits.into_iter().rev() {
        if value < 0 || value > 9 {
            return None;
        }

        let mut value = value + carry;
        carry = 0;
        if value >= 10 {
            value %= 10;
            carry = 1;
        }
        result.push(value);
    }

    if carry != 0 {
        result.push(carry);
    }

    result.reverse();
    return Some(result);
}
