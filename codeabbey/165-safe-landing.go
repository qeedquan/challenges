/*

You are in a rocket approaching the Moon!
Main computer failed (it was not built by DEC)!
You are to perform manual landing by controlling engines
specify fuel burning rate (kgs per second) for each 10 sec
and try to touch down with safe speed. Good luck!!!
Rocket weight: 7500 kg

Time   Height(m)   Speed(m/s)   Fuel(kg)   Gravity(m/s^2)
   0     200000       1600       7500           1.30
burning rate:


In the year of 1969 first ever people from the Earth landed on the Moon. As Neil Armstrong the commander of the Apollo 11 mission told about it one small step for man, one giant leap for mankind! However we rarely think about how technically complicated this task was.

Here is a pilot's landing simulator - imagine, you are being trained for next manned missions to the moon. I have found the game in the old book 101 BASIC Computer Games and so here is an exercise based on it.

Problem statement
You are in the space craft which is approaching the Moon. Initially you flight (or rather fall) to the surface with the great speed. However you have some fuel for landing and you can burn it in the retrorockets for "braking".

You can change the settings of the engine each 10 seconds. For each next period you specify the burning rate of the fuel - i.e. how many kilograms of fuel should be fed to the engine each second.

Try playing the demo above. You will see that burn rate could be set to any value between 0 and 100. When engines are off you are free falling - and you will see that:

height is decreased according to descent speed i.e. with speed 300 m/s you travel roughly 3000 m in 10 sec period;
speed itself is increading according to gravity acceleration i.e. with gravity 1.5 m/s^2 the speed increases from 300 to about 315 after ten seconds;
gravity itself is slightly increasing as you approach the surface.
If you turn on engines (i.e. set non-zero burning rate), the speed is also affected by retro-rockets according to Tsiolkovsky Rocket Equation.

You can find detailed explanations of these calculations in the article on rocket flight and gravity.

You will be given a sequence of values - successive settings of burning rate for each 10 seconds of the flight. Your goal is to tell the speed the craft will have on touch down (i.e. on reaching the height 0). Perform simulation with small steps, for example dt=0.1 sec.

Additional data you will need:

Moon radius is 1737.1 km;
gravity acceleration at its surface is 1.622 m/s^2;
your rocket exhaust speed is 2800 m/s.
Input data will have the mass of the craft, mass of the fuel, initial height and descent velocity in the first line.
Next line will specify several values - settings of the burn rate for each next period. After the fuel is ended the further settings should be ignored. If after proceeding through all the sequence the rocket still is not on the surface, continue calculation as it is in free fall.
Answer should give single value - the speed on reaching the Moon surface. Error about 1% is acceptable.

Example #1:

input data:
7500 7500 200000 1600
0 0 0 0 0 0 0

answer:
1772
Example #2:

input data:
6000 7000 150000 2000
0 100 100 100 50 50 50 50 50 50 100 100 100

answer:
273

*/

package main

import (
	"math"
)

func main() {
	assert(simulate(7500, 7500, 200000, 1600, []float64{0, 0, 0, 0, 0, 0, 0}) == 1772)
	assert(simulate(6000, 7000, 150000, 2000, []float64{0, 100, 100, 100, 50, 50, 50, 50, 50, 50, 100, 100, 100}) == 273)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

m_craft: dry mass of spacecraft (kg)
m_fuel: initial mass of fuel (kg)
init_height: starting height above surface (m)
init_velocity: starting downward velocity (m/s)
burn_rates: list of burn rate values (kg/s) provided for every 10s period

*/

func simulate(m_craft, m_fuel, init_height, init_velocity float64, burn_rates []float64) int {
	const (
		dt = 0.001     // Step size in seconds
		R  = 1737100.0 // Moon radius in meters
		g0 = 1.622     // Surface gravity in m/s^2
		Ve = 2800.0    // Exhaust velocity in m/s
	)

	h := init_height
	v := init_velocity
	fuel := m_fuel
	t := 0.0
	for h > 0 {
		// Determine the current 10-second period index
		rate_idx := int(t / 10)

		// Get the burn rate configuration; if we run out of settings, default to 0 (free fall)
		current_rate := 0.0
		if rate_idx < len(burn_rates) && fuel > 0 {
			current_rate = burn_rates[rate_idx]
		}

		// Calculate maximum fuel available to burn in this dt interval
		dm := current_rate * dt
		if dm > fuel {
			dm = fuel
		}

		// Update mass properties
		m_total := m_craft + fuel

		// Calculate local gravity at the current altitude
		g_local := g0 * sqr(R/(R+h))

		// Update Velocity (Tsiolkovsky rocket equation factor + gravity factor)
		v_next := v + g_local*dt
		if dm > 0 {
			v_next -= Ve * math.Log(m_total/(m_total-dm))
		}

		// Update Height
		h_next := h - v_next*dt

		// Break early or interpolate if we crossed the surface boundary
		if h_next <= 0 {
			// Linear interpolation for precise touchdown velocity at exactly h = 0
			fraction := h / (h - h_next)
			v = v + fraction*(v_next-v)
			break
		}

		// Commit steps
		h = h_next
		v = v_next
		fuel -= dm
		t += dt
	}
	return int(v)
}

func sqr(x float64) float64 {
	return x * x
}
