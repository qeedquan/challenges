/*

When a warrior wants to talk with another one about peace or war he uses a smartphone. In one distinct country warriors who spent all time in training kata not always have enough money. So if they call some number they want to know which operator serves this number.

Write a function which accepts number and return name of operator or string "no info", if operator can't be defined. number always looks like 8yyyxxxxxxx, where yyy corresponds to operator.

Here is short list of operators:

039 xxx xx xx - Golden Telecom
050 xxx xx xx - MTS
063 xxx xx xx - Life:)
066 xxx xx xx - MTS
067 xxx xx xx - Kyivstar
068 xxx xx xx - Beeline
093 xxx xx xx - Life:)
095 xxx xx xx - MTS
096 xxx xx xx - Kyivstar
097 xxx xx xx - Kyivstar
098 xxx xx xx - Kyivstar
099 xxx xx xx - MTS Test [Just return "MTS"]

*/

package main

func main() {
	assert(detect("80931551119") == "Life:)")
	assert(detect("8011155117711") == "no info")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func detect(number string) string {
	database := map[string]string{
		"039": "Golden Telecom",
		"050": "MTS",
		"063": "Life:)",
		"066": "MTS",
		"067": "Kyivstar",
		"068": "Beeline",
		"093": "Life:)",
		"095": "MTS",
		"096": "Kyivstar",
		"097": "Kyivstar",
		"098": "Kyivstar",
		"099": "MTS",
	}

	if len(number) < 4 || number[0] != '8' {
		return "no info"
	}

	value := database[number[1:4]]
	if value == "" {
		value = "no info"
	}
	return value
}
