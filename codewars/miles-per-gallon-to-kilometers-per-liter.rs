/*

Sometimes, I want to quickly be able to convert miles per imperial gallon into kilometers per liter.

Create an application that will display the number of kilometers per liter (output) based on the number of miles per imperial gallon (input).

Make sure to round off the result to two decimal points. If the answer ends with a 0, it should be rounded off without the 0. So instead of 5.50, we should get 5.5.

Some useful associations relevant to this kata:
1 Imperial Gallon = 4.54609188 litres
1 Mile = 1.609344 kilometres

*/

fn main() {
    assert_allclose(mpg2kpm(10.0), 3.54);
    assert_allclose(mpg2kpm(20.0), 7.08);
    assert_allclose(mpg2kpm(30.0), 10.62);
}

fn assert_allclose(x: f64, y: f64) {
    assert_eq!((x - y).abs() < 1e-2, true);
}

fn mpg2kpm(mpg: f64) -> f64 {
    (35.4006 * mpg).round() / 100.0
}
