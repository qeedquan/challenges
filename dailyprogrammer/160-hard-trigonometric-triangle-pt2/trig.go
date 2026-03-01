/*

[I'm posting this early because there's a chance I won't have access to the internet tomorrow. Better an hour early than a day late I suppose.]

A triangle on a flat plane is described by its angles and side lengths, and you don't need all of the angles and side lengths to work out everything about the triangle.
(This is the same as last time.)
However, this time, the triangle will not necessarily have a right angle.
This is where more trigonometry comes in. Break out your trig again, people.

Here's a representation of how this challenge will describe a triangle.
Each side is a lower-case letter, and the angle opposite each side is an upper-case letter - exactly the same as last time.
Side a is opposite angle A, side b is opposite angle B, and side c is opposite angle C.
However, angle C is not guaranteed to be 90' anymore, meaning the old right-angle trigonometry will not work; the choice of letter is completely arbitrary now.
Your challenge is, using trigonometry and given an appropriate number of values, to find the rest of the values.

Formal Inputs and Outputs
Input Description
On the console, you will be given a number N. You will then be given N lines, expressing some details of a triangle in the format:

3
a=2.45912
A=39
B=56
a, A and B are just examples, it could be a, b and B or whatever.

Where all angles are in degrees.
Note that, depending on your language of choice, a conversion to radians may be needed to use trigonometric functions such as sin, cos and tan.

Output Description
You must print out all of the details shown below of the triangle in the same format as above.

a=2.45912
b=3.23953
c=3.89271
A=39
B=56
C=85
The input data will always give enough information and will describe a valid triangle.

Sample Inputs & Outputs
Sample Input
3
c=7
A=43
C=70

Sample Output
a=5.08037
b=6.85706
c=7
A=43
B=67
C=70

Notes
There are 5 more useful trigonometric identities you may find very useful. The 4 from Part 1 aren't great here as they are edge cases of trigonometry.

Sum of the angles is 180

Sine Rule 1

Sine Rule 2 (same as above but re-arranged)

Cosine Rule 1

Cosine Rule 2 (same as above but re-arranged)

Finally...
Some of your excellent solutions to Part 1 already accounted for these situations.
If your solution from last time already solves this challenge, don't be afraid of posting it again here too!
If your solution from last time doesn't, don't fret.
You may be able to re-use a lot of code from last time anyway.
Learning to write reusable code is generally good practice in the field.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math"
	"os"
	"strings"
)

type Identity struct {
	symbol   *float64
	evaluate func() float64
}

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	variables, err := parse(flag.Arg(0))
	check(err)

	solve(variables)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <file>")
	flag.PrintDefaults()
	os.Exit(2)
}

func parse(name string) (map[rune]float64, error) {
	variables := make(map[rune]float64)
	file, err := os.Open(name)
	if err != nil {
		return variables, err
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		var (
			symbol rune
			value  float64
		)
		matched, _ := fmt.Sscanf(scanner.Text(), "%c=%f", &symbol, &value)
		if matched == 2 {
			variables[symbol] = value
		}
	}

	return variables, nil
}

func solve(variables map[rune]float64) {
	for _, symbol := range "abcABC" {
		_, found := variables[symbol]
		if !found {
			variables[symbol] = math.NaN()
		} else if strings.IndexRune("ABC", symbol) >= 0 {
			variables[symbol] = deg2rad(variables[symbol])
		}
	}

	a := variables['a']
	b := variables['b']
	c := variables['c']
	A := variables['A']
	B := variables['B']
	C := variables['C']
	identities := []Identity{
		{&A, func() float64 { return math.Asin(a * math.Sin(B) / b) }},
		{&A, func() float64 { return math.Asin(a * math.Sin(C) / c) }},
		{&B, func() float64 { return math.Asin(b * math.Sin(A) / a) }},
		{&B, func() float64 { return math.Asin(b * math.Sin(C) / c) }},
		{&C, func() float64 { return math.Asin(c * math.Sin(A) / a) }},
		{&C, func() float64 { return math.Asin(c * math.Sin(B) / b) }},

		{&c, func() float64 { return math.Sqrt(a*a + b*b - 2*a*b*math.Cos(C)) }},
		{&c, func() float64 { return a * math.Sin(math.Pi-A-B) / math.Sin(A) }},
		{&c, func() float64 { return a * math.Sin(C) / math.Sin(A) }},
		{&c, func() float64 { return a * math.Sin(C) / math.Sin(math.Pi-B-C) }},
		{&c, func() float64 { return b * math.Sin(math.Pi-A-B) / math.Sin(B) }},
		{&c, func() float64 { return b * math.Sin(C) / math.Sin(math.Pi-A-C) }},
		{&c, func() float64 { return b * math.Sin(C) / math.Sin(B) }},

		{&b, func() float64 { return math.Sqrt(a*a + c*c - 2*a*c*math.Cos(B)) }},
		{&b, func() float64 { return c * math.Sin(B) / math.Sin(math.Pi-A-B) }},
		{&b, func() float64 { return c * math.Sin(math.Pi-A-C) / math.Sin(C) }},
		{&b, func() float64 { return c * math.Sin(B) / math.Sin(C) }},

		{&a, func() float64 { return math.Sqrt(b*b + c*c - 2*b*c*math.Cos(A)) }},
		{&a, func() float64 { return c * math.Sin(A) / math.Sin(math.Pi-A-B) }},
		{&a, func() float64 { return c * math.Sin(A) / math.Sin(C) }},
		{&a, func() float64 { return c * math.Sin(math.Pi-B-C) / math.Sin(C) }},

		{&A, func() float64 { return math.Acos((b*b + c*c - a*a) / (2 * b * c)) }},
		{&B, func() float64 { return math.Acos((a*a + c*c - b*b) / (2 * a * c)) }},
		{&C, func() float64 { return math.Acos((a*a + b*b - c*c) / (2 * a * b)) }},
	}

	for _, identity := range identities {
		if math.IsNaN(*identity.symbol) {
			*identity.symbol = identity.evaluate()
		}
	}

	fmt.Printf("a=%.5f\n", a)
	fmt.Printf("b=%.5f\n", b)
	fmt.Printf("c=%.5f\n", c)
	fmt.Printf("A=%.0f\n", rad2deg(A))
	fmt.Printf("B=%.0f\n", rad2deg(B))
	fmt.Printf("C=%.0f\n", rad2deg(C))
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}

func rad2deg(x float64) float64 {
	return x * 180 / math.Pi
}
