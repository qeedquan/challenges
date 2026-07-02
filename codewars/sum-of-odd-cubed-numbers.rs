/*

Find the sum of the odd numbers within an array, after cubing the initial integers. The function should return undefined if any of the values aren't numbers.

*/

fn main() {
    assert_eq!(cubeodd(&vec![1, 2, 3, 4]), 28);
    assert_eq!(cubeodd(&vec![-3, -2, 2, 3]), 0);
}

fn cubeodd(array: &Vec<isize>) -> isize {
    let mut total = 0;
    for value in array {
        let cubed = value * value * value;
        if cubed % 2 != 0 {
            total += cubed;
        }
    }
    total
}
