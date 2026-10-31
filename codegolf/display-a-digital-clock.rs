/*

Display a Digital Clock
(I see there are many clock challenges, I have tried to read them all, I'm pretty sure this is unique)

Write some code that continuously updates a digital clock displayed in the format h:m:s where h, m, and s can occupy 1 or 2 characters each. The restrictions in simple terms as @BlueEyedBeast put it, I basically want it to replace the time shown.

Newlines are not allowed
Trailing spaces are allowed
Other trailing characters are not allowed
No seconds should be missed (57 -> 59 is not allowed)
Numbers beginning with "0" are allowed, as long as they don't occupy more than 2 characters
The code must not accept any input
If your language can't get the current time without input, you may use for input up to 8 bytes in a standardly allowed way
Output must be to stdout
This is codegolf so the shortest answer wins!
Example

I'm working on a language named *><> (starfish) because programs like this aren't possible in ><> (just wait for file i/o) . Here's a working digital clock program in it (ungolfed). This program is written in *><>:

s":"m":"hnonon"   "ooo88888888888ooooooooooo1S
Note: Everything is identical to ><> in this except, s = second, m = minute, h = hour, S = sleep(100ms*x)

This outputs:

14:44:31
Updating every 100ms until terminated.

Disallowed Examples

The following are not allowed:

1:

14:44:3114:44:32
2:

14:44:31 14:44:32
3:

14:44:31
14:44:32
The time must remain on the first line it was outputted with no visible trailing characters. Clearing the terminal though, would be allowed as that still wouldn't have any trailing characters.

*/

use std::thread::*;
use std::time::*;

fn main() {
    loop {
        let now = SystemTime::now();
        clear();
        println!("{:?}", now);
        sleep(Duration::from_millis(100));
    }
}

fn clear() {
    print!("\x1b[2J\x1b[H");
}
