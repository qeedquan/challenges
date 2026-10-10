/*

Create the function type which takes the argument val and returns val's type as a string. If possible, type should return additional information. Instead of a wall of text, here are code examples:

type(undefined) --> 'Undefined'
type(null) --> 'Null'
type(true) --> 'Boolean'
type(function(){}) --> 'Function'
type(Math.max) --> 'Function'
type('abc') --> 'String'
type({snap: "crackle"}) --> 'Object'

//Numbers should include additional information
type(1) --> 'Number Integer'
type(1.1) --> 'Number Float'
type(NaN) --> 'Number NaN'
type(-Infinity) --> 'Number Infinite'

//If a string is numeric-formatted:
type('123')
type('123.321')
type('0xF')
  --> All return 'String Numeric'

//For constructed objects, return the name of the constructor
type(/abc/) --> 'RegExp'
type([1,2,3]) --> 'Array'
function Custom(){}
type(new Custom()) --> 'Custom'

Related reading: MDN's page for Object.prototype.toString and Object.prototype.constructor.

*/

package main

import (
	"bytes"
	"image"
	"reflect"
)

func main() {
	assert(kind(nil) == "nil")
	assert(kind(3) == "int")
	assert(kind(uint8(0xf)) == "uint8")
	assert(kind(float32(3.525)) == "float32")
	assert(kind(3.525) == "float64")
	assert(kind("xzy") == "string")
	assert(kind('F') == "int32")

	assert(kind(map[string]bool{}) == "map[string]bool")
	assert(kind(image.Pt(2, 3)) == "image.Point")
	assert(kind(new(bytes.Buffer)) == "*bytes.Buffer")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func kind(x any) string {
	if x == nil {
		return "nil"
	}

	r := reflect.TypeOf(x)
	return r.String()
}
