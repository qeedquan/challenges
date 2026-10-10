/*

According to the creation myths of the Abrahamic religions, Adam and Eve were the first Humans to wander the Earth.

You have to do God's job.
The creation method must return an array of length 2 containing objects (representing Adam and Eve).
The first object in the array should be an instance of the class Man.
The second should be an instance of the class Woman.
Both objects have to be subclasses of Human.
Your job is to implement the Human, Man and Woman classes.

*/

package main

import "fmt"

func main() {
	god := God{}
	humans := god.Create()
	for _, human := range humans {
		fmt.Printf("%T\n", human)
	}
}

type Human interface{}
type God struct{}
type Man struct{}
type Woman struct{}

func (g *God) Create() [2]Human {
	return [2]Human{Man{}, Woman{}}
}
