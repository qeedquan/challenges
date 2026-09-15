/*

A friend of mine takes the sequence of all numbers from 1 to n (where n > 0).
Within that sequence, he chooses two numbers, a and b.
He says that the product of a and b should be equal to the sum of all numbers in the sequence, excluding a and b.
Given a number n, could you tell me the numbers he excluded from the sequence?
The function takes the parameter: n (n is always strictly greater than 0) and returns an array or a string (depending on the language) of the form:

[(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or or [{a, b}, ...]

with all (a, b) which are the possible removed numbers in the sequence 1 to n.

[(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or ... will be sorted in increasing order of the "a".

It happens that there are several possible (a, b). The function returns an empty array (or an empty string) if no possible numbers are found which will prove that my friend has not told the truth! (Go: in this case return nil).

Examples:
removNb(26) should return [(15, 21), (21, 15)]
or
removNb(26) should return { {15, 21}, {21, 15} }
or
removeNb(26) should return [[15, 21], [21, 15]]
or
removNb(26) should return [ {15, 21}, {21, 15} ]
or
removNb(26) should return "15 21, 21 15"
or

in C:
removNb(26) should return  {{15, 21}{21, 15}} tested by way of strings.
Function removNb should return a pointer to an allocated array of Pair pointers, each one also allocated.

Note
See examples of returns for each language in "RUN SAMPLE TESTS"

*/

fn main() {
    assert_eq!(rmnb(26), vec![(15, 21), (21, 15)]);
    assert_eq!(rmnb(100), vec![]);
    assert_eq!(rmnb(101), vec![(55, 91), (91, 55)]);
}

fn rmnb(n: isize) -> Vec<(isize, isize)> {
    let mut r = vec![];
    let s = n * (n + 1) / 2;
    for i in 1..n + 1 {
        if (s + 1) % (i + 1) != 0 {
            continue;
        }

        let j = (s + 1) / (i + 1) - 1;
        if 1 <= j && j <= n {
            r.push((i, j));
        }
    }
    r
}
