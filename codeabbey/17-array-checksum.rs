/*

Checksums are small values calculated from big amount of data to test whether data are consistent, i.e. whether they contain errors.

For example if Anna sends some file to Bob, she can calculate its checksum and tell it Bob, who will calculate checksum on the file he received, and compare it with the value told by Anna.

Another, even more common example - any bank card you use has a checksum in the last digit of its number so any device could prevent you from entering wrong number by mistake (you may read more in the exercise on Luhn Algorithm).

For programming several further tasks we'll use similar way to check whether resulting array is correct or not. To avoid problems with such tasks let us now practice the checksum calculating algorithm which will be involved.

Problem statement
You will be given the array for which checksum should be calculated. Perform calculation as follows: for each element of the array (starting from beginning) add this element to result variable and multiply this sum by 113 - this new value taken by modulo 10000007 should become the next value of result, and so on.

Read the article on checksum for detailed description of this algorithm. An example of calculation also could be found there.

Input data will tell the length of an array in the first line.
Array values themselves follow in the second line, separated by spaces.
Answer should have a single value - calculated checksum.

Example:

input data:
6
3 1 4 1 5 9

answer:
8921379
All input values are between 0 and 1,000,000,000 - be sure to take care of possible overflow in progress of calculations!

*/

fn main() {
    assert_eq!(checksum(&[3, 1, 4, 1, 5, 9]), 8921379);
}

fn checksum(a: &[isize]) -> isize {
    let m = 10000007;
    let mut r = 0;
    for &x in a {
        r = (r + x) * 113;
        r %= m;
    }
    r
}
