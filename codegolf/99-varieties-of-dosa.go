/*

99 Varieties of Dosa is a popular chain of roadside dosa stalls across South India. This is inspired by a combination of this chain and the classic CodeGolf challenge "99 Bottles of Beer".

Recreate the variant of the menu of the popular '99 Varieties of Dosa' listed below.

(Note: Despite the name, the list contains 103 varieties and not exactly 99)

The desired output is the following list (in any order):

Sada Dosa
Cheese Sada Dosa
Paneer Sada Dosa
Paneer Cheese Sada Dosa
Schezwan Sada Dosa
Cheese Schezwan Sada Dosa
Paneer Schezwan Sada Dosa
Paneer Cheese Schezwan Sada Dosa
Onion Sada Dosa
Cheese Onion Sada Dosa
Paneer Onion Sada Dosa
Paneer Cheese Onion Sada Dosa
Chutney Dosa
Cheese Chutney Dosa
Paneer Chutney Dosa
Paneer Cheese Chutney Dosa
Tomato Onion Dosa
Cheese Tomato Onion Dosa
Paneer Tomato Onion Dosa
Paneer Cheese Tomato Onion Dosa
Schezwan Onion Dosa
Cheese Schezwan Onion Dosa
Paneer Schezwan Onion Dosa
Paneer Cheese Schezwan Onion Dosa
Jain Dosa
Jain Cheese Dosa
Jain Paneer Dosa
Jain Paneer Cheese Dosa
Masala Dosa
Cheese Masala Dosa
Paneer Masala Dosa
Paneer Cheese Masala Dosa
Onion Masala Dosa
Onion Paneer Masala Dosa
Cheese Onion Masala Dosa
Paneer Cheese Onion Masala Dosa
Schezwan Masala Dosa
Cheese Schezwan Masala Dosa
Paneer Schezwan Masala Dosa
Paneer Cheese Schezwan Masala Dosa
Mysore Masala Dosa
Paneer Mysore Masala Dosa
Cheese Mysore Masala Dosa
Paneer Cheese Mysore Masala Dosa
Paneer Cheese Schezwan Mysore Masala Dosa
Kerala Dosa
Kerala Cheese Dosa
Paneer Kerala Dosa
Paneer Cheese Kerala Dosa
Pav Bhaji Dosa
Pav Bhaji Cheese Dosa
Pav Bhaji Paneer Dosa
Pav Bhaji Cheese Paneer Dosa
Spring Vegetable Dosa
Spring Paneer Vegetable Dosa
Spring Cheese Vegetable Dosa
Spring Paneer Cheese Vegetable Dosa
Sweet Corn Dosa
Sweet Corn Cheese Dosa
Sweet Corn Paneer Dosa
Sweet Corn Paneer Cheese Dosa
Sweet Corn Schezwan Dosa
Sweet Corn Schezwan Paneer Dosa
Sweet Corn Schezwan Cheese Dosa
Sweet Corn Schezwan Paneer Cheese Dosa
Sweet Corn Mushroom Dosa
Sweet Corn Mushroom Paneer Dosa
Sweet Corn Mushroom Cheese Dosa
Sweet Corn Mushroom Paneer Cheese Dosa
Mushroom Dosa
Mushroom Cheese Dosa
Mushroom Paneer Dosa
Mushroom Paneer Cheese Dosa
Schezwan Mushroom Dosa
Schezwan Mushroom Paneer Dosa
Schezwan Mushroom Cheese Dosa
Schezwan Corn Mushroom Paneer Cheese Dosa
Paneer Chilli Dosa
Paneer Chilli Cheese Dosa
Mushroom Chilli Dosa
Mushroom Chilli Cheese Dosa
Mushroom Chilli Paneer Dosa
Mushroom Chilli Paneer Cheese Dosa
Sada Uttappam Dosa
Sada Uttappam Cheese Dosa
Sada Uttappam Paneer Dosa
Sada Uttappam Paneer Cheese Dosa
Onion Uttappam Dosa
Onion Uttappam Cheese Dosa
Onion Uttappam Paneer Dosa
Onion Uttappam Paneer Cheese Dosa
Masala Uttappam Dosa
Masala Uttappam Cheese Dosa
Masala Uttappam Paneer Dosa
Masala Uttappam Paneer Cheese Dosa
Mysore Uttappam Dosa
Mysore Uttappam Cheese Dosa
Mysore Uttappam Paneer Dosa
Mysore Uttappam Paneer Cheese Dosa
Mixed Uttappam Dosa
Mixed Uttappam Cheese Dosa
Mixed Uttappam Paneer Dosa
Mixed Uttappam Paneer Cheese Dosa

*/

