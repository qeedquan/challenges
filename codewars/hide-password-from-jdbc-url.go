/*

We have to create a function that receives a connection string with password included and you have to mask the password i.e. change password by asterisks.

Preconditions:

non empty valid url
password always next to string section password=
assume password will not contain ampersand sign for sake of simplicity
to make it more real it has non ASCII characters
"password=" and "user" will occur only once
empty passwords are not validated but best solutions take empty passwords into account

Example:

input
jdbc:mysql://sdasdasdasd:szdasdasd:dfsdfsdfsdf/sdfsdfsdf?user=root&password=12345

output
jdbc:mysql://sdasdasdasd:szdasdasd:dfsdfsdfsdf/sdfsdfsdf?user=root&password=*****

Extra readings:

https://alvinalexander.com/java/jdbc-connection-string-mysql-postgresql-sqlserver

*/

package main

import (
	"strings"
)

func main() {
	assert(hide("jdbc:mysql://sdasdasdasd:szdasdasd:dfsdfsdfsdf/sdfsdfsdf?user=root&password=12345") == "jdbc:mysql://sdasdasdasd:szdasdasd:dfsdfsdfsdf/sdfsdfsdf?user=root&password=*****")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hide(s string) string {
	i := strings.Index(s, "password=")
	if i < 0 {
		return s
	}

	b := []byte(s)
	for i += 9; i < len(b) && b[i] != '&'; i++ {
		b[i] = '*'
	}

	return string(b)
}
