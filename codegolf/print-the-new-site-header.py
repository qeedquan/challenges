#!/usr/bin/env python3

"""

The new site header has some bits of source code from various questions as the background. Here are the first 3 lines:

--<-<<+[+[<+>--->->->-<<<]>]<<--.<++++++.<<-..<<.<+.>>.>>.<<<.+++.>>.>>-.<<<+. Hello, World! IT'S SHOWTIME TALK TO THE HAND "Hello, World!" YOU HAVE BEEN TERMINATED "9!dlroW ,olleH"ck,@ 72a101a+7aa+3a44a32a87a111a+3a-6a-8a33a Take Circle Line to Paddington Take Circle Line to Wood Lane Take Circle L
alert'Hello, World!' target byteorder little;import puts;export main;section"data"{s:bits8[]"Hello, World!\0";}foreign"C"main(){foreign"C"puts("address"s);foreign"C"return(0);} aeeeaeeewueuueweeueeuewwaaaweaaewaeaawueweeeaeeewaaawueeueweeaweeeueuw H class H{public static void main(String[]a){System.
World!");}}+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+. "Hello, World!"o| :after{content:"Hello, World!" H;e;P1;@/;W;o;/l;;o;Q/r;l;d;2;P0 ('&%:9]!~}|z2Vxwv-,POqponl$Hjihf|B@@>,=<M:9&7Y#VV2TSn.Oe*c;(I&%$#"mCBA?zxxv*Pb8`qo42mZF.{Iy*@dD'<;_?!\}}|z2VxSSQ main(){puts("Hello, W

However, a few microseconds of extra load time can cause the user to click away from the site, so the page header download really should be optimized as much as possible.

Write a program that takes no input and produces the (first 3 lines of) text from the new header as output.

    Trailing newline is optional
    Must include the line breaks from the original header
    code-golf, so shortest code wins!

"""

CODE = """--<-<<+[+[<+>--->->->-<<<]>]<<--.<++++++.<<-..<<.<+.>>.>>.<<<.+++.>>.>>-.<<<+. Hello, World! IT'S SHOWTIME TALK TO THE HAND "Hello, World!" YOU HAVE BEEN TERMINATED "9!dlroW ,olleH"ck,@ 72a101a+7aa+3a44a32a87a111a+3a-6a-8a33a Take Circle Line to Paddington Take Circle Line to Wood Lane Take Circle L
alert'Hello, World!' target byteorder little;import puts;export main;section"data"{s:bits8[]"Hello, World!\0";}foreign"C"main(){foreign"C"puts("address"s);foreign"C"return(0);} aeeeaeeewueuueweeueeuewwaaaweaaewaeaawueweeeaeeewaaawueeueweeaweeeueuw H class H{public static void main(String[]a){System.
World!");}}+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+. "Hello, World!"o| :after{content:"Hello, World!" H;e;P1;@/;W;o;/l;;o;Q/r;l;d;2;P0 ('&%:9]!~}|z2Vxwv-,POqponl$Hjihf|B@@>,=<M:9&7Y#VV2TSn.Oe*c;(I&%$#"mCBA?zxxv*Pb8`qo42mZF.{Iy*@dD'<;_?!\}}|z2VxSSQ main(){puts("Hello, W"""

def main():
    print(CODE)

main()
