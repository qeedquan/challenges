/*

--- Day 4: Security Through Obscurity ---
Finally, you come across an information kiosk with a list of rooms. Of course, the list is encrypted and full of decoy data, but the instructions to decode the list are barely hidden nearby. Better remove the decoy data first.

Each room consists of an encrypted name (lowercase letters separated by dashes) followed by a dash, a sector ID, and a checksum in square brackets.

A room is real (not a decoy) if the checksum is the five most common letters in the encrypted name, in order, with ties broken by alphabetization. For example:

aaaaa-bbb-z-y-x-123[abxyz] is a real room because the most common letters are a (5), b (3), and then a tie between x, y, and z, which are listed alphabetically.
a-b-c-d-e-f-g-h-987[abcde] is a real room because although the letters are all tied (1 of each), the first five are listed alphabetically.
not-a-real-room-404[oarel] is a real room.
totally-real-room-200[decoy] is not.
Of the real rooms from the list above, the sum of their sector IDs is 1514.

What is the sum of the sector IDs of the real rooms?

--- Part Two ---
With all the decoy data out of the way, it's time to decrypt this list and get moving.

The room names are encrypted by a state-of-the-art shift cipher, which is nearly unbreakable without the right software. However, the information kiosk designers at Easter Bunny HQ were not expecting to deal with a master cryptographer like yourself.

To decrypt a room name, rotate each letter forward through the alphabet a number of times equal to the room's sector ID. A becomes B, B becomes C, Z becomes A, and so on. Dashes become spaces.

For example, the real name for qzmt-zixmtkozy-ivhz-343 is very encrypted name.

What is the sector ID of the room where North Pole objects are stored?

*/

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"log"
	"os"
	"regexp"
	"sort"
	"strconv"
	"strings"
)

func main() {
	value1, value2, err := solve("4.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(value1)
	fmt.Println(value2)
}

func solve(name string) (value1, value2 int, err error) {
	file, err := os.Open(name)
	if err != nil {
		return
	}
	defer file.Close()

	regex := regexp.MustCompile(`([a-z\-]*)(\d+)(\[.*\])`)
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		values := regex.FindAllStringSubmatch(line, -1)
		if len(values) < 1 || len(values[0]) != 4 {
			continue
		}

		name := values[0][1]
		counts := frequency(name)
		sectorid, _ := strconv.Atoi(values[0][2])
		checksum := values[0][3]
		checksum = checksum[1 : len(checksum)-1]

		if compute(counts) == checksum {
			value1 += sectorid
		}

		if decrypt(name, sectorid) == "northpole object storage" {
			value2 = sectorid
		}
	}
	return
}

func frequency(input string) map[rune]int {
	counts := make(map[rune]int)
	for _, symbol := range input {
		if symbol != '-' {
			counts[symbol] += 1
		}
	}
	return counts
}

func compute(counts map[rune]int) string {
	table := [][2]int{}
	for key, value := range counts {
		table = append(table, [2]int{int(key), value})
	}

	sort.Slice(table, func(i, j int) bool {
		if table[i][1] == table[j][1] {
			return table[i][0] < table[j][0]
		}
		return table[i][1] > table[j][1]
	})

	output := new(bytes.Buffer)
	for i := range table {
		fmt.Fprintf(output, "%c", table[i][0])
	}

	result := output.String()
	if len(result) > 5 {
		result = result[:5]
	}
	return result
}

func decrypt(name string, sectorid int) string {
	output := new(bytes.Buffer)
	for _, symbol := range name {
		if symbol == '-' {
			fmt.Fprintf(output, " ")
		} else {
			fmt.Fprintf(output, "%c", 'a'+(int(symbol)-'a'+sectorid)%26)
		}
	}
	result := output.String()
	result = strings.TrimSpace(result)
	return result
}
