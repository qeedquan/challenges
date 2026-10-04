/*

I have a list of decimal digits:

4, 4, 4, 7, 7, 9, 9, 9, 9, 2, 2, 2, 4, 4

The list of decimal digits are known as items. We can form "chunks" from these items by grouping together identical and adjacent numbers. I want to assign each chunk a unique number, starting from 1, and increasing by 1 in the order the chunks appear in the original list. So, the output for the given example would look like this:

1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5

Input format
A list of digits. (0-9) You may use your language built-ins to read this list however you want. Encoding: ASCII

Output format
A series of decimal numbers, separated by a delimiter. Your program must always use the same delimiter. The delimiter must be longer than 0 bits. Encoding: ASCII

Standard loopholes apply.

*/

fn chunk(a: Vec<isize>) -> Vec<isize> {
    let mut r = vec![];
    let mut c = 1;
    let mut i = 0;
    let n = a.len();
    while i < n {
        let mut j = i;
        while j < n && a[i] == a[j] {
            j += 1;
        }

        for _ in i..j {
            r.push(c);
        }

        c += 1;
        i = j;
    }
    r
}

fn main() {
    assert_eq!(
        chunk(vec![4, 4, 4, 7, 7, 9, 9, 9, 9, 2, 2, 2, 4, 4]),
        vec![1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5]
    );
}
