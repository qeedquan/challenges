#!/bin/bash

cat << EOF > /dev/null

For example, in traditional web hexadecimal, a certain base-16 number represents an RGB value. For example, 45A19C equals (69,161,156) in RGB.

You'll be converting from that number to RGB value, however, instead you'll be given that number in base-10 rather than base 16.

So in the example used above, 45A19C would equal 4563356 in base-10. Thus 4563356 converted to RGB would equal (69,161,156).

So assume the integer given is previously stored in variable n and is between 0 and 16777215. Take number n and convert it to RGB values between 0 and 255. Return or save in a variable the three values as a list [r,g,b].

An RGB to RGB int can be found here. This link converts the opposite of what your trying to do.

Shortest code wins.

If clarification is needed, please ask so I can fix my question to be more helpful.

EOF

dec2rgb() {
	b=$(($1 & 0xff))
	g=$((($1>>8) & 0xff))
	r=$((($1>>16) & 0xff))
	printf "[%d, %d, %d]\n" $r $g $b
}

dec2rgb 4563356
dec2rgb 16777215
dec2rgb 16711680
dec2rgb 65280
dec2rgb 255
