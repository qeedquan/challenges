#!/bin/bash

cat << EOF >/dev/null

On occasion I get a little blue and need a little music to cheer me up, but clicking the start button and finding my media player takes sooooooo long. I want a faster way to play a song.

The challenge:

Write a program that:

Choose a song from my home directory (so you don’t mix-up program sound files with music) (this includes sub folders of the home directory).

This song should be a random choice from all the media in my home folder. This doesn't need to be a perfect random, but I don't want to hear the same song multiple times. (unless that's my only song ;)

To make it simple you should only look for files ending in .mp3.

In the event that you find no music in my home dir, you should print Sorry Joe, no Jams! to stdout or closest equivalent (btw my name isn't Joe ;)

The layout of my home folder will contain no infinite loops

You should use system to play the song instead of using built in media playing APIs in your language (i.e. I want the song to play in the default player for my system).

I should be able to place this file anywhere on my computer (e.g. my desktop or start folder)

Your answer should work on windows, multi-platform is a (un-scored) bonus

This is code golf so the shortest program in bytes wins!!

EOF

find $HOME -name \*.mp3 | shuf | (read l && xdg-open "$l" || echo Sorry Joe, no Jams!)

