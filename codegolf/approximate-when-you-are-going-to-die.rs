/*

A mortality table or life table is an actuarial tool that gives the probability that a person aged A

years will die in the next year, and is used to help calculate the premiums for life insurance, among other things.
One of the first people to compile a life table was Edmond Halley, of cometary fame.
These probabilities also allow you to estimate the life expectancy for a given age, which is the goal of this challenge.

Input

    An integer from 0 to 119, inclusive.
    An indicator for Sex M/F.

Output

    An approximation for the life expectancy for that Age/Sex according to the Social Security Administration's 2016 Mortality Table, aka the Actuarial Life table,
    the relevant part of which can be found below.

Age     M           F
0       75.97       80.96
1       75.45       80.39
2       74.48       79.42
3       73.50       78.43
4       72.52       77.45
5       71.53       76.46
6       70.54       75.47
7       69.55       74.47
8       68.56       73.48
9       67.57       72.49
10      66.57       71.50
11      65.58       70.50
12      64.59       69.51
13      63.60       68.52
14      62.61       67.53
15      61.63       66.54
16      60.66       65.55
17      59.70       64.57
18      58.74       63.59
19      57.79       62.61
20      56.85       61.63
21      55.91       60.66
22      54.98       59.69
23      54.06       58.72
24      53.14       57.75
25      52.22       56.78
26      51.31       55.82
27      50.39       54.85
28      49.48       53.89
29      48.56       52.93
30      47.65       51.97
31      46.74       51.01
32      45.83       50.06
33      44.92       49.10
34      44.01       48.15
35      43.10       47.20
36      42.19       46.25
37      41.28       45.30
38      40.37       44.36
39      39.47       43.41
40      38.56       42.47
41      37.65       41.53
42      36.75       40.59
43      35.85       39.66
44      34.95       38.73
45      34.06       37.80
46      33.17       36.88
47      32.28       35.96
48      31.41       35.04
49      30.54       34.13
50      29.67       33.23
51      28.82       32.33
52      27.98       31.44
53      27.14       30.55
54      26.32       29.68
55      25.50       28.81
56      24.70       27.94
57      23.90       27.09
58      23.12       26.24
59      22.34       25.39
60      21.58       24.56
61      20.83       23.72
62      20.08       22.90
63      19.35       22.07
64      18.62       21.26
65      17.89       20.45
66      17.18       19.65
67      16.47       18.86
68      15.77       18.07
69      15.07       17.30
70      14.39       16.54
71      13.71       15.79
72      13.05       15.05
73      12.40       14.32
74      11.76       13.61
75      11.14       12.92
76      10.53       12.23
77      9.94        11.57
78      9.37        10.92
79      8.82        10.29
80      8.28        9.68
81      7.76        9.09
82      7.26        8.52
83      6.79        7.98
84      6.33        7.45
85      5.89        6.95
86      5.48        6.47
87      5.08        6.01
88      4.71        5.57
89      4.37        5.16
90      4.05        4.78
91      3.75        4.43
92      3.48        4.11
93      3.23        3.81
94      3.01        3.55
95      2.81        3.31
96      2.64        3.09
97      2.49        2.90
98      2.36        2.73
99      2.24        2.58
100     2.12        2.42
101     2.01        2.28
102     1.90        2.14
103     1.80        2.01
104     1.70        1.88
105     1.60        1.76
106     1.51        1.65
107     1.42        1.54
108     1.34        1.44
109     1.26        1.34
110     1.18        1.24
111     1.10        1.15
112     1.03        1.06
113     0.96        0.98
114     0.90        0.91
115     0.84        0.84
116     0.78        0.78
117     0.72        0.72
118     0.66        0.66
119     0.61        0.61

For convenience, here they are in wide form (ages 0-119 in order):

M: [75.97, 75.45, 74.48, 73.5, 72.52, 71.53, 70.54, 69.55, 68.56, 67.57, 66.57, 65.58, 64.59, 63.6, 62.61, 61.63, 60.66, 59.7, 58.74, 57.79, 56.85, 55.91, 54.98, 54.06, 53.14, 52.22, 51.31, 50.39, 49.48, 48.56, 47.65, 46.74, 45.83, 44.92, 44.01, 43.1, 42.19, 41.28, 40.37, 39.47, 38.56, 37.65, 36.75, 35.85, 34.95, 34.06, 33.17, 32.28, 31.41, 30.54, 29.67, 28.82, 27.98, 27.14, 26.32, 25.5, 24.7, 23.9, 23.12, 22.34, 21.58, 20.83, 20.08, 19.35, 18.62, 17.89, 17.18, 16.47, 15.77, 15.07, 14.39, 13.71, 13.05, 12.4, 11.76, 11.14, 10.53, 9.94, 9.37, 8.82, 8.28, 7.76, 7.26, 6.79, 6.33, 5.89, 5.48, 5.08, 4.71, 4.37, 4.05, 3.75, 3.48, 3.23, 3.01, 2.81, 2.64, 2.49, 2.36, 2.24, 2.12, 2.01, 1.9, 1.8, 1.7, 1.6, 1.51, 1.42, 1.34, 1.26, 1.18, 1.1, 1.03, 0.96, 0.9, 0.84, 0.78, 0.72, 0.66, 0.61]
F: [80.96, 80.39, 79.42, 78.43, 77.45, 76.46, 75.47, 74.47, 73.48, 72.49, 71.5, 70.5, 69.51, 68.52, 67.53, 66.54, 65.55, 64.57, 63.59, 62.61, 61.63, 60.66, 59.69, 58.72, 57.75, 56.78, 55.82, 54.85, 53.89, 52.93, 51.97, 51.01, 50.06, 49.1, 48.15, 47.2, 46.25, 45.3, 44.36, 43.41, 42.47, 41.53, 40.59, 39.66, 38.73, 37.8, 36.88, 35.96, 35.04, 34.13, 33.23, 32.33, 31.44, 30.55, 29.68, 28.81, 27.94, 27.09, 26.24, 25.39, 24.56, 23.72, 22.9, 22.07, 21.26, 20.45, 19.65, 18.86, 18.07, 17.3, 16.54, 15.79, 15.05, 14.32, 13.61, 12.92, 12.23, 11.57, 10.92, 10.29, 9.68, 9.09, 8.52, 7.98, 7.45, 6.95, 6.47, 6.01, 5.57, 5.16, 4.78, 4.43, 4.11, 3.81, 3.55, 3.31, 3.09, 2.9, 2.73, 2.58, 2.42, 2.28, 2.14, 2.01, 1.88, 1.76, 1.65, 1.54, 1.44, 1.34, 1.24, 1.15, 1.06, 0.98, 0.91, 0.84, 0.78, 0.72, 0.66, 0.61]

Scoring Rules

For this challenge, the submission with the lowest score wins. Your score will be equal to (1+L)×(1+M),
where L is the length of your code in bytes and M is the mean-squared error of your estimates, rounded to two decimal places.
This is a scoring program for M.

Other rules

    Standard loopholes are forbidden.
    Input is pretty flexible. You can specify any two distinct values for M/F: 'M'/'F',0/1. If you really wanted, you could even take a single integer, with the sign representing M/F, but note that 0 is an input for both. Or the real and imaginary parts of a complex number.
        You don't have to take any input if you don't want, which should allow you to post answers that just always return 4 or whatever.
    In case there was any confusion, the output cannot be random.
    Please include a means of verifying your score.
    Builtins that have this exact mortality table are not banned, but do please implement your own solution as well.
    Explanations are encouraged.

Additional Bonuses:

Since R is the language of the month for September 2020, I will be awarding a 500 rep bounty to the R answer with the best score at the end of the month.

*/

