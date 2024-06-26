#!/bin/bash

cat << EOF > /dev/null

Given a list of countries, each on a new line, your task is to read them into an array. Then slice the array and display only the elements lying between positions  and , both inclusive. Indexing starts from from .

Input Format

A list of country names. The only characters present in the country names will be upper or lower case characters and hyphens.

Output Format

Display the sliced portion of the array of country names, with a space between each of them.

Sample Input

Namibia
Nauru
Nepal
Netherlands
NewZealand
Nicaragua
Niger
Nigeria
NorthKorea
Norway
Sample Output

Netherlands NewZealand Nicaragua Niger Nigeria
Explanation

We displayed the sliced portion of the array.

EOF

array=(Namibia Nauru Nepal Netherlands NewZealand Nicaragua Niger Nigeria NorthKorea Norway)
echo ${array[@]:3:5}
