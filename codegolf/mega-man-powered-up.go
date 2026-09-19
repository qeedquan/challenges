/*

Objective

Given the name of a robot master in Mega Man: Powered Up except the trailing string Man, output the name of the robot master (again, except the trailing string Man) whom the inputted robot master has advantage over in fighting (with his weapon).
Mapping

(Input -> Output)

Cut -> Bomb
Bomb -> Ice
Ice -> Fire
Fire -> Oil
Oil -> Elec
Elec -> Time
Time -> Guts
Guts -> Cut

I/O Format

It is implementation-defined whether to accept leading or trailing whitespace on the input.

Outputting a trailing newline in the output is permitted.

Otherwise flexible.

*/

package main

func main() {
	assert(advantage("Cut") == "Bomb")
	assert(advantage("Bomb") == "Ice")
	assert(advantage("Ice") == "Fire")
	assert(advantage("Fire") == "Oil")
	assert(advantage("Oil") == "Elec")
	assert(advantage("Elec") == "Time")
	assert(advantage("Time") == "Guts")
	assert(advantage("Guts") == "Cut")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func advantage(master string) string {
	lut := map[string]string{
		"Cut":  "Bomb",
		"Bomb": "Ice",
		"Ice":  "Fire",
		"Fire": "Oil",
		"Oil":  "Elec",
		"Elec": "Time",
		"Time": "Guts",
		"Guts": "Cut",
	}
	return lut[master]
}
