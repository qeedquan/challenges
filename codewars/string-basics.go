/*

Hey CodeWarrior,

we've got a lot to code today!

I hope you know the basic string manipulation methods, because this kata will be all about them.

Here we go...

Background
We've got a very long string, containing a bunch of User IDs. This string is a listing, which seperates each user ID with a comma and a whitespace ("' "). Sometimes there are more than only one whitespace. Keep this in mind! Futhermore, some user Ids are written only in lowercase, others are mixed lowercase and uppercase characters. Each user ID starts with the same 3 letter "uid", e.g. "uid345edj". But that's not all! Some stupid student edited the string and added some hashtags (#). User IDs containing hashtags are invalid, so these hashtags should be removed!

Task
Remove all hashtags
Remove the leading "uid" from each user ID
Return an array of strings --> split the string
Each user ID should be written in only lowercase characters
Remove leading and trailing whitespaces

Note
Even if this kata can be solved by using Regex, please try to find a solution by using only the built-in String methods.

*/

package main

import (
	"fmt"
	"reflect"
	"strings"
)

func main() {
	test("uid12345", []string{"12345"})
	test("   uidabc  ", []string{"abc"})
	test("#uidswagger", []string{"swagger"})
	test("uidone, uidtwo", []string{"one", "two"})
	test("uidCAPSLOCK", []string{"capslock"})

	test("uid##doublehashtag", []string{"doublehashtag"})
	test("  uidin name whitespace", []string{"in name whitespace"})
	test("uidMultipleuid", []string{"multipleuid"})
	test("uid12 ab, uid#, uidMiXeDcHaRs", []string{"12 ab", "", "mixedchars"})
	test(" uidT#e#S#t# ", []string{"test"})
}

func test(listing string, expected []string) {
	users := userids(listing)
	fmt.Println(users)
	assert(reflect.DeepEqual(users, expected))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func userids(listing string) []string {
	var users []string
	for _, user := range strings.Split(listing, ", ") {
		user = strings.Replace(user, "#", "", -1)
		user = strings.ToLower(user)
		user = strings.TrimSpace(user)
		user = strings.TrimPrefix(user, "uid")
		user = strings.TrimSpace(user)
		users = append(users, user)
	}
	return users
}
