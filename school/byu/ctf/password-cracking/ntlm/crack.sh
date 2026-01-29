#!/bin/sh

hashcat -m 1000 -a 3 -i --increment-min 4 --increment-max 4 hash.txt --show

