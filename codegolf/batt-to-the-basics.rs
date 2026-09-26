/*

One of your acquaintances has a hobby of making make-shift electrical gadgets using various types of batteries.
However, since they're thrifty, they want to use as few batteries as possible for their projects.
This challenge uses several types of batteries; your job is to output the fewest number of batteries that will output a given voltage when chained together.

The batteries you'll be using
Here are the types of batteries you will be using, along with their ID numbers (I assigned those for this challenge) and their output voltages:

AA 1.5V
Button battery 3V
Li-ion battery 3.7V
9V battery 9V
Car battery 12V
Batteries can also be half-charged, meaning that their voltage is half of what it is fully charged (I've removed any batteries who's half-voltages are the voltages of any full batteries):

½ AA .75V
½ Li-ion 1.85V
½ 9V battery 4.5V
½ Car battery 6V
The rules
Input i must be a float where 1 ≤ i ≤ 100, and where i has 1 or 2 decimal digits.
Output must be a list of the fewest number of battery ID numbers (as listed above) that, when combined, will output the voltage, or an empty list (or any other empty value) if the voltage can't be produced using the above batteries.
Alternatively, the list can consist of the voltages of the batteries used; however, the voltages must correspond with one of the batteries above.
Here are some test cases (the numbers aren't very large right now because of the time it takes to run the code for large numbers):

input: 1.5
output: [1.5]

input: 2
output: [] or None

input: 7.5
output: [6, 1.5]

input: 15
output: [12, 3]
This is a code-golf challenge, so the fewest bytes wins!

*/

fn main() {
    assert_eq!(solve(1.5), vec![1.5]);
    assert_eq!(solve(2.0), vec![]);
    assert_eq!(solve(7.5), vec![6.0, 1.5]);
    assert_eq!(solve(15.0), vec![12.0, 3.0]);

    let mut voltage = 0.0;
    while voltage <= 20.0 {
        println!("{voltage} -> {:?}", solve(voltage));
        voltage += 1.0;
    }
}

fn solve(voltage: f64) -> Vec<f64> {
    let mut result = vec![];
    if !recurse(voltage, &mut result, 0.0) {
        return vec![];
    }
    result
}

fn recurse(voltage: f64, result: &mut Vec<f64>, total: f64) -> bool {
    if total > voltage {
        return false;
    }
    if total == voltage {
        return true;
    }

    for value in vec![12.0, 9.0, 6.0, 4.5, 3.7, 3.0, 1.85, 1.5, 0.75] {
        result.push(value);
        if recurse(voltage, result, total + value) {
            return true;
        }
        result.pop();
    }
    false
}
