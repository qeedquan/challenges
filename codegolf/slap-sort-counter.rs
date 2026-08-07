/*

Slap sort is such a sorting strategy:

Repeatedly move to end the first element which is larger than the following element, until sorted(aka. no such element exist).
This is easily coded when elements are stored in a gravity stack, e.g. in game EXAPUNKS.

Now, given some values, count how many operations done during this sorting process.

I decide that input is a permutation of {1,2,3,...,n} since that shouldn't help a pure simulation but may help formula-based solution(if it exists) which I encourage.

Example
Given array [3,2,1], it goes like following:

[3]2 1
[2]1 3
 1[3]2
 1 2 3
which takes 3 steps.

Test cases
3,2,1 => 3
1,3,5,2,4 => 5
1,2,5,3,4 => 1
3,6,5,4,1,2 => 10
2,5,1,3,4 => 8
Shortest code in each language wins.

*/

fn main() {
    assert_eq!(slapsort(&mut [3, 2, 1]), 3);
    assert_eq!(slapsort(&mut [1, 3, 5, 2, 4]), 5);
    assert_eq!(slapsort(&mut [1, 2, 5, 3, 4]), 1);
    assert_eq!(slapsort(&mut [3, 6, 5, 4, 1, 2]), 10);
    assert_eq!(slapsort(&mut [2, 5, 1, 3, 4]), 8);
}

fn slapsort(list: &mut [isize]) -> usize {
    if list.len() == 0 {
        return 0;
    }

    let mut steps = 0;
    'top: loop {
        for i in 0..list.len() - 1 {
            if list[i] > list[i + 1] {
                list[i..].rotate_left(1);
                steps += 1;
                continue 'top;
            }
        }
        break;
    }
    steps
}
