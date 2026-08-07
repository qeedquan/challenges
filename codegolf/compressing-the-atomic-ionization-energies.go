/*

This is a different type of compression challenge. In a normal kolmogorov-complexity challenge, you are required to recreate a list exactly. Here, you are allowed to round the values in any way you wish. What's the catch? Your score is penalized based on how wrong your output is.

At the bottom of this question is a list of the first ionization energies for the first 108 elements. Your program, upon execution, should output a reasonably accurate copy of this list. There will be no input or arguments. For scoring purposes your output should be deterministic (same output every time).

Output format

Your program/function must output a list of 108 numbers, sorted in order of increasing atomic number. This list can be in any appropriate format. The source data below is provided in the correct order, from hydrogen to hassium.

Scoring
Your score will be your program's length in bytes plus a rounding penalty. A rounding penalty is calculated for each element and summed to give the total penalty.

As an example, let's take the number 11.81381. Let's say that your program outputs an incorrect value of 11.81299999.

First, both numbers are multiplied by the same power of 10 such that there is no longer a decimal point in the true value: 1181381, 1181299.999. Trailing zeros in the true value are considered significant.

Then, the absolute difference is taken to determine the absolute error: 81.001.

Finally, we calculate this element's penalty as max(0, log10(err * 4 - 1)) -> 2.50921. This formula was chosen such that an error < 0.5 gives no penalty (since the answer is correct within rounding), while also giving an asymptotic 50% chance that rounding the number to any particular decimal place would provide a net benefit in score (assuming no other compression).

Here is a Try-It-Online implementation of a penalty-calculating program. The input to this program is provided as a list of numbers, one per line. The output of this program is the total penalty and a per-element breakdown of scoring.

Data
The list of numbers below is the target data, in the correct order from atomic number 1 to 108.

https://physics.nist.gov/cgi-bin/ASD/ie.pl?spectra=H-DS+i&units=1&at_num_out=on&el_name_out=on&shells_out=on&level_out=on&e_out=0&unc_out=on&biblio=on
Source

13.598434005136
24.587387936
5.391714761
9.322699
8.2980190
11.260296
14.53413
13.618054
17.42282
21.564540
5.1390767
7.646235
5.985768
8.151683
10.486686
10.36001
12.96763
15.7596112
4.34066354
6.11315520
6.56149
6.82812
6.746187
6.76651
7.434018
7.9024678
7.88101
7.639877
7.726380
9.3941990
5.9993018
7.899435
9.7886
9.752392
11.81381
13.9996049
4.177128
5.69486720
6.21726
6.63390
6.75885
7.09243
7.11938
7.36050
7.45890
8.33686
7.576234
8.993822
5.7863552
7.343917
8.608389
9.00966
10.45126
12.1298431
3.893905548
5.211664
5.5769
5.5386
5.473
5.5250
5.582
5.64371
5.670385
6.14980
5.8638
5.93905
6.0215
6.1077
6.18431
6.254159
5.425871
6.825069
7.549571
7.86403
7.83352
8.43823
8.96702
8.95883
9.225553
10.437504
6.1082871
7.4166796
7.285516
8.414
9.31751
10.7485
4.0727409
5.278424
5.380226
6.3067
5.89
6.19405
6.2655
6.0258
5.9738
5.9914
6.1978
6.2817
6.3676
6.50
6.58
6.65
4.90
6.01
6.8
7.8
7.7
7.6

Baselines & Tips
The source data above is 906 bytes, with certain compression tools able to get it to sub-500 bytes. Interesting solutions are those that attempt to perform intelligent rounding, use algebraic formulas, or other techniques to output approximate values in fewer bytes than compression alone. It is difficult, however, to judge these tradeoffs across languages: for some languages compression alone might be optimal, while many other languages might lack compression tools altogether, so I expect a wide variation in score across languages. This is fine, as I'm going by the "competition within languages, not between them" philosophy.

I anticipate that it might be useful to attempt to take advantage of trends in the periodic table. Below is a graph I found of ionization energies, so that you can see some of these trends.

https://i.stack.imgur.com/5pJyF.png

*/

package main

import "fmt"

func main() {
	output()
}

func output() {
	ions := []float64{
		13.598434005136,
		24.587387936,
		5.391714761,
		9.322699,
		8.2980190,
		11.260296,
		14.53413,
		13.618054,
		17.42282,
		21.564540,
		5.1390767,
		7.646235,
		5.985768,
		8.151683,
		10.486686,
		10.36001,
		12.96763,
		15.7596112,
		4.34066354,
		6.11315520,
		6.56149,
		6.82812,
		6.746187,
		6.76651,
		7.434018,
		7.9024678,
		7.88101,
		7.639877,
		7.726380,
		9.3941990,
		5.9993018,
		7.899435,
		9.7886,
		9.752392,
		11.81381,
		13.9996049,
		4.177128,
		5.69486720,
		6.21726,
		6.63390,
		6.75885,
		7.09243,
		7.11938,
		7.36050,
		7.45890,
		8.33686,
		7.576234,
		8.993822,
		5.7863552,
		7.343917,
		8.608389,
		9.00966,
		10.45126,
		12.1298431,
		3.893905548,
		5.211664,
		5.5769,
		5.5386,
		5.473,
		5.5250,
		5.582,
		5.64371,
		5.670385,
		6.14980,
		5.8638,
		5.93905,
		6.0215,
		6.1077,
		6.18431,
		6.254159,
		5.425871,
		6.825069,
		7.549571,
		7.86403,
		7.83352,
		8.43823,
		8.96702,
		8.95883,
		9.225553,
		10.437504,
		6.1082871,
		7.4166796,
		7.285516,
		8.414,
		9.31751,
		10.7485,
		4.0727409,
		5.278424,
		5.380226,
		6.3067,
		5.89,
		6.19405,
		6.2655,
		6.0258,
		5.9738,
		5.9914,
		6.1978,
		6.2817,
		6.3676,
		6.50,
		6.58,
		6.65,
		4.90,
		6.01,
		6.8,
		7.8,
		7.7,
		7.6,
	}

	for i := range ions {
		fmt.Println(i+1, ions[i])
	}
}
