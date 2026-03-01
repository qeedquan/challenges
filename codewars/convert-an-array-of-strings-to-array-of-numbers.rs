/*

Oh no!
Some really funny web dev gave you a sequence of numbers from his API response as an sequence of strings!

You need to cast the whole array to the correct type.

Create the function that takes as a parameter a sequence of numbers represented as strings and outputs a sequence of numbers.

ie:["1", "2", "3"] to [1, 2, 3]

Note that you can receive floats as well.

*/

fn main() {
    assert_eq!(to_number_array(&["1", "2", "3"]), vec![1.0, 2.0, 3.0]);
}

fn to_number_array(numbers: &[&'static str]) -> Vec<f64> {
    let mut result = vec![];
    for number in numbers {
        if let Ok(value) = number.parse::<f64>() {
            result.push(value);
        }
    }
    result
}
