/*

You get a list of integers, and you have to write a function mirror that returns the "mirror" (or symmetric) version of this list:
i.e. the middle element is the greatest, then the next greatest on both sides, then the next greatest, and so on...

More info
The list will always consist of integers in range -1000..1000 and will vary in size between 0 and 10000.
Your function should not mutate the input array, and this will be tested (where applicable).
Notice that the returned list will always be of odd size, since there will always be a definitive middle element.

Examples
[]  -->  []
[1]  -->  [1]
[2, 1]  -->  [1, 2, 1]
[1, 3, 2]  -->  [1, 2, 3, 2, 1]
[-8, 42, 18, 0, -16]  -->  [-16, -8, 0, 18, 42, 18, 0, -8, -16]
[-3, 15, 8, -1, 7, -1] --> [-3, -1, -1, 7, 8, 15, 8, 7, -1, -1, -3]
[-5, 10, 8, 10, 2, -3, 10] --> [-5, -3, 2, 8, 10, 10, 10, 10, 10, 8, 2, -3, -5]

Good luck!

*/

fn main() {
    assert_eq!(mirror(&mut []), vec![]);
    assert_eq!(mirror(&mut [1]), vec![1]);
    assert_eq!(mirror(&mut [2, 1]), vec![1, 2, 1]);
    assert_eq!(mirror(&mut [1, 3, 2]), vec![1, 2, 3, 2, 1]);
    assert_eq!(
        mirror(&mut [-8, 42, 18, 0, -16]),
        vec![-16, -8, 0, 18, 42, 18, 0, -8, -16]
    );
    assert_eq!(
        mirror(&mut [-3, 15, 8, -1, 7, -1]),
        vec![-3, -1, -1, 7, 8, 15, 8, 7, -1, -1, -3]
    );
    assert_eq!(
        mirror(&mut [-5, 10, 8, 10, 2, -3, 10]),
        vec![-5, -3, 2, 8, 10, 10, 10, 10, 10, 8, 2, -3, -5]
    );
}

fn mirror(array: &mut [isize]) -> Vec<isize> {
    let (mut result, length) = (vec![], array.len());
    if length == 0 {
        return result;
    }

    array.sort();
    for i in 0..length {
        result.push(array[i]);
    }
    for i in (0..length - 1).rev() {
        result.push(array[i]);
    }
    return result;
}
