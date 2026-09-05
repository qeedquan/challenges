/*

We all know run-length decoding: A list of character-length pairs expands to a string of that many characters, so A1B4C2 expands to ABBBBCC. But what if we stretch this concept to 2 dimensions?

Instead of character-length pairs, in this challenge you will be given character-length-direction triples. For example, using N/S/E/W to indicate direction, the input A4E B5S C3W D3N E1W should yield the output

AAAAB   
    B
 E  B
 D  B
 D  B
 DCCC
You can take input in any reasonable format (such as a list of (char, length, N/E/S/W) like shown here, or perhaps (0/1/2/3, length, char)).

The input will not overlap itself, so A5E B3W or A5E B4S C4W D4N is invalid input.

The input will also not expand past the left or top edges of the string, only the bottom and right edges will be expanded.

The character will always be within the printable ASCII range.

Consistent trailing or leading whitespace that does not affect the presentation of the output is fine.

This is code-golf, so the shortest submission per language, measured in bytes, wins.

Here are a couple cases to test your entry against:

A4E B5S C3W D3N E1W
AAAAB   
    B
 E  B
 D  B
 D  B
 DCCC

A4E B5S C3W D3N -2E -1N  2W |1S
AAAAB   
 |  B
 ---B
 D  B
 D  B
 DCCC

.3S  2E ,3N  2E .5S
.   . 
. , .  
. , .  
  , .   
    .

>6E v3S <6W ^2N >5E v1S <5W
>>>>>>v 
>>>>>vv
^<<<<<v
^<<<<<<
And here's an example implementation in JavaScript.

https://ato.pxeger.com/run?1=hVPBjpswEFWvfMWIk1HAWpJmtdKGSG2XnqocyoEDpRIiZkNKTQp2lajJl-wlh_aj2tv-yKpjGxJ2K6WRItvj996M5w0PP3m9ZMfjLykK7-bPq8dC8lyUNYdl2TC9y6qPkn9g_F6s7liOaFLyjQM_LIC85q2ArGkggCS9xUjFBGzxdNUfdv2hqBsgSb7KGhcvlJp7zpFCXcBJtgMreqnpuMw6Eu5Hox4GKneyS2G_7wtQv7IAYi6oIcEsgO2ZNNBfG_016m9xUdIdcyPbFbHBdnrVw7OUyTZFqnrOMOvpQRAEAdih7WA3RgH4F0CxBnmXQRGCdv9TWmjQWUlVrP4NE7LhqvBb69A7_WTMw6ZLgS9p2DeJasQuWtuhDcuW78uKRTuekysXbCTdqFboxhlmVXLW2SYFbTdVKYj9idvOcDZ0WE0HpVQRtEfmKl9J_qXFO43BlEuZM0JM2AXOtsKBYN65pp5rrmgmiOc7vbXq5ROnUzOuJWlnGqtaBs9ZGqC1DaTrjQGp0MGFJEmNgilUNWOnzdZCX7MNGQyynuJUV9oFR-foUKSVlerEhe9KJzpx6orRqr4nqm3_BI2crkX7gNnVStd1yYmNHnQ77cdLsnMag-Pv_M3rEN5OI3g3ieFusoDQj62XMW8cgucvAMYx7P3IopMI9yG4k4Ve6TSy5tchfMf47DqGz-MFzKd49vE8jU2uvw

*/

function directionalRunLengthDecode(inp) {
    const arr = [];
    let x = 0;
    let y = 0;
    for ([char, length, direction] of inp) {
        for (let i = 0; i < length; i++) {
            arr[y] ||= [];
            if (arr[y].length <= x) {
                for (let j = 0; j < x; j++)
                    arr[y].push(" ");
            }
            arr[y][x] = char;

            if (direction === "E")
                x += 1;
            else if (direction === "W")
                x -= 1;
            else if (direction === "S")
                y += 1;
            else if (direction === "N")
                y -= 1;
        }
    }
    return arr;
}

function main() {
    const input = `
A4E B5S C3W D3N E1W
A4E B5S C3W D3N -2E -1N  2W |1S
.3S  2E ,3N  2E .5S
>6E v3S <6W ^2N >5E v1S <5W
`

    for (const line of input.split("\n")) {
        if (line === "")
            continue;

        const split = [...line];
        const chunks = split.reduce((chunks, next) => {
            if (chunks.at(-1).length === 3)
                chunks.push([]);
            else
                chunks.at(-1).push(next);
            return chunks;
        }, [
            []
        ]);
        const ready = chunks.map(([char, len, dir]) => [char, +len, dir]);
        const result = directionalRunLengthDecode(ready);
        console.log(line);
        console.log(result.map(line => line.join("")).join("\n"));
        console.log();
    }
}

main();
