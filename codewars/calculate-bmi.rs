/*

Write function bmi that calculates body mass index (bmi = weight / height^2).

if bmi <= 18.5 return "Underweight"

if bmi <= 25.0 return "Normal"

if bmi <= 30.0 return "Overweight"

if bmi > 30 return "Obese"

*/

fn main() {
    assert_eq!(bmi(50.0, 1.80), "Underweight");
    assert_eq!(bmi(80.0, 1.80), "Normal");
    assert_eq!(bmi(90.0, 1.80), "Overweight");
    assert_eq!(bmi(100.0, 1.80), "Obese");
}

fn bmi(weight: f64, height: f64) -> &'static str {
    let value = weight / (height * height);
    if value <= 18.5 {
        return "Underweight";
    }
    if value <= 25.0 {
        return "Normal";
    }
    if value <= 30.0 {
        return "Overweight";
    }
    return "Obese";
}
