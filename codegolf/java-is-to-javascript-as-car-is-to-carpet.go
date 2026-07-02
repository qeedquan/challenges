/*

Title stolen inspired by Greg Hewgill's answer to What's the difference between JavaScript and Java?

Introduction
Java and JavaScript are commonly used languages among programmers, and are currently the most popular tags on Stack Overflow. Yet aside from similar names, the two have almost nothing in common.

In honor of one of programming's most infamous debates, and inspired by my recent frustrations in tag searching, I propose the following:

Challenge
Write a program which takes in a string as input. Return car if the string begins with "Java" and does not include "JavaScript". Otherwise, return carpet.

Example Input and Output
car:
java
javafx
javabeans
java-stream
java-script
java-8
java.util.scanner
java-avascript
JAVA-SCRIPTING
javacarpet
carpet:
javascript
javascript-events
facebook-javascript-sdk
javajavascript
jquery
python
rx-java
java-api-for-javascript
not-java
JAVASCRIPTING
Notes
Input matching should be case insensitive
Only possibilities for output should be car or carpet
Imaginary bonus points if your answer uses Java, JavaScript, or Regex
Alternate Title: Java is to JavaScript as ham is to hamster


*/

package main

import "strings"

func main() {
	assert(identify("java") == "car")
	assert(identify("javafx") == "car")
	assert(identify("javabeans") == "car")
	assert(identify("java-stream") == "car")
	assert(identify("java-script") == "car")
	assert(identify("java-8") == "car")
	assert(identify("java.util.scanner") == "car")
	assert(identify("java-avascript") == "car")
	assert(identify("JAVA-SCRIPTING") == "car")
	assert(identify("javacarpet") == "car")

	assert(identify("javascript") == "carpet")
	assert(identify("javascript-events") == "carpet")
	assert(identify("facebook-javascript-sdk") == "carpet")
	assert(identify("javajavascript") == "carpet")
	assert(identify("jquery") == "carpet")
	assert(identify("python") == "carpet")
	assert(identify("rx-java") == "carpet")
	assert(identify("java-api-for-javascript") == "carpet")
	assert(identify("not-java") == "carpet")
	assert(identify("JAVASCRIPTING") == "carpet")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func identify(s string) string {
	switch s = strings.ToLower(s); {
	case !strings.HasPrefix(s, "java"):
		fallthrough
	case strings.Index(s, "javascript") >= 0:
		return "carpet"
	}
	return "car"
}
