/*

Given one of the following as input:

AK,AR,AS,AZ,CA,CT,DC,FL,GA,IL,IN,IA,KS,KY,LA,MD,MI,MN,MS,NV,NH,NJ,NM,NY,NC,ND,MP,OH,OK,OR,PA,PR,RI,SC,TN,TX,UT,VT,VA,WA,WI
(with quotes)

"AK","AR","AS","AZ","CA","CT","DC","FL","GA","IL","IN","IA","KS","KY","LA","MD","MI","MN","MS","NV","NH","NJ","NM","NY","NC","ND","MP","OH","OK","OR","PA","PR","RI","SC","TN","TX","UT","VT","VA","WA","WI"

Generate and output a (uniformly) random license plate of the format matching the input. If there are multiple (comma separated) formats, use a (uniformly) random format:

AK, IA, MS, MP, VT: AAA 000
AS: 0000
AZ, GA, WA: AAA0000
AR, KS, KY, LA, ND, OR: 000 AAA
CA: 0AAA000
CT: AA-00000
DC: AA-0000
FL: AAA A00
IL: AA 00000
IN: 000A,000AA,000AAA,AAA000
MD: 0AA0000
MI: AAA 0000,0AA A00,AAA 000
MN: 000-AAA
NV: 00A-000
NH: 000 0000
NJ: A00-AAA
NM: 000-AAA,AAA-000
NY, NC, PA, TX, VA, WI: AAA-0000
OH: AAA 0000
OK: 000AAA
PR: AAA-000
RI: 000-000
SC: AAA 000,000 0AA
TN: A00-00A
UT: A00 0AA

Where A means a random character in the uppercase alphabet minus IOQ and 0 means a random single digit number (0 to 9).

All information from Wikipedia. These (states) were all of the ones that I understood and that didn't have wonky rules.

This is code-golf, so shortest answer in bytes wins!

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
)

func main() {
	states := []string{
		"AK", "AR", "AS", "AZ", "CA", "CT", "DC", "FL", "GA",
		"IL", "IN", "IA", "KS", "KY", "LA", "MD", "MI", "MN",
		"MS", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "MP",
		"OH", "OK", "OR", "PA", "PR", "RI", "SC", "TN", "TX",
		"UT", "VT", "VA", "WA", "WI",
	}

	for _, state := range states {
		fmt.Printf("%q: %q\n", state, plate(state))
	}
}

func plate(state string) string {
	const (
		alphabet = "ABCDEFGHJKLMNPRSTUVWXYZ"
		digit    = "0123456789"
	)

	formats := map[string]string{
		"AK": "AAA 000",
		"IA": "AAA 000",
		"MS": "AAA 000",
		"MP": "AAA 000",
		"VT": "AAA 000",
		"AS": "0000",
		"AZ": "AAA0000",
		"GA": "AAA0000",
		"WA": "AAA0000",
		"AR": "000 AAA",
		"KS": "000 AAA",
		"KY": "000 AAA",
		"LA": "000 AAA",
		"ND": "000 AAA",
		"OR": "000 AAA",
		"CA": "0AAA000",
		"CT": "AA-00000",
		"DC": "AA-0000",
		"FL": "AAA A00",
		"IL": "AA 00000",
		"IN": "000A,000AA,000AAA,AAA000",
		"MD": "0AA0000",
		"MI": "AAA 0000,0AA A00,AAA 000",
		"MN": "000-AAA",
		"NV": "00A-000",
		"NH": "000 0000",
		"NJ": "A00-AAA",
		"NM": "000-AAA,AAA-000",
		"NY": "AAA-0000",
		"NC": "AAA-0000",
		"PA": "AAA-0000",
		"TX": "AAA-0000",
		"VA": "AAA-0000",
		"WI": "AAA-0000",
		"OH": "AAA 0000",
		"OK": "000AAA",
		"PR": "AAA-000",
		"RI": "000-000",
		"SC": "AAA 000,000 0AA",
		"TN": "A00-00A",
		"UT": "A00 0AA",
	}

	output := new(bytes.Buffer)
	for _, symbol := range formats[state] {
		switch symbol {
		case 'A':
			index := rand.Intn(len(alphabet))
			output.WriteByte(alphabet[index])

		case '0':
			index := rand.Intn(len(digit))
			output.WriteByte(digit[index])

		default:
			output.WriteRune(symbol)
		}
	}
	return output.String()
}
