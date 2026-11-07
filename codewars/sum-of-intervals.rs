/*

Write a function called sumIntervals/sum_intervals() that accepts an array of intervals, and returns the sum of all the interval lengths. Overlapping intervals should only be counted once.

Intervals
Intervals are represented by a pair of integers in the form of an array. The first value of the interval will always be less than the second value. Interval example: [1, 5] is an interval from 1 to 5. The length of this interval is 4.

Overlapping Intervals
List containing overlapping intervals:

[
   [1,4],
   [7, 10],
   [3, 5]
]
The sum of the lengths of these intervals is 7. Since [1, 4] and [3, 5] overlap, we can treat the interval as [1, 5], which has a length of 4.

Examples:
sumIntervals( [
   [1,2],
   [6, 10],
   [11, 15]
] ); // => 9

sumIntervals( [
   [1,4],
   [7, 10],
   [3, 5]
] ); // => 7

sumIntervals( [
   [1,5],
   [10, 20],
   [1, 6],
   [16, 19],
   [5, 11]
] ); // => 19

*/

fn main() {
    assert_eq!(sum_intervals(&mut vec![[1, 5]]), 4);
    assert_eq!(sum_intervals(&mut vec![[1, 5], [6, 10]]), 8);
    assert_eq!(sum_intervals(&mut vec![[1, 2], [6, 10], [11, 15]]), 9);
    assert_eq!(sum_intervals(&mut vec![[1, 4], [7, 10], [3, 5]]), 7);
    assert_eq!(
        sum_intervals(&mut vec![[1, 5], [10, 20], [1, 6], [16, 19], [5, 11]]),
        19
    );

    assert_eq!(
        sum_intervals(&mut vec![[-1000000000, 1000000000]]),
        2000000000
    );

    assert_eq!(
        sum_intervals(&mut vec![[0, 20], [-100000000, 10], [30, 40]]),
        100000030
    );
}

fn sum_intervals(intervals: &mut Vec<[isize; 2]>) -> isize {
    merge_intervals(intervals);
    let mut total = 0;
    for interval in intervals {
        total += interval[1] - interval[0];
    }
    total
}

// https://www.geeksforgeeks.org/merging-intervals/
fn merge_intervals(intervals: &mut Vec<[isize; 2]>) {
    intervals.sort();
    let mut length = 0;
    for i in 1..intervals.len() {
        if intervals[length][1] >= intervals[i][0] {
            if intervals[length][1] <= intervals[i][1] {
                intervals[length][1] = intervals[i][1];
            }
        } else {
            length += 1;
            intervals[length] = intervals[i];
        }
    }
    intervals.resize(length + 1, [0, 0]);
}
