/*

The first input array is the key to the correct answers to an exam, like ["a", "a", "b", "d"]. The second one contains a student's submitted answers.

The two arrays are not empty and are the same length. Return the score for this array of answers, giving +4 for each correct answer, -1 for each incorrect answer, and +0 for each blank answer, represented as an empty string (in C the space character is used).

If the score < 0, return 0.

For example:

checkExam(["a", "a", "b", "b"], ["a", "c", "b", "d"]) → 6
checkExam(["a", "a", "c", "b"], ["a", "a", "b",  ""]) → 7
checkExam(["a", "a", "b", "c"], ["a", "a", "b", "c"]) → 16
checkExam(["b", "c", "b", "a"], ["",  "a", "a", "c"]) → 0

*/

use std::cmp::max;

fn main() {
    assert_eq!(check_exam(&["a", "a", "b", "b"], &["a", "c", "b", "d"]), 6);
    assert_eq!(check_exam(&["a", "a", "c", "b"], &["a", "a", "b", ""]), 7);
    assert_eq!(check_exam(&["a", "a", "b", "c"], &["a", "a", "b", "c"]), 16);
    assert_eq!(check_exam(&["b", "c", "b", "a"], &["", "a", "a", "c"]), 0);
}

fn check_exam(answers: &[&'static str], submits: &[&'static str]) -> isize {
    let mut score = 0;
    for i in 0..answers.len() {
        if answers[i] == submits[i] {
            score += 4;
        } else if submits[i] != "" {
            score -= 1;
        }
    }
    max(score, 0)
}
