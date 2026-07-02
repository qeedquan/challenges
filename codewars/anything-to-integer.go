/*

Your task is to program a function which converts any input to an integer.

Do not perform rounding, the fractional part should simply be discarded.

If converting the input to an integer does not make sense (with an object, for instance), the function should return 0 (zero).

Also, Math.floor(), parseInt() and parseFloat() are disabled for your unconvenience.

Onegaishimasu!

*/

package main

import (
	"fmt"
	"math"
	"reflect"
	"strconv"
)

func main() {
	fmt.Println(toint([]string{}))
	fmt.Println(toint([]string{"34"}))
	fmt.Println(toint(294))
	fmt.Println(toint(24.563))
	fmt.Println(toint(math.NaN()))
}

func toint(x any) int {
	rv := reflect.ValueOf(x)
	kind := rv.Kind()
	switch {
	case rv.CanInt():
		return int(rv.Int())
	case rv.CanUint():
		return int(rv.Uint())
	case rv.CanFloat():
		v := rv.Float()
		if math.IsNaN(v) || math.IsInf(v, 0) {
			return 0
		}
		return int(v)
	case kind == reflect.String:
		v, err := strconv.Atoi(rv.String())
		if err == nil {
			return v
		}
	case kind == reflect.Array || kind == reflect.Slice:
		if rv.Len() > 0 {
			return toint(rv.Index(0).Interface())
		}
	}
	return 0
}
