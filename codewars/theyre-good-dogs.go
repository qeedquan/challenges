/*

Description:
At 'We Rate Dogs', we try our best to give dogs accurate ratings, which will always be above 10/10. Because they're good dogs. Over the weekend Bront has come in and hacked our system, lowering the ratings of dogs to below 10/10. Please help to fix Brant's bad system and give the dogs their original ratings. They're good dogs Brent.

Task:
The function weRateDogs(str, rating) takes a string and an integer as the inputs. Within the string is an incorrect rating x/y.

You will need to change the incorrect rating x/y to the correct rating rating/10. The given string may contain numbers and letters, but no special characters other than /.

For example:
if you are given the following string:
'This is Max99. She has one ear that is always s1ightly higher than the other 4/10 wonky af'
And the following rating: 11 return: 'This is Max99. She has one ear that is always s1ightly heigher than the other 11/10 wonky af'

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	fmt.Println(ratedogs(`This is Max99. She has one ear that is always s1ightly higher than the other 4/10 wonky af`, 11))
	fmt.Println(ratedogs(`1/2 3/4 5/6 7/8 9/10 11/12aabcc`, 33))
}

func ratedogs(input string, rating int) string {
	re := regexp.MustCompile(`\d*\/\d*`)
	return re.ReplaceAllString(input, fmt.Sprintf("%d/10", rating))
}
