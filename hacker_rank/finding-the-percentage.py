#!/usr/bin/env python3

"""

The provided code stub will read in a dictionary containing key/value pairs of name:[marks] for a list of students. Print the average of the marks array for the student name provided, showing 2 places after the decimal.

Example
marks key: value pairs are
'alpha': [20, 30, 40]
'beta': [30, 50, 70]
query_name = 'beta'

The query_name is 'beta'. beta's average score is (30 + 50 + 70) / 3 = 50.0

Input Format

The first line contains the integer n, the number of students' records. The next n lines contain the names and marks obtained by a student, each value separated by a space. The final line contains query_name, the name of a student to query.

Constraints
2 <= n <= 10
0 <= marks[i] <= 100
length of marks arrays = 3

Output Format

Print one line: The average of the marks obtained by the particular student correct to 2 decimal places.

Sample Input 0
3
Krishna 67 68 69
Arjun 70 98 63
Malika 52 56 60
Malika
Sample Output 0
56.00

Sample Input 1
2
Harsh 25 26.5 28
Anurag 26 28 30
Harsh

Sample Output 1
26.50

"""

import numpy as np

def main():
    marks_1 = {"Krishna": [67, 68, 69], "Arjun": [70, 98, 63], "Malika": [52, 56, 60]}
    marks_2 = {"Harsh": [25, 26.5, 28], "Anurag": [26, 28, 30]}
    
    assert(np.mean(marks_1["Malika"]) == 56.0)
    assert(np.mean(marks_2["Harsh"]) == 26.5)

main()
