#!/bin/sh

cat << EOF >/dev/null

Alice travels a lot for work. On each trip, she visits one city before returning home.

Recently, someone asked her: "How many different cities have you visited for work?"
Fortunately, Alice kept a record of all her trips.
Help Alice determine the number of unique cities she has visited at least once.

Input
The first line contains the number of test cases t (t≤50).
The first line of each test case contains the number of trips n Alice has taken for work.
The following n lines describe the trips: the i-th line contains the name of the city Alice visited on her i-th trip.

The cities Alice visits have simple names: they contain only uppercase letters, contain at least one letter, and do not contain spaces.

The number of trips does not exceed 100, and each city name contains no more than 20 characters.

Output
For each test case, print a single number on a new line — the number of unique cities Alice visited during her work trips.

Examples
Input #1
2
7
saskatoon
toronto
winnipeg
toronto
vancouver
saskatoon
toronto
3
edmonton
edmonton
edmonton

Answer #1
4
1

EOF

solve() {
	echo $@ | tr ' ' '\n' | sort | uniq | wc -l
}

lines1=$(cat << EOF
saskatoon
toronto
winnipeg
toronto
vancouver
saskatoon
toronto
EOF
)

lines2=$(cat << EOF
edmonton
edmonton
edmonton
EOF
)

solve $lines1
solve $lines2