package main

import "fmt"

func main() {
	fmt.Println(VARIETIES)
}

const VARIETIES = `Sada Dosa
Cheese Sada Dosa
Paneer Sada Dosa
Paneer Cheese Sada Dosa
Schezwan Sada Dosa
Cheese Schezwan Sada Dosa
Paneer Schezwan Sada Dosa
Paneer Cheese Schezwan Sada Dosa
Onion Sada Dosa
Cheese Onion Sada Dosa
Paneer Onion Sada Dosa
Paneer Cheese Onion Sada Dosa
Chutney Dosa
Cheese Chutney Dosa
Paneer Chutney Dosa
Paneer Cheese Chutney Dosa
Tomato Onion Dosa
Cheese Tomato Onion Dosa
Paneer Tomato Onion Dosa
Paneer Cheese Tomato Onion Dosa
Schezwan Onion Dosa
Cheese Schezwan Onion Dosa
Paneer Schezwan Onion Dosa
Paneer Cheese Schezwan Onion Dosa
Jain Dosa
Jain Cheese Dosa
Jain Paneer Dosa
Jain Paneer Cheese Dosa
Masala Dosa
Cheese Masala Dosa
Paneer Masala Dosa
Paneer Cheese Masala Dosa
Onion Masala Dosa
Onion Paneer Masala Dosa
Cheese Onion Masala Dosa
Paneer Cheese Onion Masala Dosa
Schezwan Masala Dosa
Cheese Schezwan Masala Dosa
Paneer Schezwan Masala Dosa
Paneer Cheese Schezwan Masala Dosa
Mysore Masala Dosa
Paneer Mysore Masala Dosa
Cheese Mysore Masala Dosa
Paneer Cheese Mysore Masala Dosa
Paneer Cheese Schezwan Mysore Masala Dosa
Kerala Dosa
Kerala Cheese Dosa
Paneer Kerala Dosa
Paneer Cheese Kerala Dosa
Pav Bhaji Dosa
Pav Bhaji Cheese Dosa
Pav Bhaji Paneer Dosa
Pav Bhaji Cheese Paneer Dosa
Spring Vegetable Dosa
Spring Paneer Vegetable Dosa
Spring Cheese Vegetable Dosa
Spring Paneer Cheese Vegetable Dosa
Sweet Corn Dosa
Sweet Corn Cheese Dosa
Sweet Corn Paneer Dosa
Sweet Corn Paneer Cheese Dosa
Sweet Corn Schezwan Dosa
Sweet Corn Schezwan Paneer Dosa
Sweet Corn Schezwan Cheese Dosa
Sweet Corn Schezwan Paneer Cheese Dosa
Sweet Corn Mushroom Dosa
Sweet Corn Mushroom Paneer Dosa
Sweet Corn Mushroom Cheese Dosa
Sweet Corn Mushroom Paneer Cheese Dosa
Mushroom Dosa
Mushroom Cheese Dosa
Mushroom Paneer Dosa
Mushroom Paneer Cheese Dosa
Schezwan Mushroom Dosa
Schezwan Mushroom Paneer Dosa
Schezwan Mushroom Cheese Dosa
Schezwan Corn Mushroom Paneer Cheese Dosa
Paneer Chilli Dosa
Paneer Chilli Cheese Dosa
Mushroom Chilli Dosa
Mushroom Chilli Cheese Dosa
Mushroom Chilli Paneer Dosa
Mushroom Chilli Paneer Cheese Dosa
Sada Uttappam Dosa
Sada Uttappam Cheese Dosa
Sada Uttappam Paneer Dosa
Sada Uttappam Paneer Cheese Dosa
Onion Uttappam Dosa
Onion Uttappam Cheese Dosa
Onion Uttappam Paneer Dosa
Onion Uttappam Paneer Cheese Dosa
Masala Uttappam Dosa
Masala Uttappam Cheese Dosa
Masala Uttappam Paneer Dosa
Masala Uttappam Paneer Cheese Dosa
Mysore Uttappam Dosa
Mysore Uttappam Cheese Dosa
Mysore Uttappam Paneer Dosa
Mysore Uttappam Paneer Cheese Dosa
Mixed Uttappam Dosa
Mixed Uttappam Cheese Dosa
Mixed Uttappam Paneer Dosa
Mixed Uttappam Paneer Cheese Dosa`
