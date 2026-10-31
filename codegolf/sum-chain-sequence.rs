/*

Sequence:

We start at 1.
We first add the current 1-indexed value to the previous number in the sequence.
Then we apply the following mathematical operations in order if they apply to this current value:
Divisible by 2? => Addition
Divisible by 3? => Subtraction
Divisible by 4? => (Addition AND) Multiply
Not divisible by neither 2, 3 nor 4? -> Continue with current sum-result
Output:

Output the first 100 numbers in this sequence:

1, 1, 21, 25, 30, 216, 223, 223, 2169, 2179, 2190, 2202, 2215, 2215, 2245, 2261, 2295, 2295, 2333, 2353, 2395, 2417, 56649, 56649, 56699, 56725, 1533033, 1533061, 1533090, 45993600, 45993631, 45993631, 1517792001, 1517792035, 1517792070, 1517792106, 1517792143, 1517792143, 1517792221, 1517792261, 1517792343, 1517792343, 1517792429, 1517792473, 1517792563, 1517792609, 71336257041, 71336257041, 71336257139, 71336257189, 3638149121841, 3638149121893, 3638149121946, 196460052588000, 196460052588055, 196460052588055, 11198222997525633, 11198222997525691, 11198222997525750, 11198222997525810, 11198222997525871, 11198222997525871, 11198222997525997, 11198222997526061, 11198222997526191, 11198222997526191, 11198222997526325, 11198222997526393, 11198222997526531, 11198222997526601, 795073832824398753, 795073832824398753, 795073832824398899, 795073832824398973, 59630537461829934225, 59630537461829934301, 59630537461829934378, 4651181922022734887568, 4651181922022734887647, 4651181922022734887647, 376745735683841525912529, 376745735683841525912611, 376745735683841525912694, 376745735683841525912778, 376745735683841525912863, 376745735683841525912863, 376745735683841525913037, 376745735683841525913125, 376745735683841525913303, 376745735683841525913303, 376745735683841525913485, 376745735683841525913577, 376745735683841525913763, 376745735683841525913857, 35790844889964944961834465, 35790844889964944961834465, 35790844889964944961834659, 35790844889964944961834757, 3543293644106529551221660545, 3543293644106529551221660645
Here are the first 10 numbers in the sequence with explanation:

// Starting number of the sequence:
1

// 1 (previous number in the sequence)
// + 2 (current index in 1-indexed sequence)
// = 3 -> 3 - 2 (3 is divisible by 3, so we subtract the current index 2)
// = 1
1

// 1 (previous number in the sequence)
// + 3 (current index in 1-indexed sequence)
// = 4 -> 4 + 3 (4 is divisible by 2, so we first add the current index 3)
// = 7 -> 7 * 3 (and 4 is also divisible by 4, so we then also multiply the current index 3)
// = 21
21

// 21 (previous number in the sequence)
// + 4 (current index in 1-indexed sequence)
// = 25 (25 is not divisible by 2, 3 nor 4)
25

// 25 (previous number in the sequence)
// + 5 (current index in 1-indexed sequence)
// = 30 -> 30 + 5 (30 is divisible by 2, so we first add the current index 5)
// = 35 -> 35 - 5 (and 30 is also divisible by 3, so we then also subtract the current index 5)
// = 30
30

// 30 (previous number in the sequence)
// + 6 (current index in 1-indexed sequence)
// = 36 -> 36 + 6 (36 is divisible by 2, so we first add the current index 6)
// = 42 -> 42 - 6 (and 36 is also divisible by 3, so we then also subtract the current index 6)
// = 36 -> 36 * 6 (and 36 is also divisible by 4, so we then also multiply the current index 6)
// = 216
216

// 216 (previous number in the sequence)
// + 7 (current index in 1-indexed sequence)
// = 223 (223 is not divisible by 2, 3 nor 4)
223

// 223 (previous number in the sequence)
// + 8 (current index in 1-indexed sequence)
// = 231 -> 231 - 8 (231 is divisible by 3, so we subtract the current index 8)
// = 223
223

// 223 (previous number in the sequence)
// + 9 (current index in 1-indexed sequence)
// = 232 -> 232 + 9 (232 is divisible by 2, so we first add the current index 9)
// = 241 -> 241 * 9 (and 232 is also divisible by 4, so we then also multiply the current index 9)
// = 2169
2169

// 2169 (previous number in the sequence)
// + 10 (current index in 1-indexed sequence)
// 2179 (2179 is not divisible by 2, 3 nor 4)
2179
Challenge rules:

If your language doesn't support anything bigger than 231-1, you can continue the sequence until that max (so the first 46 numbers, up until - and including - 1,517,792,609).
The output format is flexible. You can return an array or list, a string separated with spaces, commas, etc. Your call.
General rules:

This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

*/

fn main() {
    let tab = vec![
        1,
        1,
        21,
        25,
        30,
        216,
        223,
        223,
        2169,
        2179,
        2190,
        2202,
        2215,
        2215,
        2245,
        2261,
        2295,
        2295,
        2333,
        2353,
        2395,
        2417,
        56649,
        56649,
        56699,
        56725,
        1533033,
        1533061,
        1533090,
        45993600,
        45993631,
        45993631,
        1517792001,
        1517792035,
        1517792070,
        1517792106,
        1517792143,
        1517792143,
        1517792221,
        1517792261,
        1517792343,
        1517792343,
        1517792429,
        1517792473,
        1517792563,
        1517792609,
        71336257041,
        71336257041,
        71336257139,
        71336257189,
        3638149121841,
        3638149121893,
        3638149121946,
        196460052588000,
        196460052588055,
        196460052588055,
        11198222997525633,
        11198222997525691,
        11198222997525750,
        11198222997525810,
        11198222997525871,
        11198222997525871,
        11198222997525997,
        11198222997526061,
        11198222997526191,
        11198222997526191,
        11198222997526325,
        11198222997526393,
        11198222997526531,
        11198222997526601,
        795073832824398753,
        795073832824398753,
        795073832824398899,
        795073832824398973,
        59630537461829934225,
        59630537461829934301,
        59630537461829934378,
        4651181922022734887568,
        4651181922022734887647,
        4651181922022734887647,
        376745735683841525912529,
        376745735683841525912611,
        376745735683841525912694,
        376745735683841525912778,
        376745735683841525912863,
        376745735683841525912863,
        376745735683841525913037,
        376745735683841525913125,
        376745735683841525913303,
        376745735683841525913303,
        376745735683841525913485,
        376745735683841525913577,
        376745735683841525913763,
        376745735683841525913857,
        35790844889964944961834465,
        35790844889964944961834465,
        35790844889964944961834659,
        35790844889964944961834757,
        3543293644106529551221660545,
        3543293644106529551221660645,
    ];

    assert_eq!(gen(tab.len() as u128), tab);
}

fn gen(n: u128) -> Vec<u128> {
    let mut r = vec![];
    let mut v = 0;
    for i in 1..n + 1 {
        v += i;

        let u = v;
        if u % 2 == 0 {
            v += i;
        }
        if u % 3 == 0 {
            v -= i;
        }
        if u % 4 == 0 {
            v *= i;
        }
        r.push(v);
    }
    r
}
