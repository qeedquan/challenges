/*

This challenge will be based on an R language trivia: every release is named and it's a reference to Peanuts comic strips (see here and here).

Task
Given a release name, output its number.

For reference, use the below list:

Great Pumpkin            2.14.0
December Snowflakes      2.14.1
Gift-Getting Season      2.14.2
Easter Beagle            2.15.0
Roasted Marshmallows     2.15.1
Trick or Treat           2.15.2
Security Blanket         2.15.3
Masked Marvel            3.0.0
Good Sport               3.0.1
Frisbee Sailing          3.0.2
Warm Puppy               3.0.3
Spring Dance             3.1.0
Sock it to Me            3.1.1
Pumpkin Helmet           3.1.2
Smooth Sidewalk          3.1.3
Full of Ingredients      3.2.0
World-Famous Astronaut   3.2.1
Fire Safety              3.2.2
Wooden Christmas-Tree    3.2.3
Very Secure Dishes       3.2.4
Very, Very Secure Dishes 3.2.5
Supposedly Educational   3.3.0
Bug in Your Hair         3.3.1
Sincere Pumpkin Patch    3.3.2
Another Canoe            3.3.3
You Stupid Darkness      3.4.0
Single Candle            3.4.1
Short Summer             3.4.2
Kite-Eating Tree         3.4.3
Someone to Lean On       3.4.4
Joy in Playing           3.5.0
Feather Spray            3.5.1
Eggshell Igloo           3.5.2
Great Truth              3.5.3
Planting of a Tree       3.6.0
Action of the Toes       3.6.1
Dark and Stormy Night    3.6.2
Holding the Windsock     3.6.3
Arbor Day                4.0.0
See Things Now           4.0.1
Taking Off Again         4.0.2
Bunny-Wunnies Freak Out  4.0.3
Lost Library Book        4.0.4
Shake and Throw          4.0.5
Camp Pontanezen          4.1.0
Kick Things              4.1.1
Bird Hippie              4.1.2
One Push-Up              4.1.3
Vigorous Calisthenics    4.2.0

Rules
You may take input and output in any reasonable format (for output this includes a dot delimited string (as above), a string with other delimiter, a 3-element list etc.).
This is code-golf - usual rules apply.


*/

package main

import "fmt"

func main() {
	fmt.Println(rel2ver("Feather Spray"))
	fmt.Println(rel2ver("Wooden Christmas-Tree"))
}

func rel2ver(s string) string {
	tab := map[string]string{
		"Great Pumpkin":            "2.14.0",
		"December Snowflakes":      "2.14.1",
		"Gift-Getting Season":      "2.14.2",
		"Easter Beagle":            "2.15.0",
		"Roasted Marshmallows":     "2.15.1",
		"Trick or Treat":           "2.15.2",
		"Security Blanket":         "2.15.3",
		"Masked Marvel":            "3.0.0",
		"Good Sport":               "3.0.1",
		"Frisbee Sailing":          "3.0.2",
		"Warm Puppy":               "3.0.3",
		"Spring Dance":             "3.1.0",
		"Sock it to Me":            "3.1.1",
		"Pumpkin Helmet":           "3.1.2",
		"Smooth Sidewalk":          "3.1.3",
		"Full of Ingredients":      "3.2.0",
		"World-Famous Astronaut":   "3.2.1",
		"Fire Safety":              "3.2.2",
		"Wooden Christmas-Tree":    "3.2.3",
		"Very Secure Dishes":       "3.2.4",
		"Very, Very Secure Dishes": "3.2.5",
		"Supposedly Educational":   "3.3.0",
		"Bug in Your Hair":         "3.3.1",
		"Sincere Pumpkin Patch":    "3.3.2",
		"Another Canoe":            "3.3.3",
		"You Stupid Darkness":      "3.4.0",
		"Single Candle":            "3.4.1",
		"Short Summer":             "3.4.2",
		"Kite-Eating Tree":         "3.4.3",
		"Someone to Lean On":       "3.4.4",
		"Joy in Playing":           "3.5.0",
		"Feather Spray":            "3.5.1",
		"Eggshell Igloo":           "3.5.2",
		"Great Truth":              "3.5.3",
		"Planting of a Tree":       "3.6.0",
		"Action of the Toes":       "3.6.1",
		"Dark and Stormy Night":    "3.6.2",
		"Holding the Windsock":     "3.6.3",
		"Arbor Day":                "4.0.0",
		"See Things Now":           "4.0.1",
		"Taking Off Again":         "4.0.2",
		"Bunny-Wunnies Freak Out":  "4.0.3",
		"Lost Library Book":        "4.0.4",
		"Shake and Throw":          "4.0.5",
		"Camp Pontanezen":          "4.1.0",
		"Kick Things":              "4.1.1",
		"Bird Hippie":              "4.1.2",
		"One Push-Up":              "4.1.3",
		"Vigorous Calisthenics":    "4.2.0",
	}
	return tab[s]
}
