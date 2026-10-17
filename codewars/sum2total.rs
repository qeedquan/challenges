/*

Write a function that takes an array/list of numbers and returns a number such that

Explanation total([1,2,3,4,5]) => 48

1+2=3--\ 3+5 =>     8 \
2+3=5--/ \            ==  8+12=>20\     
          ==>5+7=> 12 / \           20+28 => 48
3+4=7--\ /            == 12+16=>28/
4+5=9--/ 7+9 =>     16  /

if total([1,2,3]) => 8 then

first+second => 3 \
                   then 3+5 => 8
second+third => 5 /

Examples
total([-1,-1,-1]) => -4
total([1,2,3,4])  => 20

Note: each array/list will have at least an element and all elements will be valid numbers.

*/

fn main() {
    assert_eq!(total(&[1, 2, 3, 4, 5]), 48);
    assert_eq!(total(&[1, 2, 3]), 8);
    assert_eq!(total(&[-1, -1, -1]), -4);
    assert_eq!(total(&[1, 2, 3, 4]), 20);
}

fn total(a: &[isize]) -> isize {
    let n = a.len();
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return a[0];
    }

    let mut b = vec![];
    for i in 1..n {
        b.push(a[i] + a[i - 1]);
    }
    return total(&b);
}
