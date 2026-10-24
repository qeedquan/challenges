/*

Jack and Jill are twins. When they are 10 years of age, Jack leaves earth in his spaceship bound for Altair IV, some 17 light-years distant. Though not equipped with warp drive, Jack's ship is still capable of attaining near light speed. When he returns to earth he finds that Jill has grown to adulthood while he, Jack, remains a young boy.

Albert Einstein had predicted this strange quirk of time in his 1905 paper "On the Electrodynamics of Moving Bodies" aka The Theory of Special Relativity. It has been verified experimentally many times.

Implement a function that has as its arguments: The twins' age at the time of Jack's departure, the distance in light-years to the destination star, and the speed of Jack's ship as a fraction of the speed of light. The function will return Jack's age and Jill's age at the time of Jack's return to earth, to the nearest of a year. The math is simple enough for 10-year-old Jack to understand.

Examples
(20, 10, 0.4) ➞ (65.8, 70) # Jack's age is 65.8, Jill's age is 70.0

(20, 10, 0.8) ➞  (35, 45) # Jack's age is 35.0, Jill's age is 45.0"

(10, 16.73, 0.999) ➞  (11.5, 43.5) # Jack's age is 11.5, Jill's age is 43.5"
// The Altair IV trip.

Notes
We are assuming for the sake of simplicity that Jack's periods of acceleration and deceleration are negligibly brief. That is a huge assumption but, nevertheless, it doesn't invalidate the age calculations.
See this for help.
https://en.wikipedia.org/wiki/Twin_paradox

*/

fn main() {
    println!("{:?}", twins(20.0, 10.0, 0.4));
    println!("{:?}", twins(20.0, 10.0, 0.8));
    println!("{:?}", twins(10.0, 16.73, 0.999));
}

fn twins(age: f64, distance: f64, velocity: f64) -> (f64, f64) {
    let time = (2.0 * distance) / velocity;
    let jill = age + time;
    let jack = age + time * (1.0 - velocity * velocity).sqrt();
    (jack, jill)
}
