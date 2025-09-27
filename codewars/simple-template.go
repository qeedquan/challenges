/*

Implement function createTemplate which takes string with tags wrapped in {{brackets}} as input and returns closure, which can fill string with data (flat object, where keys are tag names).

let personTmpl = createTemplate("{{name}} likes {{animalType}}");
personTmpl({ name: "John", animalType: "dogs" }); // John likes dogs

When key doesn't exist in the map, put there empty string.

*/

package main

import (
	"os"
	"text/template"
)

type Person struct {
	Name       string
	AnimalType string
}

func main() {
	p := Person{Name: "John", AnimalType: "Dogs"}
	t := template.New("")
	_, err := t.Parse("{{.Name}} likes {{.AnimalType}}\n")
	check(err)
	err = t.Execute(os.Stdout, &p)
	check(err)
}

func check(err error) {
	if err != nil {
		panic(err)
	}
}
