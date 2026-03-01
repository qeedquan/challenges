/*

Agent 47, you have a new task! Among citizens of the city X are hidden 2 dangerous criminal twins. Your task is to identify them and eliminate!

Given an array of integers, your task is to find two same numbers and return one of them, for example in array [2, 3, 6, 34, 7, 8, 2] answer is 2.

If there are no twins in the city - return None or the equivalent in the language that you are using.

*/

fn main() {
    assert_eq!(elimination(&vec![2, 3, 6, 34, 7, 8, 2]), Some(2));
    assert_eq!(elimination(&vec![2, 3, 6, 34, 7, 8, 5]), None);
}

fn elimination(a: &Vec<isize>) -> Option<isize> {
    let n = a.len();
    for i in 0..n {
        for j in i + 1..n {
            if a[i] == a[j] {
                return Some(a[i]);
            }
        }
    }
    return None;
}
