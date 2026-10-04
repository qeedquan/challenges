/*

For this challenge, you need to print out the fingerings for various brass instruments.

The notes an instrument can play (as well as their fingerings) are listed below:

    Cornet                       Baritone
    Trumpet  Bugle  French Horn  Euphonium  Tuba
A#0                                         0
B0
C1                                          1234
C#1                                         134
D1                                          234
D#1                                         14
E1                                          24
F1                                          4
F#1                                         23
G1                                          12
G#1                                         1
A1                                          2
A#1                              0          0
B1                  123          1234       24
C2                  13           134        4
C#2                 23           234        23
D2                  12           124        12
D#2                 1            14         1
E2                  2            24         2
F2                  0            4          0
F#2                 123          23         23
G2                  13           12         12
G#2                 23           1          1
A2                  12           2          2
A#2                 1            0          0
B2                  2            24         12
C3                  0            4          1
C#3                 23           23         2
D3                  12           12         0
D#3                 1            1          1
E3  123             2            2          2
F3  13              0            0          0
F#3 23              12           23         23
G3  12              1            12         12
G#3 1               2            1          1
A3  2               0            2          2
A#3 0               1            0          0
B3  123             2            12         12
C4  13              0            1          1
C#4 23              23           2          2
D4  12              12           0          0
D#4 1               1            1          1
E4  2               2            2          2
F4  0               0            0          0
F#4 23              2            23         23
G4  12       0      0            12         12
G#4 1               2            1          1
A4  2               0            2          2
A#4 0               1            0          0
B4  12              2            12
C5  1        0      0            1
C#5 2               23           2
D5  0               12           0
D#5 1               1            1
E5  2        0      2            2
F5  0               0            0
F#5 23
G5  12       0
G#5 1
A5  2
A#5 0

Input
A single string with a name of an instrument. You can assume the name will always be one of the 7 listed above.
A note, which can be a single string or a string and integer. You can assume the note will match one of the notes listed above.

Output
The fingering for the note on that instrument. This can either be a list of integers (one for each digit), or a single integer.
If the instrument cannot play a given note (listed as blank above), return "Impossible"

Test Cases
Cornet D#3        Impossible
Cornet E3         123
Trumpet G4        12
Trumpet B4        12
Trumpet F#5       23
Bugle F#5         Impossible
Bugle G5          0
Bugle G1          Impossible
French Horn B1    123
French Horn C3    0
French Horn E5    2
French Horn A#5   Impossible
Baritone A#5      Impossible
Baritone A#2      0
Baritone B2       24
Baritone B1       1234
Euphonium F2      4
Tuba A#0          0
Tuba B0           Impossible
Tuba C1           1234
Tuba B1           24
Tuba G#4          1
Tuba B4           Impossible

Notes
Trumpet and Cornet have the same fingerings, as well as Baritone and Euphonium
These ranges aren't comprehensive. I've tried to stick to the "standard" notes, but instruments can often go below (pedal notes) or above.
The notes listed are in concert pitch
You'll notice that there are a lot of patterns between the fingerings. Finding those patterns is critical to golfing this well.
This is a code-golf, so the shortest answer in your favorite language wins!

*/

package main

