package main

import "fmt"

func main() {
	fmt.Println(length("quarter", 3*1e2))
}

/*

https://en.wikipedia.org/wiki/Whip_antenna

A form of monopole antenna

Whip antennas are normally designed as resonant antennas; the rod acts as a resonator for radio waves, with standing waves of voltage and current reflected back and forth from its ends.
Therefore, the length of the antenna rod is determined by the wavelength (lambda) of the radio waves used. The most common length is approximately one-quarter of the wavelength (1/4*lambda) called a "quarter-wave whip"
(although often shortened by the use of a loading coil; see Electrically short whips below).
For example, the common quarter-wave whip antennas used on FM radios in the USA are approximately 75 cm (2.5 feet) long, which is roughly one-quarter the length of radio waves in the FM radio band, which are 2.78 to 3.41 m (9 to 11 feet) long.

Half-wave whips (1/2*lambda) which have greater gain, and five-eighth wave whips (5/8*lambda) which have the maximum horizontal gain achievable by a monopole, are also common lengths.

To reduce the length of a whip antenna to make it less cumbersome, an inductor (loading coil) is often added in series with it. This allows the antenna to be made much shorter than the normal length of a quarter-wavelength, and still be resonant, by cancelling out the capacitive reactance of the short antenna. This is called an electrically short whip. The coil is added at the base of the whip (called a base-loaded whip) or occasionally in the middle (center-loaded whip). In the most widely used form, the rubber ducky antenna, the loading coil is integrated with the antenna itself by making the whip out of a narrow helix of springy wire. The helix distributes the inductance along the antenna's length, improving the radiation pattern, and also makes it more flexible. Another alternative occasionally used to shorten the antenna is to add a "capacity hat", a metal screen or radiating wires, at the end. However all these electrically short whips have lower gain than a full-length quarter-wave whip.

Multi-band operation is possible with coils at about one-half or one-third and two-thirds that do not affect the aerial much at the lowest band, but it creates the effect of stacked dipoles at a higher band (usually ×2 or ×3 frequency).

At higher frequencies[a] the feed coax can go up the centre of a tube. The insulated junction of the tube and whip is fed from the coax and the lower tube end where coax cable enters has an insulated mount. This kind of vertical whip is a full dipole and thus needs no ground plane. It generally works better several wavelengths above ground, hence the limitation normally to microwave bands.

*/

func length(kind string, wavelength float64) float64 {
	ratio := 1.0
	switch kind {
	case "quarter":
		ratio = 0.25
	case "half":
		ratio = 0.5
	case "five-eight":
		ratio = 5.0 / 8
	}
	return ratio * wavelength
}
