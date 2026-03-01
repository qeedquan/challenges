#!/usr/bin/env python3

"""

Ubiquitous in engineering are sensors that periodically send readings to a processor. Information from these readings must then be processed so that the system can respond appropriately. There are issues with readings, however:

the readings may contain noise (random deviations from the actual values), and
the signal of interest may be mixed with other signals of which you have no interest.
As examples of the second:

The power grid delivers power in North America using alternating current at 60 Hz (in Europe, power is delivered at 100 Hz).
Any electromagnetic signal associated that is connected to the power grid will almost certainly have 60 Hz interference which must be removed before the actual signal can be read.
Listening to the heart beat of a fetus requires extracting that heart beat from a signal that contains all the other noises of the mother's body,
including the mother's heart beat, gastro-intestinal noises, lung inflation and deflation, and other naturally- occuring noises.
This first signal is straight-forward and it is called an averaging filter. It is used strictly for removing white noise.

Your program will query the user for an integer N that is greater than zero. You will read numbers from a file.
Once you have read in N numbers, you will begin to produce output; that output being the average of the last N numbers that were read in.

Enter the number of values to average (0 to quit): 10
Enter a file name: data.txt
For example, if the input file contains the following twenty numbers:

39.572
19.314
 2.242
80.019
42.755
84.262
41.229
99.642
38.641
69.461
77.301
73.062
10.651
39.641
94.491
21.094
75.007
45.474
73.660
32.984

your output will be:

51.7137
55.4866
60.8614
61.7023
57.6645
62.8381
56.5213
59.8991
54.4823
57.9842
54.3365

"""

import numpy as np
import sys

# https://stackoverflow.com/questions/14313510/how-to-calculate-rolling-moving-average-using-python-numpy-scipy
def moving_average(a, n):
    r = np.cumsum(a, dtype=float)
    r[n:] = r[n:] - r[:-n]
    return r[n - 1:] / n

def read_floats(name):
    f = open(name)
    r = []
    for x in f.readlines():
        r.append(float(x))
    f.close()
    return r

def main():
    if len(sys.argv) != 3:
        print("usage: <input> <n>")
        sys.exit(2)
    
    x = read_floats(sys.argv[1])
    print(moving_average(x, int(sys.argv[2])))

main()
