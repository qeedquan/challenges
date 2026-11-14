/*

Task
A list S will be given. You need to generate a list T from it by following the given process:

Remove the first and last element from the list S and add them to the list T.
Reverse the list S
Repeat the process until list S gets emptied.
The above process results in the depletion of the list S. Your task is to generate list T without mutating the input List S.

Example
S = [1,2,3,4,5,6]
T = []

S = [2,3,4,5] => [5,4,3,2]
T = [1,6]

S = [4,3] => [3,4]
T = [1,6,5,2]

S = []
T = [1,6,5,2,3,4]
return T
Note
size of S goes up to 10^6
Keep the efficiency of your code in mind.
Do not mutate the Input.

*/

fn main() {
    assert_eq!(arrange(&vec![1, 2, 3, 4, 5, 6]), vec![1, 6, 5, 2, 3, 4]);
    assert_eq!(arrange(&vec![1, 2]), vec![1, 2]);
    assert_eq!(arrange(&vec![4, 3, 2]), vec![4, 2, 3]);
    assert_eq!(
        arrange(&vec![9, 7, -2, 8, 5, -3, 6, 5, 1]),
        vec![9, 1, 5, 7, -2, 6, -3, 8, 5]
    );
    assert_eq!(arrange(&vec![1]), vec![1]);
    assert_eq!(arrange(&vec![]), vec![]);
    assert_eq!(arrange(&vec![2, 4, 3, 4]), vec![2, 4, 3, 4]);
}

fn arrange(s: &Vec<isize>) -> Vec<isize> {
    let mut t = vec![];
    let mut p = 0;
    let n = s.len();
    for i in 0..n / 2 {
        if i & 1 != 0 {
            t.push(s[n - 1 - p]);
            t.push(s[p]);
        } else {
            t.push(s[p]);
            t.push(s[n - 1 - p]);
        }
        p += 1;
    }
    if n & 1 != 0 {
        t.push(s[n / 2]);
    }
    t
}
