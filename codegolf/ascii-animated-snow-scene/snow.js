/*

Write the shortest program to turn any piece of ASCII art into an animated snow scene that begins to form from the falling snow (non-golfed JavaScript example last updated 2011-12-19).
https://jsfiddle.net/plstand/GD2Dk/

Input specification: Your program must accept arbitrary combinations of spaces, asterisks, and newlines. The input will contain at most 23 lines and 80 characters per line. There will be no empty lines, yet lines may consist of only whitespace. A single trailing newline will be included and must be ignored.

Output: Output ASCII characters (spaces, asterisks) and control codes (carriage returns, linefeeds, ANSI escape codes, etc.) for your operating system's text console or terminal emulator until the user manually terminates the program. You may assume the terminal window is 80x24 characters if your operating system allows that setting.

Rules:

The animation must be smooth and fast (15 fps preferred).
Snow density must be between 5% and 15%.
No more than one screen of snow may scroll per second. (That means no more than 24 lines of new snow may be added in any one second time period.)
The snow must not display any obvious pattern as it enters the top of the screen; it must look random.
The program must fill all rows of the screen with snow as quickly as possible when it starts; initial filling of the screen's individual rows must not be obvious to the viewer.
The lower left corner of the input ASCII art must be at the lower left corner of the screen (Figure 1 for further clarification).
The area inside or under the ASCII art must not be permanently filled with asterisks. However, asterisks may (but are not required to) scroll through this area.
Snow must not accumulate at the bottom of the screen or on top of existing snow except as shown in the input.
Lower spaces must be filled before upper ones, as filling spaces in the opposite order makes the Christmas tree animation look very different from my original code's output. (added 2011-12-20)
Happy holidays!

Figure 1: labeled areas of an 80x24 screen
---------------------------New snow added on this line--------------------------
                                                                             |
                                                                             |
----------------------------------------------------------+                  |
                                                    ****  |                  |
    Snow MUST fall  Snow MAY fall ---------------->  **** |                  |
    through this    through these          ****      **** |  Snow MUST fall  |
    area.           areas of a              ****     **** |  through this    |
                    completed   \--------->  ****     ****|  area.           |
        ASCII art   scene.    \     ***        ****   ****|                  |
          area         \       \   *******      ****  ****|                  |
                        \       \    ********     ***  ***|  (ALL CAPS terms |
      (located in        \       \-->   *********  ***    |  have standard   |
       lower left         \     *******     ******  MAY   |     RFC 2119     |
       corner of           \    *************  **   fall  |    meanings.)    |
       screen)              \        ***********    here  |                  |
                         *** +--->          ****  ***     |                  |
                         *** | ****************   ***     |                  |
  | Snow MUST fall       *** | ****************   ***     |                  |
  | through this         *** +--->                ***     |                  |
  | area.                *** | ****************   ***     |                  |
--+---------------------+*** +--->                ***+----+------------------+--
  |   Snow MUST NOT     |****************************|      Snow MUST NOT    |
  V  accumulate here.   |****************************|     accumulate here.  V
Example inputs
Code Golf Banner
 ******   *******  ********  ********     ******    *******  **       ******** 
**    ** **     ** **     ** **          **    **  **     ** **       **       
**       **     ** **     ** **          **        **     ** **       **       
**       **     ** **     ** ******      **   **** **     ** **       ******   
**       **     ** **     ** **          **    **  **     ** **       **       
**    ** **     ** **     ** **          **    **  **     ** **       **       
 ******   *******  ********  ********     ******    *******  ******** **       
Stack Overflow Logo
                                                    ****
                                                     ****
                                           ****      ****
                                            ****     ****
                                             ****     ****
                                    ***        ****   ****
                                   *******      ****  ****
                                     ********     ***  ***
                                        *********  ***
                                *******     ******
                                *************  **
                                     ***********
                         ***                ****  ***
                         ***   ****************   ***
                         ***   ****************   ***
                         ***                      ***
                         ***   ****************   ***
                         ***                      ***
                         ****************************
                         ****************************
Christmas Trees
                                        *
                                       ***                           *
                *                     *****                         ***
               ***                   *******           *           *****
              *****                 *********         ***            *
                *                  ***********       *****
                       *          *************     *******
        *             ***        ***************       *               *
       ***           *****      *****************                     ***
      *****         *******    *******************                   *****
     *******           *      *********************                 *******
    *********                           *                          *********
        *                                                              *

*/

var snow = [],
    art = [];

function initArrays() {
    var i, x, y;

    // Initialize snow array
    for (i = 0; i < 1920; ++i) {
        snow[i] = ' ';
    }

    // Initialize art array
    var artLines = document.getElementById('input').value.split('\n');
    if (!artLines[artLines.length - 1]) {
        artLines.pop();
    }
    var artStart = 24 - artLines.length;

    for (i = 0; i < artLines.length; ++i) {
        y = artStart + i;
        for (x = 0; x < artLines[i].length; ++x) {
            art[80 * y + x] = artLines[i][x];
        }
    }

}

function dropSnow() {
    for (var y = 24; y--;) {
        for (var x = 0; x < 80; ++x) {
            if (snow[80 * y + x] === '*') {
                var drop = true;

                // Check if this space is supposed to be filled in.
                if (art[80 * y + x] === '*') {
                    // No drop unless there is a space to be filled
                    drop = false;

                    // Look for a remaining empty space.
                    for (var z = y + 1; z < 24; ++z) {
                        if (art[80 * z + x] === '*' && snow[80 * z + x] !== '*') {
                            drop = true;
                            break;
                        }
                    }

                }

                if (drop) {
                    snow[80 * y + x] = ' ';
                    snow[80 * (y + 1) + x] = '*';
                }
            }
		}
	}
}

function addSnow() {
    for (var x = 0; x < 80; ++x) {
        if (Math.random() < 0.1) {
            snow[x] = '*';
        }
    }
}

function displaySnow() {
    var text = '';
    for (var x = 0; x < 24; ++x) {
        text += snow.slice(80 * x, 80 * (x + 1)).join('') + '\n';
    }
    document.getElementById('output').value = text;
}

function animate() {
    dropSnow();
    addSnow();
    displaySnow();
}

initArrays();
for (var x = 0; x < 24; ++x) {
    animate();
}

setInterval(animate, 67);
