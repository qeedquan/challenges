#!/usr/bin/env python3

r"""

True color (24-bit) at Wikipedia is described in pertinent part as

24 bits almost always uses 8 bits of each of R, G, B. As of 2018 24-bit color depth is used by virtually every computer and phone display and the vast majority of image storage formats. Almost all cases where there are 32 bits per pixel mean that 24 are used for the color, and the remaining 8 are the alpha channel or unused.

224 gives 16,777,216 color variations. The human eye can discriminate up to ten million colors[10] and since the gamut of a display is smaller than the range of human vision, this means this should cover that range with more detail than can be perceived. ...

...

Macintosh systems refer to 24-bit color as "millions of colors". The term "True color" is sometime used to mean what this article is calling "Direct color".[13] It is also often used to refer to all color depths greater or equal to 24.

https://upload.wikimedia.org/wikipedia/commons/e/e9/16777216colors.png

Task
Write a program which generates and returns all 16,777,216 color variations within an array as strings in the CSS rgb() function

5.1. The RGB functions: rgb() and rgba()

The rgb() function defines an RGB color by specifying the red, green, and blue channels directly. Its syntax is:

rgb() = rgb( <percentage>{3} [ / <alpha-value> ]? ) |
        rgb( <number>{3} [ / <alpha-value> ]? )
<alpha-value> = <number> | <percentage>
The first three arguments specify the red, green, and blue channels of the color, respectively. 0% represents the minimum value for that color channel in the sRGB gamut, and 100% represents the maximum value. A <number> is equivalent to a <percentage>, but with a different range: 0 again represents the minimum value for the color channel, but 255 represents the maximum. These values come from the fact that many graphics engines store the color channels internally as a single byte, which can hold integers between 0 and 255. Implementations should honor the precision of the channel as authored or calculated wherever possible. If this is not possible, the channel should be rounded to the closest value at the highest precision used, rounding up if two values are equally close.

The final argument, the <alpha-value>, specifies the alpha of the color. If given as a <number>, the useful range of the value is 0 (representing a fully transparent color) to 1 (representing a fully opaque color). If given as a , 0% represents a fully transparent color, while 100% represents a fully opaque color. If omitted, it defaults to 100%.

Values outside these ranges are not invalid, but are clamped to the ranges defined here at computed-value time.

For legacy reasons, rgb() also supports an alternate syntax that separates all of its arguments with commas:

rgb() = rgb( <percentage>#{3} , <alpha-value>? ) |
        rgb( <number>#{3} , <alpha-value>? )
Also for legacy reasons, an rgba() function also exists, with an identical grammar and behavior to rgb().

or RGB hexadecimal notation #RRGGBB format

5.2. The RGB hexadecimal notations: #RRGGBB

The CSS hex color notation allows a color to be specified by giving the channels as hexadecimal numbers, which is similar to how colors are often written directly in computer code. It’s also shorter than writing the same color out in rgb() notation.

The syntax of a <hex-color> is a <hash-token> token whose value consists of 3, 4, 6, or 8 hexadecimal digits. In other words, a hex color is written as a hash character, "#", followed by some number of digits 0-9 or letters a-f (the case of the letters doesn’t matter - #00ff00 is identical to #00FF00).

The number of hex digits given determines how to decode the hex notation into an RGB color:

6 digits

The first pair of digits, interpreted as a hexadecimal number, specifies the red channel of the color, where 00 represents the minimum value and ff (255 in decimal) represents the maximum. The next pair of digits, interpreted in the same way, specifies the green channel, and the last pair specifies the blue. The alpha channel of the color is fully opaque.

EXAMPLE 2
In other words, #00ff00 represents the same color as rgb(0 255 0) (a lime green).

See Editor's Draft of CSS Color Module Level 4

Examples
CSS rgb() function (space character can be substituted for comma character, e.g., rgb(0 255 0))

// `rgb()` `<percentage>` as strings in resulting array
['rgb(0%,0%,0%)', ...,'rgb(0%,255%,0)', ...'rgb(255,255,255)']

// `rgb()` `<number>` as strings in resulting array
['rgb(0,0,0)', ...,'rgb(0,255,0)', ...'rgb(255,255,255)']
CSS RGB hexadecimal notation RRGGBB

// RGB hexadecimal notation as strings in resulting array
['#000000', ...,'#00ff00', ...'#ffffff']
Winning criteria
Least bytes used to write the program.

"""

def gen():
    r = []
    for i in range(2**24):
        r.append("#%06X" % (i))
    return r

def main():
    print(gen())

main()
