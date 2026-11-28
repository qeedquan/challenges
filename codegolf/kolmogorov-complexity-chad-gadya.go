/*

NOTE: It is not clear how answers to the question of compressing a long text, without cumulative properties are relevant to golfing a short cumulative strong, any more than general Lempel Ziv techniques are relevant to code-golfing. Take note that the complexity of 99 bottles of beer is not O(Sqrt(n))

Knuth suggested the notion of theoretical complexity of songs (Knuth, Donald E. "The complexity of songs." Communications of the ACM 27.4 (1984): 344-346.‏), noting that most cumulative songs are O(sqrt(n)).

Cumulative songs never showed up in PPCG. The challenge this time is Chad Gadya, a famous cumulative song in Aramaic and Hebrew, sung in cumulation of the seder. The lyrics can be found, e.g., here (blue text). (There are slight variations, so use this one, copied below).

To state the obvious, Chad Gadya belongs in the complexity class of the famous "Läuschen und Flöhchen" tale by the Grimm brothers, and some other more or less famous English songs, i.e., O(sqrt n).

The challenge is to write a program, in any programming language, that produces the song, each verse in its own line. The program takes no input, and cannot cheat by using, e.g., wget. A greater challenge is to make the solution so small that it can fit in a twitter message. (I bet no one here would be able to meet this challenge)

A short such program could be useful for twitter/sms holiday greetings. Please minimize the number of bytes (not characters). Output should be in UTF8.

Why is this interesting?

Knuth paper on the the complexity of cumulative songs
Song is very short; standard tricks would not help.
Space savings in Niqqud is an extra challenge.
Repetitions are not only due to the cumulative nature of the song.
The twitter objective seems impossible.
The song itself is quite short, much shorter than other songs that have been posted here. Compression of short text is more challenging than that of long text.
Output

חַד גַּדְיָא, חַד גַּדְיָא דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא שׁוּנְרָא, וְאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא כַלְבָּא, וְנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא חוּטְרָא, וְהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא נוּרָא, וְשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא מַיָּא, וְכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא תוֹרָא, וְשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא הַשּׁוֹחֵט, וְשָׁחַט לְתוֹרָא, דְּשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא מַלְאַךְ הַמָּוֶת, וְשָׁחַט לְשׁוֹחֵט, דְּשָׁחַט לְתוֹרָא, דְּשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא הַקָּדוֹשׁ בָּרוּךְ הוּא, וְשָׁחַט לְמַלְאַךְ הַמָּוֶת, דְּשָׁחַט לְשׁוֹחֵט, דְּשָׁחַט לְתוֹרָא, דְּשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
If you find it hard to deal with Hebrew and Aramaic (tough luck...), try first getting your hands dirty with Läuschen und Flöhchen, and then proceed to the real challenge.

A related, but different question is that of "99 Bottles of Beer". If you care about complexity, you would notice that the theoretical complexity of bottles of beers is different from that of the two farthing kid.

*/

package main

import "fmt"

func main() {
	fmt.Println(LYRICS)
}

const LYRICS = `
חַד גַּדְיָא, חַד גַּדְיָא דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא שׁוּנְרָא, וְאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא כַלְבָּא, וְנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא חוּטְרָא, וְהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא נוּרָא, וְשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא מַיָּא, וְכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא תוֹרָא, וְשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא הַשּׁוֹחֵט, וְשָׁחַט לְתוֹרָא, דְּשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא מַלְאַךְ הַמָּוֶת, וְשָׁחַט לְשׁוֹחֵט, דְּשָׁחַט לְתוֹרָא, דְּשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא
וַאֲתָא הַקָּדוֹשׁ בָּרוּךְ הוּא, וְשָׁחַט לְמַלְאַךְ הַמָּוֶת, דְּשָׁחַט לְשׁוֹחֵט, דְּשָׁחַט לְתוֹרָא, דְּשָׁתָה לְמַיָּא, דְּכָבָה לְנוּרָא, דְּשָׂרַף לְחוּטְרָא, דְּהִכָּה לְכַלְבָּא, דְּנָשַׁךְ לְשׁוּנְרָא, דְּאָכְלָה לְגַדְיָא, דִּזְבַן אַבָּא בִּתְרֵי זוּזֵי. חַד גַּדְיָא, חַד גַּדְיָא 
`
