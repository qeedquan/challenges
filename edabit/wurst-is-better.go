/*

Wurst is the best. Create a method that takes a string and replaces every mention of any type of sausage with the German word "Wurst," unless—of course—the sausage is already a type of German "Wurst" (i.e. "Bratwurst", see below), then leave the sausage name unchanged.

German Wursts	Convert to Wurst
Bratwurst	Kielbasa
Kochwurst	Chorizo
Leberwurst	Moronga
Mettwurst	Salami
Rostbratwurst	Sausage
~	Andouille
~	Naem
~	Merguez
~	Gurka
~	Snorkers
~	Pepperoni
Rules
Replace sausages from the "Convert to Wurst" column with "Wurst".
Do not replace any German sausage with the word "Wurst".
The word "Wurst" must be title case.
Examples
wurstIsBetter("I like chorizos, but not sausages") ➞ "I like Wursts, but not Wursts"

wurstIsBetter("sich die Wurst vom Brot nehmen lassen") ➞ "sich die Wurst vom Brot nehmen lassen"

wurstIsBetter("Bratwurst and Rostbratwurst are sausages") ➞ "Bratwurst and Rostbratwurst are Wursts"

Notes
All German sausage names contain the word "wurst".

*/

package main

import "strings"

func main() {
	assert("Wurst fests are like Wurst fests" == wurst("Sausage fests are like salami fests"))
	assert("Add the Wurst and the reserved potatoes and stir through" == wurst("Add the kielbasa and the reserved potatoes and stir through"))
	assert("Wurst sandwiches, Wurst and cheese, Wurst on crackers— I couldn't get enough of the salty, spicy Wurst" == wurst("Salami sandwiches, salami and cheese, salami on crackers— I couldn't get enough of the salty, spicy sausage"))
	assert("sich die Wurst vom Brot nehmen lassen" == wurst("sich die Wurst vom Brot nehmen lassen"))
	assert("Bratwurst and Rostbratwurst is a Wurst made from finely minced pork and beef and usually grilled and served with sweet German mustard and a piece of bread or hard roll. It can be sliced and made into Currywurst by slathering it in a catchup-curry sauce." == wurst("Bratwurst and Rostbratwurst is a sausage made from finely minced pork and beef and usually grilled and served with sweet German mustard and a piece of bread or hard roll. It can be sliced and made into Currywurst by slathering it in a catchup-curry sauce."))
	assert("Il n’arrête pas de faire l’Wurst" == wurst("Il n’arrête pas de faire l’andouille"))
	assert("Wurst is a common way of preserving pork meat in several Southeast Asian countries, including Thailand, Laos, Cambodia and Vietnam" == wurst("Naem is a common way of preserving pork meat in several Southeast Asian countries, including Thailand, Laos, Cambodia and Vietnam"))
	assert("The chipper group over at Orangatang recently dropped another wheel sensation; the Wurst" == wurst("The chipper group over at Orangatang recently dropped another wheel sensation; the Moronga"))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wurst(s string) string {
	tab := []string{
		"Kielbasa", "Chorizo", "Chorizo", "Moronga",
		"Salami", "Sausage", "Andouille", "Naem",
		"Merguez", "Gurka", "Snorkers", "Pepperoni",
	}

	for _, t := range tab {
		s = strings.Replace(s, t, "Wurst", -1)
		s = strings.Replace(s, strings.ToLower(t), "Wurst", -1)
	}
	return s
}
