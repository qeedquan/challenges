/*

Please write a function that sums a list, but ignores any duplicate items in the list.

For instance, for the list [3, 4, 3, 6] , the function should return 10.

*/

fn main() {
    assert_eq!(sum_no_duplicates(&mut [3, 4, 3, 6]), 10);
}

fn sum_no_duplicates(numbers: &mut [isize]) -> isize {
    numbers.sort();

    let mut total = 0;
    let mut start = 0;
    while start < numbers.len() {
        let mut end = start + 1;
        while end < numbers.len() && numbers[start] == numbers[end] {
            end += 1;
        }
        if end - start == 1 {
            total += numbers[start];
        }
        start = end;
    }
    total
}
