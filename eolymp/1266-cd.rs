/*

You have a long car journey ahead. You have a tape recorder, but unfortunately your favorite music is only on CDs.
In order to listen to it in the car, you need to record it onto a tape.
You have a tape of N minutes in length.
How should you select tracks from the CD to make the best use of the tape's capacity, minimizing the unused space?

Assumptions:

The number of tracks on the CD does not exceed 100.

No track is longer than N minutes.

The length of each track is an integer.

N is also an integer (0≤N≤200).

The program should find a set of tracks that fills the tape as much as possible and print the chosen track durations in the same order as they appear on the CD.

Input
The input consists of multiple lines. Each line contains the value N, followed by the number of tracks, then the durations of each track.
All values are separated by spaces. For example, in the first line of the sample data:
N=5, number of tracks s=3, first track lasts 1 minute, second 3 minutes, and the last 4 minutes.

Output
Output the durations of the selected tracks in the order they appear on the CD on a single line.
Then, on the next line, output the string sum: and the sum of their durations.

Examples
Input #1
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2

Answer #1
sum:5
sum:10
sum:19
sum:55
sum:45

*/

fn main() {
    assert_eq!(solve(5, &[1, 3, 4]), 5);
    assert_eq!(solve(10, &[9, 8, 4, 2]), 10);
    assert_eq!(solve(20, &[10, 5, 7, 4]), 19);
    assert_eq!(solve(90, &[10, 23, 1, 2, 3, 4, 5, 7]), 55);
    assert_eq!(solve(45, &[4, 10, 44, 43, 12, 9, 8, 2]), 45);
}

fn solve(tracks: usize, values: &[usize]) -> usize {
    let mut result = 0;
    backtrack(0, 0, tracks, values, &mut result);
    result
}

fn backtrack(position: usize, sum: usize, tracks: usize, values: &[usize], result: &mut usize) {
    if *result == tracks || sum > tracks {
        return;
    }

    if position >= values.len() {
        if sum > *result && sum <= tracks {
            *result = sum;
        }
        return;
    }

    backtrack(position + 1, sum + values[position], tracks, values, result);
    backtrack(position + 1, sum, tracks, values, result);
}
