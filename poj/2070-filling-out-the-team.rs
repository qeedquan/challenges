/*

Description

Over the years, the people of the great city of Pittsburgh have repeatedly demonstrated a collective expertise at football second to none. Recently a spy has discovered the true source of the city's football power-a wizard known only as "Myron," who is infallible at selecting the proper position at which each player will excel.

Now that you know the source of Pittsburgh's wisdom, you are determined to provide your school's football team with a computer program that matches the wisdom of "Myron." You have consulted with the best football minds you can find, and they have dispensed their wisdom on the slowest speed, minimum weight, and minimum strength required to play each position.

http://poj.org/images/2070_1.jpg

Using this knowledge, you will develop a program that reads in several players physical attributes and outputs what position(s) they are able to play.

Input

Each line of the input file will list the attributes for one player:
< speed > < weight > < strength >
Each number will be a real-valued number. The file will end with a line reading "0 0 0"

Output

For each player, you will output one line listing the positions that player can play. A player can play a position if each of their attributes is greater or equal to the minimum for weight and strength, and less than or equal to the slowest speed. If a player can play multiple positions, output them in the order listed above, separated by whitespace. You may leave an extra space at the end of the line. If a player can play no positions, write "No positions" on the line.

Sample Input

4.4 180 200
5.5 350 700
4.4 205 350
5.2 210 500
0 0 0

Sample Output

Wide Receiver
Lineman
Wide Receiver Quarterback
No positions
Source

Mid-Atlantic 2004

*/

fn main() {
    assert_eq!(positions(4.4, 180.0, 200.0), vec!["Wide Receiver"]);
    assert_eq!(positions(5.5, 350.0, 700.0), vec!["Lineman"]);
    assert_eq!(
        positions(4.4, 205.0, 350.0),
        vec!["Wide Receiver", "Quarterback"]
    );
    assert_eq!(positions(5.2, 210.0, 500.0), vec!["No positions"]);
}

fn positions(speed: f64, weight: f64, strength: f64) -> Vec<&'static str> {
    let mut result = vec![];

    if speed <= 4.5 && weight >= 150.0 && strength >= 200.0 {
        result.push("Wide Receiver");
    }

    if speed <= 6.0 && weight >= 300.0 && strength >= 500.0 {
        result.push("Lineman");
    }

    if speed <= 5.0 && weight >= 200.0 && strength >= 300.0 {
        result.push("Quarterback");
    }

    if result.len() == 0 {
        result.push("No positions");
    }

    result
}
