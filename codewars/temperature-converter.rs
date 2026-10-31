/*

Write a function convert_temp(temp, from_scale, to_scale) converting temperature from one scale to another. Return converted temp value.

Round converted temp value to an integer(!).

Reading: http://en.wikipedia.org/wiki/Conversion_of_units_of_temperature

possible scale inputs:
    "C"  for Celsius
    "F"  for Fahrenheit
    "K"  for Kelvin
    "R"  for Rankine
    "De" for Delisle
    "N"  for Newton
    "Re" for Réaumur
    "Ro" for Rømer
temp is a number, from_scale and to_scale are strings.

convert_temp(   100, "C",  "F") # => 212
convert_temp(    40, "Re", "C") # => 50
convert_temp(    60, "De", "F") # => 140
convert_temp(373.15, "K",  "N") # => 33
convert_temp(   666, "K",  "K") # => 666

*/

#![allow(non_snake_case)]

use std::collections::HashMap;

fn main() {
    assert_eq!(conv(100.0, "C", "F"), 212);
    assert_eq!(conv(40.0, "Re", "C"), 50);
    assert_eq!(conv(60.0, "De", "F"), 140);
    assert_eq!(conv(373.15, "K", "N"), 33);
    assert_eq!(conv(666.0, "K", "K"), 666);
}

fn conv(t: f64, from: &'static str, to: &'static str) -> isize {
    let t = convf(t, from);
    let t = convt(t, to);
    t.round() as isize
}

fn convf(t: f64, scale: &'static str) -> f64 {
    let SCALE = HashMap::from([
        ("C", t),
        ("F", (t - 32.0) * 5.0 / 9.0),
        ("K", t - 273.15),
        ("R", (t - 491.67) * 5.0 / 9.0),
        ("De", 100.0 - (t * 2.0 / 3.0)),
        ("N", t * 100.0 / 33.0),
        ("Re", t * 5.0 / 4.0),
        ("Ro", (t - 7.5) * 40.0 / 21.0),
    ]);

    SCALE[scale]
}

fn convt(t: f64, scale: &'static str) -> f64 {
    let SCALE = HashMap::from([
        ("C", t),
        ("F", t * 9.0 / 5.0 + 32.0),
        ("K", t + 273.15),
        ("R", (t + 273.15) * 9.0 / 5.0),
        ("De", (100.0 - t) * 3.0 / 2.0),
        ("N", t * 33.0 / 100.0),
        ("Re", t * 4.0 / 5.0),
        ("Ro", t * 21.0 / 40.0 + 7.5),
    ]);

    SCALE[scale]
}
