/*

Sometimes I feel angry to arrange contests, as I am too lazy. Today I am arranging a contest for the AIUB students. So, I made a plan to share some anger with them. While they will be busy with the contest, I will cover their rooms with dusts. And after the contest, they will surely get angry because they would have to clean up quite a bit.

So, at first, I will have to fix the amount of dusts for each student. This amount may not be the same for everyone. Now you are given the amount of dust unit for each student, you have to help me find the total dust unit I have to collect to cause them some pain.

But there is a problem, my random function which generates dust units for students has a bug, it sometimes returns negative numbers. If a student gets a negative number, I think he/she is lucky, the lucky person will have no dusts.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a blank line. The next line contains an integer N (1 ≤ N ≤ 1000), means that there are N students. The next line will contain N integers separated by spaces which denote the dust unit for all students. The dust unit for any student will not contain more than two digits.

Output
For each case print the case number and the total required dust units.

Sample
Input	Output
2

3
1 5 10

2
1 99

Case 1: 16
Case 2: 100

*/

fn main() {
    assert_eq!(solve(&[1, 5, 10]), 16);
    assert_eq!(solve(&[1, 99]), 100);
}

fn solve(dusts: &[isize]) -> isize {
    let mut result = 0;
    for &dust in dusts {
        if dust > 0 {
            result += dust;
        }
    }
    result
}
