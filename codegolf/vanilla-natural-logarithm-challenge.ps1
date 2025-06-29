#!/usr/bin/env pwsh

<#

There is a challenge for multiplying two numbers so I guess this counts too

Given as input a positive real number n compute its natural logarithm.

Your answer should be within 10^-6 for 1≤n≤10 and within 10^-3 for 0.1≤n≤100. You don't need to handle numbers outside this range.

See this thread on mathematics.se for various approaches to this problem. Just for inspiration, feel free to use a method not on that page.

Please add builtin answers to the community wiki instead of posting them separately.

Test Cases
x	ln(x)
0.1	-2.3025850929940455
0.25	-1.3862943611198906
0.5	-0.6931471805599453
0.75	-0.2876820724517809
0.9	-0.10536051565782628
1.0	0.0
1.3	0.26236426446749106
2	0.6931471805599453
2.718281828459045	1.0
3.141592653589793	1.1447298858494002
4	1.3862943611198906
5	1.6094379124341003
7	1.9459101490553132
10	2.302585092994046
53	3.970291913552122
54.59815003314423	4.0
99	4.59511985013459

IO
Standard IO rules apply. Importantly, you may take input as a fraction if you prefer. You may also output as a fraction, which does not need to be fully reduced.

#>

function main() {
	$values = @(0.1, 0.25, 0.5, 0.75, 0.9, 1.0, 1.3, 2, 2.718281828459045, 3.141592653589793, 4, 5, 7, 10, 53, 54.59815003314423, 99)

	foreach ($value in $values) {
		"{0} -> {1}" -f $value, [Math]::Log($value)
	}
}

main
