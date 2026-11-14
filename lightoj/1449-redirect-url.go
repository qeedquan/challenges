/*

Welcome to the new version of LightOJ with new UI and features.

When we deployed the new version, we wanted to add SSL certificates to the domain to make the website safer and more secure. After adding the SSL certificate, LightOJ website's URL became https://lightoj.com.

So from now on, when user hits this url http://lightoj.com we redirect them to https://lightoj.com.

We solved this problem on our server configuration, what if you had to write a code to solve the similar problem? And what if your code should support other domain names too.

Input
Input starts with an integer T (≤ 20), denoting the number of test cases.

Each case will contain a valid URL and will start with either http:// or https:// protocol name. Each URL length will be between 10 to 100 characters and will only contain lowercase english characters (a-z), :, . and /.

Output
For each case, print the case number and the redirected url, if user don't need to be redirected then print the original input url.

Sample
Input	Output
4
http://lightoj.com
https://lightoj.com
http://example.com
https://example.com

Case 1: https://lightoj.com
Case 2: https://lightoj.com
Case 3: https://example.com
Case 4: https://example.com

*/

package main

import "strings"

func main() {
	assert(redirect("http://lightoj.com") == "https://lightoj.com")
	assert(redirect("https://lightoj.com") == "https://lightoj.com")
	assert(redirect("http://example.com") == "https://example.com")
	assert(redirect("https://example.com") == "https://example.com")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func redirect(url string) string {
	if strings.HasPrefix(url, "http://") {
		url = "https://" + url[7:]
	}
	return url
}
