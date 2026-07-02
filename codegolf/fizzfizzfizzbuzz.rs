/*

Given a positive integer n, output the "FizzFizzFizzBuzz" sequence for that number:
print the decimal representations of the numbers 1 through n (inclusive on both ends), separated by newlines, however for each number in the sequence:

If the number is divisible by both 3 and 5, instead of the number output Fizz the number of times it can divide by 3 without leaving a remainder, then Buzz the number of times it can divide by 5 without leaving a remainder.
For example, 45 and 90 output FizzFizzBuzz, 75 outputs FizzBuzzBuzz, 135 outputs FizzFizzFizzBuzz, and 225 outputs FizzFizzBuzzBuzz.

Else if the number is divisible by 3, instead of the number output Fizz the number of times it can divide by 3 without leaving a remainder.
For example, 9 and 18 output FizzFizz, and 27 and 54 output FizzFizzFizz.

Else if the number is divisible by 5, instead of the number output Buzz the number of times it can divide by 5 without leaving a remainder.
For example, 25 outputs BuzzBuzz, 35 outputs Buzz, and 125 and 500 output BuzzBuzzBuzz.

Example to 200:

1
2
Fizz
4
Buzz
Fizz
7
8
FizzFizz
Buzz
11
Fizz
13
14
FizzBuzz
16
17
FizzFizz
19
Buzz
Fizz
22
23
Fizz
BuzzBuzz
26
FizzFizzFizz
28
29
FizzBuzz
31
32
Fizz
34
Buzz
FizzFizz
37
38
Fizz
Buzz
41
Fizz
43
44
FizzFizzBuzz
46
47
Fizz
49
BuzzBuzz
Fizz
52
53
FizzFizzFizz
Buzz
56
Fizz
58
59
FizzBuzz
61
62
FizzFizz
64
Buzz
Fizz
67
68
Fizz
Buzz
71
FizzFizz
73
74
FizzBuzzBuzz
76
77
Fizz
79
Buzz
FizzFizzFizzFizz
82
83
Fizz
Buzz
86
Fizz
88
89
FizzFizzBuzz
91
92
Fizz
94
Buzz
Fizz
97
98
FizzFizz
BuzzBuzz
101
Fizz
103
104
FizzBuzz
106
107
FizzFizzFizz
109
Buzz
Fizz
112
113
Fizz
Buzz
116
FizzFizz
118
119
FizzBuzz
121
122
Fizz
124
BuzzBuzzBuzz
FizzFizz
127
128
Fizz
Buzz
131
Fizz
133
134
FizzFizzFizzBuzz
136
137
Fizz
139
Buzz
Fizz
142
143
FizzFizz
Buzz
146
Fizz
148
149
FizzBuzzBuzz
151
152
FizzFizz
154
Buzz
Fizz
157
158
Fizz
Buzz
161
FizzFizzFizzFizz
163
164
FizzBuzz
166
167
Fizz
169
Buzz
FizzFizz
172
173
Fizz
BuzzBuzz
176
Fizz
178
179
FizzFizzBuzz
181
182
Fizz
184
Buzz
Fizz
187
188
FizzFizzFizz
Buzz
191
Fizz
193
194
FizzBuzz
196
197
FizzFizz
199
BuzzBuzz

This is code-golf, so fewest bytes wins!

*/

fn main() {
    fizz3buzz(200);
}

fn fizz3buzz(n: isize) {
    for i in 1..n + 1 {
        let mut j = i;

        while j % 3 == 0 {
            print!("Fizz");
            j /= 3;
        }

        while j % 5 == 0 {
            print!("Buzz");
            j /= 5;
        }

        if i == j {
            print!("{j}");
        }

        println!();
    }
}
