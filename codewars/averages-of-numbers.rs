/*

#Get the averages of these numbers

Write a method, that gets an array of integer-numbers and return an array of the averages of each integer-number and his follower, if there is one.

Example:

Input:  [ 1, 3, 5, 1, -10]
Output:  [ 2, 4, 3, -4.5]
If the array has 0 or 1 values or is null, your method should return an empty array.

Have fun coding it and please don't forget to vote and rank this kata! :-)

*/

fn main() {
    println!("{:?}", averages(&[1.0, 3.0, 5.0, 1.0, -10.0]));
}

fn averages(numbers: &[f64]) -> Vec<f64> {
    let mut result = vec![];
    for i in 1..numbers.len() {
        result.push((numbers[i - 1] + numbers[i]) * 0.5);
    }
    result
}