fn main() {
    for i in 0..120 {
        println!("{} {} {}", i, life_expectancy(i, 'M'), life_expectancy(i, 'F'));
    }
}

fn life_expectancy(year: usize, sex: char) -> f64 {
    let males = vec![75.97, 75.45, 74.48, 73.5, 72.52, 71.53, 70.54, 69.55, 68.56, 67.57, 66.57, 65.58, 64.59, 63.6, 62.61, 61.63, 60.66, 59.7, 58.74, 57.79, 56.85, 55.91, 54.98, 54.06, 53.14, 52.22, 51.31, 50.39, 49.48, 48.56, 47.65, 46.74, 45.83, 44.92, 44.01, 43.1, 42.19, 41.28, 40.37, 39.47, 38.56, 37.65, 36.75, 35.85, 34.95, 34.06, 33.17, 32.28, 31.41, 30.54, 29.67, 28.82, 27.98, 27.14, 26.32, 25.5, 24.7, 23.9, 23.12, 22.34, 21.58, 20.83, 20.08, 19.35, 18.62, 17.89, 17.18, 16.47, 15.77, 15.07, 14.39, 13.71, 13.05, 12.4, 11.76, 11.14, 10.53, 9.94, 9.37, 8.82, 8.28, 7.76, 7.26, 6.79, 6.33, 5.89, 5.48, 5.08, 4.71, 4.37, 4.05, 3.75, 3.48, 3.23, 3.01, 2.81, 2.64, 2.49, 2.36, 2.24, 2.12, 2.01, 1.9, 1.8, 1.7, 1.6, 1.51, 1.42, 1.34, 1.26, 1.18, 1.1, 1.03, 0.96, 0.9, 0.84, 0.78, 0.72, 0.66, 0.61];
    let females = vec![80.96, 80.39, 79.42, 78.43, 77.45, 76.46, 75.47, 74.47, 73.48, 72.49, 71.5, 70.5, 69.51, 68.52, 67.53, 66.54, 65.55, 64.57, 63.59, 62.61, 61.63, 60.66, 59.69, 58.72, 57.75, 56.78, 55.82, 54.85, 53.89, 52.93, 51.97, 51.01, 50.06, 49.1, 48.15, 47.2, 46.25, 45.3, 44.36, 43.41, 42.47, 41.53, 40.59, 39.66, 38.73, 37.8, 36.88, 35.96, 35.04, 34.13, 33.23, 32.33, 31.44, 30.55, 29.68, 28.81, 27.94, 27.09, 26.24, 25.39, 24.56, 23.72, 22.9, 22.07, 21.26, 20.45, 19.65, 18.86, 18.07, 17.3, 16.54, 15.79, 15.05, 14.32, 13.61, 12.92, 12.23, 11.57, 10.92, 10.29, 9.68, 9.09, 8.52, 7.98, 7.45, 6.95, 6.47, 6.01, 5.57, 5.16, 4.78, 4.43, 4.11, 3.81, 3.55, 3.31, 3.09, 2.9, 2.73, 2.58, 2.42, 2.28, 2.14, 2.01, 1.88, 1.76, 1.65, 1.54, 1.44, 1.34, 1.24, 1.15, 1.06, 0.98, 0.91, 0.84, 0.78, 0.72, 0.66, 0.61];

    if year < 120 {
        if sex == 'M' {
            return males[year];
        } else if sex == 'F' {
            return females[year];
        }
    }
    return -1.0;
}

