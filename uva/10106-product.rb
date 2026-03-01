#!/usr/bin/env ruby

=begin

The problem is to multiply two integers X, Y . (0 ≤ X, Y < 10^250)

Input
The input will consist of a set of pairs of lines. Each line in pair contains one multiplyer.

Output
For each input pair of lines the output line should consist one integer the product.

Sample Input
12
12
2
222222222222222222222222

Sample Output
144
444444444444444444444444

=end

raise unless 12*12 == 144
raise unless 2*222222222222222222222222 == 444444444444444444444444
