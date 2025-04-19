/*

The array duplicates problem is when one integer is in an array for more than once.

If you are given an array with integers between 1 and 1,000,000 or in some other interval and one integer is in the array twice. How can you determine which one?

Your task is to write code to solve the challenge.

Note: try to find the most efficient way to solve this challenge.

*/

use std::collections::*;

fn main() {
    assert_eq!(find_duplicates(vec![1, 2, 5, 5, 3, 4]), (5, true));
    assert_eq!(find_duplicates(vec![10, 10]), (10, true));
    assert_eq!(find_duplicates(vec![10, 1, 3, 2, 14]), (0, false));
}

fn find_duplicates(values: Vec<isize>) -> (isize, bool) {
    let mut seen: HashMap<isize, bool> = HashMap::new();
    for value in values {
        match seen.get(&value) {
            Some(_) => {
                return (value, true);
            }
            _ => {
                seen.insert(value, true);
            }
        }
    }
    return (0, false);
}
