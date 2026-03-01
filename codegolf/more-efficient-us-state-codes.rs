/*

Abbreviate that US state! was fun, but we learnt that efficiently abbreviating US state names is hard with the current system. Let's come up with an alternative state code scheme for efficient golfing.

Your task:

Write a function (or program) which, given a valid US state name (only the 50 normal states required), returns a unique two-letter code in uppercase identifying it. The code must meet these requirements:

The first letter must be the same as the first letter of the state.
The second letter must be one of the other letters of the state (not a space).
It must always give the same output for the same input, and must never give the same output for two different valid inputs.
For instance, given "Alabama", your function could return "AL", "AA", "AB" or "AM" - as long as it doesn't return that value for any of Alaska, Arkansas, etc. ("AA" is only possible because "A" appears more than once in the state name.)

Standard loopholes forbidden. Standard input/output are ok. This is code golf, so shortest solution, in bytes, wins.

The complete list of possible inputs is here:

Alabama
Alaska
Arizona
Arkansas
California
Colorado
Connecticut
Delaware
Florida
Georgia
Hawaii
Idaho
Illinois
Indiana
Iowa
Kansas
Kentucky
Louisiana
Maine
Maryland
Massachusetts
Michigan
Minnesota
Mississippi
Missouri
Montana
Nebraska
Nevada
New Hampshire
New Jersey
New Mexico
New York
North Carolina
North Dakota
Ohio
Oklahoma
Oregon
Pennsylvania
Rhode Island
South Carolina
South Dakota
Tennessee
Texas
Utah
Vermont
Virginia
Washington
West Virginia
Wisconsin
Wyoming

*/

fn main() {
    let states = [
        "Alabama",
        "Alaska",
        "Arizona",
        "Arkansas",
        "California",
        "Colorado",
        "Connecticut",
        "Delaware",
        "Florida",
        "Georgia",
        "Hawaii",
        "Idaho",
        "Illinois",
        "Indiana",
        "Iowa",
        "Kansas",
        "Kentucky",
        "Louisiana",
        "Maine",
        "Maryland",
        "Massachusetts",
        "Michigan",
        "Minnesota",
        "Mississippi",
        "Missouri",
        "Montana",
        "Nebraska",
        "Nevada",
        "New Hampshire",
        "New Jersey",
        "New Mexico",
        "New York",
        "North Carolina",
        "North Dakota",
        "Ohio",
        "Oklahoma",
        "Oregon",
        "Pennsylvania",
        "Rhode Island",
        "South Carolina",
        "South Dakota",
        "Tennessee",
        "Texas",
        "Utah",
        "Vermont",
        "Virginia",
        "Washington",
        "West Virginia",
        "Wisconsin",
        "Wyoming",
    ];

    for state in states {
        println!("{} -> {}", state, abbreviate(state));
    }
}

fn abbreviate(state: &'static str) -> String {
    let chars: Vec<_> = state.chars().collect();
    if chars.len() < 2 {
        return format!("{state}");
    }

    let mut index = 906 % chars.len();
    if index == 0 {
        index = 1;
    }
    return format!("{}{}", chars[0].to_uppercase(), chars[index].to_uppercase());
}