func main() {
	assert(fingerings("Cornet", "D#3") == "Impossible")
	assert(fingerings("Cornet", "E3") == "123")
	assert(fingerings("Trumpet", "G4") == "12")
	assert(fingerings("Trumpet", "B4") == "12")
	assert(fingerings("Trumpet", "F#5") == "23")
	assert(fingerings("Bugle", "F#5") == "Impossible")
	assert(fingerings("Bugle", "G5") == "0")
	assert(fingerings("Bugle", "G1") == "Impossible")
	assert(fingerings("French Horn", "B1") == "123")
	assert(fingerings("French Horn", "C3") == "0")
	assert(fingerings("French Horn", "E5") == "2")
	assert(fingerings("French Horn", "A#5") == "Impossible")
	assert(fingerings("Baritone", "A#5") == "Impossible")
	assert(fingerings("Baritone", "A#2") == "0")
	assert(fingerings("Baritone", "B2") == "24")
	assert(fingerings("Baritone", "B1") == "1234")
	assert(fingerings("Euphonium", "F2") == "4")
	assert(fingerings("Tuba", "A#0") == "0")
	assert(fingerings("Tuba", "B0") == "Impossible")
	assert(fingerings("Tuba", "C1") == "1234")
	assert(fingerings("Tuba", "B1") == "24")
	assert(fingerings("Tuba", "G#4") == "1")
	assert(fingerings("Tuba", "B4") == "Impossible")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fingerings(instrument, note string) string {
	INSTRUMENTS := map[string]int{
		"Trumpet":     0,
		"Cornet":      0,
		"Bugle":       1,
		"French Horn": 2,
		"Baritone":    3,
		"Euphonium":   3,
		"Tuba":        4,
	}
	NOTES := map[string]int{
		"A#0": 0,
		"B0":  1,
		"C1":  2,
		"C#1": 3,
		"D1":  4,
		"D#1": 5,
		"E1":  6,
		"F1":  7,
		"F#1": 8,
		"G1":  9,
		"G#1": 10,
		"A1":  11,
		"A#1": 12,
		"B1":  13,
		"C2":  14,
		"C#2": 15,
		"D2":  16,
		"D#2": 17,
		"E2":  18,
		"F2":  19,
		"F#2": 20,
		"G2":  21,
		"G#2": 22,
		"A2":  23,
		"A#2": 24,
		"B2":  25,
		"C3":  26,
		"C#3": 27,
		"D3":  28,
		"D#3": 29,
		"E3":  30,
		"F3":  31,
		"F#3": 32,
		"G3":  33,
		"G#3": 34,
		"A3":  35,
		"A#3": 36,
		"B3":  37,
		"C4":  38,
		"C#4": 39,
		"D4":  40,
		"D#4": 41,
		"E4":  42,
		"F4":  43,
		"F#4": 44,
		"G4":  45,
		"G#4": 46,
		"A4":  47,
		"A#4": 48,
		"B4":  49,
		"C5":  50,
		"C#5": 51,
		"D5":  52,
		"D#5": 53,
		"E5":  54,
		"F5":  55,
		"F#5": 56,
		"G5":  57,
		"G#5": 58,
		"A5":  59,
		"A#5": 60,
	}
	VALUES := [][]string{
		{"Impossible", "Impossible", "Impossible", "Impossible", "0"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "Impossible"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "1234"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "134"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "234"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "14"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "24"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "4"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "23"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "12"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "1"},
		{"Impossible", "Impossible", "Impossible", "Impossible", "2"},
		{"Impossible", "Impossible", "Impossible", "0", "0"},
		{"Impossible", "Impossible", "123", "1234", "24"},
		{"Impossible", "Impossible", "13", "134", "4"},
		{"Impossible", "Impossible", "23", "234", "23"},
		{"Impossible", "Impossible", "12", "124", "12"},
		{"Impossible", "Impossible", "1", "14", "1"},
		{"Impossible", "Impossible", "2", "24", "2"},
		{"Impossible", "Impossible", "0", "4", "0"},
		{"Impossible", "Impossible", "123", "23", "23"},
		{"Impossible", "Impossible", "13", "12", "12"},
		{"Impossible", "Impossible", "23", "1", "1"},
		{"Impossible", "Impossible", "12", "2", "2"},
		{"Impossible", "Impossible", "1", "0", "0"},
		{"Impossible", "Impossible", "2", "24", "12"},
		{"Impossible", "Impossible", "0", "4", "1"},
		{"Impossible", "Impossible", "23", "23", "2"},
		{"Impossible", "Impossible", "12", "12", "0"},
		{"Impossible", "Impossible", "1", "1", "1"},
		{"123", "Impossible", "2", "2", "2"},
		{"13", "Impossible", "0", "0", "0"},
		{"23", "Impossible", "12", "23", "23"},
		{"12", "Impossible", "1", "12", "12"},
		{"1", "Impossible", "2", "1", "1"},
		{"2", "Impossible", "0", "2", "2"},
		{"0", "Impossible", "1", "0", "0"},
		{"123", "Impossible", "2", "12", "12"},
		{"13", "Impossible", "0", "1", "1"},
		{"23", "Impossible", "23", "2", "2"},
		{"12", "Impossible", "12", "0", "0"},
		{"1", "Impossible", "1", "1", "1"},
		{"2", "Impossible", "2", "2", "2"},
		{"0", "Impossible", "0", "0", "0"},
		{"23", "Impossible", "2", "23", "23"},
		{"12", "0", "0", "12", "12"},
		{"1", "Impossible", "2", "1", "1"},
		{"2", "Impossible", "0", "2", "2"},
		{"0", "Impossible", "1", "0", "0"},
		{"12", "Impossible", "2", "12", "Impossible"},
		{"1", "0", "0", "1", "Impossible"},
		{"2", "Impossible", "23", "2", "Impossible"},
		{"0", "Impossible", "12", "0", "Impossible"},
		{"1", "Impossible", "1", "1", "Impossible"},
		{"2", "0", "2", "2", "Impossible"},
		{"0", "Impossible", "0", "0", "Impossible"},
		{"23", "Impossible", "Impossible", "Impossible", "Impossible"},
		{"12", "0", "Impossible", "Impossible", "Impossible"},
		{"1", "Impossible", "Impossible", "Impossible", "Impossible"},
		{"2", "Impossible", "Impossible", "Impossible", "Impossible"},
		{"0", "Impossible", "Impossible", "Impossible", "Impossible"},
	}

	index0, found0 := NOTES[note]
	index1, found1 := INSTRUMENTS[instrument]
	if !found0 || !found1 {
		return "Impossible"
	}
	return VALUES[index0][index1]
}
