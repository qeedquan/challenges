/*

Not only do students worry about unsolved problems, but teachers also share this concern.
Each evening, they discuss how the day went and review the results of the practice sessions.
For each problem, they know how many students managed to solve it.
If no student solved a particular problem, it is considered very bad news for the teachers.
Before examining the results table, they want to determine how many pieces of bad news they will face today.

The input specifies the number of problems in today's contest and the statistics for each problem.

Input
The first line contains a single integer N — the number of problems.

The following N lines each contain a single non-negative integer, representing the number of students who solved that problem.

Output
Output a single integer: the number of pieces of bad news the teachers will have to face.

Examples
Input #1
5
0
7
0
2
2

Answer #1
2

*/

fn main() {
    assert_eq!(solve(&[0, 7, 0, 2, 2]), 2);
}

fn solve(a: &[isize]) -> usize {
    let mut r = 0;
    for &x in a {
        if x == 0 {
            r += 1;
        }
    }
    r
}
