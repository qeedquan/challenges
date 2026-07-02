/*

A laboratory is testing how atoms react in ionic state during nuclear fusion. They introduce different elements with Hydrogen in high temperature and pressurized chamber. Due to unknown reason the chamber lost its power and the elements in it started precipitating
Given the number of atoms of Carbon [C],Hydrogen[H] and Oxygen[O] in the chamber. Calculate how many molecules of Water [H2O], Carbon Dioxide [CO2] and Methane [CH4] will be produced following the order of reaction affinity below

1. Hydrogen reacts with Oxygen   = H2O
2. Carbon   reacts with Oxygen   = CO2
3. Carbon   reacts with Hydrogen = CH4

https://imgur.com/wDYZ9zg

FOR EXAMPLE:
(C,H,O) = (45,11,100)
return no. of water, carbon dioxide and methane molecules
Output should be like:
(5,45,0)

*/

use std::cmp::min;

fn main() {
    assert_eq!(burner(45, 11, 100), (5, 45, 0));
    assert_eq!(burner(354, 1023230, 0), (0, 0, 354));
    assert_eq!(burner(939, 3, 694), (1, 346, 0));
    assert_eq!(burner(215, 41, 82100), (20, 215, 0));
    assert_eq!(burner(113, 0, 52), (0, 26, 0));
}

fn burner(carbon: isize, hydrogen: isize, oxygen: isize) -> (isize, isize, isize) {
    let water = min(hydrogen / 2, oxygen);
    let co2 = min(carbon, (oxygen - water) / 2);
    let methane = min(carbon - co2, (hydrogen - (water * 2)) / 4);
    (water, co2, methane)
}
