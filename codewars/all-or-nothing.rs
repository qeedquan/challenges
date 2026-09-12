/*

Suppose a student can earn 100% on an exam by getting the answers all correct or all incorrect. Given a potentially incomplete answer key and the student's answers, write a function that determines whether or not a student can still score 100%. Incomplete questions are marked with an underscore, "_".

["A", "_", "C", "_", "B"]   # answer key
["A", "D", "C", "E", "B"]   # student's solution

➞ True

# Possible for student to get all questions correct.

["B", "_", "B"]   # answer key
["B", "D", "C"]   # student's solution

➞ False

# First question is correct but third is wrong, so not possible to score 100%.

["T", "_", "F", "F", "F"]   # answer key
["F", "F", "T", "T", "T"]   # student's solution

➞ True

# Possible for student to get all questions incorrect.

Examples

(["B", "A", "_", "_"], ["B", "A", "C", "C"]) ➞ True

(["A", "B", "A", "_"], ["B", "A", "C", "C"]) ➞ True

(["A", "B", "C", "_"], ["B", "A", "C", "C"]) ➞ False

(["B", "_"], ["C", "A"]) ➞ True

(["B", "A"], ["C", "A"]) ➞ False

(["B"], ["B"]) ➞ True

(["_"], ["B"]) ➞ True

Notes

Test has at least one question.
len(key) == len(answers)

*/

fn main() {
    assert_eq!(
        possibly_perfect(&['A', '_', 'C', '_', 'B'], &['A', 'D', 'C', 'E', 'B']),
        true
    );

    assert_eq!(possibly_perfect(&['B', '_', 'B'], &['B', 'D', 'C']), false);

    assert_eq!(
        possibly_perfect(&['T', '_', 'F', 'F', 'F'], &['F', 'F', 'T', 'T', 'T']),
        true
    );

    assert_eq!(
        possibly_perfect(&['B', 'A', '_', '_'], &['B', 'A', 'C', 'C']),
        true
    );

    assert_eq!(
        possibly_perfect(&['A', 'B', 'A', '_'], &['B', 'A', 'C', 'C']),
        true
    );

    assert_eq!(
        possibly_perfect(&['A', 'B', 'C', '_'], &['B', 'A', 'C', 'C']),
        false
    );

    assert_eq!(possibly_perfect(&['B', '_'], &['C', 'A']), true);
    assert_eq!(possibly_perfect(&['B', 'A'], &['C', 'A']), false);
    assert_eq!(possibly_perfect(&['B'], &['B']), true);
    assert_eq!(possibly_perfect(&['_'], &['B']), true);
}

fn possibly_perfect(key: &[char], answers: &[char]) -> bool {
    if key.len() != answers.len() {
        return false;
    }

    let (mut correct, mut wrong) = (0, 0);
    for i in 0..key.len() {
        if key[i] == '_' {
            continue;
        }

        if answers[i] == key[i] {
            correct += 1;
        } else {
            wrong += 1;
        }

        if correct > 0 && wrong > 0 {
            return false;
        }
    }
    return true;
}
