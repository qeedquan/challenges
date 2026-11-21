#!/bin/sh

cat << EOF >/dev/null

I've always liked screens full of randomly colored pixels. They're interesting to look at and the programs that draw them are fun to watch.

The challenge
Fill your screen, or a graphical window, with colored pixels.

The rules
Your program must have an even chance of picking all colors (i.e in the range #000000 to #FFFFFF), or all colors that can be displayed on your system.
Your program must continue to display random pixels until manually stopped (it cannot terminate on its own).
Pixels can be any size, as long as your output has at least 40x40 "pixels".
Your program must run at such a speed that it can replace every pixel on the screen/window at least once after running for three minutes.
Your program must choose truly random colors and points to replace, i.e. random with all points/colors equally likely. It cannot just look random. It must use a pRNG or better, and the output cannot be the same every time.
Your program must have an equal chance of picking all colors each iteration.
Your program must replace only one pixel at once.
Your program cannot use the internet nor your filesystem (/dev/random and /dev/urandom excepted).
Example
Your output could look like this if stopped at a random time:

https://i.sstatic.net/WL3xZ.png

The winner
The shortest answer in each language wins. Have fun!

EOF

ffmpeg -f rawvideo -video_size 320x200 -pixel_format yuv420p -framerate 30 -i /dev/urandom -ar 48000 -ac 2 -f s16le -i /dev/urandom -codec:a copy -t 5 output.mkv

