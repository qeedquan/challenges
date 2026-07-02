/*

An array is called zero-plentiful if it contains multiple zeros, and every sequence of zeros is at least 4 items long.

Your task is to return the number of zero sequences if the given array is zero-plentiful, oherwise 0.

Examples
[0, 0, 0, 0, 0, 1]  -->  1
# 1 group of 5 zeros (>= 4), thus the result is 1

[0, 0, 0, 0, 1, 0, 0, 0, 0]  -->  2
# 2 group of 4 zeros (>= 4), thus the result is 2

[0, 0, 0, 0, 1, 0]  -->  0 
# 1 group of 4 zeros and 1 group of 1 zero (< 4)
# _every_ sequence of zeros must be at least 4 long, thus the result is 0

[0, 0, 0, 1, 0, 0]  -->  0
# 1 group of 3 zeros (< 4) and 1 group of 2 zeros (< 4)

[1, 2, 3, 4, 5]  -->  0
# no zeros

[]  -->  0
# no zeros

*/

fn main() {
    assert_eq!(zero_plentiful(&vec![0, 0, 0, 0, 0, 1]), 1);
    assert_eq!(zero_plentiful(&vec![0, 0, 0, 0, 1, 0, 0, 0, 0]), 2);
    assert_eq!(zero_plentiful(&vec![0, 0, 0, 0, 1, 0]), 0);
    assert_eq!(zero_plentiful(&vec![0, 0, 0, 1, 0, 0]), 0);
    assert_eq!(zero_plentiful(&vec![1, 2, 3, 4, 5]), 0);
    assert_eq!(zero_plentiful(&vec![]), 0);
}

fn zero_plentiful(x: &Vec<isize>) -> isize {
    let (mut c, mut i, n) = (0, 0, x.len());
    while i < n {
        let mut j = i + 1;
        while j < n && x[i] == x[j] {
            j += 1;
        }
        if x[i] == 0 {
            if j - i >= 4 {
                c += 1;
            } else {
                return 0;
            }
        }
        i = j;
    }
    return c;
}
