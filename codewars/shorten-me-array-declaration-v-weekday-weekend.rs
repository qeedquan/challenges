/*

Shorten Me: Array Declaration V (Weekday & Weekend)

Task
You have to write an array() function returning an array object with elements as follow:

[ 'sunday', 'monday', 'tuesday', 'wednesday',
  'thursday','friday','saturday' ]

Coding Limitation:
Less than 75 characters

*/

fn main() {
    println!("{:?}", days());
}

fn days() -> &'static [&'static str] {
    &[
        "sunday",
        "monday",
        "tuesday",
        "wednesday",
        "thursday",
        "friday",
        "saturday",
    ]
}
