/*

We will look at four filters that approximate both the derivative and the integral of the signal over the most recent time step.

Both integration and differentiation require us to understand how far apart the signals are given in time. You will first query the user for the time step. If the samples are being taken at 10 Hz or 0.1 s apart, the user would then enter:

What is the time step between readings? 0.1
Enter a file name: data.txt
Differentiation
When calculating the derivative, the simplest formula is rise over run, and in this case, the run is the time step:

y[n] = (x[n] - x[n-1]) / Δt

where Δt is the time step. For example, if the time step is 0.1 and the input file is

0.0998
0.199
0.296
0.389
0.479
0.565
0.644
0.717
0.783
0.841
your output will be:

0.992
0.97
0.93
0.90
0.86
0.79
0.73
0.66
0.58
This approximates the derivative by calculating the rise over the run of the last two values, as shown in Figure 1.

https://ece.uwaterloo.ca/~ece150/Projects/Q.4/img/diff.1.png

A better approximation of the derivative is to use the formula

y[n] = (3x[n] - 4x[n−1] + x[n−2]) / (2Δt).

For the same intput file above, the output will be

0.959
0.91
0.885
0.84
0.755
0.7
0.625
0.54

This approximates the derivative by calculating the slope of an interpolating quadratic over the past three values, as shown in Figure 2.
https://ece.uwaterloo.ca/~ece150/Projects/Q.4/img/diff.2.png


Integration
If you are calculating an integral, the trapezoidal rule approximates the area as

y[n] = (x[n] + x[n-1])/2 * Δt + y[n-1].

where Δt is the time step. For example, if the time step is 0.1 and the input file is

0.01494
0.03969
0.07394
0.11734
0.16954
0.22999
0.29804
0.37304
0.45424
This approximates the integral by calculating the area of the trapezoid as shown in Figure 3.

Using half of Simpson's rule, we have a better approximation with

y[n] = (5x[n] + 8x[n-1] - x[n-2])/12 * Δt + y[n−1].

Now the output becomes

0.02476833333333333
0.05905166666666667
0.1024766666666667
0.15471
0.2152183333333333
0.2833183333333333
0.3583766666666667
0.4396433333333333
This approximates the integral by calculating the area under the quadratic interpolating the last three points, but only integrating this quadratic over the final interval, as shown in Figure 4.

https://ece.uwaterloo.ca/~ece150/Projects/Q.4/img/sum.2.png

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"strconv"
)

type Algorithm func(int, []float64, float64, float64) (float64, bool)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 3 {
		usage()
	}

	f := algorithm(flag.Arg(0))
	if f == nil {
		log.Fatal("invalid algorithm")
	}

	dt, err := strconv.ParseFloat(flag.Arg(1), 64)
	check(err)

	x, err := readfloats(flag.Arg(2))
	check(err)

	calculus(x, dt, f)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <algorithm> <timestep> <file>")
	flag.PrintDefaults()
	fmt.Fprintln(os.Stderr, "available algorithms: diff1 diff2 int1 int2")
	os.Exit(2)
}

func algorithm(name string) Algorithm {
	switch name {
	case "diff1":
		return diff1
	case "diff2":
		return diff2
	case "int1":
		return int1
	case "int2":
		return int2
	}
	return nil
}

func readfloats(name string) ([]float64, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := []float64{}
	for {
		var v float64
		n, _ := fmt.Fscanf(f, "%v", &v)
		if n != 1 {
			break
		}
		r = append(r, v)
	}
	return r, nil
}

func calculus(x []float64, dt float64, f Algorithm) {
	var (
		y  float64
		ok bool
	)
	for n := range x {
		y, ok = f(n, x, y, dt)
		if ok {
			fmt.Printf("%.6f\n", y)
		}
	}
}

func diff1(n int, x []float64, y, dt float64) (float64, bool) {
	if n < 1 {
		return 0, false
	}
	return (x[n] - x[n-1]) / dt, true
}

func diff2(n int, x []float64, y, dt float64) (float64, bool) {
	if n < 2 {
		return 0, false
	}
	return (3*x[n] - 4*x[n-1] + x[n-2]) / (2 * dt), true
}

func int1(n int, x []float64, y, dt float64) (float64, bool) {
	if n < 1 {
		return 0, false
	}
	return (x[n]+x[n-1])/2*dt + y, true
}

func int2(n int, x []float64, y, dt float64) (float64, bool) {
	if n < 2 {
		return 0, false
	}
	return (5*x[n]+8*x[n-1]-x[n-2])/12*dt + y, true
}
