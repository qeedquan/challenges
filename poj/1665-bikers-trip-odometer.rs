/*

Description

Most bicycle speedometers work by using a Hall Effect sensor fastened to the front fork of the bicycle. A magnet is attached to one of the spokes on the front wheel so that it will line up with the Hall Effect switch once per revolution of the wheel. The speedometer monitors the sensor to count wheel revolutions. If the diameter of the wheel is known, the distance traveled can be easily be calculated if you know how many revolutions the wheel has made. In addition, if the time it takes to complete the revolutions is known, the average speed can also be calculated.
For this problem, you will write a program to determine the total distance traveled (in miles) and the average speed (in Miles Per Hour) given the wheel diameter, the number of revolutions and the total time of the trip. You can assume that the front wheel never leaves the ground, and there is no slipping or skidding.

Input

Input consists of multiple datasets, one per line, of the form:
diameter revolutions time
The diameter is expressed in inches as a floating point value. The revolutions is an integer value. The time is expressed in seconds as a floating point value. Input ends when the value of revolutions is 0 (zero).

Output

For each data set, print:
Trip #N: distance MPH
Of course N should be replaced by the data set number, distance by the total distance in miles (accurate to 2 decimal places) and MPH by the speed in miles per hour (accurate to 2 decimal places). Your program should not generate any output for the ending case when revolutions is 0.

Sample Input

26 1000 5
27.25 873234 3000
26 0 1000

Sample Output

Trip #1: 1.29 928.20
Trip #2: 1179.86 1415.84

Hint

Constants
For p use the value: 3.1415927.
There are 5280 feet in a mile.
There are 12 inches in a foot.
There are 60 minutes in an hour.
There are 60 seconds in a minute.
There are 201.168 meters in a furlong.
Source

Greater New York 2003

*/

use std::f64::consts::*;

fn main() {
    test(26.0, 1000.0, 5.0, 1.29, 928.20);
    test(27.25, 873234.0, 3000.0, 1179.86, 1415.84);
}

fn test(diameter: f64, revolutions: f64, time: f64, expected_distance: f64, expected_speed: f64) {
    let eps = 1e-2;
    let (distance, speed) = motion(diameter, revolutions, time);
    println!("{} {}", distance, speed);
    assert_eq!(true, (distance - expected_distance).abs() < eps);
    assert_eq!(true, (speed - expected_speed).abs() < eps);
}

fn motion(diameter: f64, revolutions: f64, time: f64) -> (f64, f64) {
    let distance = (diameter * revolutions * PI) / 63360.0;
    let speed = (distance * 3600.0) / time;
    (distance, speed)
}
